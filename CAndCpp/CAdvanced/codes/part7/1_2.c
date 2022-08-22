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
    Stu *s1 = (Stu *)malloc(sizeof(Stu));
    s1->id = 1;
    strcpy(s1->name, "Anna");

    Stu *s2 = (Stu *)malloc(sizeof(Stu));
    s2->id = 2;
    strcpy(s2->name, "Bob");

    Stu *s3 = (Stu *)malloc(sizeof(Stu));
    s3->id = 3;
    strcpy(s3->name, "Cord");

    s1->next = s2;
    s2->next = s3;
    s3->next = NULL;

    Stu *p = s1;
    while (p != NULL)
    {
        printf("id = %d\tname = %s\n", p->id, p->name);
        p = p->next;
    }

    p = s1;
    Stu *tmp = NULL;
    while (p != NULL)
    {
        tmp = p;
        p = p->next;

        free(tmp);
        tmp = NULL;
    }
}

int main()
{
    test();
    char name[100];

    /*
        id = 1  name = Anna
        id = 2  name = Bob
        id = 3  name = Cord
    */

    return 0;
}