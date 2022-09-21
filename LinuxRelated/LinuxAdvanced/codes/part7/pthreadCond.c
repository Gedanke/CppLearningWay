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

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

Node *head = NULL;

// 定义一把锁
pthread_mutex_t mutex;

// 定义条件变量
pthread_cond_t cond;

// 生产者线程
void *producer(void *arg)
{
    Node *pNode = NULL;
    while (1)
    {
        // 生产一个节点
        pNode = (Node *)malloc(sizeof(Node));
        if (pNode == NULL)
        {
            perror("malloc error");
            exit(-1);
        }
        pNode->data = rand() % 1000;
        printf("P: %d\n", pNode->data);

        // 加锁
        pthread_mutex_lock(&mutex);

        pNode->next = head;
        head = pNode;

        // 解锁
        pthread_mutex_unlock(&mutex);

        // 通知消费者线程解锁阻塞
        pthread_cond_signal(&cond);

        sleep(rand() % 3);
    }
}

// 消费者线程
void *consumer(void *arg)
{
    Node *pNode = NULL;
    while (1)
    {
        // 加锁
        pthread_mutex_lock(&mutex);

        if (head == NULL)
        {
            // 若条件不满足，需要阻塞等待
            // 若条件不满足，则阻塞等待并解锁
            // 若条件满足(被生成者线程调用 pthread_cond_signal 函数通知)，解除阻塞并加锁
            pthread_cond_wait(&cond, &mutex);
        }
        printf("C: %d\n", head->data);
        pNode = head;
        head = head->next;

        // 解锁
        pthread_mutex_unlock(&mutex);

        free(pNode);
        pNode = NULL;

        sleep(rand() % 3);
    }
}

int main()
{
    int ret;
    pthread_t thread1;
    pthread_t thread2;

    // 初始化互斥锁
    pthread_mutex_init(&mutex, NULL);
    // 初始化条件变量
    pthread_cond_init(&cond, NULL);

    // 创建生产者线程
    ret = pthread_create(&thread1, NULL, producer, NULL);
    if (ret != 0)
    {
        printf("pthread_create error, %s\n", strerror(ret));
        return -1;
    }

    // 创建消费者线程
    ret = pthread_create(&thread2, NULL, consumer, NULL);
    if (ret != 0)
    {
        printf("pthread_create error, %s\n", strerror(ret));
        return -1;
    }

    // 等待线程结束
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    // 释放互斥锁
    pthread_mutex_destroy(&mutex);

    // 释放条件锁
    pthread_cond_destroy(&cond);

    /*
        P: 383
        C: 383
        P: 915
        C: 915
        P: 386
        C: 386
        P: 421
        C: 421
        P: 690
        C: 690
    */

    return 0;
}