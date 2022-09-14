#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <sys/wait.h>
#include <sys/stat.h>

void testPipe1()
{
    // 创建管道
    // int pipe(int pipefd[2]);
    int fd[2];
    int ret = pipe(fd);
    if (ret < 0)
    {
        perror("pipe error");
        return;
    }

    // 创建子进程
    pid_t pid = fork();
    if (pid < 0)
    {
        perror("fork error");
        return;
    }
    else if (pid > 0)
    {
        // 关闭读端
        close(fd[0]);
        sleep(5);
        write(fd[1], "hello, I am parent process", strlen("hello, I am parent process"));
    }
    else
    {
        // 关闭写端
        close(fd[1]);
        char buf[64];
        memset(buf, 0, sizeof(buf));
        int n = read(fd[0], buf, sizeof(buf));
        printf("read over, n: %d, buf: %s\n", n, buf);
    }
}

void testPipe2()
{
    // 创建管道
    // int pipe(int pipefd[2]);
    int fd[2];
    int ret = pipe(fd);
    if (ret < 0)
    {
        perror("pipe error");
        return;
    }

    // 创建子进程
    pid_t pid = fork();
    if (pid < 0)
    {
        perror("fork error");
        return;
    }
    else if (pid > 0)
    {
        // 关闭写端
        close(fd[1]);

        char buf[64];
        memset(buf, 0, sizeof(buf));
        int n = read(fd[0], buf, sizeof(buf));
        printf("read over, n: %d, buf: %s\n", n, buf);

        int status;
        int wpid = wait(&status);
        printf("wpid: %d\n", wpid);

        if (WIFEXITED(status))
        {
            // 正常退出
            printf("Child normal exit, status: %d\n", WEXITSTATUS(status));
        }
        else if (WIFSIGNALED(status))
        {
            // 被信号杀死
            printf("Child killed by signal, signo: %d\n", WTERMSIG(status));
        }
        else
        {
        }
    }
    else
    {
        // 关闭读端
        close(fd[0]);
        write(fd[1], "hello, I am child process", strlen("hello, I am child process"));
    }
}

void testPipe3()
{
    // 创建管道
    // int pipe(int pipefd[2]);
    int fd[2];

    int ret = pipe(fd);

    if (ret < 0)
    {
        perror("pipe error");
        return;
    }

    // 创建子进程
    pid_t pid = fork();
    if (pid < 0)
    {
        perror("fork error");
        return;
    }
    else if (pid > 0)
    {
        sleep(4);
        char *str = "hello, I am parent process";
        printf("parent send over, buf: %s\n", str);
        write(fd[1], str, strlen(str));

        sleep(4);

        char buf[64];
        memset(buf, 0, sizeof(buf));
        int n = read(fd[0], buf, sizeof(buf));
        printf("parent read over, n: %d, buf: %s\n", n, buf);
    }
    else
    {
        char *str = "hello, I am child process";
        char buf[64];
        memset(buf, 0, sizeof(buf));
        int n = read(fd[0], buf, sizeof(buf));
        printf("child read over, n: %d, buf: %s\n", n, buf);

        sleep(4);

        printf("child send over, buf: %s\n", str);
        write(fd[1], str, strlen(str));
    }
}

void testPipe4()
{
    // 创建管道
    // int pipe(int pipefd[2]);
    int fdP2C[2];
    int fdC2P[2];

    int retP2C = pipe(fdP2C);
    int retC2P = pipe(fdC2P);

    if (retP2C < 0 | retC2P < 0)
    {
        perror("pipe error");
        return;
    }

    // 创建子进程
    pid_t pid = fork();
    if (pid < 0)
    {
        perror("fork error");
        return;
    }
    else if (pid > 0)
    {
        char *str = "hello, I am parent process";
        // 关闭读管道，保留写
        close(fdP2C[0]);
        // 关闭写管道，保留读
        close(fdC2P[1]);

        printf("parent send over, buf: %s\n", str);
        write(fdP2C[1], str, strlen(str));

        char buf[64];
        memset(buf, 0, sizeof(buf));
        int n = read(fdC2P[0], buf, sizeof(buf));
        printf("parent read over, n: %d, buf: %s\n", n, buf);
    }
    else
    {
        char *str = "hello, I am child process";
        // 关闭写管道，保留读
        close(fdP2C[1]);
        // 关闭读管道，保留写
        close(fdC2P[0]);

        char buf[64];
        memset(buf, 0, sizeof(buf));
        int n = read(fdP2C[0], buf, sizeof(buf));
        printf("child read over, n: %d, buf: %s\n", n, buf);

        printf("child send over, buf: %s\n", str);
        write(fdC2P[1], str, strlen(str));
    }
}

int main()
{
    // testPipe1();

    /*
        read over, n: 26, buf: hello, I am parent process
    */

    // testPipe2();

    /*
        read over, n: 25, buf: hello, I am child process
        wpid: 3463
        Child normal exit, status: 0
    */

    testPipe3();

    /*
        parent send over, buf: hello, I am parent process
        child read over, n: 26, buf: hello, I am parent process
        child send over, buf: hello, I am child process
        parent read over, n: 25, buf: hello, I am child process
    */

    // testPipe4();

    /*
        parent send over, buf: hello, I am parent process
        child read over, n: 26, buf: hello, I am parent process
        child send over, buf: hello, I am child process
        parent read over, n: 25, buf: hello, I am child process
    */

    return 0;
}