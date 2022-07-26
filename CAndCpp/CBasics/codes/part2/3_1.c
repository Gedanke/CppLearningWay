#include <stdio.h>

int main()
{
    int a;
    int b = sizeof(a); // sizeof 得到指定值占用内存的大小，单位：字节
    printf("b = %d\n", b);

    size_t c = sizeof(a);
    printf("c = %lu\n", c); // 用无符号数的方式输出 c 的值

    /*
        b = 4
        c = 4
    */

    return 0;
}