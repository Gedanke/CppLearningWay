#ifndef MAINSCENE_H
#define MAINSCENE_H

#include <QMainWindow>
#include "chooselevelscene.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainScene; }
QT_END_NAMESPACE

class MainScene : public QMainWindow
{
    Q_OBJECT
public:
    // 选择关卡场景
    ChooseLevelScene* chooseScene=new ChooseLevelScene;

public:
    MainScene(QWidget *parent = nullptr);
    ~MainScene();

    // 初始化操作
    void initScene();

    // 设置背景图片
    void paintEvent(QPaintEvent *) override;

    // 创建开始按钮，并实现对应功能
    void initStart();

private:
    Ui::MainScene *ui;
};
#endif // MAINSCENE_H
