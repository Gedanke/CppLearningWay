#include "widget.h"
#include "ui_widget.h"
#include "smallwidget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    SmallWidget sw;
}

Widget::~Widget()
{
    delete ui;
}

