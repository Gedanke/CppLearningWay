#include <stdio.h>

void test()
{
    // auto 写不写是一样的
    // auto 只能出现在 {} 内部
    auto int b = 10;
}

int main(void)
{
    // b = 100; // err，在 main 作用域中没有 b

    if (1)
    {
        // 在复合语句中定义，只在复合语句中有效
        int a = 10;
        printf("a = %d\n", a);
    }

    // a = 10; // err 离开 if() 的复合语句，a 已经不存在

    // a = 10

    return 0;
}