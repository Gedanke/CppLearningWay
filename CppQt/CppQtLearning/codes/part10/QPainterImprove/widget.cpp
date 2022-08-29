#include "widget.h"
#include "ui_widget.h"
#include <QPainter>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    this->pos=0;
    // 点击移动按钮，移动图片
    this->connect(ui->pushButton,&QPushButton::clicked,[=](){
        this->pos+=20;

        // 手动调用绘图事件
        this->update();
    });
}

Widget::~Widget()
{
    delete ui;
}

// 绘图事件
void Widget::paintEvent(QPaintEvent *event){
    // 高级设置
    QPainter painter(this);

    //    painter.drawEllipse(QPoint(100,100),50,50);

    // 设置抗锯齿效果，效率稍微低
    //    painter.setRenderHint(QPainter::Antialiasing);

    //    painter.drawEllipse(QPoint(300,300),50,50);

    //    painter.drawRect(QRect(20,20,50,50));

    // 移动画家
    //    painter.translate(100,0);

    // 保存画家状态(100,0)
    //    painter.save();

    //    painter.drawRect(QRect(20,20,50,50));

    //    painter.translate(100,0);

    // 取出画家状态(100,0)
    //    painter.restore();

    //    painter.drawRect(QRect(20,20,50,50));

    // 画资源图片

    // 如果超出屏幕，强制回到起点
    if(this->pos > this->width()){
        this->pos=0;
    }
    painter.drawPixmap(this->pos,40,QPixmap(":/Image/Luffy.png"));

}
