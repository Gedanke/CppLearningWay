#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void recursion(int val)
{
    if (val == 0)
    {
        return;
    }
    int ret = val / 10;
    recursion(ret);
    printf("%d ", val % 10);
}

int main()
{
    recursion(8793);
    printf("\n");

    /*
        8 7 9 3
    */

    return 0;
}