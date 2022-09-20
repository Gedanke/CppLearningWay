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

    // 标记线程 ID
    if (pthread_equal(thread, pthread_self()) != 0)
    {
        printf("same\n");
    }
    else
    {
        printf("different\n");
    }

    // 目的是为了让子线程执行起来
    sleep(1);

    /*
        main thread, pid: 19922, id: 139778666370880
        different
        child thread, pid: 19922, id: 139778666366720
    */

    return 0;
}