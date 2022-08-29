#include "widget.h"
#include "ui_widget.h"
#include <QtDebug>
#include <QFileDialog>
#include <QMessageBox>
#include <QFile>
#include <QTextCodec>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    ui->pushButton->setText("打开");
    // 点击按钮，弹出文件对话框，选择文件
    this->connect(ui->pushButton,&QPushButton::clicked,[=](){
        QString filePath = QFileDialog::getOpenFileName(this,"打开文件","C:\\");
        qDebug()<<filePath;

        if(filePath.isEmpty()){
            QMessageBox::warning(this,"警告","您未选择任何文件!");
            return ;
        }
        else{
            // 文件路径放入 lineEdit 中
            ui->lineEdit->setText(filePath);

            // 文本编码格式类，文件的第一个字符可以判断文件编码格式
            QTextCodec* codec = QTextCodec::codecForName("utf-8");

            // 将文件内容读取到 textEdit 中
            QFile file(filePath);

            // 指定打开方式
            file.open(QIODevice::ReadOnly);

            QByteArray array;
            // 将全部内容读入
            array = file.readAll();

            // 一行行读取
            while (!file.atEnd()) {
                array.append(file.readLine());
            }

            ui->textEdit->setText(codec->toUnicode(array));
            file.close();

            // 写文件
            file.open(QIODevice::Append);
            file.write("\n这是追加的内容");
            file.close();
        }
    });
}

Widget::~Widget()
{
    delete ui;
}

