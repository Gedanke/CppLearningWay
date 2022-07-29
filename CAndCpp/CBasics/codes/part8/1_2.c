#include <stdio.h>

void fun1()
{
    int i = 0;
    i++;
    printf("i = %d\n", i);
}

void fun2()
{
    // 静态局部变量，没有赋值，系统赋值为 0，而且只会初始化一次
    static int a;
    a++;
    printf("a = %d\n", a);
}

int main(void)
{
    fun1();
    fun1();
    fun2();
    fun2();

    /*
        i = 1
        i = 1
        a = 1
        a = 2
    */

    return 0;
}
