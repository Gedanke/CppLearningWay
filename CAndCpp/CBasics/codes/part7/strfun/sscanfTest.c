#include <stdio.h>
#include <string.h>

int main(void)
{
    char src[] = "a=10, b=20";
    int a;
    int b;
    sscanf(src, "a=%d,  b=%d", &a, &b);
    printf("a:%d, b:%d\n", a, b);

    /*
        a:10, b:20
    */

    return 0;
}