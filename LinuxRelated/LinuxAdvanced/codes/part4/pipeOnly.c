#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <sys/wait.h>
#include <sys/stat.h>

int main()
{
    // 创建管道
    // int pipe(int pipefd[2]);
    int fd[2];
    int ret = pipe(fd);
    if (ret < 0)
    {
        perror("pipe error");
        return -1;
    }

    // 写端
    write(fd[1], "hello, I am parent process", strlen("hello, I am parent process"));

    sleep(5);

    // 读端
    char buf[64];
    memset(buf, 0, sizeof(buf));
    int n = read(fd[0], buf, sizeof(buf));
    printf("read over, n: %d, buf: %s\n", n, buf);

    /*
        read over, n: 26, buf: hello, I am parent process
    */

    return 0;
}