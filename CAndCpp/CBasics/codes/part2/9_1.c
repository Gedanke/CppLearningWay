#include <stdio.h>

int main()
{
    int a = 100;
    printf("a = %d\n", a); // 格式化输出一个字符串
    printf("%p\n", &a);    // 输出变量 a 在内存中的地址编号
    printf("%%d\n");

    char c = 'a';
    putchar(c); // putchar 只有一个参数，就是要输出的 char
    long a2 = 100;
    printf("%ld, %lx, %lo\n", a2, a2, a2);

    long long a3 = 1000;
    printf("%lld, %llx, %llo\n", a3, a3, a3);

    int abc = 10;
    printf("abc = '%6d'\n", abc);
    printf("abc = '%-6d'\n", abc);
    printf("abc = '%06d'\n", abc);
    printf("abc = '%-06d'\n", abc);

    double d = 12.3;
    printf("d = \' %-10.3lf \'\n", d);

    /*
        main.c: In function ‘main’:
        main.c:22:12: warning: '0' flag ignored with '-' flag in gnu_printf format [-Wformat=]
        22 |     printf("abc = '%-06d'\n", abc);
            |            ^~~~~~~~~~~~~~~~~
        a = 100
        0x7ffd31d8eb68
        %d
        a100, 64, 144
        1000, 3e8, 1750
        abc = '    10'
        abc = '10    '
        abc = '000010'
        abc = '10    '
        d = ' 12.300     '
    */

    return 0;
}