# 文件操作

---

## 概述

### 磁盘文件和设备文件

* 磁盘文件：指一组相关数据的有序集合，通常存储在外部介质(如磁盘)上，使用时才调入内存

* 设备文件：在操作系统中把每一个与主机相连的输入、输出设备看作是一个文件，把它们的输入、输出等同于对磁盘文件的读和写

### 磁盘文件的分类

计算机的存储在物理上是二进制的，所以物理上所有的磁盘文件本质上都是一样的：以字节为单位进行顺序存储

![](../photos/part10/1.png)

从用户或者操作系统使用的角度(逻辑上)把文件分为：

* 文本文件：基于字符编码的文件  
* 二进制文件：基于值编码的文件

### 文本文件和二进制文件

**文本文件**

* 基于字符编码，常见编码有 ASCII、UNICODE 等
* 一般可以使用文本编辑器直接打开
* 数 5678 的以 ASCII 存储形式(ASCII 码)为：00110101 00110110 00110111 00111000

**二进制文件**

* 基于值编码，自己根据具体应用，指定某个值是什么意思
* 把内存中的数据按其在内存中的存储形式原样输出到磁盘上
* 数 5678 的存储形式(二进制码)为：00010110 00101110

---

## 文件的打开和关闭

### 文件指针

在 C 语言中用一个指针变量指向一个文件，这个指针称为文件指针

```c
typedef struct
{
    short level;           // 缓冲区"满"或者"空"的程度
    unsigned flags;        // 文件状态标志
    char fd;               // 文件描述符
    unsigned char hold;    // 如无缓冲区不读取字符
    short bsize;           // 缓冲区的大小
    unsigned char *buffer; // 数据缓冲区的位置
    unsigned ar;           // 指针，当前的指向
    unsigned istemp;       // 临时文件，指示器
    short token;           // 用于有效性的检查
} FILE;
```

![](../photos/part10/%E6%96%87%E4%BB%B6%E6%8C%87%E9%92%88.png)

`FILE` 是系统使用 `typedef` 定义出来的有关文件信息的一种结构体类型，结构中含有文件名、文件状态和文件当前位置等信息

声明 `FILE` 结构体类型的信息包含在头文件 `stdio.h` 中，一般设置一个指向 `FILE` 类型变量的指针变量，然后通过它来引用这些 `FILE` 类型变量。通过文件指针就可对它所指的文件进行各种操作

![](../photos/part10/2.png)

读写文件与 `printf、scanf` 关联

* `printf` -- 屏幕 -- 标准输出
* `scanf` -- 键盘 -- 标准输入
* `perror` -- 屏幕 -- 标准错误

C 语言中有三个特殊的文件指针由系统默认打开，用户无需定义即可直接使用:

* `stdin`：标准输入，默认为当前终端(键盘)，我们使用的 `scanf、getchar` 函数默认从此终端获得数据
* `stdout`：标准输出，默认为当前终端(屏幕)，我们使用的 `printf、puts` 函数默认输出信息到此终端
* `stderr`：标准出错，默认为当前终端(屏幕)，我们使用的 `perror` 函数默认输出信息到此终端

应用程序启动时，自动被打开，程序执行结束时，自动被关闭 ---- 隐式回收

### 文件的打开

任何文件使用之前必须打开

```c
#include <stdio.h>
FILE *fopen(const char *filename, const char *mode);
```

* 功能：打开文件
* 参数：
    * `filename`：需要打开的文件名，根据需要加上路径
	* `mode`：打开文件的模式设置
* 返回值：
    * 成功：文件指针
    * 失败：`NULL`

**第一个参数的几种形式**:

```c
FILE *fp_passwd = NULL;
 
// 相对路径：
// 打开当前目录 passdw 文件：源文件(源程序)所在目录
FILE *fp_passwd = fopen("passwd.txt", "r");
	
// 打开当前目录(test)下 passwd.txt 文件
fp_passwd = fopen("./test/passwd.txt", "r");
	
// 打开当前目录上一级目录(相对当前目录) passwd.txt 文件
fp_passwd = fopen("../passwd.txt", "r");
		
// 绝对路径：
// 打开 C 盘 test 目录下一个叫 passwd.txt 文件
fp_passwd = fopen("c:/test/passwd.txt", "r");
```

