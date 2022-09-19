#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <errno.h>

void sighandler(int signo)
{
    printf("signo: %d\n", signo);
}

int main()
{
    signal(SIGALRM, sighandler);

    // 设置时钟
    int n = alarm(5);
    printf("n: %d\n", n);

    sleep(2);
    n = alarm(2);
    printf("n: %d\n", n);

    sleep(2);
    n = alarm(5);
    printf("n: %d\n", n);

    // 取消闹钟
    n = alarm(0);
    printf("n: %d\n", n);

    sleep(6);

    /*
        n: 0
        n: 3
        signo: 14
        n: 0
        n: 5
    */

    return 0;
}