# 结构体

---

## 结构体基础知识

### 结构体类型的定义

```c
struct Person
{
    char name[64];
    int age;
};

typedef struct _PERSON
{
    char name[64];
    int age;
} Person;
```

定义结构体类型时不要直接给成员赋值，结构体只是一个类型，编译器还没有为其分配空间，只有根据其类型定义变量时，才分配空间，有空间后才能赋值

### 结构体变量的定义

```c
struct Person
{
    char name[64];
    int age;
} p1; // 定义类型同时定义变量

struct
{
    char name[64];
    int age;
} p2; // 定义类型同时定义变量

struct Person p3; // 通过类型直接定义
```

### 结构体变量的初始化

```c
struct Person
{
    char name[64];
    int age;
} p1 = {"john", 10}; // 定义类型同时初始化变量

struct
{
    char name[64];
    int age;
} p2 = {"Obama", 30}; // 定义类型同时初始化变量

struct Person p3 = {"Edward", 33}; // 通过类型直接定义
```

### 结构体成员的使用

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Person
{
    char name[64];
    int age;
};

void test()
{
    // 在栈上分配空间
    struct Person p1;
    strcpy(p1.name, "John");
    p1.age = 30;
    // 如果是普通变量，通过 . 运算符操作结构体成员
    printf("Name: %s\tAge: %d\n", p1.name, p1.age);

    // 在堆上分配空间
    struct Person *p2 = (struct Person *)malloc(sizeof(struct Person));
    strcpy(p2->name, "Obama");
    p2->age = 33;
    // 如果是指针变量，通过 -> 操作结构体成员
    printf("Name: %s\tAge: %d\n", p2->name, p2->age);
}

int main()
{
    test();

    /*
        Name: John      Age: 30
        Name: Obama     Age: 33
    */

    return 0;
}
```

### 结构体赋值

* 赋值基本概念

相同的两个结构体变量可以相互赋值，把一个结构体变量的值拷贝给另一个结构体，这两个变量还是两个独立的变量

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Person
{
    char name[64];
    int age;
};

void test()
{
    // 在栈上分配空间
    struct Person p1 = {"John", 30};
    struct Person p2 = {"Obama", 33};
    printf("Name: %s\tAge: %d\n", p1.name, p1.age);
    printf("Name: %s\tAge: %d\n", p2.name, p2.age);
    // 将 p2 的值赋值给 p1
    p1 = p2;
    printf("Name: %s\tAge: %d\n", p1.name, p1.age);
    printf("Name: %s\tAge: %d\n", p2.name, p2.age);
}

int main()
{
    test();

    /*
        Name: John      Age: 30
        Name: Obama     Age: 33
        Name: Obama     Age: 33
        Name: Obama     Age: 33
    */

    return 0;
}
```

* 深拷贝和浅拷贝

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 一个老师有 N 个学生
typedef struct _TEACHER
{
    char *name;
} Teacher;

void test()
{
    Teacher t1;
    t1.name = malloc(64);
    strcpy(t1.name, "John");

    Teacher t2;
    t2 = t1;

    // 对手动开辟的内存，需要手动拷贝
    t2.name = malloc(64);
    strcpy(t2.name, t1.name);

    if (t1.name != NULL)
    {
        free(t1.name);
        t1.name = NULL;
    }
    if (t2.name != NULL)
    {
        free(t2.name);
        t1.name = NULL;
    }
}

int main()
{
    test();

    /*
     */

    return 0;
}
```

### 结构体数组

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _Person
{
    char name[64];
    int age;
} Person;

void test()
{
    // 在栈上分配空间
    Person p1[3] = {
        {"John", 30},
        {"Obama", 33},
        {"Edward", 25}};

    Person p2[3] = {"John", 30, "Obama", 33, "Edward", 25};
    for (int i = 0; i < 3; i++)
    {
        printf("Name: %s \tAge: %d\n", p1[i].name, p1[i].age);
    }
    printf("-----------------\n");
    for (int i = 0; i < 3; i++)
    {
        printf("Name: %s\tAge: %d\n", p2[i].name, p2[i].age);
    }
    printf("-----------------\n");
    // 在堆上分配结构体数组
    Person *p3 = (Person *)malloc(sizeof(Person) * 3);
    for (int i = 0; i < 3; i++)
    {
        sprintf(p3[i].name, "Name_%d", i + 1);
        p3[i].age = 20 + i;
    }
    for (int i = 0; i < 3; i++)
    {
        printf("Name: %s\tAge: %d\n", p3[i].name, p3[i].age);
    }
}

int main()
{
    test();

    /*
        Name: John      Age: 30
        Name: Obama     Age: 33
        Name: Edward    Age: 25
        -----------------
        Name: John      Age: 30
        Name: Obama     Age: 33
        Name: Edward    Age: 25
        -----------------
        Name: Name_1    Age: 20
        Name: Name_2    Age: 21
        Name: Name_3    Age: 22
     */

    return 0;
}
```

