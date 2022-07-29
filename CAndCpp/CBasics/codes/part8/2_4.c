#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main()
{
    int count, *array, n;
    printf("请输入要申请数组的个数:\n");
    scanf("%d", &n);

    array = (int *)malloc(n * sizeof(int));
    if (array == NULL)
    {
        printf("申请空间失败!\n");
        return -1;
    }
    // 将申请到空间清 0
    memset(array, 0, sizeof(int) * n);

    for (count = 0; count < n; count++) /*给数组赋值*/
        array[count] = count;

    for (count = 0; count < n; count++) /*打印数组元素*/
        printf("%4d", array[count]);

    free(array);
    printf("\n");

    /*
        请输入要申请数组的个数:
        12
            0   1   2   3   4   5   6   7   8   9  10  11
    */

    return 0;
}
