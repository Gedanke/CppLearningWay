#include <stdio.h>
#include <string.h>

int main(void)
{
    char src[] = "ddddabcd123abcd333abcd";
    char *p = strstr(src, "abcd");
    printf("p = %s\n", p);

    /*
        p = abcd123abcd333abcd
    */

    return 0;
}