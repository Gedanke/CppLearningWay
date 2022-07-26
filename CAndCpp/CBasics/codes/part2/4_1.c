#include <stdio.h>

int main()
{
    char ch = 'a';
    printf("sizeof(ch) = %lu\n", sizeof(ch));

    printf("ch[%%c] = %c\n", ch); // 打印字符
    printf("ch[%%d] = %d\n", ch); // 打印 a 的 ASCII的值

    char A = 'A';
    char a = 'a';
    printf("a = %d\n", a); // 97
    printf("A = %d\n", A); // 65

    printf("A = %c\n", 'a' - 32); // 小写 a 转大写 A
    printf("a = %c\n", 'A' + 32); // 大写 A 转小写 a

    ch = ' ';
    printf("空字符：%d\n", ch);    // 空字符 ASCII 值为 32
    printf("A = %c\n", 'a' - ' '); // 小写 a 转大写 A
    printf("a = %c\n", 'A' + ' '); // 大写 A 转小写 a

    /*
        sizeof(ch) = 1
        ch[%c] = a
        ch[%d] = 97
        a = 97
        A = 65
        A = A
        a = a
        空字符：32
        A = A
        a = a
    */

    return 0;
}