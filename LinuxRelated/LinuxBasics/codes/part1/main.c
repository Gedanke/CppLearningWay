#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void selectSort(void *pAddr, int elesize, int len, int (*myCompare)(void *, void *))
{
    char *temp = malloc(elesize);

    for (int i = 0; i < len; i++)
    {
        int minOrMax = i; // 定义最小值或者最大值下标
        for (int j = i + 1; j < len; j++)
        {
            // 定义出 j元素地址
            char *pJ = (char *)pAddr + elesize * j;
            char *pMinOrMax = (char *)pAddr + elesize * minOrMax;
            // if ( pAddr[j] < pAddr[minOrMax])

            /* 从大到小
            if ( *num1 > *num2)
            {
            return 1;
            }
            return 0;
            */

            if (myCompare(pJ, pMinOrMax))
            {
                minOrMax = j; // 更新最小值或者最大值下标
            }
        }

        if (i != minOrMax)
        {
            // 交换 i 和 minOrMax 下标元素
            char *pI = (char *)pAddr + i * elesize;

            char *pMinOrMax = (char *)pAddr + minOrMax * elesize;

            memcpy(temp, pI, elesize);
            memcpy(pI, pMinOrMax, elesize);
            memcpy(pMinOrMax, temp, elesize);
        }
    }

    if (temp != NULL)
    {
        free(temp);
        temp = NULL;
    }
}

int myCompareInt(void *data1, void *data2)
{
    int *num1 = data1;
    int *num2 = data2;

    if (*num1 > *num2)
    {
        return 1;
    }
    return 0;
}

void test1()
{
    int arr[] = {10, 30, 20, 60, 50, 40};

    int len = sizeof(arr) / sizeof(int);
    selectSort(arr, sizeof(int), len, myCompareInt);

    for (int i = 0; i < len; i++)
    {
        printf("%d\n", arr[i]);
    }
}

struct Person
{
    char name[64];
    int age;
};

int myComparePerson(void *data1, void *data2)
{
    struct Person *p1 = data1;
    struct Person *p2 = data2;

    // if ( p1->age < p2->age)
    //{
    //	return  1;
    // }
    // return 0;
    // 按照年龄 升序排序
    return p1->age < p2->age;
}

void test2()
{
    struct Person pArray[] =
        {
            {"aaa", 10},
            {"bbb", 40},
            {"ccc", 20},
            {"ddd", 30},
        };
    int len = sizeof(pArray) / sizeof(struct Person);
    selectSort(pArray, sizeof(struct Person), len, myComparePerson);

    for (int i = 0; i < len; i++)
    {
        printf("姓名：%s 年龄: %d\n", pArray[i].name, pArray[i].age);
    }
}

int main()
{
    test1();
    test2();

    /*
        60
        50
        40
        30
        20
        10
        姓名：aaa 年龄: 10
        姓名：ccc 年龄: 20
        姓名：ddd 年龄: 30
        姓名：bbb 年龄: 40
    */

    return 0;
}