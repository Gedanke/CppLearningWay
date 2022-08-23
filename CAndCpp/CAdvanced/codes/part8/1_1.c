#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef void(p)(int, int);

void func(int a, int b)
{
    printf("%d %d\n", a, b);
}

void test()
{
    p p1;
    // p1(10, 20); // 错误，不能直接调用，只描述了函数类型，但是并没有定义函数体，没有函数体无法调用
    p *p2 = func;
    p2(10, 20); // 正确，指向有函数体的函数入口地址
}

int main()
{
    test();

    /*
        10 20
    */

    return 0;
}