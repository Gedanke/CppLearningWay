#include <stdio.h>

int main()
{
    // 定义了一个二维数组，名字叫 a
    // 二维数组是本质上还是一维数组，此一维数组有 3 个元素
    // 每个元素又是一个一维数组 int[4]
    int a[3][4] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};

    // 数组名为数组首元素地址，二维数组的第 0 个元素为一维数组
    // 第 0 个一维数组的数组名为 a[0]
    printf("a = %p\n", a);
    printf("a[0] = %p\n", a[0]);

    // 测二维数组所占内存空间，有 3 个一维数组，每个一维数组的空间为 4*4
    // sizeof(a) = 3 * 4 * 4 = 48
    printf("sizeof(a) = %lu\n", sizeof(a));

    // 测第 0 个元素所占内存空间，a[0] 为第 0 个一维数组 int[4] 的数组名，4*4 = 16
    printf("sizeof(a[0]) = %lu\n", sizeof(a[0]));

    // 测第 0 行 0 列元素所占内存空间，第 0 行 0 列元素为一个 int 类型，4 字节
    printf("sizeof(a[0][0]) = %lu\n", sizeof(a[0][0]));

    // 求二维数组行数
    printf("i = %lu\n", sizeof(a) / sizeof(a[0]));

    // 求二维数组列数
    printf("j = %lu\n", sizeof(a[0]) / sizeof(a[0][0]));

    // 求二维数组行*列总数
    printf("n = %lu\n", sizeof(a) / sizeof(a[0][0]));

    /*
        a = 0x7ffcfbd74000
        a[0] = 0x7ffcfbd74000
        sizeof(a) = 48
        sizeof(a[0]) = 16
        sizeof(a[0][0]) = 4
        i = 3
        j = 4
        n = 12
    */

    return 0;
}
