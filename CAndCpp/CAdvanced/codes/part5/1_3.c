#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 一个老师有 N 个学生
typedef struct _TEACHER
{
    char *name;
} Teacher;

void test()
{
    Teacher t1;
    t1.name = malloc(64);
    strcpy(t1.name, "John");

    Teacher t2;
    t2 = t1;

    // 对手动开辟的内存，需要手动拷贝
    t2.name = malloc(64);
    strcpy(t2.name, t1.name);

    if (t1.name != NULL)
    {
        free(t1.name);
        t1.name = NULL;
    }
    if (t2.name != NULL)
    {
        free(t2.name);
        t1.name = NULL;
    }
}

int main()
{
    test();

    /*
     */

    return 0;
}