**第二个参数的几种形式(打开文件的方式)**:

| 打开模式 | 含义 |
|:----:|:----:|
| `r` 或 `rb` | 以只读方式打开一个文本文件(不创建文件，若文件不存在则报错) |
| `w` 或 `wb` | 以写方式打开文件(如果文件存在则清空文件，文件不存在则创建一个文件) |
| `a` 或 `ab` | 以追加方式打开文件，在末尾添加内容，若文件不存在则创建文件 |
| `r+` 或 `rb+` | 以可读、可写的方式打开文件(不创建新文件) |
| `w+` 或 `wb+` | 以可读、可写的方式打开文件(如果文件存在则清空文件，文件不存在则创建一个文件) |
| `a+` 或 `ab+` | 以添加方式打开可读、可写的文件。若文件不存在则创建文件；如果文件存在，则写入的数据会被加到文件尾后，即文件原先的内容会被保留 |

**注意**：

* `b` 是二进制模式的意思，`b` 只是在 Windows 有效，在 Linux 用 `r` 和 `rb` 的结果是一样的
* Unix 和 Linux 下所有的文本文件行都是 `\n` 结尾，而 Windows 所有的文本文件行都是 `\r\n` 结尾
* 在 Windows 平台下，以“文本”方式打开文件，不加 `b`：
    * 当读取文件的时候，系统会将所有的 `\r\n` 转换成 `\n`
    * 当写入文件的时候，系统会将 `\n` 转换成 `\r\n` 写入 
    * 以"二进制"方式打开文件，则读写都不会进行这样的转换
* 在 Unix/Linux 平台下，“文本”与“二进制”模式没有区别，`\r\n` 作为两个字符原样输入输出

```c
#include <stdio.h>

int main(void)
{
    FILE *fp = NULL;

    // "\\" 这样的路径形式，只能在 windows 使用
    // "/" 这样的路径形式，windows 和 linux 平台下都可用，建议使用这种
    // 路径可以是相对路径，也可是绝对路径
    fp = fopen("./test", "w");
    // fp = fopen(".\\test", "w");

    if (fp == NULL) // 返回空，说明打开失败
    {
        // perror() 是标准出错打印函数，能打印调用库函数出错原因
        perror("open");
        return -1;
    }

    return 0;
}
```

### 文件的关闭

任何文件在使用后应该关闭：

* 打开的文件会占用内存资源，如果总是打开不关闭，会消耗很多内存
* 一个进程同时打开的文件数是有限制的，超过最大同时打开文件数，再次调用 `fopen` 打开文件会失败
* 如果没有明确的调用 `fclose` 关闭打开的文件，那么程序在退出的时候，操作系统会统一关闭

```c
#include <stdio.h>
int fclose(FILE *stream);
```

* 功能：关闭先前 `fopen()` 打开的文件。此动作让缓冲区的数据写入文件中，并释放系统所提供的文件资源
* 参数：
    * `stream`：文件指针
* 返回值：
    * 成功：0
    * 失败：-1

```c
FILE * fp = NULL;
fp = fopen("abc.txt", "r");
fclose(fp);
```

---

## 文件的顺序读写

### 按照字符读写文件 fgetc、fputc

**写文件**

```c
#include <stdio.h>
int fputc(int ch, FILE *stream);
```

* 功能：将 `ch` 转换为 `unsigned char` 后写入 `stream` 指定的文件中
* 参数：
    * `ch`：需要写入文件的字符
    * `stream`：文件指针
* 返回值：
    * 成功：成功写入文件的字符
    * 失败：返回 -1

```c
#include <stdio.h>
#include <string.h>

int main(void)
{
    FILE *fp = NULL;
    fp = fopen("./test", "w");

    char buf[] = "this is a test for fputc";
    int i = 0;
    int n = strlen(buf);
    for (i = 0; i < n; i++)
    {
        // 往文件 fp 写入字符 buf[i]
        int ch = fputc(buf[i], fp);
        printf("%c", ch);
    }
    printf("\n");

    // this is a test for fputc

    return 0;
}
```

**文件结尾**

