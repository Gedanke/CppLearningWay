#include <stdio.h>

typedef unsigned int u32;
typedef struct PERSON
{
    char name[64];
    int age;
} Person;

void test()
{
    u32 val;       // 相当于 unsigned int val
    Person person; // 相当于 struct PERSON person
}

int main()
{
    test();

    /*
     */

    return 0;
}