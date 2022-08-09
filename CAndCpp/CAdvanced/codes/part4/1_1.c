#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int arr[10];
    // arr = NULL; // arr 作为指针常量，不可修改
    int *p = arr;                              // 此时 arr 作为指针常量来使用
    printf("sizeof(arr): %lu\n", sizeof(arr)); // 此时 sizeof 结果为整个数组的长度
    // printf("&arr type is %s\n", typeid(&arr).name()); // int(*)[10] 而不是 int*，表达式必须具有结构或联合类型，但它具有类型 "int"

    /*
        sizeof(arr): 40
    */

    return 0;
}