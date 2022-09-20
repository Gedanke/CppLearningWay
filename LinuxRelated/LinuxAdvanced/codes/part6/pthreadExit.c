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

int gVar = 9;
Test t;

// 线程执行函数
void *mythread(void *arg)
{
    printf("child thread, pid: %d, id: %ld\n", getpid(), pthread_self());
    printf("%p\n", &gVar);
    pthread_exit(&gVar);
    memset(&t, 0, sizeof(t));
    t.data = 99;
    strcpy(t.name, "pthread");
    pthread_exit(&t);
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

    // pthread_exit(NULL);

    // 回收子线程
    void *p = NULL;
    pthread_join(thread, &p);
    // int n = *(int *)p;
    Test *pt = (Test *)p;
    printf("child exit status: %d, %s, %p\n", pt->data, pt->name, p);

    // 目的是为了让子线程执行起来
    sleep(1);

    /*
        main thread, pid: 17934, id: 139877776721728
        child thread, pid: 17934, id: 139877776717568
        child exit status: 99, pthread, 0x55bd9d761040
    */

    /*
        main thread, pid: 18509, id: 140055385065280
        child thread, pid: 18509, id: 140055385061120
        0x55e0c1fab010
        child exit status: 9, , 0x55e0c1fab010
    */

    return 0;
}