#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // 给新建添加小图标
    //    ui->actionnew->setIcon(QIcon("D:/Luffy.png"));

    // 资源文件的添加 ": + 前缀 + 文件名称"

    //    ui->actionnew->setIcon(QIcon(":/Image/Luffy.png"));
    ui->actionnew->setIcon(QIcon(":/luffy_open"));

    ui->actionopen_recently->setIcon(QIcon(":/Image/LuffyQ.png"));
}

MainWindow::~MainWindow()
{
    delete ui;
}