在 C 语言中，`EOF` 表示文件结束符(`end of file`)。在 `while` 循环中以 `EOF` 作为文件结束标志，这种以 `EOF` 作为文件结束标志的文件，必须是文本文件。在文本文件中，数据都是以字符的 ASCII 代码值的形式存放。ASCII 代码值的范围是 0~127，不可能出现 -1，因此可以用 `EOF` 作为文件结束标志

```c
#define EOF (-1)
```

当把数据以二进制形式存放到文件中时，就会有 -1 值的出现，因此不能采用 `EOF` 作为二进制文件的结束标志。为解决这一个问题，ANSIC 提供一个 `feof` 函数，用来判断文件是否结束。`feof` 函数既可用以判断二进制文件又可用以判断文本文件

```c
#include <stdio.h>
int feof(FILE *stream);
```

* 功能：检测是否读取到了文件结尾。判断的是最后一次“读操作的内容”，不是当前位置内容(上一个内容)
* 参数：
    * `stream`：文件指针
* 返回值：
    * 非 0 值：已经到文件结尾
    * 0：没有到文件结尾

**读文件**

```c
#include <stdio.h>
int fgetc(FILE *stream);
```

* 功能：从 `stream` 指定的文件中读取一个字符
* 参数：
    * `stream`：文件指针
* 返回值：
    * 成功：返回读取到的字符
	* 失败：-1

```c
#include <stdio.h>
#include <string.h>

int main(void)
{
    FILE *fp = NULL;
    fp = fopen("./test", "wb");

    char buf[] = "this is a test for fputc";
    int i = 0;
    int n = strlen(buf);
    for (i = 0; i < n; i++)
    {
        // 往文件 fp 写入字符 buf[i]
        int ch = fputc(buf[i], fp);
        printf("%c", ch);
    }
    printf("\n");

    fclose(fp);

    int sign = 0;
    char ch;
    FILE *f = NULL;
    f = fopen("./test", "rb");

    if (sign)
    {
        while ((ch = fgetc(f)) != EOF)
        {
            printf("%c", ch);
        }
        printf("\n");
    }
    else
    {
        while (1)
        {
            ch = fgetc(f);

            if (!feof(f))
            {
                printf("%c", ch);
            }
            else
            {
                break;
            }
        }
        printf("\n");
    }
    fclose(f);

    /*
        this is a test for fputc
        this is a test for fputc
    */

    return 0;
}
```

### 按照行读写文件 fgets、fputs

**写文件**

```c
#include <stdio.h>
int fputs(const char *str, FILE *stream);
```

* 功能：将 `str` 所指定的字符串写入到 `stream` 指定的文件中，字符串结束符 `\0` 不写入文件
* 参数：
    * `str`：字符串
    * `stream`：文件指针
* 返回值：
    * 成功：1
    * 失败：-1

```c
#include <stdio.h>
#include <string.h>

int main(void)
{
    FILE *fp = NULL;
    fp = fopen("./test", "wb");

    char *buf[] = {"123456\n", "bbbbbbbbbb\n", "ccccccccccc\n"};
    int i = 0;
    int n = 3;
    for (i = 0; i < n; i++)
    {
        int len = fputs(buf[i], fp);
        printf("len = %d\n", len);
    }

    /*
        len = 1
        len = 1
        len = 1
    */

    return 0;
}
```

**读文件**

```c
#include <stdio.h>
char * fgets(char *str, int size, FILE *stream);
```

* 功能：从 `stream` 指定的文件内读入字符，保存到 `str` 所指定的内存空间，直到出现换行字符、读到文件结尾或是已读了 `size - 1` 个字符为止，最后会自动加上字符 `\0` 作为字符串结束
* 参数：
    * `str`：字符串
	* `size`：指定最大读取字符串的长度 `size - 1`
	* `stream`：文件指针
* 返回值：
    * 成功：成功读取的字符串
    * 读到文件尾或出错：`NULL`

```c
#include <stdio.h>
#include <string.h>

int main(void)
{
    FILE *fp = NULL;
    fp = fopen("./test", "rb");

    char buf[100] = {0};

    while (!feof(fp)) // 文件没有结束
    {
        memset(buf, 0, sizeof(buf));
        char *p = fgets(buf, sizeof(buf), fp);
        if (p != NULL)
        {
            printf("buf = %s", buf);
        }
    }

    /*
        buf = 123456
        buf = bbbbbbbbbb
        buf = ccccccccccc
    */

    return 0;
}
```

