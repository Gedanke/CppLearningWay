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

## extern "C" 的用法

为了能够正确的在 C++ 代码中调用 C 语言的代码：在程序中加上 `extern "C"` 后，相当于告诉编译器这部分代码是 C 语言写的，因此要按照 C 语言进行编译，而不是 C++

哪些情况下使用 `extern "C"`：

* C++ 代码中调用 C 语言代码
* 在 C++ 中的头文件中使用
* 在多个人协同开发时，可能有人擅长 C 语言，而有人擅长 C++

举个例子，C++ 中调用 C 代码：

```cpp
#ifndef __MY_HANDLE_H__
#define __MY_HANDLE_H__

extern "C"
{
    typedef unsigned int result_t;
    typedef void *my_handle_t;

    my_handle_t create_handle(const char *name);
    result_t operate_on_handle(my_handle_t handle);
    void close_handle(my_handle_t handle);
}

#endif
```
   
综上，总结出使用方法，在 C 语言的头文件中，对其外部函数只能指定为 `extern` 类型，C 语言中不支持 `extern "C"` 声明，在 `.c` 文件中包含了 `extern "C"` 时会出现编译语法错误。所以使用 `extern "C"` 全部都放在于 cpp 程序相关文件或其头文件中

总结出如下形式：

* C++ 调用 C 函数

```cpp
// xx.h
extern int add(...)

// xx.c
int add(){
    
}

// xx.cpp
extern "C" {
    #include "xx.h"
}
```

* C 调用 C++ 函数

```cpp
// xx.h
extern "C"{
    int add();
}

// xx.cpp
int add(){    
}

// xx.c
extern int add();
```

---

## 野指针和悬空指针

都是是指向无效内存区域(这里的无效指的是"不安全不可控")的指针，访问行为将会导致未定义行为

* 野指针

野指针，指的是没有被初始化过的指针

```cpp
int main(void) { 
    int* p;     // 未初始化
    std::cout<< *p << std::endl; // 未初始化就被使用
    
    return 0;
}
```
    
因此，为了防止出错，对于指针初始化时都是赋值为 `nullptr`，这样在使用时编译器就会直接报错，产生非法内存访问

* 悬空指针

悬空指针，指针最初指向的内存已经被释放了的一种指针

```cpp
int main(void) { 
    int * p = nullptr;
    int* p2 = new int;
    p = p2;

    delete p2;
    return 0;
}
```
   
此时 `p` 和 `p2` 就是悬空指针，指向的内存已经被释放。继续使用这两个指针，行为不可预料。需要设置为 `p = p2 = nullptr`。此时再使用，编译器会直接保错。避免野指针比较简单，但悬空指针比较麻烦。C++ 引入了智能指针，C++ 智能指针的本质就是避免悬空指针的产生

产生原因及解决办法：

* 野指针：指针变量未及时初始化 => 定义指针变量及时初始化，要么置空
* 悬空指针：指针 `free` 或 `delete` 之后没有及时置空 => 释放操作后立即置空

---

## C 和 C++ 的类型安全

**什么是类型安全**

类型安全很大程度上可以等价于内存安全，类型安全的代码不会试图访问自己没被授权的内存区域。“类型安全”常被用来形容编程语言，其根据在于该门编程语言是否提供保障类型安全的机制；有的时候也用“类型安全”形容某个程序，判别的标准在于该程序是否隐含类型错误

类型安全的编程语言与类型安全的程序之间，没有必然联系。好的程序员可以使用类型不那么安全的语言写出类型相当安全的程序，相反的，差一点儿的程序员可能使用类型相当安全的语言写出类型不太安全的程序。绝对类型安全的编程语言暂时还没有

**C 的类型安全**

C 只在局部上下文中表现出类型安全，比如试图从一种结构体的指针转换成另一种结构体的指针时，编译器将会报告错误，除非使用显式类型转换。然而，C 中相当多的操作是不安全的。以下是两个十分常见的例子：

* `printf` 格式输出

```c
int main()
{
    printf("%d\n", 10);
    printf("%f\n", 10);

    /*
        10
        0.000000
    */

    return 0;
}
```

上述代码中，使用 `%d` 控制整型数字的输出，没有问题，但是改成 `%f` 时，明显输出错误，再改成 `%s` 时，运行直接报 segmentation fault 错误

* `malloc` 函数的返回值

`malloc` 是 C 中进行内存分配的函数，它的返回类型是 `void *` 即空类型指针，常常有这样的用法 `char* pStr = (char*)malloc(100*sizeof(char))`，这里明显做了显式的类型转换

