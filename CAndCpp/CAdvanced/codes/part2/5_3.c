#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *get_str()
{
    char str[] = "abcdedsgads"; // 栈区，
    printf("[get_str]str = %s\n", str);
    return str;
}

void test()
{
    char *p = get_str();
    printf("%s\n", p);
}

int main()
{
    test();

    /*
        main.c: In function ‘get_str’:
        main.c:9:12: warning: function returns address of local variable [-Wreturn-local-addr]
            9 |     return str;
            |            ^~~
        [get_str]str = abcdedsgads
        Segmentation fault
    */

    return 0;
}