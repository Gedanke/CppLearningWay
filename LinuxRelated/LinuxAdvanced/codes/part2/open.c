#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>

int main(int argc, char *argv[])
{
    // 打开文件
    int fd = open(argv[1], O_RDWR | O_CREAT, 0777);
    if (fd < 0)
    {
        perror("open error");
        return -1;
    }

    // 写文件
    // ssize_t write(int fd, const void *buf, size_t count);
    write(fd, "hello cpp", strlen("hello cpp"));

    // 移动文件指针到文件开始处
    // off_t lseek(int fd, off_t offset, int whence);
    lseek(fd, 0, SEEK_SET);

    // 读文件
    // ssize_t read(int fd, void *buf, size_t count);
    char buf[1024];
    memset(buf, 0, sizeof(buf));
    int n = read(fd, buf, sizeof(buf));
    printf("n == [%d], buf == [%s]\n", n, buf);

    // 关闭文件
    close(fd);

    // n == [9], buf == [hello cpp]

    return 0;
}