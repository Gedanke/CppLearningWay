#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// const 修饰变量
void test1()
{
    // 1. const基本概念
    const int i = 0;
    // i = 100; // 错误，只读变量初始化之后不能修改

    // 2. 定义 const 变量最好初始化
    const int j;
    // j = 100; //错误，不能再次赋值

    // 3. c 语言的 const 是一个只读变量，并不是一个常量，可通过指针间接修改
    const int k = 10;
    // k = 100; //错误，不可直接修改，我们可通过指针间接修改
    printf("k: %d\n", k);
    int *p = &k;
    *p = 100;
    printf("k: %d\n", k);
}

// const 修饰指针
void test2()
{
    int a = 10;
    int b = 20;
    // const 放在 * 号左侧 修饰 p_a 指针指向的内存空间不能修改，但可修改指针的指向
    const int *p_a = &a;
    // *p_a = 100; // 不可修改指针指向的内存空间
    p_a = &b; // 可修改指针的指向

    // const 放在 * 号的右侧， 修饰指针的指向不能修改，但是可修改指针指向的内存空间
    int *const p_b = &a;
    // p_b = &b; // 不可修改指针的指向
    *p_b = 100; // 可修改指针指向的内存空间

    // 指针的指向和指针指向的内存空间都不能修改
    const int *const p_c = &a;
}

// const 指针用法
struct Person
{
    char name[64];
    int id;
    int age;
    int score;
};

// 每次都对对象进行拷贝，效率低，应该用指针
void printPersonByValue(struct Person person)
{
    printf("Person.name: %s\n", person.name);
    printf("Person.id: %d\n", person.id);
    printf("Person.age: %d\n", person.age);
    printf("Person.score: %d\n", person.score);
}

// 但是用指针会有副作用，可能会不小心修改原数据
void printPersonByPointer(const struct Person *person)
{
    printf("Person->name: %s\n", person->name);
    printf("Person->id: %d\n", person->id);
    printf("Person->age: %d\n", person->age);
    printf("Person->score: %d\n", person->score);
}

void test3()
{
    struct Person p = {"Obama", 1101, 23, 87};
    printPersonByValue(p);
    printPersonByPointer(&p);
}

int main()
{
    test1();
    test2();
    test3();

    /*
        main.c: In function ‘test1’:
        main.c:20:14: warning: initialization discards ‘const’ qualifier from pointer target type [-Wdiscarded-qualifiers]
        20 |     int *p = &k;
            |              ^
        k: 10
        k: 100
        Person.name: Obama
        Person.id: 1101
        Person.age: 23
        Person.score: 87
        Person->name: Obama
        Person->id: 1101
        Person->age: 23
        Person->score: 87
    */

    return 0;
}