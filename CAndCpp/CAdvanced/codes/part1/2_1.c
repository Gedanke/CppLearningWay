#include <stdio.h>

void test()
{
    int a = 10;
    const int b = 100;
    printf("未修改前 a:%d\n", a);
    printf("未修改前 b:%d\n", b);

    // 直接修改
    a = 20;
    // b = 200; // 表达式必须是可修改的左值

    printf("直接修改 a:%d\n", a);

    // 间接修改
    int *pa = &a;
    *pa = 30;
    // 可以修改但有警告
    int *pb = &b;
    *pb = 300;

    printf("间接修改 a:%d\n", a);
    printf("间接修改 b:%d\n", b);
}

int main()
{
    test();

    /*
        main.c: In function ‘test’:
        main.c:20:15: warning: initialization discards ‘const’ qualifier from pointer target type [-Wdiscarded-qualifiers]
        20 |     int *pb = &b;
            |               ^
        未修改前 a:10
        未修改前 b:100
        直接修改 a:20
        间接修改 a:30
        间接修改 b:300
    */

    return 0;
}