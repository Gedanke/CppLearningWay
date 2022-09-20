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
    sleep(2);
    printf("child thread\n");
}

int main()
{
    // 定义 pthread_attr_t 类型变量
    pthread_attr_t attr;

    // 初始化 attr 变量
    pthread_attr_init(&attr);

    // 设置 attr 为分离属性
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);

    // 创建子线程
    pthread_t thread;
    int ret = pthread_create(&thread, NULL, mythread, NULL);
    if (ret != 0)
    {
        printf("pthread_create error, %s\n", strerror(ret));
        return -1;
    }
    printf("main thread, pid: %d, id: %ld\n", getpid(), pthread_self());

    // 释放线程属性
    pthread_attr_destroy(&attr);

    // 验证子线程是否为分离属性
    ret = pthread_join(thread, NULL);
    if (ret != 0)
    {
        printf("pthread_join error, %s\n", strerror(ret));
    }

    // 目的是为了让子线程执行起来
    sleep(1);

    printf("main thread\n");

    /*
        main thread, pid: 22295, id: 139638672656192
        child thread, pid: 22295, id: 139638672652032
        child thread
        main thread
    */

    return 0;
}