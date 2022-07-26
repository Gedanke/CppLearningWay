#include <stdio.h>

int main()
{
    char ch1;
    char ch2;
    char ch3;
    int a;
    int b;

    printf("请输入 ch1 的字符：");
    ch1 = getchar();
    printf("ch1 = %c\n", ch1);

    getchar(); // 测试此处 getchar() 的作用

    printf("请输入 ch2 的字符：");
    ch2 = getchar();
    printf("\'ch2 = %ctest\'\n", ch2);

    getchar(); // 测试此处 getchar() 的作用
    printf("请输入 ch3 的字符：");
    scanf("%c", &ch3); // 这里第二个参数一定是变量的地址，而不是变量名
    printf("ch3 = %c\n", ch3);

    printf("请输入 a 的值：");
    scanf("%d", &a);
    printf("a = %d\n", a);

    printf("请输入 b 的值：");
    scanf("%d", &b);
    printf("b = %d\n", b);

    /*
        请输入 ch1 的字符：a
        ch1 = a
        请输入 ch2 的字符：d
        'ch2 = dtest'
        请输入 ch3 的字符：e
        ch3 = e
        请输入 a 的值：1
        a = 1
        请输入 b 的值：2
        b = 2
    */

    return 0;
}