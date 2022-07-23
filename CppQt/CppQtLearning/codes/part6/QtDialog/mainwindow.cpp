#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMenu>
#include <QAction>
#include <QDialog>
#include <QMessageBox>
#include <QDebug>
#include <QColorDialog>
#include <QFileDialog>
#include <QFontDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // 创建菜单栏，至多有一个
    QMenuBar *bar = menuBar();
    this->setMenuBar(bar);

    // 创建菜单
    QMenu *fileMenu = bar->addMenu("文件");
    //    QMenu *editMenu = bar->addMenu("编辑");
    //    QMenu *exitMenu = bar->addMenu("退出");

    // 创建菜单项
    QAction *newAction = fileMenu->addAction("新建");
    QAction *openAction = fileMenu->addAction("打开");

    // 添加分割线
    fileMenu->addSeparator();
    QAction *closeAction = fileMenu->addAction("关闭");

    // 点击新建，创建对话框
    //    this->connect(newAction,&QAction::triggered,this,[=](){
    //        // 对话框分类，模态对话框，非模态对话框
    //        // 模态对话框
    //        //        QDialog dlg(this);
    //        //        dlg.resize(120,50);
    //        //        // 阻塞
    //        //        dlg.exec();
    //        // 非模态对话框
    //        QDialog *dlg = new QDialog(this);
    //        dlg->resize(120,50);
    //        // 关闭对话框窗口不会消耗 dlg，只有关闭主窗口才会消耗
    //        dlg->show();
    //        // 可以设置 dlg 的 WindowAttribute
    //        dlg->setAttribute(Qt::WA_DeleteOnClose);
    //    });

    // QMessageBox 对话框
    // 错误对话框
    //    QMessageBox::critical(this,"错误","critical");

    // 信息提示对话框
    //    QMessageBox::information(this,"信息提示","info");

    // 询问提示对话框
    //    if(QMessageBox::Save == QMessageBox::question(this,"询问","question",QMessageBox::Save | QMessageBox::Cancel,QMessageBox::Cancel)){
    //        qDebug()<<"点击的是保存";
    //    }else{
    //        qDebug()<<"点击的是取消";
    //    }

    // 警告提示对话框
    //    QMessageBox::warning(this,"警告","warning");

    // 颜色对话框
    //    QColor color = QColorDialog::getColor(Qt::red);
    //    qDebug()<<color.red()<<color.green()<<color.blue();

    // 文件对话框
    //    QString fileName = QFileDialog::getOpenFileName(this,"打开文件","D:\\Wnow\\codes\\qt","(*.cpp)");
    //    qDebug()<<fileName;

    // 字体对话框
    bool flag;
    QFont font = QFontDialog::getFont(&flag,QFont("宋体",12));
    qDebug()<<"字体："<<font.family().toUtf8().data()<< "字号："<<font.pointSize()<<" 是否加粗："<<font.bold()<<" 是否倾斜："<<font.italic();

}

MainWindow::~MainWindow()
{
    delete ui;
}

