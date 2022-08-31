#ifndef MYCOIN_H
#define MYCOIN_H

#include <QPushButton>

class MyCoin : public QPushButton
{
    Q_OBJECT

public:
    // x 坐标
    int posX;
    // y 坐标
    int posY;
    // 正反标志
    bool flag;

    // 正面翻反面定时器
    QTimer *timer1;
    // 反面翻正面定时器
    QTimer *timer2;

    // 最小图片
    int minP=1;
    // 最大图片
    int maxP=8;

    // 做翻转动画的标志
    bool isAnimation=false;

    // 胜利标志
    bool isWin=false;

public:
    //    explicit MyCoin(QWidget *parent = nullptr);

    MyCoin(QString butImg);

    // 改变标志，执行翻转效果
    void changeFlag();

    // 重写鼠标按下事件
    void mousePressEvent(QMouseEvent *e) override;

signals:

};

#endif // MYCOIN_H
