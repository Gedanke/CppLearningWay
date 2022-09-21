# 守护进程和线程

**学习目标**

* 熟练掌握互斥量的使用
* 说出什么叫死锁以及解决方案
* 熟练掌握读写锁的使用
* 熟练掌握条件变量的使用
* 理解条件变量实现的生产消费者模型
* 理解信号量实现的生产消费者模型

---

## 互斥锁

### 互斥锁的使用步骤

* 创建一把互斥锁
    * `pthread_mutex_t mutex;`
* 初始化互斥锁
    * `pthread_mutex_init(&mutex);` --- 相当于 `mutex = 1`
* 在代码中寻找共享资源(也称为临界区)
    * `pthread_mutex_lock(&mutex);` --- `mutex = 0`
    * 临界区代码
    * `pthread_mutex_unlock(&mutex);` --- `mutex = 1`
* 释放互斥锁资源
    * `pthread_mutex_destroy(&mutex);`

注意：必须在所有操作共享资源的线程上都加上锁否则不能起到同步的效果。

### 练习

编写思路：

* 定义一把互斥锁，应该为一全局变量
    * `pthread_mutex_t mutex;`
* 在 `main` 函数中对 `mutex` 进行初始化
    * `pthread_mutex_init(&mutex, NULL);`
* 创建两个线程，在两个线程中加锁和解锁
* 主线程释放互斥锁资源
    * `pthread_mutex_destroy(&mutex);`

```c
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

// 定义一把锁
pthread_mutex_t mutex;

void *mythread1(void *args)
{
    while (1)
    {
        // 加锁
        pthread_mutex_lock(&mutex);

        printf("hello ");
        sleep(1);
        printf("world\n");

        // 解锁
        pthread_mutex_unlock(&mutex);
        sleep(1);
    }
    pthread_exit(NULL);
}

void *mythread2(void *args)
{
    while (1)
    {
        // 加锁
        pthread_mutex_lock(&mutex);

        printf("HELLO ");
        sleep(1);
        printf("WORLD\n");

        // 解锁
        pthread_mutex_unlock(&mutex);
        sleep(1);
    }
    pthread_exit(NULL);
}

int main()
{
    int ret;
    pthread_t thread1;
    pthread_t thread2;

    // 随机数种子
    srand(time(NULL));

    // 互斥锁初始化
    pthread_mutex_init(&mutex, NULL);

    ret = pthread_create(&thread1, NULL, mythread1, NULL);
    if (ret != 0)
    {
        printf("pthread_create error, %s\n", strerror(ret));
        return -1;
    }

    ret = pthread_create(&thread2, NULL, mythread2, NULL);
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

    /*
        HELLO WORLD
        hello world
        HELLO WORLD
        hello world
        HELLO WORLD
        hello world
        HELLO WORLD
        hello world
        HELLO WORLD
    */

    return 0;
}
```

### 死锁

死锁并不是 linux 提供给用户的一种使用方法，而是由于用户使用互斥锁不当引起的一种现象

常见的死锁有两种：

* 第一种：自己锁自己，如下代码片段

```c
void *mythread1(void *args)
{
    while (1)
    {
        // 加锁
        pthread_mutex_lock(&mutex);
        pthread_mutex_lock(&mutex);

        printf("hello ");
        sleep(1);
        printf("world\n");

        // 解锁
        pthread_mutex_unlock(&mutex);
        sleep(1);
    }
    pthread_exit(NULL);
}
```

* 第二种：线程 A 拥有 A 锁，请求获得 B 锁；线程 B 拥有 B 锁，请求获得 A 锁，这样造成线程 A 和线程 B 都不释放自己的锁，而且还想得到对方的锁，从而产生死锁，如下图所示：

![](../photos/part7/1.png)

如何解决死锁：

* 让线程按照一定的顺序去访问共享资源
* 在访问其他锁的时候，需要先将自己的锁解开
* 调用 `pthread_mutex_trylock`，如果加锁不成功会立刻返回

---

## 读写锁

* 什么是读写锁
    * 读写锁也叫共享 - 独占锁
        * 当读写锁以读模式锁住时，它是以共享模式锁住的
        * 当它以写模式锁住时，它是以独占模式锁住的
    * 写独占、读共享
