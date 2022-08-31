#include "playscene.h"
#include "mypushbutton.h"
#include "mycoin.h"
#include "dataconfig.h"
#include <QMenu>
#include <QMenuBar>
#include <QPainter>
#include <QTimer>
#include <QLabel>
#include <QDebug>
#include <QPropertyAnimation>
#include <QSound>

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

    // 返回音效
    QSound* backSound=new QSound(":/res/BackButtonSound.wav",this);

    // 返回按钮功能实现
    this->connect(closeBtn,&MyPushButton::clicked,[=](){
        backSound->play();
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

    // 初始化数组
    dataConfig config;
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            this->gameArray[i][j]=config.mData[this->levalIndex][i][j];
        }
    }

    // 胜利图片
    QLabel* winLabel=new QLabel;
    QPixmap tmpPix;
    tmpPix.load(":/res/LevelCompletedDialogBg.png");
    winLabel->setGeometry(0,0,tmpPix.width(),tmpPix.height());
    winLabel->setPixmap(tmpPix);
    winLabel->setParent(this);
    winLabel->move((this->width()-tmpPix.width())/2,-tmpPix.height());

    // 翻金币音效
    QSound* flipSound=new QSound(":/res/ConFlipSound.wav",this);
    // 胜利音效
    QSound* winSound=new QSound(":/res/LevelWinSound.wav",this);

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
            QString img;
            if(this->gameArray[i][j]==1){
                img = ":/res/Coin0001.png";
            }
            else
            {
                img = ":/res/Coin0008.png";
            }
            MyCoin* coin=new MyCoin(img);

            coin->setParent(this);
            coin->move(59+i*50,200+j*50);
            // 记录 x 坐标
            coin->posX=i;
            // 记录 y 坐标
            coin->posY=j;
            // 记录正反标志
            coin->flag=gameArray[i][j];

            // 金币按钮数组
            this->coinBtn[i][j]=coin;

            // 监听每个按钮的点击效果，翻转金币
            this->connect(coin,&MyCoin::clicked,[=](){
                // qDebug()<<"点击的位置: x = "<<coin->posX<<" y = "<<coin->posY;

                // 翻金币音效
                flipSound->play();

                // 点击按钮未全部翻动周围其他金币前，所有的金币都不允许翻动
                for(int _i=0;_i<4;_i++){
                    for(int _j=0;_j<4;_j++){
                        coinBtn[_i][_j]->isWin=true;
                    }
                }

                coin->changeFlag();
                // 数组内部记录的标志同步修改
                this->gameArray[i][j]=this->gameArray[i][j]==0?1:0;

                // 延迟翻动周围四个金币
                QTimer::singleShot(300,this,[=](){
                    // 边界判断
                    // 右边
                    if(coin->posX+1<=3){
                        this->coinBtn[coin->posX+1][coin->posY]->changeFlag();
                        this->gameArray[coin->posX+1][coin->posY]=this->gameArray[coin->posX+1][coin->posY]==0?1:0;
                    }
                    // 左边
                    if(coin->posX-1>=0){
                        this->coinBtn[coin->posX-1][coin->posY]->changeFlag();
                        this->gameArray[coin->posX-1][coin->posY]=this->gameArray[coin->posX-1][coin->posY]==0?1:0;
                    }
                    // 下边
                    if(coin->posY+1<=3){
                        this->coinBtn[coin->posX][coin->posY+1]->changeFlag();
                        this->gameArray[coin->posX][coin->posY+1]=this->gameArray[coin->posX][coin->posY+1]==0?1:0;
                    }
                    // 上边
                    if(coin->posY-1>=0){
                        this->coinBtn[coin->posX][coin->posY-1]->changeFlag();
                        this->gameArray[coin->posX][coin->posY-1]=this->gameArray[coin->posX][coin->posY-1]==0?1:0;
                    }

                    // 翻转完成后，可以点击其他金币
                    for(int _i=0;_i<4;_i++){
                        for(int _j=0;_j<4;_j++){
                            coinBtn[_i][_j]->isWin=false;
                        }
                    }

                    // 判断是否胜利
                    this->isWin=true;
                    for(int _i=0;_i<4;_i++){
                        for(int _j=0;_j<4;_j++){
                            // qDebug()<<coinBtn[_i][_j]->flag;
                            if(coinBtn[_i][_j]->flag==false){
                                this->isWin=false;
                                break;
                            }
                        }
                    }
                    if(this->isWin){
                        // 胜利音效
                        winSound->play();

                        qDebug()<<"胜利";
                        // 让每个金币的 isWin 为 true，表示停止翻动其他金币
                        for(int _i=0;_i<4;_i++){
                            for(int _j=0;_j<4;_j++){
                                coinBtn[_i][_j]->isWin=true;
                            }
                        }

                        // 让胜利图片移动下来
                        QPropertyAnimation* animation=new QPropertyAnimation(winLabel,"geometry");
                        animation->setDuration(1000);
                        animation->setStartValue(QRect(winLabel->x(),winLabel->y(),winLabel->width(),winLabel->height()));
                        animation->setEndValue(QRect(winLabel->x(),winLabel->y()+114,winLabel->width(),winLabel->height()));
                        animation->setEasingCurve(QEasingCurve::OutBounce);
                        animation->start();
                    }
                });
            });
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
