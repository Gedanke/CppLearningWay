#include "widget.h"
#include "ui_widget.h"
#include "QDebug"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    // 点击设置按钮，将小控件设置到一半位置
    this->connect(ui->pBtnSet,&QPushButton::clicked,[=](){
        ui->widget->setValue(50);
    });

    // 点击获取当前进度
    this->connect(ui->pBtnGet,&QPushButton::clicked,[=](){
        qDebug()<<ui->widget->getValue();
    });
}

Widget::~Widget()
{
    delete ui;
}

