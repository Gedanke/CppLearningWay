#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
    pid_t pid = fork();
    if (pid < 0)
    {
        perror("fork error");
        return -1;
    }
    else if (pid > 0)
    {
        printf("Parent: %d, pid: %d, fpid: %d\n", pid, getpid(), getppid());
    }
    else
    {
        printf("Child: pid: %d, fpid: %d\n", getpid(), getppid());
        // execl("/bin/ls","ls","-l",NULL);
        // execl("/home/root/codes/cplusplus/vscode/demo/test/m", "m", "gcc", "-o", "m", "m.c", "&&", "./m", "hello", "world", NULL);
        // execlp("ls", "ls", "-l", NULL);
        execl("./m", "hello", "world", NULL);
        perror("execl error");
    }

    /*
        Parent: 128182, pid: 128181, fpid: 115275
        Child: pid: 128182, fpid: 1
        total 48
        -rwxr-xr-x 1 root root 16464 Sep 13 19:03 m
        -rwxr-xr-x 1 root root 16920 Sep 13 19:28 main
        -rw-r--r-- 1 root root   872 Sep 13 19:28 main.c
        -rw-r--r-- 1 root root   179 Sep 13 19:08 m.c
    */

    /*
        Parent: 129066, pid: 129065, fpid: 115275
        Child: pid: 129066, fpid: 1
        [0]:[hello]
        [1]:[world]
    */

    return 0;
}