**强化训练：文件版四则运算**

有个文件大小不确定，每行内容都是一个四则运算表达式，还没有算出结果，写一个程序，自动算出其结果后修改文件

```c
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *fileName = NULL;

// 获取表达式的值
int getResult(char *expression);

int main(int argc, char *argv[])
{
    if (argc <= 1)
    {
        printf("参数数量不足，请在 ./xxx 后加入文件路径\n");
        return 0;
    }
    fileName = argv[1];

    // 第一次读取文件，获取表达式数目
    int num = 0;
    FILE *f1 = fopen(fileName, "r");
    char buff[100] = {0};

    while (!feof(f1))
    {
        memset(buff, 0, sizeof(buff));
        char *p = fgets(buff, sizeof(buff), f1);
        if (p != NULL)
        {
            num++;
        }
    }
    fclose(f1);
    // printf("%d\n", num);

    char **array = (char **)malloc(sizeof(char *) * num);

    // 第一次读取文件，获取表达式并将计算结果写入到 array 中
    int idx = 0;
    FILE *f2 = fopen(fileName, "r");

    while (!feof(f2))
    {
        memset(buff, 0, sizeof(buff));
        char *p = fgets(buff, sizeof(buff), f2);
        if (p != NULL)
        {
            // printf("%s", p);
            // printf("%d\n", getResult(p));
            // 得到结果，将结果添加到 buff 里面
            char res[50] = {0};
            // 结果字符串
            sprintf(res, "%d", getResult(p));
            char tmp[100] = {0};
            strncpy(tmp, p, strlen(p) - 1);
            strcat(tmp, res);
            strcat(tmp, "\n");

            array[idx] = (char *)malloc(sizeof(char) * 50);
            strcpy(array[idx], tmp);
            printf("%s", array[idx]);
            idx++;
        }
    }

    fclose(f2);

    // 第三次打开文件，写入动态数组中的内容
    FILE *f3 = fopen(fileName, "w");

    for (int i = 0; i < num; i++)
    {
        fputs(array[i], f3);
        free(array[i]);
    }

    free(array);
    fclose(f3);

    /*
     */

    return 0;
}

// 获取表达式的值
int getResult(char *expression)
{
    int res = 0;
    // 确定长度
    int len = strlen(expression);
    // 找四则运算，并确定其位置
    int idx = 0;
    int sign = -1;

    char num1[50] = {0};
    char num2[50] = {0};

    for (int i = 0; i < len - 1; i++)
    {
        if (expression[i] == '+')
        {
            idx = i;
            sign = 1;
        }
        else if (expression[i] == '-')
        {
            idx = i;
            sign = 2;
        }
        else if (expression[i] == '*')
        {
            idx = i;
            sign = 3;
        }
        else if (expression[i] == '/')
        {
            idx = i;
            sign = 4;
        }
        else
        {
            // 暂时未找到运算符
            if (sign == -1)
            {
                num1[i] = expression[i];
            }
            else
            {
                num2[i - idx - 1] = expression[i];
            }
        }
    }

    int n1 = atoi(num1);
    int n2 = atoi(num2);
    switch (sign)
    {
    case 1:
    {
        res = n1 + n2;
        break;
    }
    case 2:
    {
        res = n1 - n2;
        break;
    }
    case 3:
    {
        res = n1 * n2;
        break;
    }
    case 4:
    {
        res = n1 / n2;
        break;
    }
    default:
    {
        break;
    }
    };

    return res;
}
```

结果：

```sh
# cat a.txt
10+51=
10-5=
10*5=
10/5=
# ./calc a.txt
10+51=61
10-5=5
10*5=50
10/5=2
# cat a.txt
10+51=61
10-5=5
10*5=50
10/5=2
# 
```

改进，对表达式的提取与计算写入可以使用 `sscanf` 与 `sprintf`，这样代码可以简化

