# 原理篇

---

## 在 main 执行之前和之后执行的代码可能是什么

* `main` 函数执行之前，主要就是初始化系统相关资源：

* 设置栈指针
* 初始化静态 `static` 变量和 `global` 全局变量，即 `.data` 段的内容
* 将未初始化部分的全局变量赋初值：数值型 `short`，`int`，`long` 等为 0，`bool` 为 `FALSE`，指针为 `NULL` 等等，即 `.bss` 段的内容
* 全局对象初始化，在 `main` 之前调用构造函数，这是可能会执行前的一些代码
* 将 `main` 函数的参数 `argc`，`argv` 等传递给 `main` 函数，然后才真正运行 `main` 函数
* `__attribute__((constructor))`

* `main` 函数执行之后：

* 全局对象的析构函数会在 `main` 函数之后执行
* 可以用 `atexit` 注册一个函数，它会在 `main` 之后执行
* `__attribute__((destructor))`

---

## 结构体内存对齐问题

* 结构体内成员按照声明顺序存储，第一个成员地址和整个结构体地址相同
* 未特殊说明时，按结构体中 `size` 最大的成员对齐(若有 `double` 成员，按 8 字节对齐)

C++11 以后引入两个关键字 `alignas`(opens new window) 与 `alignof`(opens new window)。其中 `alignof` 可以计算出类型的对齐方式，`alignas` 可以指定结构体的对齐方式

但是 `alignas` 在某些情况下是不能使用的，具体见下面的例子:

```cpp
#include <iostream>

using namespace std;

// alignas 生效的情况
struct Info
{
    uint8_t a;
    uint16_t b; // 2 字节
    uint8_t c;
};

struct alignas(4) Info2
{
    uint8_t a;
    uint16_t b;
    uint8_t c;
};

int main()
{
    cout << sizeof(Info) << endl;
    cout << alignof(Info) << endl;
    cout << sizeof(Info2) << endl;
    cout << alignof(Info2) << endl;

    /*
        6
        2
        8
        4
    */

    return 0;
}
```

`alignas` 将内存对齐调整为 4 个字节。所以 `sizeof(Info2)` 的值变为了 8

```cpp
#include <iostream>

using namespace std;

// alignas 失效的情况
struct Info
{
    uint8_t a;
    uint32_t b;
    uint8_t c;
};

struct alignas(2) Info2
{
    uint8_t a;
    uint32_t b;
    uint8_t c;
};

int main()
{
    cout << sizeof(Info) << endl;
    cout << alignof(Info) << endl;
    cout << sizeof(Info2) << endl;
    cout << alignof(Info2) << endl;

    /*
        12
        4
        12
        4
    */

    return 0;
}
```

若 `alignas` 小于自然对齐的最小单位，则被忽略

如果想使用单字节对齐的方式，使用 `alignas` 是无效的。应该使用 `#pragma pack(push, 1)` 或者使用 `__attribute__((packed))`

```cpp
#include <iostream>

using namespace std;

#if defined(__GNUC__) || defined(__GNUG__)
#define ONEBYTE_ALIGN __attribute__((packed))
#elif defined(_MSC_VER)
#define ONEBYTE_ALIGN
#pragma pack(push, 1)
#endif

struct Info
{
    uint8_t a;
    uint32_t b;
    uint8_t c;
} ONEBYTE_ALIGN;

#if defined(__GNUC__) || defined(__GNUG__)
#undef ONEBYTE_ALIGN
#elif defined(_MSC_VER)
#pragma pack(pop)
#undef ONEBYTE_ALIGN
#endif

int main()
{
    cout << sizeof(Info) << endl;  // 6 1 + 4 + 1
    cout << alignof(Info) << endl; // 1

    /*
        6
        1
    */

    return 0;
}
```

确定结构体中每个元素大小可以通过下面这种方法:

