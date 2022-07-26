#include <stdio.h>

int main()
{
    // 传统方式赋值
    float a = 3.14f; // 或 3.14F
    double b = 3.14;

    printf("a = %f\n", a);
    printf("b = %lf\n", b);

    // 科学法赋值
    a = 3.2e3f; // 3.2*1000 = 3200，e 可以写 E
    printf("a1 = %f\n", a);

    a = 100e-3f; // 100*0.001 = 0.1
    printf("a2 = %f\n", a);

    a = 3.1415926f;
    printf("a3 = %f\n", a); // 结果为 3.141593

    /*
        a = 3.140000
        b = 3.140000
        a1 = 3200.000000
        a2 = 0.100000
        a3 = 3.141593
    */

    return 0;
}