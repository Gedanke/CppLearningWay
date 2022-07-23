# 信号和槽机制

信号槽是 Qt 框架引以为豪的机制之一。所谓信号槽，实际就是观察者模式。当某个事件发生之后，比如，按钮检测到自己被点击了一下，它就会发出一个信号(`signal`)。这种发出是没有目的的，类似广播。如果有对象对这个信号感兴趣，它就会使用连接(`connect`)函数，意思是，将想要处理的信号和自己的一个函数(称为槽(`slot`))绑定来处理这个信号。也就是说，当信号发出时，被连接的槽函数会自动被回调。这就类似观察者模式：当发生了感兴趣的事件，某一个操作就会被自动触发

本章节的主要内容如下图所示

![](../photos/part4/Qt%E4%BF%A1%E5%8F%B7%E5%92%8C%E6%A7%BD%20.png)

---

## 系统自带的信号和槽

按钮的创建十分简单，但是还没有体现出按钮的功能，按钮最大的功能也就是点击后触发一些事情，比如点击按钮，就把当前的窗口给关闭掉，那么在 Qt 中，这样的功能如何实现呢
	
其实两行代码就可以搞定了

```cpp
QPushButton * quitBtn = new QPushButton("关闭窗口", this);
connect(quitBtn, &QPushButton::clicked, this, &MyWidget::close);
```

第一行是创建一个关闭按钮，这个之前已经学过，第二行就是核心了，也就是信号槽的使用方式，效果如下图所示

![](../photos/part4/%E4%BF%A1%E5%8F%B7%E5%92%8C%E6%A7%BD%E8%A7%A3%E6%9E%90%E5%9B%BE.png)

`connect()` 函数最常用的一般形式：

```cpp
connect(sender, signal, receiver, slot);
```

参数解释：

* `sender`：发出信号的对象
* `signal`：发送对象发出的信号
* `receiver`：接收信号的对象
* `slot`：接收对象在接收到信号之后所需要调用的函数(槽函数)

如下图所示

![](../photos/part4/%E4%BF%A1%E5%8F%B7%E8%BF%9E%E6%8E%A5%E4%BF%A1%E5%8F%B7%E8%A7%A3%E6%9E%90%E5%9B%BE.png)

在帮助文档中输入 `QPushButton`，首先可以在 `Contents` 中寻找关键字 `signals`，信号的意思，但是我们发现并没有找到，这时候我们应该想到也许这个信号的被父类继承下来的，因此我们去他的父类 `QAbstractButton` 中就可以找到该关键字，点击 `signals` 索引到系统自带的信号有如下几个

**Signals**

* `void clicked(bool checked = false)`
* `void pressed()`
* `void released()`
* `void toggled(bool checked)`

这里的 `clicked` 就是我们要找到，槽函数的寻找方式和信号一样，只不过它的关键字是 `slot`

demo:

```cpp
#include "widget.h"
#include "ui_widget.h"
#include <QPushButton>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    this->setWindowTitle("主窗口");
    this->setFixedSize(400,300);
    // 创建按钮
    QPushButton * btn = new QPushButton;
    btn->setParent(this);
    btn->setText("点我关闭主窗口");
    btn->move(100,100);

    this->connect(btn,&QPushButton::clicked,this,&Widget::fun);
}

void Widget::fun(){
    // 关闭窗口
    this->close();
}

Widget::~Widget()
{
    delete ui;
}
```

---

## 自定义信号和槽

使用 `connect()` 可以让我们连接系统提供的信号和槽。但是 Qt 的信号槽机制并不仅仅是使用系统提供的那部分，还会允许我们设计自己的信号和槽

下面看看使用 Qt 的信号槽的案例：

首先我们自定义了两个类，`Teacher` 与 `Student`

* 下课后，老师触发一个 `饿了` 的信号
* 学生响应信号，请老师吃饭
* 过程中，信号和槽有函数重载，使用函数指针解决该问题

`teacher.h`

```cpp
#ifndef TEACHER_H
#define TEACHER_H

#include <QObject>

class Teacher : public QObject
{
    Q_OBJECT
public:
    explicit Teacher(QObject *parent = nullptr);
    ~Teacher();

    // 自定义信号位置
signals:
    // 返回值为 void
    // 只需要声明，不需要实现
    // 可以有参数，可以发生重载
    void hungry();
    void hungry(QString foodName);

};

#endif // TEACHER_H
```

`teacher.cpp`

