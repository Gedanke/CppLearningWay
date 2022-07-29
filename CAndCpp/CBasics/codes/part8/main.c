#include <stdio.h>

extern int va;
extern int getG();
extern int getO();

int main(void)
{
    printf("va = %d\n", va);
    printf("getO = %d\n", getO());
    printf("getG = %d\n", getG());
    printf("%d\n", va * getO() * getG());

    /*
        va = 5
        getO = 12
        getG = 10
        600
    */

    return 0;
}