#include <pthread.h>
#include <stdio.h>
#include <string.h>

int num = 0;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void *thread_proc(void *arg)
{
    for (int i = 0; i < 1000000; ++i)
    {
        pthread_mutex_lock(&mutex);
        num++;
        pthread_mutex_unlock(&mutex);
    }
    return NULL;
}

int main(void)
{
    int tcount = 3;
    pthread_t tids[tcount];
    for (long long i = 1; i <= tcount; ++i)
    {
        int errno = pthread_create(&tids[i - 1], NULL, thread_proc, (void *)i);
        if (errno)
        {
            fprintf(stderr, "pthread_create:%s\n", strerror(errno));
            return -1;
        }
    }
    for (int i = 0; i < tcount; ++i)
    {
        pthread_t tid = tids[i];
        pthread_join(tid, NULL);
        printf("thread %lld 结束\n", (long long)tid);
    }
    printf("所有线程执行完毕，num: %d\n", num);

    /*
        thread 140326834177792 结束
        thread 140326825785088 结束
        thread 140326817392384 结束
        所有线程执行完毕，num: 3000000
    */

    return 0;
}