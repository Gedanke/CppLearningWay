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

    // 阻塞等待子线程
    void *ptr = NULL;
    int res = pthread_join(thread, &ptr);
    if (res != 0)
    {
        printf("pthread_join error\n");
    }

    printf("%p\n", ptr);

    // 目的是为了让子线程执行起来
    sleep(1);

    printf("main thread\n");

    /*
        main thread, pid: 13593, id: 140240246724416
        child thread, pid: 13593, id: 140240246720256
        child thread
        0xd
        main thread
    */

    return 0;
}