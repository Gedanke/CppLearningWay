#include "mypushbutton.h"
#include <QDebug>

MyPushButton::MyPushButton(QWidget *parent) : QPushButton(parent)
{

}

MyPushButton::~MyPushButton()
{
    qDebug()<<"MyPushButton 的析构函数";
}
