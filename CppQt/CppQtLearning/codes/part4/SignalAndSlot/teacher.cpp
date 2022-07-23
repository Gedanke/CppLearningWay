#include "teacher.h"
#include <QDebug>

Teacher::Teacher(QObject *parent) : QObject(parent)
{
    qDebug()<<"Teacher 构造";
}

Teacher::~Teacher()
{
    qDebug()<<"Teacher 析构";
}
