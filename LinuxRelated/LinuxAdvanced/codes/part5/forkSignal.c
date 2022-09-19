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

void sighandler(int signo)
{
    printf("signo: %d\n", signo);
}

int main()
{
    pid_t pid;
    int i = 0;

    signal(SIGCHLD, sighandler);

    pid = fork();

    if (pid < 0)
    {
        perror("fork error");
        return -1;
    }
    else if (pid > 0)
    {
        printf("The father process, pid: %d, child pid: %d\n", getpid(), pid);
        int status;
        while (1)
        {
            sleep(1);
            pid_t p = waitpid(-1, &status, WNOHANG);
            if (WIFEXITED(status))
            {
                // 正常退出
                printf("Child normal exit, status: %d\n", WEXITSTATUS(status));
                break;
            }
            else if (WIFSIGNALED(status))
            {
                // 被信号杀死
                printf("Child killed by signal, signo: %d\n", WTERMSIG(status));
                break;
            }
            else
            {
            }
        }
    }
    else
    {
        printf("The child process, father pid: %d, pid: %d\n", getppid(), getpid());
        exit(-1);
    }

    /*
        The father process, pid: 17726, child pid: 17727
        The child process, father pid: 17726, pid: 17727
        signo: 17
        Child normal exit, status: 255
    */

    return 0;
}