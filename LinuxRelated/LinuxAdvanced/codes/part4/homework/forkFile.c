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

    int fd = open("./test.log", O_RDWR | O_CREAT, 0777);
    if (fd < 0)
    {
        perror("open error");
        return -1;
    }

    pid_t pid = fork();
    if (pid < 0)
    {
        perror("fork error");
        return -1;
    }
    else if (pid > 0)
    {
        printf("father: fpid: %d, cpid: %d\n", getpid(), pid);
        write(fd, "hello world", strlen("hello world"));
        close(fd);
    }
    else
    {
        printf("child: fpid: %d, cpid: %d\n", getppid(), getpid());
        char buf[256];
        int n;
        memset(buf, 0, sizeof(buf));
        sleep(1);
        lseek(fd, 0, SEEK_SET);
        n = read(fd, buf, sizeof(buf));
        printf("read over, n: %d, buf: %s\n", n, buf);
        close(fd);
    }

    /*
        father: fpid: 8700, cpid: 8701
        child: fpid: 1, cpid: 8701
        read over, n: 256, buf: hello world
    */

    return 0;
}
