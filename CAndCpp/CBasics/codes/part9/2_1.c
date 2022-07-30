#include <stdio.h>

// 共用体也叫联合体
union Test
{
    unsigned char a;
    unsigned int b;
    unsigned short c;
};

int main()
{
    // 定义共用体变量
    union Test tmp;

    // 1、所有成员的首地址是一样的
    printf("%p, %p, %p\n", &(tmp.a), &(tmp.b), &(tmp.c));

    // 2、共用体大小为最大成员类型的大小
    printf("%lu\n", sizeof(union Test));

    // 3、一个成员赋值，会影响另外的成员
    // 左边是高位，右边是低位
    // 低位放低地址，高位放高地址
    tmp.b = 0x44332211;

    printf("%x\n", tmp.a); // 11
    printf("%x\n", tmp.c); // 2211

    tmp.a = 0x00;
    printf("short: %x\n", tmp.c); // 2200
    printf("int: %x\n", tmp.b);   // 44332200

    /*
        0x7ffef9aacd34, 0x7ffef9aacd34, 0x7ffef9aacd34
        4
        11
        2211
        short: 2200
        int: 44332200
    */

    return 0;
}
