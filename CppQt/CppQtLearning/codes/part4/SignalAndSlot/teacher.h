#ifndef TEACHER_H
#define TEACHER_H

#include <QObject>

class Teacher : public QObject
{
    Q_OBJECT
public:
    explicit Teacher(QObject *parent = nullptr);
    ~Teacher();

    // 自定义信号位置
signals:
    // 返回值为 void
    // 只需要声明，不需要实现
    // 可以有参数，可以发生重载
    void hungry();
    void hungry(QString foodName);

};

#endif // TEACHER_H
