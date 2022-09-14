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

    void *addr = mmap(NULL, 4096, PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANONYMOUS, -1, 0);
    if (addr == MAP_FAILED)
    {
        perror("mmap error");
        return -1;
    }

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