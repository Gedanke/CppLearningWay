#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <errno.h>
#include <sys/time.h>

void waitchild(int signo)
{
    printf("signo: %d\n", signo);
}

int main()
{
    int i = 0;
    int n = 3;

    for (i = 0; i < n; i++)
    {
        // fork 子进程
        pid_t pid = fork();
        if (pid < 0)
        {
            perror("fork error");
            return -1;
        }
        else if (pid > 0)
        {
            printf("father: pid: %d\n", getpid());
            sleep(1);
        }
        else
        {
            printf("child: pid: %d\n", getpid());
            break;
        }
    }

    // 父进程
    if (i == 3)
    {
        printf("%d: father: pid: %d\n", i, getpid());
        signal(SIGCHLD, waitchild);

        while (1)
        {
            sleep(4);
            // 杀死一个进程组
            kill(0, SIGKILL);
        }
    }
    if (i == 0)
    {
        printf("%d: child: %d\n", i, getpid());
        sleep(10);
    }
    if (i == 1)
    {
        printf("%d: child: %d\n", i, getpid());
        sleep(10);
    }
    if (i == 2)
    {
        printf("%d: child: %d\n", i, getpid());
        sleep(10);
    }

    /*
        father: pid: 19627
        child: pid: 19628
        0: child: 19628
        father: pid: 19627
        child: pid: 19654
        1: child: 19654
        father: pid: 19627
        child: pid: 19679
        2: child: 19679
        3: father: pid: 19627
        Killed
    */

    return 0;
}