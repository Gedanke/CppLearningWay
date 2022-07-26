#include <stdio.h>

int main()
{
    // extern 关键字只做声明，不能做任何定义，后面还会学习，这里先了解
    // 声明一个变量 a，a 在这里没有建立存储空间
    extern int a;
    // a = 10; // err, 没有空间，就不可以赋值

    int b = 10; // 定义一个变量 b，b 的类型为 int，b 赋值为 10

    return 0;
}