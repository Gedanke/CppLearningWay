#include <stdio.h>

#define PI 3.14

int main()
{
    // 求圆的面积与周长
    double r;
    printf("请输入圆的半径 r:\n");
    scanf("%lf", &r);

    double area = PI * PI * r;
    double length = 2 * PI * r;

    printf("面积为 %lf\n", area);
    printf("周长为 %lf\n", length);

    /*
        请输入圆的半径 r:
        10
        面积为 98.596000
        周长为 62.800000
    */

    return 0;
}