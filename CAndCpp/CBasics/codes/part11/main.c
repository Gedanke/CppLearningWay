#define _CRT_SECURE_NO_WARNINGS

#include "snake.h" // 引入自定义头文件

int main(void)
{
    // 去除光标。
    CONSOLE_CURSOR_INFO cci;
    cci.dwSize = sizeof(cci);
    cci.bVisible = FALSE; // TRUE :
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cci);

    srand(time(NULL)); // 播种随机数种子。

    initSnake(); // 初始化蛇
    initFood();  // 初始化食物

    initWall(); // 画墙
    initUI();   // 画蛇和食物

    playGame(); // 启动游戏

    showScore(); // 打印分数

    system("pause");
    return EXIT_SUCCESS;
}

void showScore(void)
{
    // 将光标默认位置移动至 不干扰游戏的任意位置。
    COORD coord;

    coord.X = 0;
    coord.Y = HIGH + 2;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);

    printf("Game Over!!!\n");
    printf("成绩为：%d\n\n\n", score);
}

void initWall(void)
{
    for (size_t i = 0; i <= HIGH; i++) // 多行
    {
        for (size_t j = 0; j <= WIDE; j++) // 一行中的多列
        {
            if (j == WIDE)
            {
                printf("|");
            }
            else if (i == HIGH)
            {
                printf("_");
            }
            else
            {
                printf(" ");
            }
        }
        printf("\n");
    }
}

void playGame(void)
{
    char key = 'd';

    // 判断蛇撞墙
    while (snake.body[0].X >= 0 && snake.body[0].X < WIDE && snake.body[0].Y >= 0 && snake.body[0].Y < HIGH)
    {
        // 更新蛇
        initUI();

        // 接收用户按键输入  asdw
        if (_kbhit())
        { // 为真时，说明用户按下按键。
            key = _getch();
        }
        switch (key)
        {
        case 'w':
            kx = 0;
            ky = -1;
            break;
        case 's':
            kx = 0;
            ky = +1;
            break;
        case 'd':
            kx = +1;
            ky = 0;
            break;
        case 'a':
            kx = -1;
            ky = 0;
            break;
        default:
            break;
        }

        // 蛇头撞身体： 蛇头 == 任意一节身体
        for (size_t i = 1; i < snake.size; i++)
        {
            if (snake.body[0].X == snake.body[i].X && snake.body[0].Y == snake.body[i].Y)
            {
                return; // 游戏结束。
            }
        }

        // 蛇头撞食物
        if (snake.body[0].X == food.X && snake.body[0].Y == food.Y)
        {
            initFood();   // 食物消失
            snake.size++; // 身体增长
            score += 10;  // 加分

            sleepSecond -= 100; // 加速
        }

        // 存储蛇尾坐标
        lastX = snake.body[snake.size - 1].X;
        lastY = snake.body[snake.size - 1].Y;

        // 蛇移动，前一节身体给后一节身体赋值。
        for (size_t i = snake.size - 1; i > 0; i--)
        {
            snake.body[i].X = snake.body[i - 1].X;
            snake.body[i].Y = snake.body[i - 1].Y;
        }
        snake.body[0].X += kx; // 蛇头坐标根据用户按键，修改。
        snake.body[0].Y += ky;

        Sleep(sleepSecond);
        // 清屏
        // system("cls");
    }

    return;
}

// 定义初始化蛇函数
void initSnake(void)
{
    snake.size = 2;

    snake.body[0].X = WIDE / 2; //蛇头初始化
    snake.body[0].Y = HIGH / 2;

    snake.body[1].X = WIDE / 2 - 1; // 蛇一节身体初始化
    snake.body[1].Y = HIGH / 2;

    return;
}

// 初始化界面控件
void initUI(void)
{
    COORD coord = {0}; // 光标移动的位置。

    // 画蛇
    for (size_t i = 0; i < snake.size; i++)
    {
        coord.X = snake.body[i].X;
        coord.Y = snake.body[i].Y;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);

        if (i == 0)
            putchar('@');
        else
            putchar('*');
    }
    // 去除蛇尾
    coord.X = lastX;
    coord.Y = lastY;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
    putchar(' ');

    // 画食物
    coord.X = food.X;
    coord.Y = food.Y;

    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
    putchar('#');
}

// 食物的初始化函数
void initFood(void)
{
    food.X = rand() % WIDE; // 0-59
    food.Y = rand() % HIGH; // 0-59
    return;
}
