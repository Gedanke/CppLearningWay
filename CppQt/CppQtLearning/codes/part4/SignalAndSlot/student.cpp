#include "student.h"
#include <QDebug>

Student::Student(QObject *parent) : QObject(parent)
{
    qDebug()<<"Student 构造";
}

void Student::treat()
{
    qDebug()<<"请老师吃饭";
}

void Student::treat(QString foodName)
{
    // QString 转为 char*
    // 先通过 .toUtf8() 转为 QByteArray 类型
    qDebug()<<"请老师吃饭，老师想吃 "<<foodName.toUtf8().data();
}

Student::~Student()
{
    qDebug()<<"Student 析构";
}
