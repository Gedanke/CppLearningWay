#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main()
{
    time_t tm = time(NULL);  // 得到系统时间
    srand((unsigned int)tm); // 随机种子只需要设置一次即可

    int r = rand();
    printf("r = %d\n", r);

    // r = 1391819817

    return 0;
}
