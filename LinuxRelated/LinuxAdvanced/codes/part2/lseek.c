#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>

void testLseek1(char *argv[])
{
    int fd = open(argv[1], O_RDWR);
    if (fd < 0)
    {
        perror("open error");
        return;
    }

    int len = lseek(fd, 0, SEEK_END);
    printf("file size: %d\n", len);

    close(fd);
}

void testLseek2(char *argv[])
{
    int fd = open(argv[1], O_RDWR);
    if (fd < 0)
    {
        perror("open error");
        return;
    }

    lseek(fd, 20, SEEK_SET);
    write(fd, "H", 1);

    close(fd);

    fd = open(argv[1], O_RDWR);
    if (fd < 0)
    {
        perror("open error");
        return;
    }

    char buf[1024];
    memset(buf, 0, sizeof(buf));
    int n = read(fd, buf, sizeof(buf));
    printf("First: n == %d, buf == %s\n", n, buf);

    close(fd);
}

int main(int argc, char *argv[])
{
    // testLseek1(argv);

    // file size: 9

    testLseek2(argv);

    // First: n == 21, buf == 

    return 0;
}