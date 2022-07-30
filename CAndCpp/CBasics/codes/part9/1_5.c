#include <stdio.h>
#include <string.h>

// 结构体类型的定义
struct stu
{
    char name[50];
    int age;
};

int main()
{
    struct stu s1;

    // 如果是普通变量，通过点运算符操作结构体成员
    strcpy(s1.name, "abc");
    s1.age = 18;
    printf("s1.name = %s, s1.age = %d\n", s1.name, s1.age);
    printf("&s1 = %p\n", &s1);

    // 相同类型的两个结构体变量，可以相互赋值
    // 把 s1 成员变量的值拷贝给 s2 成员变量的内存
    // s1 和 s2 只是成员变量的值一样而已，它们还是没有关系的两个变量
    struct stu s2 = s1;
    // memcpy(&s2, &s1, sizeof(s1));
    printf("s2.name = %s, s2.age = %d\n", s2.name, s2.age);
    printf("&s2 = %p\n", &s2);

    /*
        s1.name = abc, s1.age = 18
        &s1 = 0x7ffea4c6f840
        s2.name = abc, s2.age = 18
        &s2 = 0x7ffea4c6f880
    */

    return 0;
}