```c
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *fileName = NULL;
char result[100];

// 获取表达式的值
void getResult(char *expression);

int main(int argc, char *argv[])
{
    if (argc <= 1)
    {
        printf("参数数量不足，请在 ./xxx 后加入文件路径\n");
        return 0;
    }
    fileName = argv[1];

    // 读取文件，获取表达式并将计算结果写入到 array 中
    FILE *f1 = fopen(fileName, "r");
    char array[1024] = {0};
    char buff[100];

    while (!feof(f1))
    {
        memset(buff, 0, sizeof(buff));
        char *p = fgets(buff, sizeof(buff), f1);
        if (p != NULL)
        {
            getResult(p);
            strcat(array, result);
            printf("%s", result);
        }
    }
    fclose(f1);

    // 打开文件，写入动态数组中的内容
    FILE *f2 = fopen(fileName, "w");
    fputs(array, f2);
    fclose(f2);

    /*
     */

    return 0;
}

// 获取表达式的值
void getResult(char *expression)
{
    memset(result, 0, sizeof(result));
    int num1, num2;
    char ch;
    int res = 0;

    sscanf(expression, "%d%c%d=\n", &num1, &ch, &num2);

    if (ch == '+')
    {
        res = num1 + num2;
    }
    else if (ch == '-')
    {
        res = num1 - num2;
    }
    else if (ch == '*')
    {
        res = num1 * num2;
    }
    else
    {
        res = num1 / num2;
    }

    sprintf(result, "%d%c%d=%d\n", num1, ch, num2, res);
}
```

### 按照格式化文件 fprintf、fscanf

**写文件**

```c
#include <stdio.h>
int fprintf(FILE *stream, const char *format, ...);
```

* 功能：根据参数 `format` 字符串来转换并格式化数据，然后将结果输出到 `stream` 指定的文件中，指定出现字符串结束符 `\0` 为止
* 参数：
    * `stream`：已经打开的文件
	* `format`：字符串格式，用法和 `printf()` 一样
* 返回值：
    * 成功：实际写入文件的字符个数
    * 失败：-1

```c
fprintf(fp, "%d %d %d\n", 1, 2, 3);
```

**读文件**

```c
#include <stdio.h>
int fscanf(FILE *stream, const char *format, ...);
```

* 功能：从 `stream` 指定的文件读取字符串，并根据参数 `format` 字符串来转换并格式化数据
* 参数：
    * `stream`：已经打开的文件
    * `format`：字符串格式，用法和 `scanf()` 一样
* 返回值：
    * 成功：参数数目，成功转换的值的个数
    * 失败：-1

```c
int a = 0;
int b = 0;
int c = 0;
fscanf(fp, "%d %d %d\n", &a, &b, &c);
printf("a = %d, b = %d, c = %d\n", a, b, c);
```

* 边界溢出，存储读取的数据空间在使用之前清空
* `fscanf` 函数，每次在调用时都会判断下一次调用是否匹配参数2，如果不匹配提前结束读文件(`feof(fp)` 为真)

**强化训练：文件版排序**

```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

void write_rand()
{
    FILE *fp = fopen("test.txt", "w");
    if (!fp) // fp == NULL
    {
        perror("fopen error");
        return;
    }
    srand(time(NULL)); // 随机数种子
    for (size_t i = 0; i < 10; i++)
    {
        fprintf(fp, "%d\n", rand() % 100); // 将生成的随机数写入文件
    }

    fclose(fp);
}

void BubbleSort(int *src, int len)
{
    for (int i = 0; i < len - 1; i++)
    {
        for (int j = 0; j < len - 1 - i; j++)
        {
            if (src[j] > src[j + 1])
            {
                int temp = src[j];
                src[j] = src[j + 1];
                src[j + 1] = temp;
            }
        }
    }
}

void read_rand02()
{
    int arr[10], i = 0;

    FILE *fp = fopen("test.txt", "r");
    if (!fp) // fp == NULL
    {
        perror("fopen error");
        return;
    }

    while (1)
    {
        fscanf(fp, "%d\n", &arr[i]); // 从文件中读取一个随机数，存入数组 arr
        i++;
        if (feof(fp)) // 先存储，后判断，防止最后一个元素丢失
            break;
    }
    BubbleSort(arr, sizeof(arr) / sizeof(arr[0])); // 对读取到的乱序数组排序

    fclose(fp);                  // 关闭文件
    fp = fopen("test.txt", "w"); // 重新 w 方式打开文件，清空原未排序文件
    if (!fp)                     // fp == NULL
    {
        perror("fopen error");
        return;
    }
    for (size_t i = 0; i < 10; i++)
        fprintf(fp, "%d\n", arr[i]); // 写排好序的数组到文件

    fclose(fp);
}

int main(void)
{
    write_rand();
    getchar();
    read_rand02();

    // 12

    return EXIT_SUCCESS;
}
```

