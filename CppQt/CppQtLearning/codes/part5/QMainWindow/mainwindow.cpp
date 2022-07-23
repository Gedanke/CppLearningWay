#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMenuBar>
#include <QToolBar>
#include <QStatusBar>
#include <QLabel>
#include <QDockWidget>
#include <QTextEdit>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->resize(600,500);
    // 创建菜单栏，至多有一个，系统创建，并使用 set
    QMenuBar *bar = menuBar();
    this->setMenuBar(bar);

    // 创建菜单
    QMenu *fileMenu = bar->addMenu("文件");
    QMenu *editMenu = bar->addMenu("编辑");
    QMenu *exitMenu = bar->addMenu("退出");

    // 创建菜单项
    QAction *newAction = fileMenu->addAction("新建");
    QAction *openAction = fileMenu->addAction("打开");
    QAction *recentAction = fileMenu->addAction("最近打开");
    // 添加分割线
    fileMenu->addSeparator();
    QAction *closeAction = fileMenu->addAction("关闭");

    // 工具栏，可以有多个，堆区创建，对象自己调用
    QToolBar *toolBar = new QToolBar(this);
    this->addToolBar(Qt::LeftToolBarArea,toolBar);

    // 设置只允许左右停靠
    toolBar->setAllowedAreas(Qt::LeftToolBarArea | Qt::RightToolBarArea);

    // 设置浮动
    toolBar->setFloatable(false);

    // 设置移动
    //    toolBar->setMovable(false);

    // 工具栏中放入小的部件
    toolBar->addAction(newAction);
    toolBar->addAction(openAction);
    // 添加分割线
    toolBar->addSeparator();
    toolBar->addAction(recentAction);

    // 状态栏，至多一个
    QStatusBar *stBar = statusBar();
    this->setStatusBar(stBar);

    QLabel *label1 = new QLabel("左侧提示信息",this);
    stBar->addWidget(label1);

    QLabel *label2 = new QLabel("右侧提示信息",this);
    stBar->addPermanentWidget(label2);

    QLabel *label12 = new QLabel("字数统计",this);
    stBar->addWidget(label12);

    // 铆接部件(浮动窗口)，只能有一个
    QDockWidget *dock = new QDockWidget("浮动窗口",this);
    //    this->addDockWidget(Qt::TopDockWidgetArea,dock);
    this->addDockWidget(Qt::BottomDockWidgetArea,dock);

    // 只允许左右停靠
    dock->setAllowedAreas(Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea);

    // 核心部件，只能有一个
    QTextEdit *edit = new QTextEdit(this);
    this->setCentralWidget(edit);

}

MainWindow::~MainWindow()
{
    delete ui;
}

