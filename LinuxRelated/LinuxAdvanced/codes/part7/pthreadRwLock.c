#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/time.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <signal.h>
#include <time.h>
#include <pthread.h>

int number = 0;

// 定义一把读写锁
pthread_rwlock_t rwlock;

// 写线程回调函数
void *thread_write(void *arg)
{
    int i = *(int *)arg;
    int cur;

    while (1)
    {
        // 尝试加写锁
        int ret = pthread_rwlock_trywrlock(&rwlock);
        if (ret == 0)
        {
            // 加写锁
            // pthread_rwlock_wrlock(&rwlock);

            // 加写锁成功

            cur = number;
            cur++;
            number = cur;
            printf("%d-W: %d\n", i, cur);

            // 解锁
            pthread_rwlock_unlock(&rwlock);
        }
        else
        {
        }
        sleep(1);
    }
}

// 写线程回调函数
void *thread_read(void *arg)
{
    int i = *(int *)arg;
    int cur;

    while (1)
    {
        // 尝试加读锁
        int ret = pthread_rwlock_tryrdlock(&rwlock);
        if (ret == 0)
        {
            // 加读锁
            // pthread_rwlock_rdlock(&rwlock);

            // 加读锁成功

            cur = number;
            printf("%d-R: %d\n", i, cur);

            // 解锁
            pthread_rwlock_unlock(&rwlock);
        }
        else
        {
        }

        sleep(1);
    }
}

int main()
{
    int n = 8;
    int i = 0;
    int arr[n];
    pthread_t thread[n];
    int idx = 3;

    // 读写锁初始化
    pthread_rwlock_init(&rwlock, NULL);

    // 创建三个写子线程
    for (int i = 0; i < idx; i++)
    {
        arr[i] = i;
        pthread_create(&thread[i], NULL, thread_write, &arr[i]);
    }

    // 创建五个读子线程
    for (int i = idx; i < n; i++)
    {
        arr[i] = i;
        pthread_create(&thread[i], NULL, thread_read, &arr[i]);
    }

    // 回收子线程
    for (int j = 0; j < n; j++)
    {
        pthread_join(thread[j], NULL);
    }

    // 释放锁
    pthread_rwlock_destroy(&rwlock);

    /*
        6-R: 0
        7-R: 0
        5-R: 0
        4-R: 0
        3-R: 0
        2-W: 1
        1-W: 2
        0-W: 3
        6-R: 3
        7-R: 3
        5-R: 3
        4-R: 3
        3-R: 3
        2-W: 4
        1-W: 5
        0-W: 6
        6-R: 6
        7-R: 6
        5-R: 6
        4-R: 6
        3-R: 6
        2-W: 7
        1-W: 8
        0-W: 9
        6-R: 9
        7-R: 9
        5-R: 9
        4-R: 9
        3-R: 9
        2-W: 10
        1-W: 11
        0-W: 12
    */

    return 0;
}