#include "serverwidget.h"
#include "ui_serverwidget.h"

ServerWidget::ServerWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ServerWidget)
{
    ui->setupUi(this);
    // 当有客户端向服务端发送连接请求，发送信号 newConnection
    this->connect(&this->tcpServer,&QTcpServer::newConnection,this,&ServerWidget::onNewConnection);
    // 定时器到时间发送信号
    this->connect(&this->timer,&QTimer::timeout,this,&ServerWidget::onTimeOut);
}

ServerWidget::~ServerWidget()
{
    delete ui;
}

// 创建服务器按钮的槽函数
void ServerWidget::on_pushButton_clicked()
{
    // 获取端口
    this->port=ui->lineEdit->text().toShort();
    // 设置服务器 IP 和端口
    if(this->tcpServer.listen(QHostAddress::Any,this->port)){
        qDebug()<<"创建服务器成功!";
        // 禁用按钮和端口
        ui->lineEdit->setEnabled(false);
        ui->pushButton->setEnabled(false);
        QMessageBox::information(this,"Ok","创建服务器成功!");
        // 开启定时器
        this->timer.start(3000);
    }else{
        qDebug()<<"创建服务器失败!";
        QMessageBox::critical(this,"Error","创建");
    }
}

// 响应客户端链接请求的槽函数
void ServerWidget::onNewConnection(){
    // 获取和客户端通信的套接字
    QTcpSocket* tcpClient=this->tcpServer.nextPendingConnection();
    // 保存客户端套接字
    this->tcpClientList.append(tcpClient);
    // 当客户端向服务器发送消息时，通信套接字发送信号 readyRead
    this->connect(tcpClient,&QTcpSocket::readyRead,this,&ServerWidget::onReayRead);
}

// 接收客户端消息的槽函数
void ServerWidget::onReayRead(){
    // 遍历容器，是哪个客户端给服务器发了消息
    for(int i=0;i<this->tcpClientList.size();i++){
        // bytesAvailable: 获取当前套接字等待读取消息字节数
        if(this->tcpClientList.at(i)->bytesAvailable()){
            // 读取消息并保存
            QByteArray buf=this->tcpClientList.at(i)->readAll();
            // 显示聊天消息
            ui->listWidget->addItem(buf);
            ui->listWidget->scrollToBottom();
            // 转发给所有在线的客户端
            this->sendMessage(buf);
        }
    }
}

// 转发聊天消息给其他客户端
void ServerWidget::sendMessage(const QByteArray& buf){
    for(QTcpSocket* tcp : this->tcpClientList){
        tcp->write(buf);
    }
}

// 定时器将执行的槽函数
void ServerWidget::onTimeOut(){
    // 遍历检查容器中保存的客户端套接字是否断开连接，如果是则删除
    for(int i=0;i<this->tcpClientList.size();i++){
        if(this->tcpClientList.at(i)->state()==QAbstractSocket::UnconnectedState){
            this->tcpClientList.removeAt(i);
            i--;
        }
    }
}