类型匹配尚且没有问题，但是一旦出现 `int* pInt = (int*)malloc(100*sizeof(char))` 就很可能带来一些问题，而这样的转换 C 并不会提示错误

**C++ 的类型安全**

如果 C++ 使用得当，它将远比 C 更有类型安全性。相比于 C 语言，C++ 提供了一些新的机制保障类型安全：

* 操作符 `new` 返回的指针类型严格与对象匹配，而不是 `void*`
* C 中很多以 `void*` 为参数的函数可以改写为 C++ 模板函数，而模板是支持类型检查的
* 引入 `const` 关键字代替 `#define constants`，它是有类型、有作用域的，而 `#define constants` 只是简单的文本替换
* 一些 `#define` 宏可被改写为 `inline` 函数，结合函数的重载，可在类型安全的前提下支持多种类型，当然改写为模板也能保证类型安全
* C++ 提供了 `dynamic_cast` 关键字，使得转换过程更加安全，因为 `dynamic_cast` 比 `static_cast` 涉及更多具体的类型检查

例 1：使用 `void*` 进行类型转换

```cpp
int main()
{
    int i = 5;
    void *pInt = &i;
    double d = (*(double *)pInt);
    cout << d << endl;

    /*
        7.0113e+207
    */

    return 0;
}
```

​例 2：不同类型指针之间转换

```cpp
#include <iostream>
using namespace std;

class Parent
{
};

class Child1 : public Parent
{
public:
    int i;
    Child1(int e) : i(e) {}
};

class Child2 : public Parent
{
public:
    double d;
    Child2(double e) : d(e) {}
};

int main()
{
    Child1 c1(5);
    Child2 c2(4.1);
    Parent *pp;
    Child1 *pc1;

    pp = &c1;
    pc1 = (Child1 *)pp;     // 类型向下转换 强制转换，由于类型仍然为 Child1*，不造成错误
    cout << pc1->i << endl; // 输出：5

    pp = &c2;
    pc1 = (Child1 *)pp;     // 强制转换，且类型发生变化，将造成错误
    cout << pc1->i << endl; // 输出：1717986918

    return 0;
}
```

上面两个例子之所以引起类型不安全的问题，是因为程序员使用不得当。第一个例子用到了空类型指针 `void*`，第二个例子则是在两个类型指针之间进行强制转换。因此，想保证程序的类型安全性，应尽量避免使用空类型指针 `void*`，尽量不对两种类型指针做强制转换

---

## 什么情况下会调用拷贝构造函数

* 用类的一个实例化对象去初始化另一个对象的时候
* 函数的参数是类的对象时(非引用传递)
* 函数的返回值是函数体内局部对象的类的对象时，此时虽然发生(Named return Value 优化)NRV 优化，但是由于返回方式是值传递，所以会在返回值的地方调用拷贝构造函数

另：第三种情况在 Linux `g++` 下则不会发生拷贝构造函数，不仅如此即使返回局部对象的引用，依然不会发生拷贝构造函数

总结就是：即使发生 NRV 优化的情况下，Linux+ `g++` 的环境是不管值返回方式还是引用方式返回的方式都不会发生拷贝构造函数，而 Windows + VS2019 在值返回的情况下发生拷贝构造函数，引用返回方式则不发生拷贝构造函数

在 C++ 编译器发生 NRV 优化，如果是引用返回的形式则不会调用拷贝构造函数，如果是值传递的方式依然会发生拷贝构造函数

举个例子：

```cpp
#include <iostream>

using namespace std;

class A
{
public:
    A(){};
    A(const A &a)
    {
        cout << "copy constructor is called" << endl;
    };
    ~A(){};
};

void useClassA(A a) {}

A getClassA() // 此时会发生拷贝构造函数的调用，虽然发生 NRV 优化，但是依然调用拷贝构造函数
{
    A a;
    return a;
}

A &getClassA2() // VS2019下，此时编辑器会进行(Named return Value 优化)NRV 优化，不调用拷贝构造函数，如果是引用传递的方式返回当前函数体内生成的对象时，并不发生拷贝构造函数的调用
{
    A a;
    return a;
}

int main()
{
    A a1, a3, a4;
    A a2 = a1;         // 调用拷贝构造函数，对应情况 1
    useClassA(a1);     // 调用拷贝构造函数，对应情况 2
    a3 = getClassA();  // 发生 NRV 优化，但是值返回，依然会有拷贝构造函数的调用 情况3
    a4 = getClassA2(); // 发生 NRV 优化，且引用返回自身，不会调用

    /*
        copy constructor is called
        copy constructor is called
    */

    return 0;
}
```
41
---

## 


---
