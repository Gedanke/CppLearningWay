#include <stdio.h>

// 函数的定义，返回值为 int 类型
int test()
{
    printf("test\n");
}

int main()
{
    // 函数的调用
    int a = test(); // right，a 为 int 类型
    int b;
    b = test(); // right，和上面等级

    // 虽然调用成功，但没有意义， p 为 char *，函数返回值为 int，类型不匹配
    char *p = test();
    // warning: initialization of ‘char *’ from ‘int’ makes pointer from integer without a cast [-Wint-conversion]

    // error，必须定义一个匹配类型的变量来接收返回值
    // int只是类型，没有定义变量
    // int = test();

    // error，必须定义一个匹配类型的变量来接收返回值
    // int只是类型，没有定义变量
    int test();

    /*
        test
        test
        test
    */

    return 0;
}
