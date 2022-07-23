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

