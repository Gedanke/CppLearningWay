# 关键字篇

---

## C++ 中 const 和 static 的作用

**static**

* 不考虑类的情况
    * 隐藏。所有不加 `static` 的全局变量和函数具有全局可见性，可以在其他文件中使用，加了之后只能在该文件所在的编译模块中使用
    * 默认初始化为0，包括未初始化的全局静态变量与局部静态变量，都存在全局未初始化区
    * 静态变量在函数内定义，始终存在，且只进行一次初始化，具有记忆性，其作用范围与局部变量相同，函数退出后仍然存在，但不能使用
* 考虑类的情况
    * `static` 成员变量：只与类关联，不与类的对象关联。定义时要分配空间，不能在类声明中初始化，必须在类定义体外部初始化，初始化时不需要标示为 `static`；可以被非 `static` 成员函数任意访问
    * `static` 成员函数：不具有 `this` 指针，无法访问类对象的非 `static` 成员变量和非 `static` 成员函数；不能被声明为 `const`、虚函数和 `volatile`；可以被非 `static` 成员函数任意访问

**const**

* 不考虑类的情况
    * `const` 常量在定义时必须初始化，之后无法更改
    * `const` 形参可以接收 `const` 和非 `const` 类型的实参，例如 `i` 可以是 `int` 型或者 `const int` 型 `void fun(const int& i){ //...}`
* 考虑类的情况
    * `const` 成员变量：不能在类定义外部初始化，只能通过构造函数初始化列表进行初始化，并且必须有构造函数；不同类对其 `const` 数据成员的值可以不同，所以不能在类中声明时初始化
    * `const` 成员函数：`const` 对象不可以调用非 `const` 成员函数；非 `const` 对象都可以调用；不可以改变非 `mutable`(用该关键字声明的变量可以在 `const` 成员函数中被修改)数据的值

补充一点 `const` 相关：`const` 修饰变量是也与 `static` 有一样的隐藏作用。只能在该文件中使用，其他文件不可以引用声明使用。因此在头文件中声明 `const` 变量是没问题的，因为即使被多个文件包含，链接性都是内部的，不会出现符号冲突

---

## final 和 override

**override**

当在父类中使用了虚函数时候，你可能需要在某个子类中对这个虚函数进行重写，以下方法都可以：

```cpp
class A
{
    virtual void foo();
};

class B : public A
{
    void foo(); // OK
    virtual void foo(); // OK
    void foo() override; // OK
};
```
    
如果不使用 `override`，将 `foo()` 写成了 `f00()` 会怎么样呢？结果是编译器并不会报错，因为它并不知道你的目的是重写虚函数，而是把它当成了新的函数。如果这个虚函数很重要的话，那就会对整个程序不利。所以，`override` 的作用就出来了，它指定了子类的这个虚函数是重写的父类的，如果名字不小心打错了的话，编译器是不会编译通过的：

```cpp
class A
{
    virtual void foo();
};

class B : public A
{
    virtual void f00(); // OK，这个函数是 B 新增的，不是继承的
    virtual void f0o() override; // Error，加了 override 之后，这个函数一定是继承自 A 的，A 找不到就报错
};
```
    
**final**

当不希望某个类被继承，或不希望某个虚函数被重写，可以在类名和虚函数后添加 `final` 关键字，添加 `final` 关键字后被继承或重写，编译器会报错。例子如下：

```cpp
class Base
{
    virtual void foo();
};
 
class A : public Base
{
    void foo() final; // foo 被 override 并且是最后一个 override，在其子类中不可以重写
};

class B final : A // 指明 B 是不可以被继承的
{
    void foo() override; // Error: 在A中已经被 final 了
};
 
class C : B // Error: B is final
{
};
```

---

## volatile、mutable 和 explicit

**volatile**

`volatile` 关键字是一种类型修饰符，用它声明的类型变量表示可以被某些编译器未知的因素更改，比如：操作系统、硬件或者其它线程等。遇到这个关键字声明的变量，编译器对访问该变量的代码就不再进行优化，从而可以提供对特殊地址的稳定访问

当要求使用 `volatile` 声明的变量的值的时候，系统总是重新从它所在的内存读取数据，即使它前面的指令刚刚从该处读取过数据

`volatile` 定义变量的值是易变的，每次用到这个变量的值的时候都要去重新读取这个变量的值，而不是读寄存器内的备份。多线程中被几个任务共享的变量需要定义为 `volatile` 类型

