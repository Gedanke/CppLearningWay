#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPushButton>

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
    //    void(Teacher::*teacherSignal) (QString) = &Teacher::hungry;
    //    void(Student::*studentSlot) (QString) = &Student::treat;
    //    this->connect(this->teacher,teacherSignal,this->student,studentSlot);

    //    this->classOver();
    /*
    Teacher 构造
    Student 构造
    请老师吃饭，老师想吃  鸡腿
    */

    // 创建按钮
    //    QPushButton *btn = new QPushButton("点我",this);
    //    btn->resize(60,60);

    //    void(Teacher::*teacherSignal2) () = &Teacher::hungry;
    //    void(Student::*studentSlot2) () = &Student::treat;
    // 信号连接槽
    //    this->connect(this->teacher,teacherSignal2,this->student,studentSlot2);
    // 信号连接信号
    //    this->connect(btn,&QPushButton::clicked,this->teacher,teacherSignal2);
    /*
    Teacher 构造
    Student 构造
    请老师吃饭
    */

    // 可以断开信号和槽
    //    this->disconnect(this->teacher,teacherSignal2,this->student,studentSlot2);
    /*
    Teacher 构造
    Student 构造
    */

    // 一个信号可以响应多个槽函数
    //    void(Teacher::*teacherSignal3) () = &Teacher::hungry;
    //    void(Student::*studentSlot3) () = &Student::treat;

    // 信号连接槽
    //    this->connect(this->teacher,teacherSignal3,this->student,studentSlot3);
    //    this->classOver();
    // 信号连接信号
    //    this->connect(btn,&QPushButton::clicked,this->teacher,teacherSignal3);
    //    this->connect(btn,&QPushButton::clicked,this,&MainWindow::closeWindow);
    /*
    Teacher 构造
    Student 构造
    请老师吃饭
    关闭主窗口
    */

    // 多个信号可以连接一个槽函数
    // 例如，多个按钮同时绑定关闭主窗口
    // 信号和槽函数参数类型必须一一对应，信号参数个数可以多于槽函数，反之不行

    // Qt4 版本的信号槽写法
    //    this->connect(this->teacher, SIGNAL(hungry(QString)), this->student, SLOT(treat(QString)));
    //    this->classOver("红烧肉");
    /*
    Teacher 构造
    Student 构造
    请老师吃饭，老师想吃  红烧肉
    */

    //    QPushButton *btn = new QPushButton("点我",this);
    //    btn->resize(60,60);
    //    QPushButton *btn2 = new QPushButton("点我",this);
    //    btn2->resize(60,60);
    //    btn2->move(100,200);
    //    [=](){
    //        btn->setText("按钮");
    //        btn2->setText("按钮2");
    //    }();
    //    QPushButton *btn4 = new QPushButton("点我",this);
    //    btn4->resize(60,60);
    //    btn4->move(200,300);

    //    this->connect(btn4,&QPushButton::clicked,this,[=](){
    //        btn4->setText("按钮4");
    //    });
    // 使用 & 时会报错
    /*
    Teacher 构造
    Student 构造
    12:08:17: 程序异常结束。
    */
    // 当进行信号和槽连接时候，控件内部会进入锁的状态，只读状态

    // 加上 mutable 修饰符后，可以修改按值传递进来的拷贝
    //    QPushButton * myBtn = new QPushButton("mutable",this);
    //    QPushButton * myBtn2 = new QPushButton("no mutable",this);
    //    myBtn2->move(100,100);
    //    int m = 10;

    //    this->connect(myBtn,&QPushButton::clicked,this,[m]()mutable { m = 20; qDebug() << m; });
    //    this->connect(myBtn2,&QPushButton::clicked,this,[=](){ qDebug() << m; });

    //    qDebug() << m;
    /*
    Teacher 构造
    Student 构造
    10
    20
    10
    */

    // 返回值
    //    int num = [=]()->int{
    //        return 1000;
    //    }();
    //    qDebug() << num;
    /*
    Teacher 构造
    Student 构造
    1000
    */

    // 点击按钮，关闭窗口
    QPushButton *btn = new QPushButton("点我",this);
    this->connect(btn,&QPushButton::clicked,this,[=](){
        qDebug() << "关闭主窗口";
        this->student->treat("白切鸡");
        this->close();
    });
    /*
    Teacher 构造
    Student 构造
    关闭主窗口
    请老师吃饭，老师想吃  白切鸡
    */
}

void MainWindow::classOver(QString str)
{
    // 触发自定义信号，无参
    //    emit this->teacher->hungry();
    // 触发自定义信号，有参
    emit this->teacher->hungry(str);
}

void MainWindow::closeWindow()
{
    qDebug()<<"关闭主窗口";
    this->close();
}

MainWindow::~MainWindow()
{
    delete ui;
}

