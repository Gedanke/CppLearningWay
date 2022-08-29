#include "widget.h"
#include "ui_widget.h"
#include <QPainter>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

// 绘图事件
void Widget::paintEvent(QPaintEvent *event){
    QPainter painter(this);

    // 设置画笔
    QPen pen(QColor(255,0,0));

    // 设置画笔宽度
    pen.setWidth(3);

    // 设置画笔风格
    pen.setStyle(Qt::DotLine);

    // 画家拿起笔
    painter.setPen(pen);

    // 画刷
    QBrush brush(Qt::cyan);

    // 设置画刷风格
    brush.setStyle(Qt::Dense4Pattern);

    // 利用画家填充颜色
    painter.setBrush(brush);

    // 画线
    painter.drawLine(QPoint(0,0),QPoint(100,100));

    // 画圆
    painter.drawEllipse(QPoint(100,100),60,50);

    // 画矩形
    painter.drawRect(200,200,120,50);

    // 写字
    painter.drawText(QRect(50,300,100,100),"写一段话，太长了就会换行");
}
