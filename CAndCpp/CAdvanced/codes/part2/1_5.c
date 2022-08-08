#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void test()
{
    int a = 0xaabbccdd;
    int *p1 = &a;
    char *p2 = &a;

    // *p1 打印出来正确结果
    printf("%x\n", *p1);
    // *p2 没有打印出来正确结果
    printf("%x\n", *p2);

    // p1 指针 +1 加了 4 字节
    printf("p1 = %p\n", p1);
    printf("p1 + 1 = %p\n", p1 + 1);
    // p2 指针 +1 加了 1 字节
    printf("p2 = %p\n", p2);
    printf("p2 + 1 = %p\n", p2 + 1);
}

int main()
{
    test();

    /*
        main.c: In function ‘test’:
        main.c:9:16: warning: initialization of ‘char *’ from incompatible pointer type ‘int *’ [-Wincompatible-pointer-types]
            9 |     char *p2 = &a;
            |                ^
        aabbccdd
        ffffffdd
        p1 = 0x7ffcdacd23b4
        p1 + 1 = 0x7ffcdacd23b8
        p2 = 0x7ffcdacd23b4
        p2 + 1 = 0x7ffcdacd23b5
    */

    return 0;
}