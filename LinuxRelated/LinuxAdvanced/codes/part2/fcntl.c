#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>

int main(int argc, char *argv[])
{
    int fd = open(argv[1], O_RDWR);
    if (fd < 0)
    {
        perror("open error");
        return -1;
    }

    // 获取和设置 fd 的 flags 属性
    int flags = fcntl(fd, F_GETFL, 0);
    flags = flags | O_APPEND;
    fcntl(fd, F_SETFL, flags);

    write(fd, "hello world", strlen("hello world"));

    close(fd);

    /*
        newfd: 4, oldfd: 3
        read over: n == 11, buf == hello world
    */

    return 0;
}