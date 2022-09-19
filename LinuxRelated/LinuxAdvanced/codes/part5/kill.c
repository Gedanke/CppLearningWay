#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <errno.h>

void testKill1()
{
    kill(getpid(), SIGKILL);
    printf("hello world\n");
}

// 父进程杀死子进程或者子进程杀死父进程
void testKill2()
{
    pid_t pid;
    int i = 0;
    for (int i = 0; i < 3; i++)
    {
        pid = fork();
        if (pid < 0)
        {
            perror("fork error");
            return;
        }
        else if (pid > 0)
        {
            printf("father process, pid: %d, child pid: %d\n", getpid(), pid);
            // if (i == 0)
            // {
            //     kill(pid, SIGKILL);
            // }
        }
        else
        {
            printf("child process, father pid: %d, pid: %d\n", getppid(), getpid());
            break;
        }
    }

    if (i == 0)
    {
        printf("the first child, pid: %d\n", getpid());

        // 子进程杀死父进程
        // kill(getppid(), SIGKILL);

        sleep(1);
        // 杀死同一组内所有进程
        kill(0, SIGKILL);
    }
    if (i == 1)
    {
        printf("the second child, pid: %d\n", getpid());
        sleep(3);
    }
    if (i == 2)
    {
        printf("the third child, pid: %d\n", getpid());
        sleep(3);
    }
    if (i == 3)
    {
        printf("the father, pid: %d\n", getpid());
        sleep(3);
    }
}

int main()
{
    // testKill1();

    // Killed

    testKill2();

    /*
        father process, pid: 13747, child pid: 13748
        father process, pid: 13747, child pid: 13749
        father process, pid: 13747, child pid: 13750
        the first child, pid: 13747
        child process, father pid: 13747, pid: 13750
        the first child, pid: 13750
        child process, father pid: 13747, pid: 13749
        the first child, pid: 13749
        child process, father pid: 13747, pid: 13748
        the first child, pid: 13748
        Killed
    */

    return 0;
}