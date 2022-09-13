#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
    pid_t pid;
    char *mes;
    int n;
    pid = fork();

    if (pid < 0)
    {
        perror("fork failed");
        exit(1);
    }

    if (pid == 0)
    {
        mes = "This is the child\n";
        n = 6;
    }
    else
    {
        mes = "This is the parent\n";
        n = 3;
    }

    while (n--)
    {
        printf("%s", mes);
        sleep(1);
    }

    /*
        This is the parent
        This is the parent
        This is the parent
        This is the child
        This is the child
        This is the child
        This is the child
        This is the child
        This is the child
    */

    return 0;
}