### 按照块读写文件 fread、fwrite

**写文件**

```c
#include <stdio.h>
size_t fwrite(const void *ptr, size_t size, size_t nmemb, FILE *stream);
```

* 功能：以数据块的方式给文件写入内容
* 参数：
    * `ptr`：准备写入文件数据的地址
    * `size`：`size_t` 为 `unsigned int` 类型，此参数指定写入文件内容的块数据大小
	* `nmemb`：写入文件的块数，写入文件数据总大小为：`size * nmemb`
	* `stream`：已经打开的文件指针
* 返回值：
    * 成功：实际成功写入文件数据的块数目，此值和 `nmemb` 相等
    * 失败：0

```c
#include <stdio.h>
#include <string.h>

int main(void)
{
    FILE *fp = NULL;
    fp = fopen("./test", "w");

    typedef struct Stu
    {
        char name[50];
        int id;
    } Stu;

    Stu s[3];
    int i = 0;
    for (i = 0; i < 3; i++)
    {
        sprintf(s[i].name, "stu%d%d%d", i, i, i);
        s[i].id = i + 1;
    }

    int ret = fwrite(s, sizeof(Stu), 3, fp);
    printf("ret = %d\n", ret);

    /*
        ret = 3
    */

    return 0;
}
```

**读文件**

```c
#include <stdio.h>
size_t fread(void *ptr, size_t size, size_t nmemb, FILE *stream);
```

* 功能：以数据块的方式从文件中读取内容
* 参数：
    * `ptr`：存放读取出来数据的内存空间
	* `size`：`size_t` 为 `unsigned int` 类型，此参数指定读取文件内容的块数据大小
    * `nmemb`：读取文件的块数，读取文件数据总大小为：`size * nmemb`
	* `stream`：已经打开的文件指针
* 返回值：
    * 成功：实际成功读取到内容的块数，如果此值比 `nmemb` 小，但大于 0，说明读到文件的结尾
	* 失败：0。0 表示读到文件结尾 `feof()`

```c
#include <stdio.h>
#include <string.h>

int main(void)
{
    FILE *fp = NULL;
    fp = fopen("./test", "r");

    typedef struct Stu
    {
        char name[50];
        int id;
    } Stu;

    Stu s[3];
    int ret = fread(s, sizeof(Stu), 3, fp);
    printf("ret = %d\n", ret);

    int i = 0;
    for (i = 0; i < 3; i++)
    {
        printf("s = %s, %d\n", s[i].name, s[i].id);
    }

    /*
        ret = 3
        s = stu000, 1
        s = stu111, 2
        s = stu222, 3
    */

    return 0;
}
```

**强化训练：大文件拷贝**

已知一个任意类型的文件，对该文件复制，产生一个相同的新文件

* 打开两个文件， 一个 `r`， 另一 `w` 
* 从 `r` 中 `fread`，`fwrite` 到 `w` 文件中
* 判断到达文件结尾，终止  
* 关闭

注意：在 `windows` 下，打开二进制文件(mp3、mp4、avi、jpg...)时需要使用 `b`。如：`rb`、`wb`

```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

void myfile_cp()
{
    FILE *rfp = fopen("test.txt", "rb");
    FILE *wfp = fopen("test2.txt", "wb");

    char buf[4096] = {0}; // 缓冲区。

    int ret = 0;

    while (1)
    {
        memset(buf, 0, sizeof(buf));
        ret = fread(buf, 1, sizeof(buf), rfp);
        if (ret == 0)
        {
            break;
        }
        printf("ret = %d\n", ret);
        fwrite(buf, 1, ret, wfp);
    }

    fclose(wfp);
    fclose(rfp);
}

int main()
{
    myfile_cp();
    printf("---------------------finish\n");

    /*
        ret = 26
        ---------------------finish
    */

    return EXIT_SUCCESS;
}
```