* 读写锁使用场合
    * 读写锁非常适合于对数据结构读的次数远大于写的情况
* 读写锁特性	
    * 读写锁是"写模式加锁"时，解锁前，所有对该锁加锁的线程都会被阻塞
    * 读写锁是"读模式加锁"时，如果线程以读模式对其加锁会成功；如果线程以写模式加锁会阻塞
    * 读写锁是"读模式加锁"时，既有试图以写模式加锁的线程，也有试图以读模式加锁的线程。那么读写锁会阻塞随后的读模式锁请求。解锁后优先满足写模式锁。读锁、写锁并行阻塞，写锁优先级高
* 读写锁场景练习:
    * 线程 A 加写锁成功，线程 B 请求读锁
        * 线程 B 阻塞
    * 线程 A 持有读锁，线程 B 请求写锁
        * 线程 B 阻塞
    * 线程 A 拥有读锁，线程 B 请求读锁
        * 线程 B 加锁成功
    * 线程 A 持有读锁，然后线程 B 请求写锁，然后线程 C 请求读锁
        * B 阻塞，C 阻塞 - 写的优先级高
        * A 解锁，B 线程加写锁成功，C 继续阻塞
        * B 解锁，C 加读锁成功
    * 线程 A 持有写锁，然后线程 B 请求读锁，然后线程 C 请求写锁
        * BC 阻塞
        * A 解锁，C 加写锁成功，B 继续阻塞
        * C 解锁，B 加读锁成功
* 读写锁总结
    * 读并行，写独占，当读写同时等待锁的时候写的优先级高
* 读写锁主要操作函数
    * 定义一把读写锁
        * `pthread_rwlock_t rwlock;`
    * 初始化读写锁
        * `int pthread_rwlock_init(pthread_rwlock_t *restrict rwlock, const pthread_rwlockattr_t *restrict attr);`
        * 函数参数
            * `rwlock` - 读写锁
            * `attr` - 读写锁属性，传 `NULL` 为默认属性
    * 销毁读写锁
        * `int pthread_rwlock_destroy(pthread_rwlock_t *rwlock);`
    * 加读锁
        * `int pthread_rwlock_rdlock(pthread_rwlock_t *rwlock);`
    * 尝试加读锁
        * `int pthread_rwlock_tryrdlock(pthread_rwlock_t *rwlock);`
    * 加写锁
        * `int pthread_rwlock_wrlock(pthread_rwlock_t *rwlock);`
    * 尝试加写锁
        * `int pthread_rwlock_trywrlock(pthread_rwlock_t *rwlock);`
    * 解锁
        * `int pthread_rwlock_unlock(&pthread_rwlock_t *rwlock);`

练习：3 个线程不定时写同一全局资源，5 个线程不定时读同一全局资源

```c
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
```

---

## 条件变量

* 条件本身不是锁！但它也可以造成线程阻塞。通常与互斥锁配合使用。给多线程提供一个会合的场所
    * 使用互斥量保护共享数据
    * 使用条件变量可以使线程阻塞，等待某个条件的发生，当条件满足的时候解除阻塞
* 条件变量的两个动作:
    * 条件不满足，阻塞线程
    * 条件满足，通知阻塞的线程解除阻塞，开始工作
* 条件变量相关函数
    * `pthread_cond_t cond;`
        * 定义一个条件变量
    * `int pthread_cond_init(pthread_cond_t *restrict cond, const pthread_condattr_t *restrict attr);`
        * 函数描述：初始化条件变量
        * 函数参数: 
		    * `cond`: 条件变量
		    * `attr`: 条件变量属性，通常传 `NULL`
        * 函数返回值:
            * 成功返回 0
            * 失败返回错误号
    * `int pthread_cond_destroy(pthread_cond_t *cond);`
        * 函数描述: 销毁条件变量
        * 函数参数: 条件变量
        * 返回值: 
            * 成功返回 0
            * 失败返回错误号
    * `int pthread_cond_wait(pthread_cond_t *restrict cond, pthread_mutex_t *restrict mutex);`
        * 函数描述: 
            * 条件不满足，引起线程阻塞并解锁
            * 条件满足，解除线程阻塞，并加锁
        * 函数参数:
            * `cond`: 条件变量
            * `mutex`: 互斥锁变量
        * 函数返回值: 
            * 成功返回 0
            * 失败返回错误号
    * `int pthread_cond_signal(pthread_cond_t *cond);`
        * 函数描述: 唤醒至少一个阻塞在该条件变量上的线程
        * 函数参数: 条件变量
        * 函数返回值: 
            * 成功返回 0
            * 失败返回错误号
