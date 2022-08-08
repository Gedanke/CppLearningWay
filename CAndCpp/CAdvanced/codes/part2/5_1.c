#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void test()
{
    char buf[3] = "abc";
    printf("buf: %s\n", buf);
}

int main()
{
    test();

    /*
        buf: abc
    */

    return 0;
}