```cpp
#include "teacher.h"
#include <QDebug>

Teacher::Teacher(QObject *parent) : QObject(parent)
{
    qDebug()<<"Teacher 构造";
}

Teacher::~Teacher()
{
    qDebug()<<"Teacher 析构";
}
```

`student.h`

```cpp
#ifndef STUDENT_H
#define STUDENT_H

#include <QObject>

class Student : public QObject
{
    Q_OBJECT
public:
    explicit Student(QObject *parent = nullptr);
    ~Student();

signals:

    // 自定义槽函数
public slots:
    // Qt5.0 以后，槽函数可以是全局函数、Lambda 表达式，public 作用域下等
    // 返回值为 void
    // 需要声明，也需要有实现
    // 可以有参数，可以发生重载
    void treat();
    void treat(QString foodName);

};

#endif // STUDENT_H
```

`student.cpp`

```cpp
#include "student.h"
#include <QDebug>

Student::Student(QObject *parent) : QObject(parent)
{
    qDebug()<<"Student 构造";
}

void Student::treat()
{
    qDebug()<<"请老师吃饭";
}

void Student::treat(QString foodName)
{
    // QString 转为 char*
    // 先通过 .toUtf8() 转为 QByteArray 类型
    qDebug()<<"请老师吃饭，老师想吃 "<<foodName.toUtf8().data();
}

Student::~Student()
{
    qDebug()<<"Student 析构";
}
```

`mainwindow.cpp`

```cpp
#include "mainwindow.h"
#include "ui_mainwindow.h"

/*
    Teacher 教师类
    Student 学生类
    下课后，老师触发一个 饿了 的信号
    学生响应信号，请老师吃饭
*/

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->teacher = new Teacher();
    this->student = new Student();

    // 连接信号和槽，无参
    //    this->connect(this->teacher,&Teacher::hungry,this->student,&Student::treat);

    //    emit this->teacher->hungry();
    // 或者下面这种
    //    this->classOver();
    /*
    Teacher 构造
    Student 构造
    请老师吃饭
    */

    // 连接信号和槽，有参
    // 函数指针可以指向函数的地址
    void(Teacher::*teacherSignal) (QString) = &Teacher::hungry;
    void(Student::*studentSlot) (QString) = &Student::treat;
    this->connect(this->teacher,teacherSignal,this->student,studentSlot);

    this->classOver();
    /*
    Teacher 构造
    Student 构造
    请老师吃饭，老师想吃  鸡腿
    */
}

void MainWindow::classOver()
{
    // 触发自定义信号，无参
    //    emit this->teacher->hungry();
    // 触发自定义信号，有参
    emit this->teacher->hungry("鸡腿");
}

MainWindow::~MainWindow()
{
    delete ui;
}
```

自定义信号槽需要注意的事项：

* 发送者和接收者都需要是 `QObject` 的子类(当然，槽函数(Qt5.0 以后)是全局函数、Lambda 表达式、public 作用域下等无需接收者的时候除外)
* 信号和槽函数返回值是 `void`
* 信号只需要声明，不需要实现
* 槽函数需要声明也需要实现
* 槽函数是普通的成员函数，作为成员函数，会受到 `public`、`private`、`protected` 的影响
* 使用 `emit` 在恰当的位置发送信号
* 使用 `connect()` 函数连接信号和槽
* 任何成员函数、`static` 函数、全局函数和 `lambda` 表达式都可以作为槽函数
* 信号槽要求信号和槽的参数一致，所谓一致，是参数类型一致
* 如果信号和槽的参数不一致，允许的情况是，槽函数的参数可以比信号的少，即便如此，槽函数存在的那些参数的顺序也必须和信号的前面几个一致起来。这是因为，你可以在槽函数中选择忽略信号传来的数据(也就是槽函数的参数比信号的少)

---

## 信号槽的拓展

* 一个信号可以和多个槽相连。如果是这种情况，这些槽会一个接一个的被调用，但是它们的调用顺序是不确定的
* 多个信号可以连接到一个槽。只要任意一个信号发出，这个槽就会被调用
* 一个信号可以连接到另外的一个信号。当第一个信号发出时，第二个信号被发出。除此之外，这种信号-信号的形式和信号-槽的形式没有什么区别
* 槽可以被取消链接。这种情况并不经常出现，因为当一个对象 `delete` 之后，Qt 自动取消所有连接到这个对象上面的槽
* 信号槽可以断开。利用 `disconnect` 关键字是可以断开信号槽的
* 使用 `lambda` 表达式。在使用 Qt5 的时候，能够支持 Qt5 的编译器都是支持 `lambda` 表达式的
	
