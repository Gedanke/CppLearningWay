# 贪吃蛇小游戏

* 定义蛇对象、食物对象
* 初始化蛇、初始化食物
* 控制流程：
    * 蛇头和墙壁的碰撞
    * 蛇头和蛇身体的碰撞
    * 蛇头和食物的碰撞
        * 蛇身增长
        * 食物消失 -- 新食物产生
		* 分数累加
        * 移动速度增大
    * 蛇的移动
		* 自动移动
		* 手动控制移动：ASWD --- 左下上右
    * 显示分数
		* 排行榜 
* 图形界面

---

## 具体流程

定义蛇对象:

```c
struct BODY {
	int x;
	int Y;
};

struct SNAKE {
	struct BODY body[20*60];	// 蛇身 。 body[0] -- 蛇头
    int size;			// 蛇的大小
}snake;
```
	
食物对象：

```c
struct FOOD {
	int X;
	int Y;
}food;
```

分数： 

```c
int score;
```

初始化蛇：

* 封装一个函数 完成蛇的初始：

```c
void initSnake(void)
{
	snake.size = 2;

	snake.body[0].X = WIDE/2;		// 初始化好了蛇头
	snake.body[0].Y = HiGH/2;

	snake.body[1].X = WIDE/2 - 1;		// 初始化一节蛇身
	snake.body[1].Y = HIGH/2;
}
```

初始化食物：

```c
void initFood(void)
{	
	food.X = rand() % WIDE;  // 0-59
	food.Y = rand() % HIGH;  // 0-59

	return;
}
```

修改控制台光标位置：

```c
#include <conio.h> 
#include <Windows.h>

COORD coord;		// COORD  --> 结构体， 有两个成员变量：x，y 坐标

coord.X = snake.body[0].X;
coord.Y = snake.body[0].Y;

setConsoleCursorPositon(GetStdHandle(STD_OUTPUT_HANDLE), coord);
```

会将光标位置，定位到 初始化好的蛇头位置(`WIDE/2, HIGH/2`)。屏幕中间 

画出蛇和食物：封装函数，`initUI()`

```c
initUI(){
   	COORD coord = {0};					// 光标移动的位置。

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

	// 画食物
	coord.X = food.X;
	coord.Y = food.Y;

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);

	putchar('#');

}
```

蛇的移动控制：

* W：(0, -1) --> 影响蛇头
* S: (0, +1)
* A: (-1, 0)
* D: (+1, 0)

不回显：

* `getch()`	接收用户输入
* `char key = getch();`	编译时出错，尝试使用 `_getch();`

不阻塞：

* `kbhit();` 不阻塞判断用户输入。有用户输入，返回“真”，否则返回“假”值。编译时出错，尝试使用 `_kbhit();`

开始游戏：

```c
void playGame（void）
{
	char key = 'd'; // 默认蛇向右移动

	// 蛇头和墙壁的碰撞：

	while ( 判断是否撞墙 ) {

		// 重画蛇身 intiUI

		// 接收用户键盘输入。
		// 在全局 添加：kx， ky --》 根据 asdw 按键得不同坐标，影响蛇头

		// 蛇头和身体的碰撞

		// 蛇与食物的碰撞
			
		// 蛇身体移动 ： 前一节给后一节赋值，蛇头收 kx ky 的影响。

		system("cls");  清屏 -- 去除蛇尾。
	}
}
```

蛇头和墙壁的碰撞：

```c
snake.body[0].X > 0 && snake.body[0].X < WIDE 
&&
snake.body[0].Y > 0 && snake.body[0].Y < HIGH
```

蛇头和身体的碰撞：蛇头的坐标和任意一节身体的坐标完全一致

```c
for (i = 1; i < snake.size; i++)
{
	if (snake.body[0].X == snake.body[i].X && snake.body[0].Y == snake.body[i].Y )
	{
		// 终止游戏
		return ;
	}
}
```
	
蛇头和食物的碰撞：

```c
if (snake.body[0].X == food.X && snake.body[0].Y == food.Y)
{
	// 蛇身增长： snake.size++;
	// 食物消失：（产生一个新食物）initFood（）

	// 加分：score += 10;

	//加速：sleepSecond -= 20;
}
```

蛇移动：前一节身体给后一节身体赋值。 蛇头按照 `aswd` 换算的坐标值进行变换。`

```c
for (size_t i = snake.size-1; i > 0; i--)
{
	snake.body[i].X = snake.body[i - 1].X;
	snake.body[i].Y = snake.body[i - 1].Y;
}
snake.body[0].X += kx;		// 蛇头坐标根据用户按键，修改。
snake.body[0].Y += ky;
```

画墙：

```c
void initWall(void)
{
	for (size_t i = 0; i <= HIGH; i++)	// 多行
	{
		for (size_t j = 0; j <= WIDE; j++)			// 一行中的多列
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
```

去除蛇尾：蛇移动之前保存蛇尾坐标

定义全局变量：`lastX, lastY;`

```c
lastX = snake.body[snake.size-1].X ;

lastY = snake.body[snake.size-1].Y ;
```

在 `initUI` 中，将蛇尾替换为 ' '

```c
coord.X = lastX;
coord.Y = lastY;

setConsoleCursorPosition(GetSTDHandler(STD_OUTPUT_HANDLE), coord);

putchar(' ');
```

去除光标：

```c
typedef struct _CONSOLE_CURSOR_INFO {
	DWORD  dwSize;		// 大小
    BOOL   bVisible;	// 是否可见。
} CONSOLE_CURSOR_INFO;
```

定义结构体变量：

```c
CONSOLE_CURSOR_INFO  cci;

cci.dwSize = sizeof(cci);

cci.bVisible = FALSE; //  0 假 --- 不可见
```

设置光标不可见生效：

```c
setConsoleCursorInfo(GetSTDHandler(STD_OUTPUT_HANDLE), &cci);
```

在 `main` 函数中，调用一次即可生效
	
显示分数

`playGame` 调用结束时，打印全局 `score` 值

加速：

全局定义变量：

```c
sleepSecond = 400;
Sleep(sleepSecond);

// 成功吃食物
sleepSecond -= 20;
```

---
		