#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <pthread.h>

typedef struct _Test
{
    int data;
    char name[64];
} Test;

// 线程执行函数
void *mythread(void *arg)
{
    // int n = *(int *)arg;
    // printf("n: %d\n", n);
    Test *p = (Test *)arg;
    printf("%d\t%s\n", p->data, p->name);
    printf("child thread, pid: %d, id: %ld\n", getpid(), pthread_self());
}

int main()
{
    int n = 99;
    Test t;
    memset(&t, 0, sizeof(Test));
    t.data = 88;
    strcpy(t.name, "pthread");

    // 创建子线程
    pthread_t thread;
    // int ret = pthread_create(&thread, NULL, mythread, &n);
    int ret = pthread_create(&thread, NULL, mythread, &t);
    if (ret != 0)
    {
        printf("pthread_create error, %s\n", strerror(ret));
        return -1;
    }
    printf("main thread, pid: %d, id: %ld\n", getpid(), pthread_self());

    // 目的是为了让子线程执行起来
    sleep(1);

    /*
        main thread, pid: 4912, id: 140369853019968
        n: 99
        child thread, pid: 4912, id: 140369853015808
    */

    /*
        main thread, pid: 4878, id: 140414698202944
        88      pthread
        child thread, pid: 4878, id: 140414698198784
    */

    return 0;
}