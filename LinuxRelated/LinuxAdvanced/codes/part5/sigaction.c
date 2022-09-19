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
    sleep(5);
}

int main()
{
    // 注册 SIGINT 信号处理函数
    struct sigaction act;
    // 信号处理函数
    act.sa_handler = sighandler;
    // 阻塞信号
    sigemptyset(&act.sa_mask);
    // 在信号处理函数执行期间阻塞 SIGQUIT 信号
    // sigaddset(&act.sa_mask, SIGQUIT);
    act.sa_flags = 0;
    sigaction(SIGINT, &act, NULL);

    signal(SIGQUIT, sighandler);

    while (1)
    {
        sleep(1);
    }

    /*
        ^Csigno: 2
        ^\signo: 3
        ^\^\signo: 3
        ^C^\^C^\^C^\^Csigno: 3
        ^\signo: 3
        ^Csigno: 2
    */

    return 0;
}