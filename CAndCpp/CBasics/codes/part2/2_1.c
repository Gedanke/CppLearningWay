#include <stdio.h>

int main()
{
    int a = 123;   // 定义变量 a，以 10 进制方式赋值为 123
    int b = 0567;  // 定义变量 b，以 8 进制方式赋值为 0567
    int c = 0xabc; // 定义变量 c，以 16 进制方式赋值为 0xabc

    printf("a = %d\n", a);
    printf("8 进制：b = %o\n", b);
    printf("10 进制：b = %d\n", b);
    printf("16 进制：c = %x\n", c);
    printf("16 进制：c = %X\n", c);
    printf("10 进制：c = %d\n", c);

    unsigned int d = 0xffffffff; // 定义无符号 int 变量 d，以 16 进制方式赋值
    printf("有符号方式打印：d = %d\n", d);
    printf("无符号方式打印：d = %u\n", d);

    /*
        a = 123
        8 进制：b = 567
        10 进制：b = 375
        16 进制：c = abc
        16 进制：c = ABC
        10 进制：c = 2748
        有符号方式打印：d = -1
        无符号方式打印：d = 4294967295
    */

    return 0;
}