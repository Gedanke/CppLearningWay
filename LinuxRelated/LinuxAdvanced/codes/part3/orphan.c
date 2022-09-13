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
        sleep(5);
        printf("Parent: %d, pid: %d, fpid: %d\n", pid, getpid(), getppid());
    }
    else
    {
        printf("Child: %d, pid: %d, fpid: %d\n", pid, getpid(), getppid());
        sleep(20);
        printf("Child: %d, pid: %d, fpid: %d\n", pid, getpid(), getppid());
    }

    /*
        Parent: 129363, pid: 129362, fpid: 129356
        Child: 0, pid: 129363, fpid: 129362
        Child: 0, pid: 129363, fpid: 1
     */

    return 0;
}