* 使用条件变量的代码片段

```c
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
```

上述代码中，生产者线程调用 `pthread_cond_signal` 函数会使消费者线程在 `pthread_cond_wait` 处解除阻塞

多个线程版本:

```c
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
    int n = *(int *)arg;
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
        printf("P [%d]: %d\n", n, pNode->data);

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
    int n = *(int *)arg;
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
        if (head == NULL)
        {
            // 解锁
            pthread_mutex_unlock(&mutex);
            continue;
        }

        printf("C [%d]: %d\n", n, head->data);
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
    int i = 0;
    pthread_t thread1[5];
    pthread_t thread2[5];

    // 初始化互斥锁
    pthread_mutex_init(&mutex, NULL);
    // 初始化条件变量
    pthread_cond_init(&cond, NULL);

    int arr[5];
    for (int i = 0; i < 5; i++)
    {
        arr[i] = i;
        // 创建生产者线程
        ret = pthread_create(&thread1[i], NULL, producer, &arr[i]);
        if (ret != 0)
        {
            printf("pthread_create error, %s\n", strerror(ret));
            return -1;
        }

        // 创建消费者线程
        ret = pthread_create(&thread2[i], NULL, consumer, &arr[i]);
        if (ret != 0)
        {
            printf("pthread_create error, %s\n", strerror(ret));
            return -1;
        }
    }

    // 等待线程结束
    for (i = 0; i < 5; i++)
    {
        pthread_join(thread1[i], NULL);
        pthread_join(thread2[i], NULL);
    }

    // 释放互斥锁
    pthread_mutex_destroy(&mutex);

    // 释放条件锁
    pthread_cond_destroy(&cond);

    /*
        P [3]: 383
        C [3]: 383
        P [4]: 915
        C [2]: 915
        P [2]: 386
        C [3]: 386
        P [2]: 421
        C [4]: 421
        P [1]: 690
        C [3]: 690
        P [0]: 926
        C [1]: 926
        P [0]: 172
        C [0]: 172
        P [3]: 368
        C [1]: 368
        P [3]: 782
        C [1]: 782
        P [1]: 123
        C [2]: 123
        P [4]: 929
        C [4]: 929
        P [4]: 58
    */

    return 0;
}
```

---

## 信号量

### 信号量介绍

信号量相当于多把锁，可以理解为是加强版的互斥锁

### 相关函数

* 定义信号量 `sem_t sem;`
* `int sem_init(sem_t *sem, int pshared, unsigned int value);`
    * 函数描述: 初始化信号量
    * 函数参数:
        * `sem`: 信号量变量
        * `pshared`: 
            * 0 表示线程同步
            * 1 表示进程同步
        * `value`: 最多有几个线程操作共享数据
    * 函数返回值: 
        * 成功返回 0
        * 失败返回 -1，并设置 `errno` 值
* `int sem_wait(sem_t *sem);`
    * 函数描述: 调用该函数一次，相当于 `sem--`，当 `sem` 为 0 的时候，引起阻塞
    * 函数参数: 信号量变量
    * 函数返回值: 
        * 成功返回 0
        * 失败返回 -1，并设置 `errno` 值
* `int sem_post(sem_t *sem);`
    * 函数描述: 调用一次，相当于 `sem++`
    * 函数参数: 信号量变量
    * 函数返回值: 
        * 成功返回 0
        * 失败返回 -1，并设置 `errno` 值
* `int sem_trywait(sem_t *sem);`
    * 函数描述: 尝试加锁，若失败直接返回，不阻塞
    * 函数参数: 信号量变量
    * 函数返回值: 
        * 成功返回 0
        * 失败返回 -1，并设置 `errno` 值
* `int sem_destroy(sem_t *sem);`
    * 函数描述: 销毁信号量
    * 函数参数: 信号量变量
    * 函数返回值: 
        * 成功返回 0
        * 失败返回 -1，并设置 `errno` 值

信号量代码片段:

```c
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
```

---
