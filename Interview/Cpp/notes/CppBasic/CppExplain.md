# 解释篇

---

## C++ 有哪几种的构造函数

C++ 中的构造函数可以分为 4 类：

* 默认构造函数
* 初始化构造函数(有参数)
* 拷贝构造函数
* 移动构造函数(`move` 和右值引用)
* 委托构造函数
* 转换构造函数

举个例子：

```cpp
#include <iostream>

using namespace std;

class Student
{
public:
    Student()
    { // 默认构造函数，没有参数
        this->age = 20;
        this->num = 1000;
    };
    Student(int a, int n) : age(a), num(n){}; // 初始化构造函数，有参数和参数列表
    Student(const Student &s)
    { // 拷贝构造函数，这里与编译器生成的一致
        this->age = s.age;
        this->num = s.num;
    };
    Student(int r)
    { // 转换构造函数,形参是其他类型变量，且只有一个形参
        this->age = r;
        this->num = 1002;
    };
    ~Student() {}

public:
    int age;
    int num;
};

int main()
{
    Student s1;
    Student s2(18, 1001);
    int a = 10;
    Student s3(a);
    Student s4(s3);

    printf("s1 age: %d, num: %d\n", s1.age, s1.num);
    printf("s2 age: %d, num: %d\n", s2.age, s2.num);
    printf("s3 age: %d, num: %d\n", s3.age, s3.num);
    printf("s2 age: %d, num: %d\n", s4.age, s4.num);

    /*
        s1 age: 20, num: 1000
        s2 age: 18, num: 1001
        s3 age: 10, num: 1002
        s2 age: 10, num: 1002
    */

    return 0;
}
```

* 默认构造函数和初始化构造函数在定义类的对象，完成对象的初始化工作
* 复制构造函数用于复制本类的对象
* 转换构造函数用于将其他类型的变量，隐式转换为本类对象

---

## public，protected 和 private 访问权限

|||||
|:----:|:----:|:----:|:----:|
| 访问权限 | 外部 | 派生类 | 内部 |
| `public` | ✔ | ✔ | ✔ |
| `protected` | ❌ | ✔ | ✔ |
| `private` | ❌ | ❌ | ✔ |

`public`、`protected`、`private` 的访问权限范围关系：

```cpp
public > protected > private
```

---

## 继承权限/public/protected/private

* 派生类继承自基类的成员权限有四种状态：`public`、`protected`、`private`、不可见
* 派生类对基类成员的访问权限取决于两点：
    * 继承方式
    * 基类成员在基类中的访问权限
* 派生类对基类成员的访问权限是取以上两点中的更小的访问范围(除了 `private` 的继承方式遇到 `private` 成员是不可见外)

例如：

* `public` 继承 + `private` 成员 => `private`
* `private` 继承 + `protected` 成员 => `private`
* `private` 继承 + `private` 成员 => 不可见

---

## 如何用代码判断大小端存储

* 大端存储：字数据的高字节存储在低地址中
* 小端存储：字数据的低字节存储在低地址中

例如：32 `bit` 的数字 0x12345678

所以在 `socket` 编程中，往往需要将操作系统所用的小端存储的 IP 地址转换为大端存储，这样才能进行网络传输

小端模式中的存储方式为：

||||||
|:----:|:----:|:----:|:----:|:----:|
| 内存地址 | 0x4000 | 0x4001 | 0x4002 | 0x4003 |
| 存放内容 | 0x78 | 0x56 | 0x34 | 0x12 |

大端模式中的存储方式为：

||||||
|:----:|:----:|:----:|:----:|:----:|
| 内存地址 | 0x4000 | 0x4001 | 0x4002 | 0x4003 |
| 存放内容 | 0x12 | 0x34 | 0x56 | 0x78 |

了解了大小端存储的方式，如何在代码中进行判断呢？下面介绍两种判断方式：

* 方式一：使用强制类型转换 - 这种法子不错

