#include "mainscene.h"
#include "ui_mainscene.h"
#include "mypushbutton.h"
#include <QPainter>
#include <QTimer>
#include <QSound>

MainScene::MainScene(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainScene)
{
    ui->setupUi(this);

    // 初始化
    this->initScene();

    // 点击退出，实现退出
    this->connect(ui->actionQuit,&QAction::triggered,[=](){
        this->close();
    });

    this->initStart();

    // 监听选择场景的返回按钮
    this->connect(this->chooseScene,&ChooseLevelScene::chooseSceneBack,[=](){
        this->show();
    });
}

MainScene::~MainScene()
{
    delete ui;
}

// 初始化操作
void MainScene::initScene(){
    // 设置窗口固定大小
    this->setFixedSize(320,580);
    // 设置应用图标
    this->setWindowIcon(QPixmap(":/res/Coin0001.png"));
    // 设置窗口标题
    this->setWindowTitle("翻金币");
}

// 设置背景图片
void MainScene::paintEvent(QPaintEvent *){
    // 创建画家，指定绘图设备
    QPainter painter(this);
    // 创建 QPixmap 对象
    QPixmap pix;
    // 加载图片
    pix.load(":/res/PlayLevelSceneBg.png");
    // 绘制背景图片
    painter.drawPixmap(0,0,this->width(),this->height(),pix);

    // 加载标题
    pix.load(":/res/Title.png");
    // 缩放图片
    pix=pix.scaled(pix.width()/2,pix.height()/2);
    // 绘制标题
    painter.drawPixmap(10,30,pix.width(),pix.height(),pix);
}

// 创建开始按钮，并实现对应功能
void MainScene::initStart(){
    QSound* startSound=new QSound(":/res/TapButtonSound.wav",this);

    // 创建开始按钮
    MyPushButton* startBtn=new MyPushButton(":/res/MenuSceneStartButton.png");
    startBtn->setParent(this);
    startBtn->move(this->width()/2 - startBtn->width()/2, this->height()*0.7);

    // 监听事件，执行特效
    this->connect(startBtn,&MyPushButton::clicked,[=](){
        // 开始音效
        startSound->play();
        startBtn->zoom1();
        startBtn->zoom2();

        // 延迟 500 ms，进入选择场景
        QTimer::singleShot(500,this,[=](){
            // 隐藏窗口
            this->hide();
            this->chooseScene->setGeometry(this->geometry());
            // 进入选择窗口
            this->chooseScene->show();

            // 监听选择场景返回按钮
            this->connect(this->chooseScene,&ChooseLevelScene::chooseSceneBack,[=](){
                this->setGeometry(this->chooseScene->geometry());
                // 进入选择窗口
                this->show();
            });
        });
    });
}
