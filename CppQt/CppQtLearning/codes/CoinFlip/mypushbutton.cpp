#include "mypushbutton.h"
#include <QDebug>
#include <QPropertyAnimation>

MyPushButton::MyPushButton(QWidget *parent) : QPushButton(parent)
{

}

MyPushButton::MyPushButton(QString normalImg, QString pressImg){
    // 成员变量 normalImgPath 保存正常显示图片路径
    this->normalImgPath=normalImg;
    // 成员变量 pressedImgPath 保存按下后显示的图片
    this->pressedImgPath=pressImg;

    // 创建 QPixmap 对象
    QPixmap pix;
    // 判断是否能够加载正常显示的图片
    bool ret=pix.load(this->normalImgPath);
    if(!ret){
        qDebug()<<this->normalImgPath<<" 加载图片失败";
    }

    // 设置图片的固定大小
    this->setFixedSize(pix.width(),pix.height());
    // 设置不规则图片样式表
    this->setStyleSheet("QPushButton{border:0px;}");
    // 设置图标
    this->setIcon(pix);
    // 设置图标大小
    this->setIconSize(QSize(pix.width(),pix.height()));
}

// 特效1
void MyPushButton::zoom1(){
    // 创建动画对象
    QPropertyAnimation* animation=new QPropertyAnimation(this,"geometry");
    // 设置时间对象间隔，单位毫秒
    animation->setDuration(200);
    // 创建起始位置
    animation->setStartValue(QRect(this->x(),this->y(),this->width(),this->height()));
    // 创建结束位置
    animation->setEndValue(QRect(this->x(),this->y()+10,this->width(),this->height()));

    // 设置缓和曲线，QEasingCurve::OutBounce 为弹跳效果
    animation->setEasingCurve(QEasingCurve::OutBounce);
    // 开始执行动画
    animation->start();
}

// 特效2
void MyPushButton::zoom2(){
    // 创建动画对象
    QPropertyAnimation* animation=new QPropertyAnimation(this,"geometry");
    // 设置时间对象间隔，单位毫秒
    animation->setDuration(200);
    // 创建起始位置
    animation->setStartValue(QRect(this->x(),this->y()+10,this->width(),this->height()));
    // 创建结束位置
    animation->setEndValue(QRect(this->x(),this->y(),this->width(),this->height()));

    // 设置缓和曲线，QEasingCurve::OutBounce 为弹跳效果
    animation->setEasingCurve(QEasingCurve::OutBounce);
    // 开始执行动画
    animation->start();
}

// 鼠标按下事件
void MyPushButton::mousePressEvent(QMouseEvent *e){
    if(this->pressedImgPath!=""){
        // 路径不为空
        QPixmap pixmap;
        bool ret=pixmap.load(this->pressedImgPath);
        if(!ret){
            qDebug()<<this->pressedImgPath<<"加载图片失败";
        }

        this->setFixedSize(pixmap.width(),pixmap.height());
        this->setStyleSheet("QPushButton{border:0px;}");
        this->setIcon(pixmap);
        this->setIconSize(QSize(pixmap.width(),pixmap.height()));
    }
    // 交给父类执行按下事件
    return QPushButton::mousePressEvent(e);
}

// 鼠标释放事件
void MyPushButton::mouseReleaseEvent(QMouseEvent *e){
    if(this->normalImgPath!=""){
        // 路径不为空
        QPixmap pixmap;
        bool ret=pixmap.load(this->normalImgPath);
        if(!ret){
            qDebug()<<this->normalImgPath<<"加载图片失败";
        }

        this->setFixedSize(pixmap.width(),pixmap.height());
        this->setStyleSheet("QPushButton{border:0px;}");
        this->setIcon(pixmap);
        this->setIconSize(QSize(pixmap.width(),pixmap.height()));
    }
    // 交给父类执行按下事件
    return QPushButton::mouseReleaseEvent(e);
}
