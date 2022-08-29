#include "widget.h"
#include "ui_widget.h"
#include <QtDebug>
#include <QFileDialog>
#include <QMessageBox>
#include <QFile>
#include <QTextCodec>
#include <QFileInfo>
#include <QDateTime>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    ui->pushButton->setText("打开");
    // 点击按钮，弹出文件对话框，选择文件
    this->connect(ui->pushButton,&QPushButton::clicked,[=](){
        QString filePath = QFileDialog::getOpenFileName(this,"打开文件","D:\\");
        qDebug()<<filePath;

        if(filePath.isEmpty()){
            QMessageBox::warning(this,"警告","您未选择任何文件!");
            return ;
        }
        else{
            // 文件路径放入 lineEdit 中
            ui->lineEdit->setText(filePath);

            QFileInfo fileInfo(filePath);
            QByteArray array;
            array.append(
                        "文件后缀名: "+fileInfo.suffix()+
                        "\n文件大小: "+fileInfo.size()+
                        "\n文件名: "+fileInfo.fileName()+
                        "\n文件路径: "+fileInfo.filePath()+
                        "\n文件日期: "+fileInfo.created().toString("yyyy-mm-dd hh:mm:ss")+
                        "\n最后修改日期: "+fileInfo.lastModified().toString("yyyy-mm-dd hh:mm:ss")
                        );
            ui->textEdit->setText(array);
        }
    });
}

Widget::~Widget()
{
    delete ui;
}

