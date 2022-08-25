# 面向接口编程

---

## 案例背景

一般的企业信息系统都有成熟的框架。软件框架一般不发生变化，能自由的集成第三方厂商的产品

---

## 案例需求

要求在企业信息系统框架中集成第三方厂商的游戏功能产品。软件设计要求：能够满足用户需求，完成的产品可以与用户完美对接

---

## 案例要求

* 能支持多个厂商的游戏功能产品入围
* 能够实现第三方产品和用户产品的对接
* 系统整体框架不轻易发生改变

---

## 编程提示

* 抽象游戏中玩家结构体设计(struct Player)
* 框架接口设计(playGame)
    * 初始化游戏
    * 核心功能战斗
    * 查看玩家信息
    * 结束游戏
* 游戏厂商入围
    * 游戏厂商 1 入围(GameCompany1)
    * 游戏厂商 2 入围(GameCompany2)
* 框架接口分文件编写

`gameCompany1.h`

```c
#pragma once
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Player
{
    char name[64]; // 玩家姓名
    int level;     // 玩家等级
    int exp;       // 玩家经验
};

// 初始化游戏：参数1，玩家指针；参数2，玩家姓名
void INIT_GAME_COMPANY1(void **player, char *name);

// 副本战斗：返回战斗是否胜利：1、代表胜利，0、代表失败。参数1：玩家；参数2：游戏副本难度
int FIGHT_GAME_COMPANY1(void *player, int gameDiff);

// 查看玩家信息
void PRINT_GAME_COMPANY1(void *player);

// 离开游戏
void EXIT_GAME_COMPANY1(void *player);

// 判断游戏是否胜利
int isWin(int winRate, int diff);
```

`gameCompany1.c`

```c
#include "gameCompany1.h"

// 初始化游戏：参数1，玩家指针；参数2，玩家姓名
void INIT_GAME_COMPANY1(void **player, char *name)
{
    struct Player *player1 = malloc(sizeof(struct Player));

    if (player1 == NULL)
    {
        printf("初始化失败\n");
        return;
    }

    *player = player1;

    strcpy(player1->name, name);
    player1->level = 0;
    player1->exp = 0;
}

// 副本战斗：返回战斗是否胜利：1、代表胜利，0、代表失败。参数1：玩家；参数2：游戏副本难度
int FIGHT_GAME_COMPANY1(void *p, int gameDiff)
{
    struct Player *player = p;
    int addExp = 0; // 增加经验值

    switch (gameDiff)
    {
    case 1:
        addExp = isWin(90, 1);
        break;
    case 2:
        addExp = isWin(50, 2);
        break;
    case 3:
        addExp = isWin(30, 3);
        break;
    default:
        break;
    }

    // 累积经验到玩家身上
    player->exp += addExp;
    player->level = player->exp / 10;

    if (addExp == 0)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

// 判断游戏是否胜利
int isWin(int winRate, int diff)
{
    int random = rand() % 100 + 1; // 1 ~ 100
    if (random <= winRate)
    {
        return diff * 10;
    }
    else
    {
        return 0;
    }
}

// 查看玩家信息
void PRINT_GAME_COMPANY1(void *p)
{
    struct Player *player = p;
    printf("玩家<%s> ------ 当前等级：<%d>级 ----- 当前经验： <%d> \n", player->name, player->level, player->exp);
}

// 离开游戏
void EXIT_GAME_COMPANY1(void *player)
{
    if (player == NULL)
    {
        return;
    }

    free(player);
    player = NULL;
}
```

`main.c`

```c
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "gameCompany1.h"
#include <time.h>

// 初始化游戏：参数1，玩家指针；参数2，玩家姓名
typedef void (*INIT_GAME)(void **player, char *name);

// 副本战斗：返回战斗是否胜利：1、代表胜利，0、代表失败。参数1：玩家；参数2：游戏副本难度
typedef int (*FIGHT_GAME)(void *player, int gameDiff);

// 查看玩家信息
typedef void (*PRINT_GAME)(void *player);

// 离开游戏
typedef void (*EXIT_GAME)(void *player);

void playGame(INIT_GAME init, FIGHT_GAME fight, PRINT_GAME printGame, EXIT_GAME exitGame)
{
    // 初始化游戏
    void *player = NULL;
    printf("请输入姓名：\n");
    char userName[64];
    scanf("%s", userName);
    init(&player, userName);

    // 副本难度 变量
    int diff = -1;

    while (1)
    {
        getchar();
        printf("请选择游戏难度：\n");
        printf("1、简单\n");
        printf("2、中等\n");
        printf("3、困难\n");

        scanf("%d", &diff);
        getchar(); // 取走换行符

        // 战斗
        int ret = fight(player, diff);
        if (ret == 0)
        {
            printf("游戏失败\n");
            break;
        }
        else
        {
            printf("挑战成功，玩家当前信息如下：\n");
            printGame(player);
        }
    }

    // 关闭游戏
    exitGame(player);
}

int main()
{
    srand((unsigned int)time(NULL));
    playGame(INIT_GAME_COMPANY1, FIGHT_GAME_COMPANY1, PRINT_GAME_COMPANY1, EXIT_GAME_COMPANY1);

    return 0;
}
```

---

## 补充

* 回调函数作业-实现对任意类型数组排序

使用选择排序

![](../photos/part10/%E9%80%89%E6%8B%A9%E6%8E%92%E5%BA%8F%E6%80%9D%E8%B7%AF%E5%9B%9E%E9%A1%BE.png)

```c
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
```

---
