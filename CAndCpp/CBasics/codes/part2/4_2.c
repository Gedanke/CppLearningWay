#include <stdio.h>

int main()
{
    char ch;
    printf("请输入 ch 的值：");

    // 不要加 \n
    scanf("%c", &ch);
    printf("ch = %c\n", ch); // 打印 ch 的字符

    /*
        请输入 ch 的值：d
        ch = d
    */

    return 0;
}