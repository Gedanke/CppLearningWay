#include "widget.h"
#include "ui_widget.h"
#include <QPushButton>
#include "mypushbutton.h"
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    //    // 按钮
    //    QPushButton * btn = new QPushButton;
    //    // 顶层弹出
    //    btn->show();

    //    // 显示到当前窗口，需要依赖于当前窗口
    //    btn->setParent(this);
    //    // 显示文本
    //    btn->setText("Button 按钮");

    //    // 按钮 2
    //    QPushButton * btn2 = new QPushButton("Button 按钮2", this);

    //    // 移动 btn2
    //    btn2->move(100,100);
    //    // 重置窗口大小
    //    this->resize(300,400);
    //    // 重置 btn2 大小
    //    btn2->resize(100,100);
    //    // 窗口标题
    //    this->setWindowTitle("主窗口标题");
    //    // 设置窗口默认大小，不能缩放
    //    this->setFixedSize(400,500);

    // 创建自定义按钮
    MyPushButton * myBtn = new MyPushButton;
    // 增加到对象树上
    myBtn->setParent(this);
    myBtn->setText("我的按钮");
    myBtn->move(20,20);
    /*
    Widget 的析构函数
    MyPushButton 的析构函数
    */
}

Widget::~Widget()
{
    qDebug()<<"Widget 的析构函数";
    delete ui;
}

