#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <errno.h>
#include <signal.h>

// SIGCHLD 信号处理函数
void waitchild(int signo)
{
    pid_t wpid;
    while (1)
    {
        wpid = waitpid(-1, NULL, WNOHANG);
        if (wpid > 0)
        {
            printf("child is quit, wpid: %d\n", wpid);
        }
        else if (wpid == 0)
        {
            printf("child is living, wpid: %d\n", wpid);
            break;
        }
        else if (wpid == -1)
        {
            printf("no child is living, wpid: %d\n", wpid);
            break;
        }
        else
        {
        }
    }
}

int main()
{
    pid_t pid;
    int i = 0;

    // 将 SIGCHLD 信号阻塞
    sigset_t mask;
    sigemptyset(&mask);
    sigaddset(&mask, SIGCHLD);
    sigprocmask(SIG_BLOCK, &mask, NULL);

    for (i = 0; i < 3; i++)
    {
        pid = fork();
        if (pid < 0)
        {
            perror("fork error");
            return -1;
        }
        else if (pid > 0)
        {
            printf("father process, pid: %d, child pid: %d\n", getpid(), pid);
        }
        else
        {
            printf("child process, father pid: %d, pid: %d\n", getppid(), getpid());
            break;
        }
    }

    if (i == 0)
    {
        printf("the first child, pid: %d\n", getpid());
    }
    if (i == 1)
    {
        printf("the second child, pid: %d\n", getpid());
    }
    if (i == 2)
    {
        printf("the third child, pid: %d\n", getpid());
    }
    if (i == 3)
    {
        printf("the father, pid: %d\n", getpid());

        // 注册 SIGCHLD 信号处理函数
        struct sigaction act;
        act.sa_handler = waitchild;
        sigemptyset(&act.sa_mask);
        act.sa_flags = 0;
        sleep(5);
        sigaction(SIGCHLD, &act, NULL);

        // 完成 SIGCHLD 信号的注册后，解除对 SIGCHLD 信号的阻塞
        sigprocmask(SIG_UNBLOCK, &mask, NULL);

        while (1)
        {
            sleep(1);
        }
    }

    /*
        father process, pid: 42357, child pid: 42358
        father process, pid: 42357, child pid: 42359
        father process, pid: 42357, child pid: 42360
        the father, pid: 42357
        child process, father pid: 42357, pid: 42360
        the third child, pid: 42360
        child process, father pid: 42357, pid: 42359
        the second child, pid: 42359
        child process, father pid: 42357, pid: 42358
        the first child, pid: 42358
        child is quit, wpid: 42358
        child is quit, wpid: 42359
        child is quit, wpid: 42360
        no child is living, wpid: -1
    */

    return 0;
}