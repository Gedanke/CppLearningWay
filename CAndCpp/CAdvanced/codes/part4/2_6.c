#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 二维数组的第一种形式
void PrintArray1(int arr[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("arr[%d][%d]: %d\t", i, j, arr[i][j]);
        }
        printf("\n");
    }
}

// 二维数组的第二种形式
void PrintArray2(int arr[][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("arr[%d][%d]: %d\t", i, j, arr[i][j]);
        }
        printf("\n");
    }
}

// 二维数组的第三种形式
void PrintArray3(int (*arr)[3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("arr[%d][%d]: %d\t", i, j, arr[i][j]);
        }
        printf("\n");
    }
}

void test()
{
    int arr[][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}};

    PrintArray1(arr);
    PrintArray2(arr);
    PrintArray3(arr);
}

int main()
{
    test();

    /*
        arr[0][0]: 1    arr[0][1]: 2    arr[0][2]: 3
        arr[1][0]: 4    arr[1][1]: 5    arr[1][2]: 6
        arr[2][0]: 7    arr[2][1]: 8    arr[2][2]: 9
        arr[0][0]: 1    arr[0][1]: 2    arr[0][2]: 3
        arr[1][0]: 4    arr[1][1]: 5    arr[1][2]: 6
        arr[2][0]: 7    arr[2][1]: 8    arr[2][2]: 9
        arr[0][0]: 1    arr[0][1]: 2    arr[0][2]: 3
        arr[1][0]: 4    arr[1][1]: 5    arr[1][2]: 6
        arr[2][0]: 7    arr[2][1]: 8    arr[2][2]: 9
    */

    return 0;
}