---

## 结构体嵌套指针

### 结构体嵌套一级指针

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Person
{
    char *name;
    int age;
    int *sex;
} Person;

void allocateMen(Person **person)
{
    if (person == NULL)
    {
        return;
    }
    Person *p = (Person *)malloc(sizeof(Person) * 1);
    if (p == NULL)
    {
        return;
    }

    p->name = (char *)malloc(sizeof(char) * 64);
    p->age = 23;
    p->sex = (int *)malloc(sizeof(int) * 1);
    strcpy(p->name, "Cook");
    *(p->sex) = 1;

    *person = p;
}

void printPerson(const Person *p)
{
    printf("Name: %s; Age: %d; Sex: %d\n", p->name, p->age, *(p->sex));
}

void freeMem(Person **person)
{
    if (person == NULL)
    {
        return;
    }
    Person *p = *person;
    if (p->name != NULL)
    {
        free(p->name);
        p->name = NULL;
    }
    if (p->sex != NULL)
    {
        free(p->sex);
        p->sex = NULL;
    }

    free(p);
}

void test1()
{
    Person *p = NULL;
    allocateMen(&p);
    printPerson(p);
    freeMem(&p);
}

void initPerson(Person *p)
{
    if (p == NULL)
    {
        return;
    }

    p->name = (char *)malloc(sizeof(char) * 64);
    p->age = 24;
    p->sex = (int *)malloc(sizeof(int) * 1);

    strcpy(p->name, "Frank");
    *(p->sex) = 0;
}

void showPerson(const Person p)
{
    printf("Name: %s; Age: %d; Sex: %d\n", p.name, p.age, *(p.sex));
}

void freePerson(Person *p)
{
    if (p == NULL)
    {
        return;
    }
    if (p->name != NULL)
    {
        free(p->name);
        p->name = NULL;
    }
    if (p->sex != NULL)
    {
        free(p->sex);
        p->sex = NULL;
    }
    p->age = 0;
}

void test2()
{
    Person p;
    initPerson(&p);
    showPerson(p);
    freePerson(&p);
}

