#ifndef MYPUSHBUTTON_H
#define MYPUSHBUTTON_H

#include <QPushButton>

class MyPushButton : public QPushButton
{
    Q_OBJECT

public:
    QString normalImgPath;  // 默认显示图片路径
    QString pressedImgPath; // 按下后显示图片路径

public:
    explicit MyPushButton(QWidget *parent = nullptr);

    // normalImg 代表正常显示的图片
    // pressImg 代表按下后显示的图片，默认为空
    MyPushButton(QString normalImg, QString pressImg = "");

    // 特效1
    void zoom1();

    // 特效2
    void zoom2();

    // 鼠标按下事件
    void mousePressEvent(QMouseEvent *e) override;

    // 鼠标释放事件
    void mouseReleaseEvent(QMouseEvent *e) override;


signals:
    public slots:

};

#endif // MYPUSHBUTTON_H
