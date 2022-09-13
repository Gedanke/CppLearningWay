#include <sys/stat.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>

int main()
{
    pid_t cpid, wpid;
    int status;
    int n = 5;
    int i;
    for (i = 0; i < n; i++)
    {
        cpid = fork();
        if (cpid == -1)
        {
            perror("fork");
            exit(EXIT_FAILURE);
        }
        else if (cpid == 0)
        {
            break;
        }
    }
    if (n == i)
    {
        sleep(n);
        printf("I am parent, pid is: %d\n", getpid());
        do
        {
            wpid = waitpid(-1, NULL, WNOHANG);
            if (wpid > 0)
            {
                n--;
                printf("child pid: %d called back\n", wpid);
            }
            sleep(1);
        } while (n > 0);
        printf("wait finished\n");
    }
    else
    {
        sleep(i);
        printf("I'm %dth child, pid = %d\n", i + 1, getpid());
    }

    /*
        I'm 1th child, pid = 131507
        I'm 2th child, pid = 131508
        I'm 3th child, pid = 131509
        I'm 4th child, pid = 131510
        I'm 5th child, pid = 131511
        I am parent, pid is: 131506
        child pid: 131507 called back
        child pid: 131508 called back
        child pid: 131509 called back
        child pid: 131510 called back
        child pid: 131511 called back
        wait finished
    */

    return 0;
}