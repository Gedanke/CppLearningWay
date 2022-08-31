#ifndef PLAYSCENE_H
#define PLAYSCENE_H

#include "mycoin.h"
#include <QMainWindow>

class PlayScene : public QMainWindow
{
    Q_OBJECT

public:
    // 具体选择的关卡号
    int levalIndex;

    // 二维数组数据
    int gameArray[4][4];

    // 金币按钮数组
    MyCoin* coinBtn[4][4];

    // 是否胜利
    bool isWin=false;

public:
    explicit PlayScene(QWidget *parent = nullptr);

    PlayScene(int index);

    // 重写绘图事件
    void paintEvent(QPaintEvent *) override;

signals:
    void chooseSceneBack();

public slots:

};

#endif // PLAYSCENE_H
