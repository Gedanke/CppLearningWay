# 程序流程结构

---

## 概述

C 语言支持最基本的三种程序运行结构：顺序结构、选择结构、循环结构

* 顺序结构：程序按顺序执行，不发生跳转
* 选择结构：依据是否满足条件，有选择的执行相应功能
* 循环结构：依据条件是否满足，循环多次执行某段代码

---

## 选择结构

### if 语句

![](../photos/part4/1.png)

```c
#include <stdio.h>

int main()
{
    int a = 1;
    int b = 2;

    if (a > b)
    {
        printf("%d\n", a);
    }

    return 0;
}
```

### if ... else 语句

![](../photos/part4/2.png)

```c
#include <stdio.h>

int main()
{
    int a = 1;
    int b = 2;

    if (a > b)
    {
        printf("%d\n", a);
    }
    else
    {
        printf("%d\n", b);
    }

    // 2

    return 0;
}
```

### if ... else if ... else 语句

![](../photos/part4/3.png)

```c
#include <stdio.h>

int main()
{
    unsigned int a;
    scanf("%u", &a);

    if (a < 10)
    {
        printf("个位\n");
    }
    else if (a < 100)
    {
        printf("十位\n");
    }
    else if (a < 1000)
    {
        printf("百位\n");
    }
    else
    {
        printf("很大\n");
    }

    /*
        1024
        很大
    */

    return 0;
}
```

### 三目运算符

```c
#include <stdio.h>

int main()
{
    int a = 10;
    int b = 20;
    int c;

    if (a > b)
    {
        c = a;
    }
    else
    {
        c = b;
    }
    printf("c1 = %d\n", c);

    a = 1;
    b = 2;
    c = (a > b ? a : b);
    printf("c2 = %d\n", c);

    /*
        c1 = 20
        c2 = 2
    */

    return 0;
}
```

### switch 语句

```c
#include <stdio.h>

int main()
{
    char c;
    c = getchar();

    switch (c) // 参数只能是整型变量
    {
    case '1':
        printf("Ok\n");
        break; // switch 遇到 break 就中断了
    case '2':
        printf("Not OK\n");
        break;
    default: // 如果上面的条件都不满足，那么执行 default
        printf("Are u ok?\n");
    }

    /*
        3
        Are u ok?
    */

    return 0;
}
```

在一个 `case` 分支中如果，没有 `break`；那么它会向下继续执行下一个 `case` 分支

---

## 循环结构

### while 语句

![](../photos/part4/4.png)

```c
#include <stdio.h>

int main()
{
    int a = 20;
    while (a > 10)
    {
        scanf("%d", &a);
        printf("a = %d\n", a);
    }

    /*
        11
        a = 11
        10
        a = 10
    */

    return 0;
}
```

### do ... while 语句

![](../photos/part4/5.png)

```c
#include <stdio.h>

int main()
{
    int a = 1;
    do
    {
        a++;
        printf("a = %d\n", a);
    } while (a < 5);

    /*
        a = 2
        a = 3
        a = 4
        a = 5
    */

    return 0;
}
```

### for 语句

```c
#include <stdio.h>

int main()
{
    int i;
    int sum = 0;
    for (i = 0; i <= 100; i++)
    {
        sum += i;
    }

    printf("sum = %d\n", sum);

    // sum = 5050

    return 0;
}
```

### 嵌套循环

循环语句之间可以相互嵌套

```c
#include <stdio.h>

int main()
{
    int num = 0;
    int i, j, k;
    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < 2; j++)
        {
            for (k = 0; k < 2; k++)
            {
                printf("hello world\n");
                num++;
            }
        }
    }

    printf("num = %d\n", num);

    /*
        hello world
        hello world
        hello world
        hello world
        hello world
        hello world
        hello world
        hello world
        num = 8
    */

    return 0;
}
```

---

## 跳转语句

### break 语句

在 `switch` 条件语句和循环语句中都可以使用 `break` 语句：

* 当它出现在 `switch` 条件语句中时，作用是终止某个 `case` 并跳出 `switch` 结构
* 当它出现在循环语句中，作用是跳出当前内循环语句，执行后面的代码
* 当它出现在嵌套循环语句中，跳出最近的内循环语句，执行后面的代码

```c
#include <stdio.h>

int main()
{
    int i = 0;
    while (1)
    {
        i++;
        printf("i = %d\n", i);

        if (i == 3)
        {
            break; // 跳出 while 循环
        }
    }

    int flag = 0;
    int m = 0;
    int n = 0;

    for (m = 0; m < 10; m++)
    {
        for (n = 0; n < 10; n++)
        {
            if (n == 5)
            {
                flag = 1;
                break; // 跳出 for (n = 0; n < 10; n++)
            }
        }

        if (flag == 1)
        {
            break; // 跳出 for (m = 0; m < 10; m++)
        }
    }

    /*
        i = 1
        i = 2
        i = 3
    */

    return 0;
}
```

### continue 语句

在循环语句中，如果希望立即终止本次循环，并执行下一次循环，此时就需要使用 `continue` 语句

```c
#include <stdio.h>

int main()
{
    int sum = 0; // 定义变量 sum

    for (int i = 1; i <= 100; i++)
    {
        if (i % 2 == 0) // 如果 i 是一个偶数，执行 if 语句中的代码
        {
            continue; // 结束本次循环
        }
        sum += i; // 实现 sum 和 i 的累加
    }

    printf("sum = %d\n", sum);

    // sum = 2500

    return 0;
}
```

### goto 语句

`goto` 语句可以无条件跳转，但尽量少用

```c
#include <stdio.h>

int main()
{
    goto End; // 无条件跳转到 End 的标识
    printf("aaaaaaaaa\n");

End:
{
    printf("bbbbbbbb\n");
    printf("cccccccc\n");
}
    printf("dddddddd\n");

    /*
        bbbbbbbb
        cccccccc
        dddddddd
    */

    return 0;
}
```

---
