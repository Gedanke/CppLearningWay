#include "widget.h"
#include "ui_widget.h"
#include "QMovie"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    // 点击按钮切换 tab
    // 默认显示第一个 tab1
    ui->stackedWidget->setCurrentIndex(0);
    this->connect(ui->pBtn1,&QPushButton::clicked,[=](){
        ui->stackedWidget->setCurrentIndex(0);
    });
    this->connect(ui->pBtn2,&QPushButton::clicked,[=](){
        ui->stackedWidget->setCurrentIndex(1);
    });
    this->connect(ui->pBtn3,&QPushButton::clicked,[=](){
        ui->stackedWidget->setCurrentIndex(2);
    });
    this->connect(ui->pBtn4,&QPushButton::clicked,[=](){
        ui->stackedWidget->setCurrentIndex(3);
    });

    // 下拉框的使用
    ui->comboBox->addItem("风");
    ui->comboBox->addItem("雷");
    ui->comboBox->addItem("水");
    ui->comboBox->addItem("火");

    // 点击按钮选择下拉框内容
    this->connect(ui->pBtnLei,&QPushButton::clicked,[=](){
//        ui->comboBox->setCurrentIndex(1);
        ui->comboBox->setCurrentText("雷");
    });

    // 利用 QLabel 显示图片
    ui->label_image->setPixmap(QPixmap(":/Image/down.png"));

    // 利用 QLabel 显示动图
    QMovie* movie=new QMovie(":/Image/mario.gif");
    ui->label_gif->setMovie(movie);
    movie->start();
}

Widget::~Widget()
{
    delete ui;
}

