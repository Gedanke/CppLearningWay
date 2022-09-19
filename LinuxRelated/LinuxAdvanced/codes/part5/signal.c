#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <errno.h>

// 信号处理函数
void sighandler(int signo)
{
    printf("signo: %d\n", signo);
}

int main()
{
    // 创建管道
    int fd[2];
    int ret = pipe(fd);
    if (ret < 0)
    {
        perror("pipe error");
        return -1;
    }

    // 注册 SIGPIPE 信号处理函数
    signal(SIGPIPE, sighandler);

    // 关闭读端
    close(fd[0]);
    // 不关闭读端，没有 SIGPIPE 信号

    write(fd[1], "hello world", strlen("hello world"));

    /*
        signo: 13
    */

    return 0;
}