int main()
{
    test1();
    test2();

    /*
        Name: Cook; Age: 23; Sex: 1
        Name: Frank; Age: 24; Sex: 0
    */

    return 0;
}
```

### 结构体嵌套二级指针

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 一个老师有多个学生
typedef struct Teacher
{
    char *name;
    char **students;
} Teacher;

void createTeacher(Teacher **teacher, int n, int m)
{
    if (teacher == NULL)
    {
        return;
    }

    Teacher *teachers = (Teacher *)malloc(sizeof(Teacher) * n);
    if (teachers == NULL)
    {
        return;
    }

    // 给 n 个老师分配 m 个学生
    int num = 0;
    for (int i = 0; i < n; i++)
    {
        // 分配 name
        teachers[i].name = (char *)malloc(sizeof(char) * 32);
        sprintf(teachers[i].name, "Teacher_%d", i + 1);
        // 第一次分配 students
        teachers[i].students = (char **)malloc(sizeof(char *) * 32);
        for (int j = 0; j < m; j++)
        {
            // 第二次分配 students[j]
            teachers[i].students[j] = (char *)malloc(sizeof(char *) * 32);
            sprintf(teachers[i].students[j], "Student_%d", num + 1);
            num++;
        }
    }

    *teacher = teachers;
}

void printTeacher(const Teacher *teacher, int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        printf("%s: \n", teacher[i].name);
        for (int j = 0; j < m; j++)
        {
            printf("%s\t", teacher[i].students[j]);
        }
        printf("\n");
    }
}

void freeTeacher(Teacher **teacher, int n, int m)
{
    if (teacher == NULL)
    {
        return;
    }

    Teacher *tmp = *teacher;

    for (int i = 0; i < n; i++)
    {
        // 释放 name
        if (tmp[i].name != NULL)
        {
            free(tmp[i].name);
            tmp[i].name = NULL;
        }
        for (int j = 0; j < m; j++)
        {
            // 释放 students[j]
            if (tmp[i].students[j] != NULL)
            {
                free(tmp[i].students[j]);
                tmp[i].students[j] = NULL;
            }
        }
        // 释放 students
        if (tmp[i].students != NULL)
        {
            free(tmp[i].students);
            tmp[i].students = NULL;
        }
    }

    // 释放 tmp
    free(tmp);
}

void test()
{
    Teacher *p = NULL;
    createTeacher(&p, 3, 3);
    printTeacher(p, 3, 3);
    freeTeacher(&p, 3, 3);
}

int main()
{
    test();

    /*
        Teacher_1:
        Student_1       Student_2       Student_3
        Teacher_2:
        Student_4       Student_5       Student_6
        Teacher_3:
        Student_7       Student_8       Student_9
    */

    return 0;
}
```

---

## 结构体成员偏移量

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>

typedef struct Teacher
{
    char a;
    int b;
} Teacher;

void test()
{
    Teacher t;
    Teacher *p = &t;

    int offset1 = (int)&(p->b) - (int)p;
    int offset2 = offsetof(Teacher, b);

    printf("offset1: %d\n", offset1);
    printf("offset2: %d\n", offset2);
}

int main()
{
    test();

    /*
        main.c: In function ‘test’:
        main.c:16:19: warning: cast from pointer to integer of different size [-Wpointer-to-int-cast]
        16 |     int offset1 = (int)&(p->b)-(int)p;
            |                   ^
        main.c:16:32: warning: cast from pointer to integer of different size [-Wpointer-to-int-cast]
        16 |     int offset1 = (int)&(p->b)-(int)p;
            |                                ^
        offset1: 4
        offset2: 4
    */

    return 0;
}
```

---

## 结构体字节对齐

在用 `sizeof` 运算符求算某结构体所占空间时，并不是简单地将结构体中所有元素各自占的空间相加，这里涉及到内存字节对齐的问题

从理论上讲，对于任何变量的访问都可以从任何地址开始访问，但是事实上不是如此，实际上访问特定类型的变量只能在特定的地址访问，这就需要各个变量在空间上按一定的规则排列，而不是简单地顺序排列，这就是内存对齐

### 内存对齐

#### 内存对齐原因

内存的最小单元是一个字节，当 cpu 从内存中读取数据的时候，是一个一个字节读取，如下图所示

![](../photos/part5/1.png)

但是实际上 cpu 将内存当成多个块，每次从内存中读取一个块，这个块的大小可能是 2、4、8、16 等

非内存对齐和内存对齐的优缺点在哪

内存对齐是操作系统为了提高访问内存的策略。操作系统在访问内存的时候，每次读取一定长度(这个长度是操作系统默认的对齐数，或者默认对齐数的整数倍)。如果没有对齐，为了访问一个变量可能产生二次访问

内存对齐的好处

* 提高存取数据的速度。比如有的平台每次都是从偶地址处读取数据，对于一个 `int` 型的变量，若从偶地址单元处存放，则只需一个读取周期即可读取该变量；但是若从奇地址单元处存放，则需要 2 个读取周期读取该变量
* 某些平台只能在特定的地址处访问特定类型的数据，否则抛出硬件异常给操作系统

#### 如何内存对齐

* 对于标准数据类型，它的地址只要是它的长度的整数倍
* 对于非标准数据类型，比如结构体，要遵循一下对齐原则
    * 数组成员对齐规则。第一个数组成员应该放在 `offset` 为 0 的地方，以后每个数组成员应该放在 `offset` 为 `min`(当前成员的大小，`#pargama pack(n)`)整数倍的地方开始(比如 `int` 在 32 位机器为 4 字节，`#pargama pack(2)`，那么从 2 倍数地方开始存储)
    * 结构体总的大小，也就是 `sizeof` 的结果，必须是 `min`(结构体内部最大成员，`#pargama pack(n)`)的整数倍，不足要补齐
    * 结构体做为成员的对齐规则。如果一个结构体 `B` 里嵌套另一个结构体 `A`，还是以最大成员类型的大小对齐，但是结构体 `A` 的起点为 `A` 内部最大成员的整数倍的地方( `struct B` 里存有 `struct A`，`A` 里有 `char，int，double` 等成员，那 `A` 应该从 8 的整数倍开始存储)，结构体 `A` 中的成员的对齐规则仍满足原则1、原则2

