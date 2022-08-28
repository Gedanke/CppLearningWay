#ifndef MYLABEL_H
#define MYLABEL_H

#include <QWidget>
#include "QLabel"

class MyLabel : public QLabel
{
    Q_OBJECT
public:
    explicit MyLabel(QWidget *parent = nullptr);

    // 鼠标进入
    void enterEvent(QEvent *) override;

    // 鼠标离开
    void leaveEvent(QEvent *) override;

    // 鼠标移动
    void mouseMoveEvent(QMouseEvent *ev) override;

    // 鼠标按下
    void mousePressEvent(QMouseEvent *ev) override;

    // 鼠标释放
    void mouseReleaseEvent(QMouseEvent *ev) override;

    // 事件分发器
    bool event(QEvent *e) override;

signals:

};

#endif // MYLABEL_H
