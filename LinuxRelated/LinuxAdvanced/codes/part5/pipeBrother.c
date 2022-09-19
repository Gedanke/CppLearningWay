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
    int fd[2];
    int ret;
    pid_t pid;

    // 创建一个管道
    ret = pipe(fd);
    if (ret < 0)
    {
        perror("pipe error");
        return -1;
    }

    int i = 0;
    int n = 2;
    for (i = 0; i < n; i++)
    {
        // 创建子进程
        pid = fork();
        if (pid < 0)
        {
            perror("fork error");
            return -1;
        }
        else if (pid == 0)
        {
            break;
        }
        else
        {
        }
    }

    if (i == n)
    {
        close(fd[0]);
        close(fd[1]);

        pid_t wpid;
        int status;

        while (1)
        {
            // 等待子进程回收
            wpid = waitpid(-1, &status, WNOHANG);
            if (wpid == 0)
            {
                sleep(1);
                continue;
            }
            else if (wpid == -1)
            {
                printf("no child is living, wpid: %d\n", wpid);
                exit(0);
            }
            else if (wpid > 0)
            {
                if (WIFEXITED(status))
                {
                    printf("child normal exited, status: %d\n", WEXITSTATUS(status));
                }
                else if (WIFSIGNALED(status))
                {
                    printf("child killed by signo: %d\n", WTERMSIG(status));
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
    if (i == 0)
    {
        close(fd[0]);

        // 将标准输出重定向到管道写端
        dup2(fd[1], STDOUT_FILENO);
        execlp("ps", "ps", "-aux", NULL);

        close(fd[1]);
    }
    if (i == 1)
    {
        close(fd[1]);
        printf("child: fpid: %d, cpid: %d\n", getppid(), getpid());

        // 将标准输入重定向到管道读端
        dup2(fd[0], STDIN_FILENO);
        execlp("grep", "grep", "--color", "bash", NULL);

        close(fd[0]);
    }

    /*
        child: fpid: 23829, cpid: 23831
        root       15536  0.0  0.1   9624  3756 ?        Ss   11:53   0:00 bash
        root       15795  0.0  0.2  10048  4368 pts/0    Ss   11:54   0:00 /usr/bin/bash --init-file /root/.vscode-server/bin/74b1f979648cc44d385a2286793c226e611f59e7/out/vs/workbench/contrib/terminal/browser/media/shellIntegration-bash.sh
        root       23831  0.0  0.0   9032   648 pts/0    S+   19:13   0:00 grep --color bash
        child normal exited, status: 0
        child normal exited, status: 0
        no child is living, wpid: -1
    */

    return 0;
}