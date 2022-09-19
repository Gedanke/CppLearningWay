#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <errno.h>

int main()
{
    // 给当前进程发送信号
    abort();

    printf("hello world\n");

    // Aborted (core dumped)

    return 0;
}