在连接信号和槽的时候，槽函数可以使用 `lambda` 表达式的方式进行处理。后面会详细介绍什么是 `lambda` 表达式

详细代码见 [SignalAndSlot](../codes/part4/SignalAndSlot/)

---

## Qt4 版本的信号槽写法

```cpp
this->connect(this->teacher, SIGNAL(hungry(QString)), this->student, SLOT(treat(QString)));
```

这里使用了 `SIGNAL` 和 `SLOT` 这两个宏，将两个函数名转换成了字符串

优势是简单直观，注意到 `connect()` 函数的 `signal` 和 `slot` 都是接受字符串，一旦出现连接不成功的情况，Qt4 是没有编译错误的(因为一切都是字符串，编译期是不检查字符串是否匹配)，而是在运行时给出错误。这无疑会增加程序的不稳定性

Qt5 在语法上完全兼容 Qt4，而反之是不可以的

详细代码见 [SignalAndSlot](../codes/part4/SignalAndSlot/)

---

## lambda 表达式 

C++11 中的 `lambda` 表达式用于定义并创建匿名的函数对象，以简化编程工作。首先看一下 `lambda` 表达式的基本构成：

```cpp
[capture](parameters) mutable -> return-type
{
    statement
}
```

语法:

```cpp
[函数对象参数](操作符重载函数参数) mutable -> 返回值
{
    函数体
}
```

* 函数对象参数；`[]`，标识一个 `lambda` 的开始，这部分必须存在，不能省略。函数对象参数是传递给编译器自动生成的函数对象类的构造函数的。函数对象参数只能使用那些到定义 `lambda` 为止时 `lambda` 所在作用范围内可见的局部变量(包括 `lambda` 所在类的 `this`)。函数对象参数有以下形式：
    * 空。没有使用任何函数对象参数
    * `=`。函数体内可以使用 `lambda` 所在作用范围内所有可见的局部变量(包括 `lambda` 所在类的 `this`)，并且是值传递方式(相当于编译器自动为我们按值传递了所有局部变量)，最常用是 `=`
    * `&`。函数体内可以使用 `lambda` 所在作用范围内所有可见的局部变量(包括 `lambda` 所在类的 `this`)，并且是引用传递方式(相当于编译器自动为我们按引用传递了所有局部变量)
    * `this`。函数体内可以使用 `lambda` 所在类中的成员变量
    * `a`。将 `a` 按值进行传递。按值进行传递时，函数体内不能修改传递进来的 `a` 的拷贝，因为默认情况下函数是 `const` 的。要修改传递进来的 `a` 的拷贝，可以添加 `mutable` 修饰符
    * `&a`。将 `a` 按引用进行传递
    * `a, &b`。将 `a` 按值进行传递，`b` 按引用进行传递
    * `=, &a, &b`。除 `a` 和 `b` 按引用进行传递外，其他参数都按值进行传递
    * `&, a, b`。除 `a` 和 `b` 按值进行传递外，其他参数都按引用进行传递
* 操作符重载函数参数；标识重载的 `()` 操作符的参数，没有参数时，这部分可以省略。参数可以通过按值(如：`(a, b)`)和按引用(如：`(&a, &b)`)两种方式进行传递
* 可修改标示符；`mutable` 声明，这部分可以省略。按值传递函数对象参数时，加上 `mutable` 修饰符后，可以修改按值传递进来的拷贝(注意是能修改拷贝，而不是值本身)

```cpp
QPushButton * myBtn = new QPushButton("mutable",this);
QPushButton * myBtn2 = new QPushButton("no mutable",this);
myBtn2->move(100,100);
int m = 10;

this->connect(myBtn,&QPushButton::clicked,this,[m]()mutable { m = 20; qDebug() << m; });
this->connect(myBtn2,&QPushButton::clicked,this,[=](){ qDebug() << m; });

qDebug() << m;
```

* 函数返回值；`->` 返回值类型，标识函数返回值的类型，当返回值为 `void`，或者函数体中只有一处 `return` 的地方(此时编译器可以自动推断出返回值类型)时，这部分可以省略
* 是函数体；`{}`，标识函数的实现，这部分不能省略，但函数体可以为空

详细代码见 [SignalAndSlot](../codes/part4/SignalAndSlot/)

---