**volatile 指针**

`volatile` 指针和 `const` 修饰词类似，`const` 有常量指针和指针常量的说法，`volatile` 也有相应的概念

修饰由指针指向的对象、数据是 `const` 或 `volatile` 的：

```cpp
const char* cpch;
volatile char* vpch;
``` 
    
指针自身的值—— 一个代表地址的整数变量，是 `const` 或 `volatile` 的：

```cpp
char* const pchc;
char* volatile pchv;
```
 
注意：

可以把一个非 `volatile int` 赋给 `volatile int`，但是不能把非 `volatile` 对象赋给一个 `volatile` 对象

除了基本类型外，对用户定义类型也可以用 `volatile` 类型进行修饰

C++ 中一个有 `volatile` 标识符的类只能访问它接口的子集，一个由类的实现者控制的子集。用户只能用 `const_cast` 来获得对类型接口的完全访问。此外，`volatile` 向 `const` 一样会从类传递到它的成员

**多线程下的 volatile**

有些变量是用 `volatile` 关键字声明的。当两个线程都要用到某一个变量且该变量的值会被改变时，应该用 `volatile` 声明，**该关键字的作用是防止优化编译器把变量从内存装入 CPU 寄存器中**。如果变量被装入寄存器，那么两个线程有可能一个使用内存中的变量，一个使用寄存器中的变量，这会造成程序的错误执行。`volatile` 的意思是让编译器每次操作该变量时一定要从内存中真正取出，而不是使用已经存在寄存器中的值

**mutable**

`mutable` 的中文意思是“可变的，易变的”，跟 `constant`(既 C++ 中的 `const`)是反义词。在 C++ 中，`mutable` 也是为了突破 `const` 的限制而设置的。被 `mutable` 修饰的变量，将永远处于可变的状态，即使在一个 `const` 函数中。我们知道，如果类的成员函数不会改变对象的状态，那么这个成员函数一般会声明成 `const` 的。但是，有些时候，我们需要在 `const` 函数里面修改一些跟类状态无关的数据成员，那么这个函数就应该被 `mutable` 来修饰，并且放在函数后后面关键字位置

样例

```cpp
#include <iostream>

using namespace std;

class Person1
{
public:
    int m_A;
    mutable int m_B; // 特殊变量 在常函数里值也可以被修改

public:
    Person1()
    {
    }

    void add() const // 在函数里不可修改this指针指向的值 常量指针
    {
        // m_A = 10; // 错误  不可修改值，this已经被修饰为常量指针
        m_B = 20; // 正确
    }
};

class Person2
{
public:
    int m_A;
    mutable int m_B; //特殊变量 在常函数里值也可以被修改

    Person2()
    {
    }

    void add()
    {
        m_A = 10;
        m_B = 20;
    }
};

int main()
{
    const Person1 p1; // 修饰常对象 不可修改类成员的值
    // p1.m_A = 10;      // 错误，被修饰了指针常量
    p1.m_B = 200; // 正确，特殊变量，修饰了 mutable

    Person2 p2;
    p2.m_A = 10;
    p2.m_B = 200;

    /*
     */

    return 0;
}
```

**explicit**

`explicit` 关键字用来修饰类的构造函数，被修饰的构造函数的类，不能发生相应的隐式类型转换，只能以显示的方式进行类型转换，注意以下几点：

* `explicit` 关键字只能用于类内部的构造函数声明上
* `explicit` 关键字作用于单个参数的构造函数
* 被 `explicit` 修饰的构造函数的类，不能发生相应的隐式类型转换

----

## static

* 先来介绍它的第一条也是最重要的一条：隐藏(`static` 函数，`static` 变量均可)

当同时编译多个文件时，所有未加 `static` 前缀的全局变量和函数都具有全局可见性

* `static` 的第二个作用是保持变量内容的持久(`static` 变量中的记忆功能和全局生存期)存储在静态数据区的变量会在程序刚开始运行时就完成初始化，也是唯一的一次初始化。共有两种变量存储在静态存储区：全局变量和 `static` 变量，只不过和全局变量比起来，`static` 可以控制变量的可见范围，说到底 `static` 还是用来隐藏的

* `static` 的第三个作用是默认初始化为 0(`static`变量)

其实全局变量也具备这一属性，因为全局变量也存储在静态数据区。在静态数据区，内存中所有的字节默认值都是 0x00，某些时候这一特点可以减少程序员的工作量

