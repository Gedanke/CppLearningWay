#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void AllocateSpace(char **p)
{
    *p = (char *)malloc(100);
    strcpy(*p, "hello world!");
}

void FreeSpace(char **p)
{
    if (p == NULL)
    {
        return;
    }
    if (*p != NULL)
    {
        free(*p);
        *p = NULL;
    }
}

void test()
{
    char *p = NULL;

    AllocateSpace(&p);
    printf("%s\n", p);
    FreeSpace(&p);

    if (p == NULL)
    {
        printf("p 内存释放!\n");
    }
}

int main()
{
    test();

    /*
        hello world!
        p 内存释放!
    */

    return 0;
}