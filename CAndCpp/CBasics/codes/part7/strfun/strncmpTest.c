#include <stdio.h>
#include <string.h>

int main(void)
{
    char *str1 = "hello world";
    char *str2 = "hello mike";
    int res = strncmp(str1, str2, 5);

    if (res == 0)
    {
        printf("str1 == str2\n");
    }
    else if (res > 0)
    {
        printf("str1 > str2\n");
    }
    else
    {
        printf("str1 < str2\n");
    }

    /*
        str1 == str2
    */

    return 0;
}