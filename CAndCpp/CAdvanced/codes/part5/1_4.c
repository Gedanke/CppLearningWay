#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _Person
{
    char name[64];
    int age;
} Person;

void test()
{
    // 在栈上分配空间
    Person p1[3] = {
        {"John", 30},
        {"Obama", 33},
        {"Edward", 25}};

    Person p2[3] = {"John", 30, "Obama", 33, "Edward", 25};
    for (int i = 0; i < 3; i++)
    {
        printf("Name: %s \tAge: %d\n", p1[i].name, p1[i].age);
    }
    printf("-----------------\n");
    for (int i = 0; i < 3; i++)
    {
        printf("Name: %s\tAge: %d\n", p2[i].name, p2[i].age);
    }
    printf("-----------------\n");
    // 在堆上分配结构体数组
    Person *p3 = (Person *)malloc(sizeof(Person) * 3);
    for (int i = 0; i < 3; i++)
    {
        sprintf(p3[i].name, "Name_%d", i + 1);
        p3[i].age = 20 + i;
    }
    for (int i = 0; i < 3; i++)
    {
        printf("Name: %s\tAge: %d\n", p3[i].name, p3[i].age);
    }
}

int main()
{
    test();

    /*
        Name: John      Age: 30
        Name: Obama     Age: 33
        Name: Edward    Age: 25
        -----------------
        Name: John      Age: 30
        Name: Obama     Age: 33
        Name: Edward    Age: 25
        -----------------
        Name: Name_1    Age: 20
        Name: Name_2    Age: 21
        Name: Name_3    Age: 22
     */

    return 0;
}