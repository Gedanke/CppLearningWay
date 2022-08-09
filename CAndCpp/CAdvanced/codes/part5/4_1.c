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