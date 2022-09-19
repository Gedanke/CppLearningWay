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

// 信号处理函数
void sighandler(int signo)
{
    printf("signo: %d\n", signo);
}

int main()
{
    // 注册信号处理函数
    signal(SIGINT, sighandler);
    signal(SIGQUIT, sighandler);

    // 定义信号集变量
    sigset_t set;
    sigset_t oldset;

    // 初始化信号集
    sigemptyset(&set);
    sigemptyset(&oldset);

    // 将 SIGINT SIGQUIT 加入到 set 集合
    sigaddset(&set, SIGINT);
    sigaddset(&set, SIGQUIT);

    // 将 set 集合中的 SIGINT，SIGQUIT 信号加入到阻塞信号集中
    sigprocmask(SIG_BLOCK, &set, &oldset);

    int i = 0;
    int j = 1;
    sigset_t pend;

    while (1)
    {
        // 获取未决信号
        sigemptyset(&pend);
        sigpending(&pend);

        for (i = 1; i <= 32; i++)
        {
            if (sigismember(&pend, i) == 1)
            {
                printf("1");
            }
            else
            {
                printf("0");
            }
        }
        printf("\n");

        // 循环 10 次接触对 SIGINT，SIGQUIT 信号的阻塞
        if (j++ % 10 == 0)
        {
            sigprocmask(SIG_SETMASK, &oldset, NULL);
        }
        else
        {
            sigprocmask(SIG_BLOCK, &set, NULL);
        }

        sleep(1);
    }

    /*
        00000000000000000000000000000000
        00000000000000000000000000000000
        ^C01000000000000000000000000000000
        01000000000000000000000000000000
        01000000000000000000000000000000
        ^\01100000000000000000000000000000
        01100000000000000000000000000000
        01100000000000000000000000000000
        01100000000000000000000000000000
        01100000000000000000000000000000
        signo: 3
        signo: 2
        00000000000000000000000000000000
        00000000000000000000000000000000
        ...
    */

    return 0;
}