```cpp
#include <iostream>

using namespace std;

int main()
{
    int a = 0x1234;
    // 由于 int 和 char 的长度不同，借助 int 型转换成 char 型，只会留下低地址的部分
    char c = (char)(a);
    if (c == 0x12)
        cout << "big endian" << endl;
    else if (c == 0x34)
        cout << "little endian" << endl;

    // little endian

    return 0;
}
```

* 方式二：巧用 `union` 联合体

```cpp
#include <iostream>

using namespace std;

// union 联合体的重叠式存储，endian 联合体占用内存的空间为每个成员字节长度的最大值
union endian
{
    int a;
    char ch;
};

int main()
{
    endian value;
    value.a = 0x1234;
    // a 和 ch 共用 4 字节的内存空间
    if (value.ch == 0x12)
        cout << "big endian" << endl;
    else if (value.ch == 0x34)
        cout << "little endian" << endl;

    // little endian

    return 0;
}
```

---

## C++ 中有几种类型的 new

在 C++ 中，`new` 有三种典型的使用方法：`plain new`，`nothrow new` 和 `placement new`

**plain new**

言下之意就是普通的 `new`，就是我们常用的 `new`，在 C++ 中定义如下：

```cpp
void* operator new(std::size_t) throw(std::bad_alloc);
void operator delete(void *) throw();
```
 
因此 `plain new` 在空间分配失败的情况下，抛出异常 `std::bad_alloc` 而不是返回 `NULL`，因此通过判断返回值是否为 `NULL` 是徒劳的，举个例子：

```cpp
#include <iostream>
#include <string>

using namespace std;

int main()
{
    try
    {
        char *p = new char[100000000000];
        delete p;
    }
    catch (const std::bad_alloc &ex)
    {
        cout << ex.what() << endl;
    }

    // std::bad_alloc

    return 0;
}
```

**nothrow new**

`nothrow new` 在空间分配失败的情况下是不抛出异常，而是返回 `NULL`，定义如下：

```cpp
void * operator new(std::size_t,const std::nothrow_t&) throw();
void operator delete(void*) throw();
```
 
举个例子：

```cpp
#include <iostream>
#include <string>

using namespace std;

int main()
{
    char *p = new (nothrow) char[1000000000000];
    if (p == NULL)
    {
        cout << "alloc failed" << endl;
    }
    delete p;

    // alloc failed

    return 0;
}
```

**placement new**

这种 `new` 允许在一块已经分配成功的内存上重新构造对象或对象数组。`placement new` 不用担心内存分配失败，因为它根本不分配内存，它做的唯一一件事情就是调用对象的构造函数。定义如下：

```cpp
void* operator new(size_t,void*);
void operator delete(void*,void*);
``` 

使用 `placement new` 需要注意两点：

* `palcement new` 的主要用途就是反复使用一块较大的动态分配的内存来构造不同类型的对象或者他们的数组
* `placement new` 构造起来的对象数组，要显式的调用他们的析构函数来销毁(析构函数并不释放对象的内存)，千万不要使用 `delete`，这是因为 `placement new` 构造起来的对象或数组大小并不一定等于原来分配的内存大小，使用 `delete` 会造成内存泄漏或者之后释放内存时出现运行时错误

举个例子：

```cpp
#include <iostream>
#include <string>

using namespace std;

class ADT
{
    int i;
    int j;

public:
    ADT()
    {
        i = 10;
        j = 100;
        cout << "ADT construct i=" << i << "; j=" << j << endl;
    }
    ~ADT()
    {
        cout << "ADT destruct" << endl;
    }
};

int main()
{
    char *p = new (nothrow) char[sizeof(ADT) + 1];
    if (p == NULL)
    {
        cout << "alloc failed" << endl;
    }
    ADT *q = new (p) ADT; // placement new: 不必担心失败，只要 p 所指对象的的空间足够 ADT 创建即可
    // delete q; // 错误!不能在此处调用 delete q
    q->ADT::~ADT(); // 显示调用析构函数
    delete[] p;

    /*
        ADT construct i=10; j=100
        ADT destruct
    */

    return 0;
}
```


---
