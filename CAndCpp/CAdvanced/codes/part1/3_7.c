#include <stdio.h>

// 栈的生长方向
void test1()
{
    int a = 10;
    int b = 20;
    int c = 30;
    int d = 40;

    printf("a = %p\n", &a);
    printf("b = %p\n", &b);
    printf("c = %p\n", &c);
    printf("d = %p\n", &d);

    // a 的地址大于 b 的地址，故而生长方向向下
}

// 内存生长方向(小端模式)
void test2()
{

    // 高位字节 -> 地位字节
    int num = 0xaabbccdd;
    unsigned char *p = &num;

    // 从首地址开始的第一个字节
    printf("%x\n", *p);
    printf("%x\n", *(p + 1));
    printf("%x\n", *(p + 2));
    printf("%x\n", *(p + 3));
}

int main()
{
    test1();
    test2();

    /*
        main.c: In function ‘test2’:
        main.c:25:24: warning: initialization of ‘unsigned char *’ from incompatible pointer type ‘int *’ [-Wincompatible-pointer-types]
        25 |     unsigned char *p = &num;
            |                        ^
        a = 0x7ffc8479b1b8
        b = 0x7ffc8479b1bc
        c = 0x7ffc8479b1c0
        d = 0x7ffc8479b1c4
        dd
        cc
        bb
        aa
    */

    return 0;
}
