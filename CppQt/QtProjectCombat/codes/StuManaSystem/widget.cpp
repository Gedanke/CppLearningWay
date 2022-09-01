#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    this->createDB();
    this->createTable();
    this->queryTable();
}

Widget::~Widget()
{
    delete ui;
}

// 创建数据库
void Widget::createDB(){

}

// 创建数据表
void Widget::createTable(){

}

// 查询
void Widget::queryTable(){

}

// 插入操作槽函数
void Widget::on_btnInsert_clicked()
{

}

// 删除操作槽函数
void Widget::on_btnDelete_clicked()
{

}

// 修改操作槽函数
void Widget::on_btnModify_clicked()
{

}

// 排序操作槽函数
void Widget::on_btnSort_clicked()
{

}
