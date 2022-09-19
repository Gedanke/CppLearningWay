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
        printf("the father: pid: %d\n", getpid());
    }
    if (i == 0)
    {
        printf("the first child: %d\n", getpid());
    }
    if (i == 1)
    {
        printf("the second child: %d\n", getpid());
    }
    if (i == 2)
    {
        printf("the third child: %d\n", getpid());
    }

    /*
        father: pid: 19239
        father: pid: 19239
        father: pid: 19239
        the father: pid: 19239
        child: pid: 19242
        the third child: 19242
        child: pid: 19241
        the second child: 19241
        child: pid: 19240
        the first child: 19240
     */

    return 0;
}