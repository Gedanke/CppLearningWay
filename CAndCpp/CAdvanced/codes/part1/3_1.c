#include <stdio.h>

char *func()
{
    char p[] = "hello world!"; // 在栈区存储 乱码
    printf("%s\n", p);
    return p;
}

void test()
{
    char *p = NULL;
    p = func();
    printf("%s\n", p);
}

int main()
{
    // test();

    /*
        main.c: In function ‘func’:
        main.c:7:12: warning: function returns address of local variable [-Wreturn-local-addr]
            7 |     return p;
            |            ^
        hello world!
        Segmentation fault
    */

    return 0;
}