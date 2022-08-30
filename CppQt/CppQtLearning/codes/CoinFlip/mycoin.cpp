#include "mycoin.h"
#include <QDebug>

//MyCoin::MyCoin(QWidget *parent) : QWidget(parent)
//{

//}

MyCoin::MyCoin(QString butImg){
    QPixmap pixmap;
    bool ret=pixmap.load(butImg);
    if(!ret){
        qDebug()<<butImg<<"加载图片失败!";
    }

    this->setFixedSize(pixmap.width(),pixmap.height());
    this->setStyleSheet("QPushButton{border:0px;}");
    this->setIcon(pixmap);
    this->setIconSize(QSize(pixmap.width(),pixmap.height()));
}
