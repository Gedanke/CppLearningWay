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

## final 和 override 关键字

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
    
**final*

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





---