```cpp
#include <iostream>

using namespace std;

#if defined(__GNUC__) || defined(__GNUG__)
#define ONEBYTE_ALIGN __attribute__((packed))
#elif defined(_MSC_VER)
#define ONEBYTE_ALIGN
#pragma pack(push, 1)
#endif

/**
 * 0 1   3     6   8 9            15
 * +-+---+-----+---+-+-------------+
 * | |   |     |   | |             |
 * |a| b |  c  | d |e|     pad     |
 * | |   |     |   | |             |
 * +-+---+-----+---+-+-------------+
 */

struct Info
{
    uint16_t a : 1;
    uint16_t b : 2;
    uint16_t c : 3;
    uint16_t d : 2;
    uint16_t e : 1;
    uint16_t pad : 7;
} ONEBYTE_ALIGN;

#if defined(__GNUC__) || defined(__GNUG__)
#undef ONEBYTE_ALIGN
#elif defined(_MSC_VER)
#pragma pack(pop)
#undef ONEBYTE_ALIGN
#endif

int main()
{
    cout << sizeof(Info) << endl;  // 2
    cout << alignof(Info) << endl; // 1

    /*
        2
        1
    */

    return 0;
}
```

这种处理方式是 `alignas` 处理不了的

---

## 在传递函数参数时，什么时候该使用指针，什么时候该使用引用呢

* 需要返回函数内局部变量的内存的时候用指针。使用指针传参需要开辟内存，用完要记得释放指针，不然会内存泄漏。而返回局部变量的引用是没有意义的
* 对栈空间大小比较敏感(比如递归)的时候使用引用。使用引用传递不需要创建临时变量，开销要更小
* 类对象作为参数传递的时候使用引用，这是 C++ 类对象传递的标准方式

---

## C++ 的顶层 const 和底层 const

**概念区分**

* 顶层 `const`：指的是 `const` 修饰的变量本身是一个常量，无法修改，指的是指针，就是 `*` 的右边
* 底层 `const`：指的是 `const` 修饰的变量所指向的对象是一个常量，指的是所指变量，就是 `*` 的左边

**举个例子**

```cpp
int a = 10;int* const b1 = &a;        //顶层 const，b1 本身是一个常量
const int* b2 = &a;       // 底层 const，b2 本身可变，所指的对象是常量
const int b3 = 20; 		   // 顶层 const，b3 是常量不可变
const int* const b4 = &a;  // 前一个 const 为底层，后一个为顶层，b4 不可变
const int& b5 = a;		   // 用于声明引用变量，都是底层 const
```

**区分作用**

* 执行对象拷贝时有限制，常量的底层 `const` 不能赋值给非常量的底层 `const`
* 使用命名的强制类型转换函数 `const_cast` 时，只能改变运算对象的底层 `const`

```cpp
const int a;int const a;const int *a;int *const a;
```

* `int const a` 和 `const int a` 均表示定义常量类型 `a`
* `const int *a`，其中 `a` 为指向 `int` 型变量的指针，`const` 在 `*` 左侧，表示 `a` 指向不可变常量(看成 `const (*a)`，对引用加 `const`)
* `int *const a`，依旧是指针类型，表示 `a` 为指向整型数据的常指针(看成 `const(a)`，对指针 `const`)

---

## 拷贝初始化和直接初始化

* 当用于类类型对象时，初始化的拷贝形式和直接形式有所不同：直接初始化直接调用与实参匹配的构造函数，拷贝初始化总是调用拷贝构造函数。拷贝初始化首先使用指定构造函数创建一个临时对象，然后用拷贝构造函数将那个临时对象拷贝到正在创建的对象。举例如下

```cpp
string str1("I am a string"); // 语句 1 直接初始化
string str2(str1); // 语句 2 直接初始化，str1 是已经存在的对象，直接调用拷贝构造函数对 str2 进行初始化
string str3 = "I am a string"; //语句 3 拷贝初始化，先为字符 "I am a string" 创建临时对象，再把临时对象作为参数，使用拷贝构造函数构造 str3
string str4 = str1; //语句4 拷贝初始化，这里相当于隐式调用拷贝构造函数，而不是调用赋值运算符函数
```

* 为了提高效率，允许编译器跳过创建临时对象这一步，直接调用构造函数构造要创建的对象，这样就完全等价于直接初始化了(语句1 和语句3 等价)，但是需要辨别两种情况
    * 当拷贝构造函数为 `private` 时：语句3 和语句4 在编译时会报错
    * 使用 `explicit` 修饰构造函数时：如果构造函数存在隐式转换，编译时会报错



---