---

## 文件的随机读写

```c
#include <stdio.h>
int fseek(FILE *stream, long offset, int whence);
```

* 功能：移动文件流(文件光标)的读写位置
* 参数：
    * `stream`：已经打开的文件指针
	* `offset`：根据 `whence` 来移动的位移数(偏移量)，可以是正数，也可以负数，如果正数，则相对于 `whence` 往右移动，如果是负数，则相对于 `whence` 往左移动。如果向前移动的字节数超过了文件开头则出错返回，如果向后移动的字节数超过了文件末尾，再次写入时将增大文件尺寸
    * `whence`：其取值如下：
	    * `SEEK_SET`：从文件开头移动 `offset` 个字节
		* `SEEK_CUR`：从当前位置移动 `offset` 个字节
		* `SEEK_END`：从文件末尾移动 `offset` 个字节
* 返回值：
    * 成功：0
	* 失败：-1

```c
#include <stdio.h>
long ftell(FILE *stream);
```

* 功能：获取文件流(文件光标)的读写位置
* 参数：
    * `stream`：已经打开的文件指针
* 返回值：
    * 成功：从文件当前读写位置到起始位置的偏移量
    * 失败：-1

借助 `ftell(fp) + fseek(fp, 0, SEEK_END);` 来获取文件大小

```c
#include <stdio.h>
void rewind(FILE *stream);
```

* 功能：把文件流(文件光标)的读写位置移动到文件开头
* 参数：
    * `stream`：已经打开的文件指针
* 返回值：
    * 无返回值

```c
#include <stdio.h>
#include <string.h>

int main(void)
{
    FILE *fp = NULL;
    fp = fopen("./test", "r");

    typedef struct Stu
    {
        char name[50];
        int id;
    } Stu;

    // 假如已经往文件写入 3 个结构体
    // fwrite(s, sizeof(Stu), 3, fp);

    Stu s[3];
    Stu tmp;
    int ret = 0;

    // 文件光标读写位置从开头往右移动 2 个结构体的位置
    fseek(fp, 2 * sizeof(Stu), SEEK_SET);

    //读第 3 个结构体
    ret = fread(&tmp, sizeof(Stu), 1, fp);
    if (ret == 1)
    {
        printf("[tmp]%s, %d\n", tmp.name, tmp.id);
    }

    // 把文件光标移动到文件开头
    // fseek(fp, 0, SEEK_SET);
    rewind(fp);

    ret = fread(s, sizeof(Stu), 3, fp);
    printf("ret = %d\n", ret);

    int i = 0;
    for (i = 0; i < 3; i++)
    {
        printf("s === %s, %d\n", s[i].name, s[i].id);
    }

    /*
        [tmp]stu222, 3
        ret = 3
        s === stu000, 1
        s === stu111, 2
        s === stu222, 3
    */

    return 0;
}
```

## Windows 和 Linux 文本文件区别

* `b` 是二进制模式的意思，`b` 只是在 Windows 有效，在 Linux 用 `r` 和 `rb` 的结果是一样的
* Unix 和 Linux 下所有的文本文件行都是 `\n` 结尾，而 Windows 所有的文本文件行都是 `\r\n` 结尾
* 在 Windows 平台下，以“文本”方式打开文件，不加 `b`：
    * 当读取文件的时候，系统会将所有的 `\r\n` 转换成 `\n`
    * 当写入文件的时候，系统会将 `\n` 转换成 `\r\n` 写入 
    * 以"二进制"方式打开文件，则读\写都不会进行这样的转换
* 在 Unix/Linux 平台下，“文本”与“二进制”模式没有区别，`\r\n` 作为两个字符原样输入输出

判断文本文件是 Linux 格式还是 Windows 格式:

```c
#include <stdio.h>

int main(int argc, char **args)
{
    if (argc < 2)
        return 0;

    FILE *p = fopen(args[1], "rb");
    if (!p)
        return 0;

    char a[1024] = {0};
    fgets(a, sizeof(a), p);

    int len = 0;
    while (a[len])
    {
        if (a[len] == '\n')
        {
            if (a[len - 1] == '\r')
            {
                printf("windows file\n");
            }
            else
            {
                printf("linux file\n");
            }
        }
        len++;
    }

    fclose(p);

    return 0;
}
```

