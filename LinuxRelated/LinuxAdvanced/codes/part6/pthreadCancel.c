#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <pthread.h>

// 线程执行函数
void *mythread(void *arg)
{
    printf("child thread, pid: %d, id: %ld\n", getpid(), pthread_self());
    while (1)
    {
        int a;
        int b;

        printf("cancel\n");

        // 设置取消点
        // pthread_testcancel();

        printf("------\n");
    }
    printf("child thread\n");
}

int main()
{
    // 创建子线程
    pthread_t thread;
    int ret = pthread_create(&thread, NULL, mythread, NULL);
    if (ret != 0)
    {
        printf("pthread_create error, %s\n", strerror(ret));
        return -1;
    }
    printf("main thread, pid: %d, id: %ld\n", getpid(), pthread_self());

    // 取消子线程
    pthread_cancel(thread);

    pthread_join(thread, NULL);

    // 目的是为了让子线程执行起来
    sleep(1);

    printf("main thread\n");

    /*
        main thread, pid: 16050, id: 140621898647360
        child thread, pid: 16050, id: 140621898643200
        main thread
    */

    return 0;
}