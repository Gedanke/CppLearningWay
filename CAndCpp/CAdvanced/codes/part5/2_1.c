#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Person
{
    char *name;
    int age;
    int *sex;
} Person;

void allocateMen(Person **person)
{
    if (person == NULL)
    {
        return;
    }
    Person *p = (Person *)malloc(sizeof(Person) * 1);
    if (p == NULL)
    {
        return;
    }

    p->name = (char *)malloc(sizeof(char) * 64);
    p->age = 23;
    p->sex = (int *)malloc(sizeof(int) * 1);
    strcpy(p->name, "Cook");
    *(p->sex) = 1;

    *person = p;
}

void printPerson(const Person *p)
{
    printf("Name: %s; Age: %d; Sex: %d\n", p->name, p->age, *(p->sex));
}

void freeMem(Person **person)
{
    if (person == NULL)
    {
        return;
    }
    Person *p = *person;
    if (p->name != NULL)
    {
        free(p->name);
        p->name = NULL;
    }
    if (p->sex != NULL)
    {
        free(p->sex);
        p->sex = NULL;
    }

    free(p);
}

void test1()
{
    Person *p = NULL;
    allocateMen(&p);
    printPerson(p);
    freeMem(&p);
}

void initPerson(Person *p)
{
    if (p == NULL)
    {
        return;
    }

    p->name = (char *)malloc(sizeof(char) * 64);
    p->age = 24;
    p->sex = (int *)malloc(sizeof(int) * 1);

    strcpy(p->name, "Frank");
    *(p->sex) = 0;
}

void showPerson(const Person p)
{
    printf("Name: %s; Age: %d; Sex: %d\n", p.name, p.age, *(p.sex));
}

void freePerson(Person *p)
{
    if (p == NULL)
    {
        return;
    }
    if (p->name != NULL)
    {
        free(p->name);
        p->name = NULL;
    }
    if (p->sex != NULL)
    {
        free(p->sex);
        p->sex = NULL;
    }
    p->age = 0;
}

void test2()
{
    Person p;
    initPerson(&p);
    showPerson(p);
    freePerson(&p);
}

int main()
{
    test1();
    test2();

    /*
        Name: Cook; Age: 23; Sex: 1
        Name: Frank; Age: 24; Sex: 0
    */

    return 0;
}