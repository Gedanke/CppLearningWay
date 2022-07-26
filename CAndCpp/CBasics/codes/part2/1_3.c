#include <stdio.h>

#define MAX 10 // 声明了一个常量，名字叫 MAX，值是 10，常量的值一旦初始化不可改

int main()
{
    int a;            // 定义了一个变量，其类型为 int，名字叫 a
    const int b = 10; // 定义一个 const 常量，名为叫 b，值为 10
    // b = 11; // err，常量的值不能改变
    // MAX = 100;	// err，常量的值不能改变

    a = MAX;           // 将 abc 的值设置为 MAX 的值
    printf("%d\n", a); // 打印变量 a 的值
    a = 123;
    printf("%d\n", a); // 打印变量 a 的值

    /*
        10
        123
    */

    return 0;
}