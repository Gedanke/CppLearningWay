#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void funB(int b)
{
    printf("b = %d\n", b);
}

void funA(int a)
{
    funB(a - 1);
    printf("a = %d\n", a);
}

int main()
{
    funA(2);
    printf("main\n");

    /*
        b = 1
        a = 2
        main
    */

    return 0;
}