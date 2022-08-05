#include <stdio.h>
#include <stdlib.h>

void fun()
{
    printf("fun\n");
    // return;
    exit(0);
}

int main()
{
    fun();
    while (1)
        ;

    // fun

    return 0;
}