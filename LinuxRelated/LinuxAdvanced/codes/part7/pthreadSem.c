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
#include <semaphore.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

Node *head = NULL;

// 定义信号量
sem_t semProducer;
sem_t semConsumer;

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
        sem_wait(&semProducer);

        pNode->next = head;
        head = pNode;

        // 解锁
        sem_post(&semConsumer);

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
        sem_wait(&semConsumer);

        printf("C: %d\n", head->data);
        pNode = head;
        head = head->next;

        // 解锁
        sem_post(&semProducer);

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

    // 初始化信号量
    sem_init(&semProducer, 0, 5);
    sem_init(&semConsumer, 0, 0);

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

    // 释放信号量
    sem_destroy(&semProducer);
    sem_destroy(&semConsumer);

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