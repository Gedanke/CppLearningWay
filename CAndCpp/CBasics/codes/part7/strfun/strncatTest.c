#include <stdio.h>
#include <string.h>

int main(void)
{
    char str[20] = "123";
    char *src = "hello world";
    printf("%s\n", strncat(str, src, 5));

    /*
        123hello
    */

    return 0;
}