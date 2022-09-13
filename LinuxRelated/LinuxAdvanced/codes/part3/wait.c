#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    pid_t pid = fork();

    if (pid < 0)
    {
        perror("fork error");
        return -1;
    }
    else if (pid > 0)
    {
        printf("Parent: %d, pid: %d, fpid: %d\n", pid, getpid(), getppid());
        int status;
        pid_t wpid = wait(&status);
        printf("wpid: %d\n", wpid);

        if (WIFEXITED(status))
        {
            // 正常退出
            printf("Child normal exit, status: %d\n", WEXITSTATUS(status));
        }
        else if (WIFSIGNALED(status))
        {
            // 被信号杀死
            printf("Child killed by signal, signo: %d\n", WTERMSIG(status));
        }
        else
        {
        }
    }
    else
    {
        printf("Child: %d, pid: %d, fpid: %d\n", pid, getpid(), getppid());
        sleep(20);
        return 9;
    }

    /*
        Parent: 130459, pid: 130458, fpid: 129376
        Child: 0, pid: 130459, fpid: 130458
        wpid: 130459
        Child normal exit, status: 9
     */

    return 0;
}