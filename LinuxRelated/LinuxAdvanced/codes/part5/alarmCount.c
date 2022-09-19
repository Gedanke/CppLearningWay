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
    alarm(1);
    int i = 0;
    while (1)
    {
        printf("[%d]", i++);
    }

    return 0;
}