#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <sys/wait.h>
#include <sys/stat.h>

int main()
{
    // 创建管道
    // int pipe(int pipefd[2]);
    int fd[2];
    int ret = pipe(fd);
    if (ret < 0)
    {
        perror("pipe error");
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
        // 关闭读终端
        close(fd[0]);
        dup2(fd[1], STDOUT_FILENO);
        execlp("ps", "ps", "aux", NULL);
        perror("execlp error");
        int wpid = waitpid(-1, NULL, WNOHANG);
        if (wpid > 0)
        {
            printf("child pid: %d called back\n", wpid);
        }
    }
    else
    {
        // 关闭终端
        close(fd[1]);
        dup2(fd[0], STDIN_FILENO);
        execlp("grep", "grep", "--color=auto", "bash", NULL);
        perror("execlp error");
    }

    /*
        root        1219  0.0  0.1   9624  3632 ?        Ss   15:14   0:00 bash
        root        1489  0.0  0.2  10072  4324 pts/0    Ss+  15:14   0:00 /bin/bash --init-file /root/.vscode-server/bin/784b0177c56c607789f9638da7b6bf3230d47a8c/out/vs/workbench/contrib/terminal/browser/media/shellIntegration-bash.sh
        root        2679  0.0  0.0   9032   720 ?        S    15:54   0:00 grep --color=auto bash
    */

    return 0;
}