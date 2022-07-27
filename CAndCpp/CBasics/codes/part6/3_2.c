#include <stdio.h>

// 函数的定义
void test()
{
    printf("ddd\n");
}

int main()
{
    // 函数的调用
    test();    // right 圆括号() 不能省略
    test(250); // error 函数调用中的参数太多

    /*
        ddd
        ddd
    */

    return 0;
}
