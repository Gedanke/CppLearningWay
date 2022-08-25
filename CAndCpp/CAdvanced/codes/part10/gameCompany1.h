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