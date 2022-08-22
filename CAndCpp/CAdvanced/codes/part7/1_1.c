#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Stu
{
    // 数据域
    int id;
    char name[100];

    // 指针域
    struct Stu *next;
} Stu;

void test()
{
    Stu s1 = {1, "Anna", NULL};
    Stu s2 = {2, "Bob", NULL};
    Stu s3 = {3, "Cord", NULL};

    s1.next = &s2;
    s2.next = &s3;
    s3.next = NULL;

    Stu *p = &s1;
    while (p != NULL)
    {
        printf("id = %d\tname = %s\n", p->id, p->name);
        p = p->next;
    }
}

int main()
{
    test();

    /*
        id = 1  name = Anna
        id = 2  name = Bob
        id = 3  name = Cord
    */

    return 0;
}