#ifndef CHOOSELEVELSCENE_H
#define CHOOSELEVELSCENE_H

#include "playscene.h"
#include <QMainWindow>

class ChooseLevelScene : public QMainWindow
{
    Q_OBJECT
public:
    explicit ChooseLevelScene(QWidget *parent = nullptr);

    // 初始化窗口
    void initScene();

    // 返回按钮功能
    void initBack();

    // 选择关卡按钮功能
    void initLevel();

    // 背景设置
    void paintEvent(QPaintEvent *) override;

public:
    PlayScene* pScene=NULL;

signals:
    // 点击返回按钮后，抛出自定义信号
    void chooseSceneBack();

public slots:

};

#endif // CHOOSELEVELSCENE_H
