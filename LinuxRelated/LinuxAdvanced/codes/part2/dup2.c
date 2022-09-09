#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>

void dup2Test1(char *argv[])
{
    int oldfd = open(argv[1], O_RDWR | O_CREAT, 0755);
    if (oldfd < 0)
    {
        perror("open error");
        return;
    }

    int newfd = open(argv[2], O_RDWR | O_CREAT, 0755);
    if (newfd < 0)
    {
        perror("open error");
        return;
    }

    // 调用 dup2 函数复制 fd
    dup2(oldfd, newfd);
    printf("newfd: %d, oldfd: %d\n", newfd, oldfd);

    write(newfd, "hello world", strlen("hello world"));

    lseek(newfd, 0, SEEK_SET);

    char buf[128];
    memset(buf, 0, sizeof(buf));
    int n = read(oldfd, buf, sizeof(buf));
    printf("read over: n == %d, buf == %s\n", n, buf);

    close(oldfd);
    close(newfd);
}

void dup2Test2(char *argv[])
{
    int fd = open(argv[1], O_RDWR | O_CREAT, 0777);
    if (fd < 0)
    {
        perror("open error");
        return;
    }

    // 调用 dup2 函数实现文件重定向操作
    dup2(fd, STDOUT_FILENO);

    printf("hello cpp");

    close(fd);
    close(STDOUT_FILENO);
}

int main(int argc, char *argv[])
{
    // dup2Test1(argv);

    /*
        newfd: 4, oldfd: 3
        read over: n == 11, buf == hello world
    */

    dup2Test2(argv);

    return 0;
}