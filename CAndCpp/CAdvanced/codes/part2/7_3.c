#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    // 栈区指针数组
    char *p1[] = {"aaaaa", "bbbbb", "ccccc"};

    // 堆区指针数组
    char **p3 = (char **)malloc(3 * sizeof(char *)); // char *array[3];

    int i = 0;
    for (i = 0; i < 3; i++)
    {
        p3[i] = (char *)malloc(10 * sizeof(char)); // char buf[10]
        sprintf(p3[i], "%d%d%d", i, i, i);
        printf("%s\n", p3[i]);
    }

    /*
        000
        111
        222
    */

    return 0;
}