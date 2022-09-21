#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/time.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <signal.h>
#include <time.h>

int fd;
int flag = 0;

// 信号处理函数
void sighandler(int signo)
{
    // 获取当前系统时间
    time_t tm;
    time(&tm);
    char *p = ctime(&tm);

    if (flag == 0)
    {
        // 新建文件
        fd = open("./mydaemon.log", O_RDWR | O_CREAT | O_APPEND, 0777);
        if (fd < 0)
        {
            perror("open error");
            return;
        }
        flag = 1;
    }

    // 写文件
    write(fd, p, strlen(p));

    return;
}

int main()
{
    // fork 子进程，父进程退出
    pid_t pid = fork();
    if (pid != 0)
    {
        exit(0);
    }

    // 子进程调用 setsid 函数创建会话
    setsid();

    // 改变当前工作目录
    chdir("/home/root/log");

    // 重设文件掩码
    umask(0000);

    // 关闭标准输入，标准输出，标准错误输出这三个文件描述符
    close(STDIN_FILENO);
    close(STDOUT_FILENO);
    close(STDERR_FILENO);

    // 核心工作
    struct sigaction act;
    act.sa_handler = sighandler;
    act.sa_flags = 0;
    sigemptyset(&act.sa_mask);
    sigaction(SIGALRM, &act, NULL);

    // 调用 setitimer 函数设置时钟
    struct itimerval tm;
    tm.it_interval.tv_sec = 2;
    tm.it_interval.tv_usec = 0;
    tm.it_value.tv_sec = 3;
    tm.it_value.tv_usec = 0;
    setitimer(ITIMER_REAL, &tm, NULL);

    while (1)
    {
        // 获取文件大小
        int size = lseek(fd, 0, SEEK_END);
        if (size > 100)
        {
            close(fd);
            rename("./mydaemon.log", "./mydaemon.log.bak");
            flag = 0;
        }
    }

    close(fd);

    /*
        # ls
        mydaemon.log  mydaemon.log.bak
        # cat mydaemon.log
        Wed Sep 21 15:23:45 2022
        Wed Sep 21 15:23:47 2022
        Wed Sep 21 15:23:49 2022
        # cat mydaemon.log.bak
        Wed Sep 21 15:23:45 2022
        Wed Sep 21 15:23:47 2022
        Wed Sep 21 15:23:49 2022
        Wed Sep 21 15:23:51 2022
        Wed Sep 21 15:23:53 2022
    */

    return 0;
}