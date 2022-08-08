#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int num1 = 5;
    int num2 = 9;

    printf("num1 = %d\n", num1);
    printf("num2 = %d\n", num2);

    int tmp = num1;
    num1 = num2;
    num2 = tmp;

    printf("num1 = %d\n", num1);
    printf("num2 = %d\n", num2);

    num1 = num1 ^ num2;
    num2 = num1 ^ num2;
    num1 = num1 ^ num2;

    printf("num1 = %d\n", num1);
    printf("num2 = %d\n", num2);

    num1 = num1 + num2;
    num2 = num1 - num2;
    num1 = num1 - num2;

    printf("num1 = %d\n", num1);
    printf("num2 = %d\n", num2);

    /*
        num1 = 5
        num2 = 9
        num1 = 9
        num2 = 5
        num1 = 5
        num2 = 9
        num1 = 9
        num2 = 5
    */

    return 0;
}