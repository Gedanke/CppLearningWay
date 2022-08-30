#ifndef PLAYSCENE_H
#define PLAYSCENE_H

#include <QMainWindow>

class PlayScene : public QMainWindow
{
    Q_OBJECT

public:
    // 具体选择的关卡号
    int levalIndex;

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
