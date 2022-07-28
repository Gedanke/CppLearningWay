#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char str1[] = "          -10";
    int num1 = atoi(str1);
    printf("num1 = %d\n", num1);

    char str2[] = "0.123";
    double num2 = atof(str2);
    printf("num2 = %lf\n", num2);

    char str3[] = "123L";
    long num3 = atol(str3);
    printf("num3 = %ld\n", num3);

    /*
        num1 = -10
        num2 = 0.123000
        num3 = 123
    */

    return 0;
}