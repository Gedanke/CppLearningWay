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