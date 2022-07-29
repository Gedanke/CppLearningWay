#include <stdio.h>
#include <stdlib.h>

void fun(int *tmp)
{
    *tmp = 100;
}

int main(int argc, char *argv[])
{
    int *p = NULL;
    p = (int *)malloc(sizeof(int));

    fun(p);                  // 值传递
    printf("*p = %d\n", *p); // ok，*p 为 100

    // *p = 100

    return 0;
}
