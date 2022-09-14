#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>

int main()
{
    // 创建 fifo 文件
    // int mkfifo(const char *pathname, mode_t mode);

    int ret = access("./myfifo", F_OK);
    if (ret != 0)
    {
        ret = mkfifo("./myfifo", 0777);
        if (ret < 0)
        {
            perror("mkfifo error");
            return -1;
        }
    }

    // 打开 fifo 文件
    int fd = open("./myfifo", O_RDWR);
    if (fd < 0)
    {
        perror("open error");
        return -1;
    }

    // 读 fifo 文件
    int n;
    char buf[64];
    while (1)
    {
        memset(buf, 0, sizeof(buf));
        n = read(fd, buf, sizeof(buf));
        printf("n: %d, buf: %s\n", n, buf);
    }

    // 关闭文件
    close(fd);

    // 先运行 read 文件，再运行 write 文件
    /*
        n: 14, buf: 0: hello world
        n: 14, buf: 1: hello world
        n: 14, buf: 2: hello world
        n: 14, buf: 3: hello world
        n: 14, buf: 4: hello world
        n: 14, buf: 5: hello world
        // ...
    */

    return 0;
}