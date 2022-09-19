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
    // printf("signo: %d\n", signo);
    printf("hello world\n");
}

int main()
{
    // int setitimer(int which, const struct itimerval *new_value, struct itimerval *old_value);

    // 注册信号 SIGAKRN 的信号处理函数
    signal(SIGALRM, sighandler);

    struct itimerval timerval;
    // 周期行时间赋值
    timerval.it_interval.tv_sec = 1;
    timerval.it_interval.tv_usec = 0;

    // 第一次触发时间
    timerval.it_value.tv_sec = 1;
    timerval.it_value.tv_usec = 0;

    setitimer(ITIMER_REAL, &timerval, NULL);

    while (1)
    {
        sleep(1);
    }

    /*
        hello world
        hello world
        hello world
        hello world
        // ...
    */

    return 0;
}