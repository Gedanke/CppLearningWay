#include <stdio.h>
#include <string.h>

int main(void)
{
    char str[30] = "123";
    char src[30] = "hello world";
    printf("%s\n", strcat(str, src));
    printf("%s\n", strcat(src, str));

    /*
        123hello world
        hello world123hello world
    */

    return 0;
}