#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>

void dupTest(char *argv[])
{
    int fd = open(argv[1], O_RDWR);
    if (fd < 0)
    {
        perror("open error");
        return;
    }

    // 调用 dup 函数复制 fd
    int newfd = dup(fd);
    printf("newfd: %d, fd: %d\n", newfd, fd);

    // 使用 fd 对文件进行写操作
    write(fd, "hello cpp", strlen("hello cpp"));

    // 调用 lseek 函数移动文件指针到开始处
    lseek(fd, 0, SEEK_SET);

    // 使用 newfd 读文件
    char buf[128];
    memset(buf, 0, sizeof(buf));
    int n = read(newfd, buf, sizeof(buf));
    printf("read over: n == %d, buf == %s\n", n, buf);

    // 关闭文件
    close(fd);
    close(newfd);
}

int main(int argc, char *argv[])
{
    dupTest(argv);

    /*
        newfd: 4, fd: 3
        read over: n == 9, buf == hello cpp
    */

    return 0;
}