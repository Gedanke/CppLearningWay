#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void test1()
{
    int val = 12;
    int *p1 = &val;
    int **p2 = &p1;
    int ***p3 = &p2;

    printf("p1 size: %lu\n", sizeof(p1));
    printf("p2 size: %lu\n", sizeof(p2));
    printf("p3 size: %lu\n", sizeof(p3));

    // 指针是变量，指针本身也占内存空间，指针也可以被赋值
    int a = 10;
    p1 = &a;

    printf("a address: %p\n", &a);
    printf("a value: %d\n", a);
    printf("p1 address: %p\n", &p1);
    printf("p1 value :%p\n", p1);
    printf("p2 address: %p\n", &p2);
    printf("p2 value :%p\n", p2);
    printf("p3 address: %p\n", &p3);
    printf("p3 value :%p\n", p3);
}

int main()
{
    test1();

    /*
        p1 size: 8
        p2 size: 8
        p3 size: 8
        a address: 0x7fff7e6cb1dc
        a value: 10
        p1 address: 0x7fff7e6cb1e0
        p1 value :0x7fff7e6cb1dc
        p2 address: 0x7fff7e6cb1e8
        p2 value :0x7fff7e6cb1e0
        p3 address: 0x7fff7e6cb1f0
        p3 value :0x7fff7e6cb1e8
    */

    return 0;
}