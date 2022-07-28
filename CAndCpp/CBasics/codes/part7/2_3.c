#include <stdio.h>

int main()
{
    int *p1;
    int **p2;
    char *p3;
    char **p4;
    printf("sizeof(p1) = %lu\n", sizeof(p1));
    printf("sizeof(p2) = %lu\n", sizeof(p2));
    printf("sizeof(p3) = %lu\n", sizeof(p3));
    printf("sizeof(p4) = %lu\n", sizeof(p4));
    printf("sizeof(double *) = %lu\n", sizeof(double *));

    /*
        sizeof(p1) = 8
        sizeof(p2) = 8
        sizeof(p3) = 8
        sizeof(p4) = 8
        sizeof(double *) = 8
    */

    return 0;
}