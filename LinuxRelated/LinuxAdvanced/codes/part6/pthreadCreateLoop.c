#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <pthread.h>

// 线程执行函数
void *mythread(void *arg)
{
    int i = *(int *)arg;
    printf("%d child thread, pid: %d, id: %ld\n", i, getpid(), pthread_self());
    sleep(4);
}

int main()
{
    int ret;
    int i = 0;
    int n = 5;
    int arr[5];
    pthread_t thread[5];
    for (i = 0; i < n; i++)
    {
        arr[i] = i;
        ret = pthread_create(&thread[i], NULL, mythread, &arr[i]);
        if (ret != 0)
        {
            printf("pthread_create error, %s\n", strerror(ret));
            return -1;
        }
    }
    printf("main thread, pid: %d, id: %ld\n", getpid(), pthread_self());

    // 目的是为了让子线程执行起来
    sleep(10);

    /*
        main thread, pid: 8844, id: 139636137559872
        4 child thread, pid: 8844, id: 139636103984896
        3 child thread, pid: 8844, id: 139636112377600
        2 child thread, pid: 8844, id: 139636120770304
        1 child thread, pid: 8844, id: 139636129163008
        0 child thread, pid: 8844, id: 139636137555712
    */

    return 0;
}