#include "snake.h"

int main()
{
    // 去除光标
    CONSOLE_CURSOR_INFO cci;
    cci.dwSize = sizeof(cci);
    cci.bVisible = FALSE;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cci);

    srand(time(NULL));

    // 初始化蛇
    initSnake();
    // 初始化食物
    initFood();
    // 画墙
    initWall();
    // 画蛇和食物
    initUI();
    // 启动游戏
    playGame();
    // 打印分数
    showScore();

    system("pause");

    return 0;
}

// 初始化蛇
void initSnake()
{
    snake.size = 2;

    // 蛇头
    snake.body[0].x = WIDE / 2;
    snake.body[0].y = HIGH / 2;

    // 一节蛇身
    snake.body[1].x = WIDE / 2 - 1;
    snake.body[1].y = HIGH / 2;

    return;
}

// 初始化食物
void initFood()
{
    food.x = rand() % WIDE;
    food.y = rand() % HIGH;
}

// 画墙
void initWall()
{
    for (int i = 0; i <= HIGH; i++)
    {
        for (int j = 0; j <= WIDE; j++)
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

// 画蛇和食物
void initUI()
{
    // 光标移动位置
    COORD coord = {0};

    // 画蛇
    for (size_t i = 0; i < snake.size; i++)
    {
        coord.X = snake.body[i].x;
        coord.Y = snake.body[i].y;
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
    coord.X = food.x;
    coord.Y = food.y;

    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
    putchar('#');
}

// 启动游戏
void playGame()
{
    char key = 'd';

    // 判断蛇撞墙
    while (snake.body[0].x >= 0 && snake.body[0].x < WIDE && snake.body[0].y >= 0 && snake.body[0].y < HIGH)
    {
        // 更新蛇
        initUI();

        // 接收用户按键输入 asdw
        if (_kbhit())
        {
            // 为真时，说明用户按下按键
            key = _getch();
        }

        switch (key)
        {
        case 'w':
        {
            kx = 0;
            ky = -1;
            break;
        }
        case 's':
        {
            kx = 0;
            ky = +1;
            break;
        }
        case 'd':
        {
            kx = +1;
            ky = 0;
            break;
        }
        case 'a':
        {
            kx = -1;
            ky = 0;
            break;
        }
        default:
        {
            break;
        }
        }

        // 蛇头撞身体：蛇头 == 任意一节身体
        for (size_t i = 1; i < snake.size; i++)
        {
            if (snake.body[0].x == snake.body[i].x && snake.body[0].y == snake.body[i].y)
            {
                // 游戏结束
                return;
            }
        }

        // 蛇头撞食物
        if (snake.body[0].x == food.x && snake.body[0].y == food.y)
        {
            // 食物消失
            initFood();
            // 身体增长
            snake.size++;
            // 加分
            score += 10;
            // 加速
            sleepTime -= 10;
        }

        // 存储蛇尾坐标
        lastX = snake.body[snake.size - 1].x;
        lastY = snake.body[snake.size - 1].y;

        // 蛇移动，前一节身体给后一节身体赋值
        for (size_t i = snake.size - 1; i > 0; i--)
        {
            snake.body[i].x = snake.body[i - 1].x;
            snake.body[i].y = snake.body[i - 1].y;
        }
        // 蛇头坐标根据用户按键，修改
        snake.body[0].x += kx;
        snake.body[0].y += ky;

        Sleep(sleepTime);
        // 清屏
        // system("cls");
    }
}

// 打印分数
void showScore()
{
    // 将光标默认位置移动至不干扰游戏的任意位置
    COORD coord;

    coord.X = 0;
    coord.Y = HIGH + 2;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);

    printf("Game Over!!!\n");
    printf("Score: %d\n\n\n", score);
}