手动设置对齐模数:

* `#pragma pack(show)` 显示当前 `packing alignment` 的字节数，以 `warning message` 的形式被显示
* `#pragma pack(push)` 将当前指定的 `packing alignment` 数组进行压栈操作，这里的栈是 `the internal compiler stack`，同时设置当前的 `packing alignment` 为 `n`；如果 `n` 没有指定，则将当前的 `packing alignment` 数组压栈
* `#pragma pack(pop)` 从 `internal compiler stack` 中删除最顶端的 `reaord` ; 如果没有指定 `n`，则当前栈顶 `record` 即为新的 `packing alignement` 数值；如果指定了 `n`，则 `n` 成为新的 `packing alignment` 值
* `#pragma pack(n)` 指定 `packing` 的数值，以字节为单位，缺省数值是 8，合法的数值分别是 1，2，4，8，16

### 内存对齐案例

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
// #pragma pack(4)

typedef struct Student
{
    int a;
    char b;
    double c;
    float d;
} Student;

typedef struct Student2
{
    char a;
    Student b;
    double c;
} Student2;

void test()
{
    // Student
    // a 从偏移量 0 位置开始存储
    // b 从 4 位置开始存储
    // c 从 8 位置开始存储
    // d 从 16 位置开存储
    // 整体为最大类型的整数倍，也就是 8 的整数倍，为 24
    Student stu;
    printf("sizeof Student: %lu\n", sizeof(stu));
    printf("stu: %p\tstu.a: %p\tstu.b: %p\tstu.c: %p\tstu.d: %p\n", &stu, &stu.a, &stu.b, &stu.c, &stu.d);

    // Student2
    // a 从偏移量为 0 位置开始
    // b 从偏移量为 Student 内部最大成员整数倍开始，也就是 8 开始
    // c 从 8 的整数倍地方开始，也就是 32 开始
    // 由于结构体中最大成员为 8，必须为 8 的整数倍，大小为 40
    Student2 stu2;
    printf("sizeof Student2: %lu\n", sizeof(stu2));
    printf("stu2: %p\tstu2.a: %p\tstu2.b: %p\tstu2.b.a: %p\tstu2.b.b: %p\tstu2.b.c: %p\tstu2.b.d: %p\tstu2.c :%p\n", &stu2, &stu2.a, &stu2.b, &stu2.b.a, &stu2.b.b, &stu2.b.c, &stu2.b.d, &stu2.c);
}

int main()
{
    test();

    /*
        sizeof Student: 24
        stu: 0x7ffe3b3f2b90     stu.a: 0x7ffe3b3f2b90   stu.b: 0x7ffe3b3f2b94   stu.c: 0x7ffe3b3f2b98   stu.d: 0x7ffe3b3f2ba0
        sizeof Student2: 40
        stu2: 0x7ffe3b3f2bb0    stu2.a: 0x7ffe3b3f2bb0  stu2.b: 0x7ffe3b3f2bb8  stu2.b.a: 0x7ffe3b3f2bb8        stu2.b.b: 0x7ffe3b3f2bbc        stu2.b.c: 0x7ffe3b3f2bc0        stu2.b.d: 0x7ffe3b3f2bc8        stu2.c :0x7ffe3b3f2bd0
    */

    return 0;
}
```

如果不是有专门的需求，按照编译器默认的方法与操作系统平台(64 位)即可，不需要手动设置对齐模数

---
