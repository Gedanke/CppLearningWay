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
    sleep(6);
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

    // 设置线程为分离属性
    pthread_detach(thread);

    // 子线程设置分离属性，则 pthread_join 不再阻塞，立刻返回
    ret = pthread_join(thread, NULL);
    if (ret != 0)
    {
        printf("pthread_join error: %s\n", strerror(ret));
    }

    // 目的是为了让子线程执行起来
    sleep(1);

    printf("main thread\n");

    /*
        main thread, pid: 14938, id: 140502206936896
        pthread_join error: Invalid argument
        child thread, pid: 14938, id: 140502206932736
        main thread
    */

    return 0;
}