#include <stdio.h>

int main()
{
    int sum = 0; // 定义变量 sum

    for (int i = 1; i <= 100; i++)
    {
        if (i % 2 == 0) // 如果 i 是一个偶数，执行 if 语句中的代码
        {
            continue; // 结束本次循环
        }
        sum += i; // 实现 sum 和 i 的累加
    }

    printf("sum = %d\n", sum);

    // sum = 2500

    return 0;
}
