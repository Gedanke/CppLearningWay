#ifndef STUDENT_H
#define STUDENT_H

#include <QObject>

class Student : public QObject
{
    Q_OBJECT
public:
    explicit Student(QObject *parent = nullptr);
    ~Student();

signals:

    // 自定义槽函数
public slots:
    // Qt5.0 以后，槽函数可以是全局函数、Lambda 表达式，public 作用域下等
    // 返回值为 void
    // 需要声明，也需要有实现
    // 可以有参数，可以发生重载
    void treat();
    void treat(QString foodName);

};

#endif // STUDENT_H
