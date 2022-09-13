#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>

int g_var = 99;

void testFork1()
{
    printf("Before fork, pid: %d\n", getpid());
    // 创建子进程
    pid_t pid = fork();

    if (pid < 0)
    {
        // 创建失败
        perror("fork error");
        exit(1);
    }
    else if (pid == 0)
    {
        // 子进程
        printf("Child: %d, pid: %d, fpid: %d\n", pid, getpid(), getppid());
    }
    else
    {
        // 父进程
        printf("Parent: %d, pid: %d, fpid: %d\n", pid, getpid(), getppid());
    }
    printf("After fork, pid: %d\n", getpid());
}

void testFork2()
{
    // 创建子进程
    pid_t pid = fork();

    if (pid < 0)
    {
        // 创建失败
        perror("fork error");
        exit(1);
    }
    else if (pid == 0)
    {
        // 子进程
        sleep(1);
        printf("Child &g_var: %p\n", &g_var);
        printf("Child: %d, pid: %d, fpid: %d\n", pid, getpid(), getppid());
        printf("Child g_var: %d\n", g_var);
    }
    else
    {
        // 父进程
        printf("Parent: %d, pid: %d, fpid: %d\n", pid, getpid(), getppid());
        g_var++;
        printf("Parent &g_var: %p\n", &g_var);
    }
}

void testFork3()
{
    int i = 0;
    for (i = 0; i < 3; i++)
    {
        // 创建子进程
        pid_t pid = fork();
        if (pid < 0)
        {
            perror("fork error");
            exit(1);
        }
        else if (pid > 0)
        {
            printf("Parent: pid: %d, fpid: %d\n", getpid(), getppid());
        }
        else
        {
            printf("Child: pid: %d, fpid: %d\n", getpid(), getppid());
            break;
        }
    }

    if (i == 0)
    {
        printf("%d -- %d: child\n", i, getpid());
    }
    if (i == 1)
    {
        printf("%d -- %d: child\n", i, getpid());
    }
    if (i == 2)
    {
        printf("%d -- %d: child\n", i, getpid());
    }
    if (i == 3)
    {
        printf("%d -- %d: child\n", i, getpid());
    }
    sleep(10);
}

int main()
{
    // testFork1();

    /*
        Before fork, pid: 45099
        Parent: 45100, pid: 45099, fpid: 45093
        After fork, pid: 45099
        Before fork, pid: 45099
        Child: 0, pid: 45100, fpid: 1
        After fork, pid: 45100
    */

    // testFork2();

    /*
        Parent: 45076, pid: 45075, fpid: 45069
        Parent &g_var: 0x560850d54010
        Child &g_var: 0x560850d54010
        Child: 0, pid: 45076, fpid: 1
        Child g_var: 99
    */

    testFork3();

    /*
        Parent: pid: 45230, fpid: 45224
        Parent: pid: 45230, fpid: 45224
        Parent: pid: 45230, fpid: 45224
        3 -- 45230: child
        Parent: pid: 45230, fpid: 45224
        Parent: pid: 45230, fpid: 45224
        Child: pid: 45233, fpid: 45230
        2 -- 45233: child
        Parent: pid: 45230, fpid: 45224
        Child: pid: 45232, fpid: 45230
        1 -- 45232: child
        Child: pid: 45231, fpid: 45230
        0 -- 45231: child
    */

    return 0;
}