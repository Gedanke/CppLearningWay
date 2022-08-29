#include "widget.h"
#include "ui_widget.h"
#include <QBitmap>
#include <QPainter>
#include <QPicture>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    // QPixmap 做绘图设备，对不同平台做了显示的优化
    //    QPixmap pix(300,300);
    //    QPainter painter(&pix);

    //    pix.fill(Qt::white);
    //    painter.setPen(QPen(Qt::red));
    //    painter.drawEllipse(QPoint(150,150),100,100);

    //    pix.save("pix.png");

    // QImage 做绘图设备，不同平台下显示效果一致，可以对像素的访问做了优化
    //    QImage img(300,300,QImage::Format_RGB32);

    //    img.fill(Qt::white);

    //    QPainter painter(&img);
    //    painter.setPen(QPen(Qt::green));
    //    painter.drawEllipse(QPoint(150,150),100,100);
    //    img.save("img.png");

    // QPicture 纪录和重现绘图指令
    QPicture pic;
    QPainter painter;
    painter.begin(&pic);

    painter.setPen(QPen(Qt::blue));
    painter.drawEllipse(QPoint(150,150),100,100);

    painter.end();
    pic.save("pic.zt");

}

Widget::~Widget()
{
    delete ui;
}

// 绘图事件
void Widget::paintEvent(QPaintEvent *event){
    this->demo1();
    QImage img;
    img.load(":/Image/Luffy.png");

    // 修改像素点
    //    for(int i=100;i<150;i++){
    //        for(int j=100;j<150;j++){
    //            QRgb value = qRgb(255,0,0);
    //            img.setPixel(i,j,value);
    //        }
    //    }

    //    QPainter painter(this);
    //    painter.drawImage(0,0,img);

    // 重现命令
    //    QPicture pic;
    //    pic.load("pic.zt");
    //    painter.drawPicture(0,0,pic);
}

// demo1
void Widget::demo1(){
    QPixmap pixmap(":/Image/butterfly.png");
    QPixmap pixmap1(":/Image/butterfly1.png");
    QBitmap bitmap(":/Image/butterfly.png");
    QBitmap bitmap1(":/Image/butterfly1.png");

    QPainter painter(this);
    painter.drawPixmap(0, 0, pixmap);
    painter.drawPixmap(200, 0, pixmap1);
    painter.drawPixmap(0, 130, bitmap);
    painter.drawPixmap(200, 130, bitmap1);
}
