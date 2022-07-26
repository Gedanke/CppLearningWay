#include <stdio.h>

int main()
{
    int num = 0;
    int i, j, k;
    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < 2; j++)
        {
            for (k = 0; k < 2; k++)
            {
                printf("hello world\n");
                num++;
            }
        }
    }

    printf("num = %d\n", num);

    /*
        hello world
        hello world
        hello world
        hello world
        hello world
        hello world
        hello world
        hello world
        num = 8
    */

    return 0;
}