---

## 获取文件状态

```c
#include <sys/types.h>
#include <sys/stat.h>
int stat(const char *path, struct stat *buf);
```

* 功能：获取文件状态信息，对于系统而言，系统资源消耗较大
* 参数：
    * `path`：文件名
    * `buf`：保存文件信息的结构体
* 返回值：
    * 成功：0
    * 失败：-1

```c
struct stat
{
    dev_t st_dev;             // 文件的设备编号
    ino_t st_ino;             // 节点
    mode_t st_mode;           // 文件的类型和存取的权限
    nlink_t st_nlink;         // 连到该文件的硬连接数目，刚建立的文件值为1
    uid_t st_uid;             // 用户 ID
    gid_t st_gid;             // 组 ID
    dev_t st_rdev;            // (设备类型)若此文件为设备文件，则为其设备编号
    off_t st_size;            // 文件字节数(文件大小)
    unsigned long st_blksize; // 块大小(文件系统的I/O 缓冲区大小)
    unsigned long st_blocks;  // 块数
    time_t st_atime;          // 最后一次访问时间
    time_t st_mtime;          // 最后一次修改时间
    time_t st_ctime;          // 最后一次改变时间(指属性)
};
```

```c
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>

int main(int argc, char **args)
{
    if (argc < 2)
        return 0;

    struct stat st = {0};

    stat(args[1], &st);
    int size = st.st_size; // 得到结构体中的成员变量
    printf("%d\n", size);

    return 0;
}
```

---

## 删除文件、重命名文件名

```c
#include <stdio.h>
int remove(const char *pathname);
```

* 功能：删除文件
* 参数：
    * `pathname`：文件名
* 返回值：
    * 成功：0
    * 失败：-1
 
```c
#include <stdio.h>
int rename(const char *oldpath, const char *newpath);
```

* 功能：把 `oldpath` 的文件名改为 `newpath`
* 参数：
    * `oldpath`：旧文件名
    * `newpath`：新文件名
* 返回值：
    * 成功：0
    * 失败：-1

---

## 文件缓冲区

![](../photos/part10/%E6%96%87%E4%BB%B6%E7%BC%93%E5%86%B2.png)

### 文件缓冲区

ANSIC 标准采用“缓冲文件系统”处理数据文件

所谓缓冲文件系统是指系统自动地在内存区为程序中每一个正在使用的文件开辟一个文件缓冲区从内存向磁盘输出数据必须先送到内存中的缓冲区，装满缓冲区后才一起送到磁盘去

如果从磁盘向计算机读入数据，则一次从磁盘文件将一批数据输入到内存缓冲区(充满缓冲区)，然后再从缓冲区逐个地将数据送到程序数据区(给程序变量)

### 磁盘文件的存取

![](../photos/part10/3.png)

* 磁盘文件，一般保存在硬盘、U 盘等掉电不丢失的磁盘设备中，在需要时调入内存
* 在内存中对文件进行编辑处理后，保存到磁盘中
* 程序与磁盘之间交互，不是立即完成，系统或程序可根据需要设置缓冲区，以提高存取效率

### 更新缓冲区

缓冲区刷新：

* 标准输出 -- `stdout` -- 标准输出缓冲区。写给屏幕的数据，都是先存缓冲区中，由缓冲区一次性刷新到物理设备(屏幕)
* 标准输入 -- `stdin` -- 标准输入缓冲区。从键盘读取的数据，直接读到缓冲区中，由缓冲区给程序提供数据
* 预读入、缓输出
* 行缓冲：`printf();` 遇到 `\n` 就会将缓冲区中的数据刷新到物理设备上
* 全缓冲：文件。缓冲区存满，数据刷新到物理设备上
* 无缓冲：`perror`。缓冲区中只要有数据，就立即刷新到物理设备
* 文件关闭时，缓冲区会被自动刷新。隐式回收：关闭文件、刷新缓冲区、释放 `malloc`

```c
#include <stdio.h>
int fflush(FILE *stream);
```

* 功能：更新缓冲区，让缓冲区的数据立马写到文件中
* 参数：
    * `stream`：文件指针
* 返回值：
    * 成功：0
    * 失败：-1

---
