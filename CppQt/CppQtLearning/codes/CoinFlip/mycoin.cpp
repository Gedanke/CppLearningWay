#include "mycoin.h"
#include <QDebug>
#include <QTimer>

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

    // 初始化定时器
    this->timer1=new QTimer(this);
    this->timer2=new QTimer(this);

    // 监听正面翻转的信号槽
    this->connect(this->timer1,&QTimer::timeout,[=](){
        QPixmap pixmap;
        QString str=QString(":/res/Coin000%1.png").arg((this->minP)++);
        pixmap.load(str);

        this->setFixedSize(pixmap.width(),pixmap.height());
        this->setStyleSheet("QPushButton{border:0px;}");
        this->setIcon(pixmap);
        this->setIconSize(QSize(pixmap.width(),pixmap.height()));

        if(this->minP>this->maxP){
            // 如果大于最大值，重置最小值，并停止定时器
            this->minP=1;
            this->isAnimation=false;
            this->timer1->stop();
        }
    });

    // 监听反面翻转的信号槽
    this->connect(this->timer2,&QTimer::timeout,[=](){
        QPixmap pixmap;
        QString str=QString(":/res/Coin000%1.png").arg((this->maxP)--);
        pixmap.load(str);

        this->setFixedSize(pixmap.width(),pixmap.height());
        this->setStyleSheet("QPushButton{border:0px;}");
        this->setIcon(pixmap);
        this->setIconSize(QSize(pixmap.width(),pixmap.height()));

        if(this->maxP<this->minP){
            // 如果小于最大值，重置最大值，并停止定时器
            this->maxP=8;
            this->isAnimation=false;
            this->timer2->stop();
        }
    });
}

// 改变标志，执行翻转效果
void MyCoin::changeFlag(){
    if(this->flag){
        // 如果是正面
        this->timer1->start(30);
        this->isAnimation=true;
        this->flag=false;
    }else{
        // 反面
        this->timer2->start(30);
        this->isAnimation=true;
        this->flag=true;
    }
}

// 重写鼠标按下事件
void MyCoin::mousePressEvent(QMouseEvent *e){
    if(this->isAnimation || this->isWin){
        return;
    }else{
        return QPushButton::mousePressEvent(e);
    }
}
