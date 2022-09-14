#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <errno.h>

int main()
{
    int i = 0;
    int n = 3;

    for (i = 0; i < n; i++)
    {
        pid_t pid = fork();
        if (pid < 0)
        {
            perror("fork error");
            return -1;
        }
        else if (pid > 0)
        {
            printf("father: fpid: %d, cpid: %d\n", getpid(), pid);
            sleep(1);
        }
        else
        {
            printf("child: fpid: %d, cpid: %d\n", getppid(), getpid());
            break;
        }
    }

    // 父进程
    if (i == 3)
    {
        printf("%d: father: fpid: %d\n", i, getpid());
        pid_t wpid;
        int status;

        while (1)
        {
            wpid = waitpid(-1, &status, WNOHANG);
            if (wpid == 0)
            {
                // 没有子进程退出
                continue;
            }
            else if (wpid == -1)
            {
                // 已经没有子进程
                printf("no child is living, wpid: %d\n", wpid);
                exit(0);
            }
            else if (wpid > 0)
            {
                if (WIFEXITED(status))
                {
                    printf("normal exit, status: %d\n", WEXITSTATUS(status));
                }
                else if (WIFSIGNALED(status))
                {
                    printf("killed by sign: %d\n", WTERMSIG(status));
                }
                else
                {
                }
            }
            else
            {
            }
        }
    }

    // 第一个子进程
    if (i == 0)
    {
        printf("%d: child: cpid: %d\n", i, getpid());
        execlp("ls", "ls", "-l", NULL);
        perror("execl error");
        exit(-1);
    }

    // 第二个子进程
    if (i == 1)
    {
        printf("%d: child: cpid: %d\n", i, getpid());
        execl("/home/root/codes/cplusplus/vscode/demo/test/hello", "hello", "111", "222", NULL);
        perror("execl error");
        return -1;
    }

    // 第三个子进程
    if (i == 2)
    {
        printf("%d: child: cpid: %d\n", i, getpid());
        execl("/home/root/codes/cplusplus/vscode/demo/test/test", "test", NULL);
        perror("execl error");
        return -1;
    }

    /*
        father: fpid: 8183, cpid: 8184
        child: fpid: 8183, cpid: 8184
        0: child: cpid: 8184
        total 100
        -rwxr-xr-x 1 root root 16784 Sep 14 20:58 hello
        -rw-r--r-- 1 root root   413 Sep 14 21:40 hello.c
        -rwxr-xr-x 1 root root 17136 Sep 14 21:55 m
        -rwxr-xr-x 1 root root 17224 Sep 14 21:45 main
        -rw-r--r-- 1 root root  1139 Sep 14 21:29 main.c
        -rw-r--r-- 1 root root  2374 Sep 14 21:55 m.c
        -rwxr-xr-x 1 root root 16696 Sep 14 21:03 test
        -rw-r--r-- 1 root root   305 Sep 14 21:51 test.c
        -rw-r--r-- 1 root root  4096 Sep 14 21:45 test.log
        father: fpid: 8183, cpid: 8221
        child: fpid: 8183, cpid: 8221
        1: child: cpid: 8221
        0: hello
        1: 111
        2: 222
        hello world
        father: fpid: 8183, cpid: 8228
        child: fpid: 8183, cpid: 8228
        2: child: cpid: 8228
        hello world
        3: father: fpid: 8183
        normal exit, status: 0
        killed by sign: 11
        hello world
        hello world
        hello world
        hello world
        hello world
        hello world
        ...
    */

    return 0;
}