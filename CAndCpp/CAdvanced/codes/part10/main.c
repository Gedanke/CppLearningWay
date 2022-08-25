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