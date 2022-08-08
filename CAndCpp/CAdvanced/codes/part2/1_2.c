#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void test()
{
    char *p = NULL;
    //给 p 指向的内存区域拷贝内容
    strcpy(p, "1111"); // err

    char *q = 0x1122;
    //给 q 指向的内存区域拷贝内容
    strcpy(q, "2222"); // err
}

int main()
{
    test();

    /*
        main.c: In function ‘test’:
        main.c:11:15: warning: initialization of ‘char *’ from ‘int’ makes pointer from integer without a cast [-Wint-conversion]
        11 |     char *q = 0x1122;
            |               ^~~~~~
        Segmentation fault
    */

    return 0;
}