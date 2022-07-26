#include <stdio.h>

int main()
{
    int a = 123;   // 十进制方式赋值
    int b = 0123;  // 八进制方式赋值，以数字 0 开头
    int c = 0xABC; // 十六进制方式赋值

    // 如果在 printf 中输出一个十进制数那么用 %d，八进制用 %o，十六进制是 %x
    printf("十进制：%d\n", a);
    printf("八进制：%o\n", b); // %o,为字母 o,不是数字
    printf("十六进制：%x\n", c);

    /*
        十进制：123
        八进制：123
        十六进制：abc
    */

    return 0;
}