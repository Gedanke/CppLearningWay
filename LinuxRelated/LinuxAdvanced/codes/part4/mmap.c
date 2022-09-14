#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/types.h>

int main()
{
    // 使用 mmap 函数建设共享映射区
    // void *mmap(void *addr, size_t length, int prot, int flags, int fd, off_t offset);
    int fd = open("./test.log", O_RDWR);
    if (fd < 0)
    {
        perror("open error");
        return -1;
    }

    // 注意，mmap 不能去扩展一个内容为空的新文件，因为大小为 0，所有本没有与之对应的合法的物理页，不能扩展
    // 方法一
    // write(fd,"fd",strlen("fd"));
    // 方法二
    ftruncate(fd, 4096);

    int len = lseek(fd, 0, SEEK_END);

    void *addr = mmap(NULL, len, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    if (addr == MAP_FAILED)
    {
        perror("mmap error");
        return -1;
    }
    close(fd);

    // 创建子进程
    pid_t pid = fork();
    if (pid < 0)
    {
        perror("fork error");
        return -1;
    }
    else if (pid > 0)
    {
        memcpy(addr, "hello world", strlen("hello world"));
        wait(NULL);
    }
    else if (pid == 0)
    {
        sleep(1);
        char *p = (char *)addr;
        printf("%s\n", p);
    }

    /*
        hello world
    */

    return 0;
}