* `static` 的第四个作用：C++ 中的类成员声明 `static`
    * 函数体内 `static` 变量的作用范围为该函数体，不同于 `auto` 变量，该变量的内存只被分配一次，因此其值在下次调用时仍维持上次的值
    * 在模块内的 `static` 全局变量可以被模块内所有函数访问，但不能被模块外其它函数访问
    * 在模块内的 `static` 函数只可被这一模块内的其它函数调用，这个函数的使用范围被限制在声明它的模块内
    * 在类中的 `static` 成员变量属于整个类所拥有，对类的所有对象只有一份拷贝
    * 在类中的 `static` 成员函数属于整个类所拥有，这个函数不接收 `this` 指针，因而只能访问类的 `static` 成员变量
* 类内：
    * `static` 类对象必须要在类外进行初始化，`static` 修饰的变量先于对象存在，所以 `static` 修饰的变量要在类外初始化
    * 由于 `static` 修饰的类成员属于类，不属于对象，因此 `static` 类成员函数是没有 `this` 指针的，`this` 指针是指向本对象的指针。正因为没有 `this` 指针，所以 `static` 类成员函数不能访问非 `static` 的类成员，只能访问 `static` 修饰的类成员
    * `static` 成员函数不能被 `virtual` 修饰，`static` 成员不属于任何对象或实例，所以加上 `virtual` 没有任何实际意义；静态成员函数没有 `this` 指针，虚函数的实现是为每一个对象分配一个 `vptr` 指针，而 `vptr` 是通过 `this` 指针调用的，所以不能为 `virtual`；虚函数的调用关系，`this->vptr->ctable->virtual function`

---

## const 关键字的作用有哪些

* 阻止一个变量被改变，可以使用 `const` 关键字。在定义该 `const` 变量时，通常需要对它进行初始化，因为以后就没有机会再去改变它了
* 对指针来说，可以指定指针本身为 `const`，也可以指定指针所指的数据为 `const`，或二者同时指定为 `const`
* 在一个函数声明中，`const` 可以修饰形参，表明它是一个输入参数，在函数内部不能改变其值
* 对于类的成员函数，若指定其为 `const` 类型，则表明其是一个常函数，不能修改类的成员变量，类的常对象只能访问类的常成员函数
* 对于类的成员函数，有时候必须指定其返回值为 `const` 类型，以使得其返回值不为“左值”
* `const` 成员函数可以访问非 `const` 对象的非 `const` 数据成员、`const` 数据成员，也可以访问 `const` 对象内的所有数据成员
* 非 `const` 成员函数可以访问非 `const` 对象的非 `const` 数据成员、`const` 数据成员，但不可以访问 `const` 对象的任意数据成员
* 一个没有明确声明为 `const` 的成员函数被看作是将要修改对象中数据成员的函数，而且编译器不允许它为一个 `const` 对象所调用。因此 `const` 对象只能调用 `const` 成员函数
* `const` 类型变量可以通过类型转换符 `const_cast` 将 `const` 类型转换为非 `const` 类型
* `const` 类型变量必须定义的时候进行初始化，因此也导致如果类的成员变量有 `const` 类型的变量，那么该变量必须在类的初始化列表中进行初始化
* 对于函数值传递的情况，因为参数传递是通过复制实参创建一个临时变量传递进函数的，函数内只能改变临时变量，但无法改变实参。则这个时候无论加不加 `const` 对实参不会产生任何影响。但是在引用或指针传递函数调用中，因为传进去的是一个引用或指针，这样函数内部可以改变引用或指针所指向的变量，这时 `const` 才是实实在在地保护了实参所指向的变量。因为在编译阶段编译器对调用函数的选择是根据实参进行的，所以，只有引用传递和指针传递可以用是否加 `const` 来重载。一个拥有顶层 `const` 的形参无法和另一个没有顶层 `const` 的形参区分开来

---

## C++ 的四种强制转换 reinterpret_cast/const_cast/static_cast/dynamic_cast

**reinterpret_cast**

```cpp
reinterpret_cast<type-id> (expression)
```

`type-id` 必须是一个指针、引用、算术类型、函数指针或者成员指针。它可以用于类型之间进行强制转换

**const_cast**

```cpp
const_cast<type_id> (expression)
```

该运算符用来修改类型的 `const` 或 `volatile` 属性。除了 `const` 或 `volatile` 修饰之外，`type_id` 和 `expression` 的类型是一样的。用法如下：

