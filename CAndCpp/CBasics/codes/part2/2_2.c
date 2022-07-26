#include <stdio.h>

int main()
{
    int a;
    printf("请输入 a 的值：");

    // 不要加 "\n"
    scanf("%d", &a);
    printf("a = %d\n", a); // 打印 a 的值

    /*
        请输入 a 的值：12
        a = 12
    */

    return 0;
}