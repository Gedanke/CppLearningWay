#include "chooselevelscene.h"
#include "mypushbutton.h"
#include <QMenuBar>
#include <QPainter>
#include <QTimer>
#include <QLabel>
#include <QSound>

ChooseLevelScene::ChooseLevelScene(QWidget *parent) : QMainWindow(parent)
{
    // 初始化
    this->initScene();
    // 返回按钮
    this->initBack();
    // 选择关卡按钮
    this->initLevel();
}

// 初始化窗口
void ChooseLevelScene::initScene(){
    // 设置窗口固定大小
    this->setFixedSize(320,580);
    // 设置图标
    this->setWindowIcon(QPixmap(":/res/Coin0001.png"));
    // 设置标题
    this->setWindowTitle("选择关卡");

    // 场景菜单栏
    QMenuBar* bar=this->menuBar();
    this->setMenuBar(bar);
    // 创建开始菜单
    QMenu* startMenu=bar->addMenu("开始");
    // 创建按钮菜单项
    QAction* quitAction=startMenu->addAction("退出");

    // 返回音效
    QSound* backSound=new QSound(":/res/BackButtonSound.wav",this);

    // 点击退出，退出按钮
    this->connect(quitAction,&QAction::triggered,[=](){
        backSound->play();
        this->close();
    });
}

// 返回按钮功能
void ChooseLevelScene::initBack(){
    // 返回按钮
    MyPushButton* closeBtn=new MyPushButton(":/res/BackButton.png",":/res/BackButtonSelected.png");
    closeBtn->setParent(this);
    closeBtn->move(this->width()-closeBtn->width(),this->height()-closeBtn->height());

    // 返回音效
    QSound* backSound=new QSound(":/res/BackButtonSound.wav",this);

    // 返回按钮功能
    this->connect(closeBtn,&MyPushButton::clicked,[=](){
        backSound->play();
        QTimer::singleShot(500,this,[=](){
            this->hide();
            // 触发自定义信号
            emit this->chooseSceneBack();
        });
    });
}

// 选择关卡按钮功能
void ChooseLevelScene::initLevel(){
    // 选择关卡音效
    QSound* chooseSound=new QSound(":/res/TapButtonSound.wav",this);

    for(int i=0;i<20;i++){
        MyPushButton* menuBtn=new MyPushButton(":/res/LevelIcon.png");
        menuBtn->setParent(this);
        menuBtn->move(25+(i%4)*70,130+(i/4)*70);

        // 监听选择关卡按钮的信号槽
        this->connect(menuBtn,&MyPushButton::clicked,[=](){
            // qDebug() <<"您选择的是第 "<< i+1 << " 关";
            // 选择关卡音效
            chooseSound->play();

            if(this->pScene==NULL){
                // 游戏场景最好别复用，直接移除掉创建新的场景
                // 隐藏当前窗口
                this->hide();
                // 将选择的关卡号传入给 PlayerScene
                this->pScene=new PlayScene(i+1);
                this->pScene->setGeometry(this->geometry());
                // 展现具体关卡窗口
                this->pScene->show();

                // 监听游戏场景中点击返回按钮，发送的自定义信号
                this->connect(this->pScene,&PlayScene::chooseSceneBack,[=](){
                    this->setGeometry(this->pScene->geometry());
                    this->show();
                    delete this->pScene;
                    this->pScene=NULL;
                });
            }
        });

        // 按钮上显示文字
        QLabel* label=new QLabel;
        label->setParent(this);
        label->setFixedSize(menuBtn->width(),menuBtn->height());
        label->setText(QString::number(i+1));
        // 居中
        label->setAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
        label->move(25+(i%4)*70,130+(i/4)*70);
        // 鼠标事件穿透
        label->setAttribute(Qt::WA_TransparentForMouseEvents,true);
    }
}

// 背景设置
void ChooseLevelScene::paintEvent(QPaintEvent *){
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/res/OtherSceneBg.png");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);

    // 加载标题
    pix.load(":/res/Title.png");
    painter.drawPixmap((this->width()-pix.width())/2,30,pix.width(),pix.height(),pix);
}