* 常量指针被转化成非常量的指针，并且仍然指向原来的对象
* 常量引用被转换成非常量的引用，并且仍然指向原来的对象
* `const_cast` 一般用于修改底指针。如 `const char *p` 形式

**static_cast**

```cpp
static_cast < type-id > (expression)
```

该运算符把 `expression` 转换为 `type-id` 类型，但没有运行时类型检查来保证转换的安全性。它主要有如下几种用法：

* 用于类层次结构中基类(父类)和派生类(子类)之间指针或引用引用的转换
    * 进行上行转换(把派生类的指针或引用转换成基类表示)是安全的
    * 进行下行转换(把基类指针或引用转换成派生类表示)时，由于没有动态类型检查，所以是不安全的
* 用于基本数据类型之间的转换，如把 `int` 转换成 `char`，把 `int` 转换成 `enum`。这种转换的安全性也要开发人员来保证
* 把空指针转换成目标类型的空指针
* 把任何类型的表达式转换成 `void` 类型

注意：`static_cast` 不能转换掉 `expression` 的 `const`、`volatile`、或者 `__unaligned` 属性

**dynamic_cast**

有类型检查，基类向派生类转换比较安全，但是派生类向基类转换则不太安全

```cpp
dynamic_cast <type-id> (expression)
```

该运算符把 `expression` 转换成 `type-id` 类型的对象。`type-id` 必须是类的指针、类的引用或者 `void*`

如果 `type-id` 是类指针类型，那么 `expression` 也必须是一个指针，如果 `type-id` 是一个引用，那么 `expression` 也必须是一个引用

`dynamic_cast` 运算符可以在执行期决定真正的类型，也就是说 `expression` 必须是多态类型。如果下行转换是安全的(也就说，如果基类指针或者引用确实指向一个派生类对象)这个运算符会传回适当转型过的指针。如果 如果下行转换不安全，这个运算符会传回空指针(也就是说，基类指针或者引用没有指向一个派生类对象)

`dynamic_cast` 主要用于类层次间的上行转换和下行转换，还可以用于类之间的交叉转换

在类层次间进行上行转换时，`dynamic_cast` 和 `static_cast` 的效果是一样的

在进行下行转换时，`dynamic_cast` 具有类型检查的功能，比 `static_cast` 更安全

举个例子：

```cpp
#include <iostream>

using namespace std;

class Base
{
public:
    Base() : b(1) {}
    virtual void fun(){};
    int b;
};

class Son : public Base
{
public:
    Son() : d(2) {}
    int d;
};

int main()
{
    int n = 97;

    // reinterpret_cast
    int *p = &n;
    // 以下两者效果相同
    char *c = reinterpret_cast<char *>(p);
    char *c2 = (char *)(p);
    cout << "reinterpret_cast 输出：" << *c2 << endl;
    // const_cast
    const int *p2 = &n;
    int *p3 = const_cast<int *>(p2);
    *p3 = 100;
    cout << "const_cast 输出：" << *p3 << endl;

    Base *b1 = new Son;
    Base *b2 = new Base;

    // static_cast
    Son *s1 = static_cast<Son *>(b1); // 同类型转换
    Son *s2 = static_cast<Son *>(b2); // 下行转换，不安全
    cout << "static_cast 输出：" << endl;
    cout << s1->d << endl;
    cout << s2->d << endl; // 下行转换，原先父对象没有d成员，输出垃圾值

    // dynamic_cast
    Son *s3 = dynamic_cast<Son *>(b1); // 同类型转换
    Son *s4 = dynamic_cast<Son *>(b2); // 下行转换，安全
    cout << "dynamic_cast 输出：" << endl;
    cout << s3->d << endl;
    if (s4 == nullptr)
        cout << "s4 指针为 nullptr" << endl;
    else
        cout << s4->d << endl;

    return 0;

    /*
        reinterpret_cast 输出：a
        const_cast 输出：100
        static_cast 输出：
        2
        0
        dynamic_cast 输出：
        2
        s4 指针为 nullptr
    */
}
```

从输出结果可以看出，在进行下行转换时，`dynamic_cast` 安全的，如果下行转换不安全的话其会返回空指针，这样在进行操作的时候可以预先判断。而使用 `static_cast` 下行转换存在不安全的情况也可以转换成功，但是直接使用转换后的对象进行操作容易造成错误

---

## 补充

更多关键字内容可以 [参考](https://github.com/Gedanke/CppNotes/tree/master/keyWords)

---
