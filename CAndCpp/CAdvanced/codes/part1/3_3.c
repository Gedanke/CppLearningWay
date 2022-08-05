#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void test1()
{
    int *p1 = calloc(10, sizeof(int));

    if (p1 == NULL)
    {
        return;
    }
    for (int i = 0; i < 10; i++)
    {
        p1[i] = i + 1;
    }
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", p1[i]);
    }
    printf("\n");
    free(p1);
}

void test2()
{
    int *p1 = calloc(10, sizeof(int));

    if (p1 == NULL)
    {
        return;
    }
    for (int i = 0; i < 10; i++)
    {
        p1[i] = i + 1;
    }

    int *p2 = realloc(p1, 15 * sizeof(int));
    if (p2 == NULL)
    {
        return;
    }

    printf("%p\n", p1);
    printf("%p\n", p2);

    // 打印
    for (int i = 0; i < 15; i++)
    {
        printf("%d ", p2[i]);
    }
    printf("\n");

    // 重新赋值
    for (int i = 0; i < 15; i++)
    {
        p2[i] = i + 1;
    }

    // 再次打印
    for (int i = 0; i < 15; i++)
    {
        printf("%d ", p2[i]);
    }
    printf("\n");

    free(p2);
}

int main()
{
    test1();
    printf("---------\n");
    test2();

    /*
        1 2 3 4 5 6 7 8 9 10
        ---------
        0x5602ea6886e0
        0x5602ea6886e0
        1 2 3 4 5 6 7 8 9 10 133377 0 0 0 0
        1 2 3 4 5 6 7 8 9 10 11 12 13 14 15
    */

    return 0;
}