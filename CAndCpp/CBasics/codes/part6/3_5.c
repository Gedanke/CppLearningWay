#include <stdio.h>

// 函数的定义
void test()
{
    printf("ddd\n");
}

int main()
{
    // 函数的调用
    test();      // right
    void test(); // error，void 关键字只能出现在定义，不可能出现在调用的地方
    // int a = test();	// error，函数定义根本就没有返回值。"void" 类型的值不能用于初始化 "int" 类型的实体

    // ddd

    return 0;
}
