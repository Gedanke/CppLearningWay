#include <stdio.h>
#include "fun.h"

int main()
{
    int num1 = 10, num2 = 12;

    int num_min = min(num1, num2);
    int num_max = max(num1, num2);

    printf("min(num1, num2) = %d\n", num_min);
    printf("max(num1, num2) = %d\n", num_max);

    /*
        min(num1, num2) = 10
        max(num1, num2) = 12
    */

    return 0;
}