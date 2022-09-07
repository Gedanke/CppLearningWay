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
    struct Person p1;
    strcpy(p1.name, "John");
    p1.age = 30;
    // 如果是普通变量，通过 . 运算符操作结构体成员
    printf("Name: %s\tAge: %d\n", p1.name, p1.age);

    // 在堆上分配空间
    struct Person *p2 = (struct Person *)malloc(sizeof(struct Person));
    strcpy(p2->name, "Obama");
    p2->age = 33;
    // 如果是指针变量，通过 -> 操作结构体成员
    printf("Name: %s\tAge: %d\n", p2->name, p2->age);
}

int main()
{
    test();
    int i;
    for(i=0;i<10;i++){
        printf("%d ",i);
    }

    /*
        Name: John      Age: 30
        Name: Obama     Age: 33
    */

    return 0;
}