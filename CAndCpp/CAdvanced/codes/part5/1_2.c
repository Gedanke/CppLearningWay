#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Person
{
    char name[64];
    int age;
};

void test()
{
    // 在栈上分配空间
    struct Person p1 = {"John", 30};
    struct Person p2 = {"Obama", 33};
    printf("Name: %s\tAge: %d\n", p1.name, p1.age);
    printf("Name: %s\tAge: %d\n", p2.name, p2.age);
    // 将 p2 的值赋值给 p1
    p1 = p2;
    printf("Name: %s\tAge: %d\n", p1.name, p1.age);
    printf("Name: %s\tAge: %d\n", p2.name, p2.age);
}

int main()
{
    test();

    /*
        Name: John      Age: 30
        Name: Obama     Age: 33
        Name: Obama     Age: 33
        Name: Obama     Age: 33
    */

    return 0;
}