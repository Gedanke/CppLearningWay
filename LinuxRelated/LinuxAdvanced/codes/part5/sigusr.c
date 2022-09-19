#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <errno.h>
#include <signal.h>

int num = 0;
int flag;

void func1(int signo)
{
    printf("F:[%d]\n", num);
    num += 2;
    flag = 0;
    sleep(1);
}

void func2(int signo)
{
    printf("C:[%d]\n", num);
    num += 2;
    flag = 0;
    sleep(1);
}

int main()
{
    int ret;
    pid_t pid;

    pid = fork();

    if (pid < 0)
    {
        perror("fork error");
        return -1;
    }
    else if (pid > 0)
    {
        num = 0;
        flag = 1;
        signal(SIGUSR1, func1);

        while (1)
        {
            if (flag == 0)
            {
                kill(pid, SIGUSR2);
                flag = 1;
            }
        }
    }
    else
    {
        num = 1;
        flag = 0;
        signal(SIGUSR2, func2);

        while (1)
        {
            if (flag == 0)
            {
                kill(getppid(), SIGUSR1);
                flag = 1;
            }
        }
    }

    /*
        F:[0]
        C:[1]
        F:[2]
        C:[3]
        F:[4]
        C:[5]
        F:[6]
        C:[7]
        // ...
    */

    return 0;
}