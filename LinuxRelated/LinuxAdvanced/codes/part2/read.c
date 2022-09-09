#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>

void testRead1()
{
    // 读标准输入
    char buf[1024];
    memset(buf, 0, sizeof(buf));
    int n = read(STDIN_FILENO, buf, sizeof(buf));
    printf("First: n == %d, buf == %s", n, buf);
}

void testRead2()
{
    // 读标准输入
    char buf[64];
    memset(buf, 0, sizeof(buf));
    int n = read(STDIN_FILENO, buf, sizeof(buf));
    printf("Read: n == %d, buf == %s", n, buf);
}

void testRead3(char *argv[])
{
    // 打开文件
    int fd = open(argv[1], O_RDWR);
    if (fd < 0)
    {
        perror("open error");
        return;
    }

    // 读文件
    char buf[1024];
    memset(buf, 0, sizeof(buf));
    int n = read(fd, buf, sizeof(buf));
    printf("First: n == %d, buf == %s\n", n, buf);

    // 再次读文件，验证 read 函数是否堵塞
    memset(buf, 0, sizeof(buf));
    n = read(fd, buf, sizeof(buf));
    printf("Second: n == %d, buf == %s\n", n, buf);

    // 关闭文件
    close(fd);
}

int main(int argc, char *argv[])
{
    // testRead1();

    /*
        hello cpp!
        First: n == 11, buf == hello cpp!
    */

    // testRead2();

    /*
        hello cpp
        Read: n == 10, buf == hello cpp
    */

    testRead3(argv);

    /*
        First: n == 9, buf == hello cpp
        Second: n == 0, buf ==
    */

    return 0;
}