#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void func1(int a)
{
    printf("func1: %d\n", a);
}

void func2(int a)
{
    printf("func2: %d\n", a);
}

void func3(int a)
{
    printf("func3: %d\n", a);
}

void test()
{
#if 0
	// 定义函数指针
	void(*func_array[])(int) = {func1, func2, func3};
#else
    void (*func_array[3])(int);
    func_array[0] = func1;
    func_array[1] = func2;
    func_array[2] = func3;
#endif
    for (int i = 0; i < 3; i++)
    {
        func_array[i](10 + i);
        (*func_array[i])(10 + i);
    }
}

int main()
{
    test();

    /*
        ret: 30
        ret: 30
        ret: 30
        ret: 30
        ret: 30
        ret: 30
    */

    return 0;
}