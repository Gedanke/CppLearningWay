#ifndef __SNAKE_H__
#define __SNAKE_H__

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <conio.h>
#include <Windows.h>

#define HIGH 20
#define WIDE 60

// 身体对象
struct Body
{
    int x;
    int y;
};

// 蛇对象
struct Snake
{
    struct Body body[HIGH * WIDE];
    int size;
} snake;

// 食物对象
struct Food
{
    int x;
    int y;
} food;

// 得分
int score = 0;

// 用户键盘输入 wasd 之一的坐标
int kx = 0;
int ky = 0;

// 蛇尾坐标
int lastX = 0;
int lastY = 0;

// 移动时间间隔
int sleepTime = 400;

// 相关函数
void initSnake();
void initFood();
void initUI();
void playGame();
void initWall();
void showScore();

#endif
