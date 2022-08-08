#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void test()
{
    int *p = 0x001; // 未初始化
    printf("%p\n", p);
    *p = 100;
}

int main()
{
    test();

    /*
        main.c: In function ‘test’:
        main.c:7:14: warning: initialization of ‘int *’ from ‘int’ makes pointer from integer without a cast [-Wint-conversion]
            7 |     int *p = 0x001; // 未初始化
            |              ^~~~~
        0x1
        Segmentation fault
    */

    return 0;
}