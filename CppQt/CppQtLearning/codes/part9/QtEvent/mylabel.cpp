#include "mylabel.h"
#include "QDebug"
#include "QMouseEvent"

MyLabel::MyLabel(QWidget *parent) : QLabel(parent)
{
    // 设置鼠标追踪
    this->setMouseTracking(true);
}

// 鼠标进入
void MyLabel::enterEvent(QEvent *){
    //    qDebug()<<"鼠标进入";
}

// 鼠标离开
void MyLabel::leaveEvent(QEvent *){
    //    qDebug()<<"鼠标离开";
}

// 鼠标移动
void MyLabel::mouseMoveEvent(QMouseEvent *ev){
    //    if(ev->buttons() & Qt::LeftButton){
    //        QString str =  QString("鼠标移动了(%1, %2))").arg(ev->x()).arg(ev->y());
    //        qDebug()<<str;
    //    }
    this->setText(QString("<center><h1>Move: (%1, %2)</h1></center>").arg(QString::number(ev->x()),
                                                                          QString::number(ev->y())));

}

// 鼠标按下
void MyLabel::mousePressEvent(QMouseEvent *ev){
    //    if(ev->button()==Qt::LeftButton){
    QString str =  QString("鼠标按下了(%1, %2))").arg(ev->x()).arg(ev->y());
    qDebug()<<str;
    //    }
    //    this->setText(QString("<center><h1>Press:(%1, %2) </h1></center>").arg(QString::number(ev->x()),
    //                                                                           QString::number(ev->y())));

}

// 鼠标释放
void MyLabel::mouseReleaseEvent(QMouseEvent *ev){
    //    if(ev->button()==Qt::LeftButton){
    //        QString str =  QString("鼠标释放了(%1, %2))").arg(ev->x()).arg(ev->y());
    //        qDebug()<<str;
    //    }
    QString msg;
    msg.asprintf("<center><h1>Release: (%d, %d)</h1></center>", ev->x(), ev->y());
    this->setText(msg);
}

// 事件分发器，用途，分发事件
bool MyLabel::event(QEvent *e){
    if(e->type() == QEvent::MouseButtonPress){
        // 如果是鼠标按下，拦截事件，不向下分发
        QMouseEvent* ev = static_cast<QMouseEvent *>(e);
        QString str =  QString("event 鼠标按下了(%1, %2))").arg(ev->x()).arg(ev->y());
        qDebug()<<str;
        return true;
    }

    // 其他事件抛给父类处理
    return QLabel::event(e);
}
