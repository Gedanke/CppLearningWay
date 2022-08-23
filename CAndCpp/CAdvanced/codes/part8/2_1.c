#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int plus(int a, int b)
{
    return a + b;
}

int sub(int a, int b)
{
    return a - b;
}

int mul(int a, int b)
{
    return a * b;
}

int division(int a, int b)
{
    return a / b;
}

// 函数指针做函数的参数 --- 回调函数
void Calculator(int (*myCalculate)(int, int), int a, int b)
{
    int ret = myCalculate(a, b); // dowork 中不确定用户选择的内容，由后期来指定运算规则
    printf("ret = %d\n", ret);
}

void test()
{
    printf("请输入操作符\n");
    printf("1、+ \n");
    printf("2、- \n");
    printf("3、* \n");
    printf("4、/ \n");

    int select = -1;
    scanf("%d", &select);

    int num1 = 0;
    printf("请输入第一个操作数：\n");
    scanf("%d", &num1);

    int num2 = 0;
    printf("请输入第二个操作数：\n");
    scanf("%d", &num2);

    switch (select)
    {
    case 1:
        Calculator(plus, num1, num2);
        break;
    case 2:
        Calculator(sub, num1, num2);
        break;
    case 3:
        Calculator(mul, num1, num2);
        break;
    case 4:
        Calculator(division, num1, num2);
        break;
    default:
        break;
    }
}

int main()
{
    test();

    /*
        请输入操作符
        1、+
        2、-
        3、*
        4、/
        2
        请输入第一个操作数：
        12
        请输入第二个操作数：
        3
        ret = 9
    */

    return 0;
}