#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>

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
        sleep(20);
        printf("Parent: %d, pid: %d, fpid: %d\n", pid, getpid(), getppid());
    }
    else
    {
        printf("Child: %d, pid: %d, fpid: %d\n", pid, getpid(), getppid());
    }

    /*
        Child: 0, pid: 129894, fpid: 129893
        Parent: 129894, pid: 129893, fpid: 129376
     */

    return 0;
}