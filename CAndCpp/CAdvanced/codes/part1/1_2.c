#include <stdio.h>

// void 修饰函数参数和函数返回
void test1(void)
{
    printf("hello world\n");
}

// 不能定义 void 类型变量
void test2()
{
    // void val; // 不允许使用不完整的类型
}

// void* 可以指向任何类型的数据，被称为万能指针
void test3()
{
    int a = 10;
    void *p = NULL;
    p = &a;
    printf("a:%d\n", *(int *)p);

    char c = 'a';
    p = (void *)&c;
    printf("c:%c\n", *(char *)p);
}

// void* 常用于数据类型的封装
void test4()
{
    void *memcpy(void *_Dst, const void *_Src, size_t _Size);
}

int main()
{
    test1();
    test2();
    test3();
    test4();

    /*
        hello world
        a:10
        c:a
    */

    return 0;
}