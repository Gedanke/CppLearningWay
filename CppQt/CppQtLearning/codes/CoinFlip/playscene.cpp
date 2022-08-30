#include "playscene.h"
#include "mypushbutton.h"
#include "mycoin.h"
#include <QMenu>
#include <QMenuBar>
#include <QPainter>
#include <QTimer>
#include <QLabel>

PlayScene::PlayScene(QWidget *parent) : QMainWindow(parent)
{

}

PlayScene::PlayScene(int index){
    // qDebug()<<"当前关卡为"<<index;
    // 记录用户选择的具体关卡号
    this->levalIndex=index;
    // 设置窗口固定大小
    this->setFixedSize(320,580);
    // 设置图片
    this->setWindowIcon(QPixmap(":/res/Coin0001.png"));
    // 标题
    this->setWindowTitle("翻金币");

    // 创建菜单栏
    QMenuBar* bar=this->menuBar();
    this->setMenuBar(bar);
    // 创建开始菜单
    QMenu* startMenu=bar->addMenu("开始");
    // 创建按钮菜单项
    QAction* quitAction=startMenu->addAction("退出");
    // 点击退出，退出游戏
    this->connect(quitAction,&QAction::triggered,[=](){
        this->close();
    });

    // 返回按钮
    MyPushButton* closeBtn=new MyPushButton(":/res/BackButton.png",":/res/BackButtonSelected.png");
    closeBtn->setParent(this);
    closeBtn->move(this->width()-closeBtn->width(),this->height()-closeBtn->height());

    // 返回按钮功能实现
    this->connect(closeBtn,&MyPushButton::clicked,[=](){
        QTimer::singleShot(500,this,[=](){
            this->hide();
            // 触发自定义信号，关闭自身，该信号写到 signals 下做声明
            emit this->chooseSceneBack();
        });
    });

    // 创建具体用户选择的关卡标签
    QLabel* label=new QLabel;
    label->setParent(this);
    QFont font;
    font.setFamily("华文新魏");
    font.setPointSize(16);
    label->setFont(font);

    QString str=QString("Leavel: %1").arg(this->levalIndex);
    label->setText(str);
    label->setGeometry(30,this->height()-50,120,50);

    // 创建金币背景图片
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            // 绘制背景图片
            QLabel* label=new QLabel;
            label->setParent(this);

            label->setGeometry(0,0,50,50);
            label->setPixmap(QPixmap(":/res/BoardNode.png"));
            label->move(57+i*50,200+j*50);

            // 金币对象
            MyCoin* coin=new MyCoin(":/res/Coin0001.png");
            coin->setParent(this);
            coin->move(59+i*50,200+j*50);
        }
    }
}

// 重写绘图事件
void PlayScene::paintEvent(QPaintEvent *){
    // 加载背景
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/res/PlayLevelSceneBg.png");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);

    // 加载标题
    pix.load(":/res/Title.png");
    pix=pix.scaled(pix.width()/2,pix.height()/2);
    painter.drawPixmap(10,30,pix.width(),pix.height(),pix);
}
