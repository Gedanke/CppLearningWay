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

    // 写 fifo 文件
    int i = 0;
    char buf[64];
    while (1)
    {
        memset(buf, 0, sizeof(buf));
        sprintf(buf, "%d: %s", i, "hello world");
        write(fd, buf, strlen(buf));
        sleep(1);
        i++;
    }

    // 关闭文件
    close(fd);

    return 0;
}
