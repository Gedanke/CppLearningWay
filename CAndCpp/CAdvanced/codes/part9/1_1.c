#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PI 3.1415

void test()
{
    double r = 10.0;
    double s = PI * r * r;
    printf("s = %lf\n", s);
}

int main()
{
    test();

    /*
        s = 314.150000
    */

    return 0;
}