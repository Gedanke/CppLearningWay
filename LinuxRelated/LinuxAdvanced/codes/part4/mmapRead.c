//使用mmap函数完成父子进程间通信
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/mman.h>

int main()
{
    // 使用 mmap 函数建立共享映射区
    // void *mmap(void *addr, size_t length, int prot, int flags, int fd, off_t offset);

    int fd = open("./test.log", O_RDWR);
    if (fd < 0)
    {
        perror("open error");
        return -1;
    }

    int len = lseek(fd, 0, SEEK_END);

    void *addr = mmap(NULL, len, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    if (addr == MAP_FAILED)
    {
        perror("mmap error");
        return -1;
    }

    char buf[64];
    memset(buf, 0, sizeof(buf));
    memcpy(buf, addr, 10);
    printf("buf: %s\n", buf);

    // buf: 0123456789

    return 0;
}
