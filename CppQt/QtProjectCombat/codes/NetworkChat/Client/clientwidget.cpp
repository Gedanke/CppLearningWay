#include "clientwidget.h"
#include "ui_clientwidget.h"

ClientWidget::ClientWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ClientWidget)
{
    ui->setupUi(this);

    this->status=false;
    this->connect(&this->tcpSocket,&QTcpSocket::connected,this,&ClientWidget::onConnected);
    this->connect(&this->tcpSocket,&QTcpSocket::disconnected,this,&ClientWidget::onDisConnected);
    this->connect(&this->tcpSocket,&QTcpSocket::readyRead,this,&ClientWidget::onReadyRead);
    // qt4
    // this->connect(&this->tcpSocket,SIGNAL(error(QTcpSocket::SocketError)),this,SLOT(onError()));
    this->connect(&this->tcpSocket,QOverload<QAbstractSocket::SocketError>::of(&QAbstractSocket::error),this,&ClientWidget::onError);
}

ClientWidget::~ClientWidget()
{
    delete ui;
}

// 发送消息
void ClientWidget::on_btnSend_clicked()
{
    // 获取用户输入的消息
    QString str=ui->editSend->text();
    if(str==""){
        return ;
    }
    str=this->userName+": "+str;
    this->tcpSocket.write(str.toUtf8());
    ui->editSend->clear();
}

// 连接服务器
void ClientWidget::on_btnConnect_clicked()
{
    // 离线，建立和服务器的连接
    if(!this->status){
        // 获取服务器 IP
        this->serverIp.setAddress(ui->editAddress->text());
        // 获取服务器端口
        this->serverPort=ui->editPort->text().toUShort();
        // 获取聊天室呢称
        this->userName=ui->editUserName->text();
        // 向服务器发送连接请求
        // 成功发送信号：connected
        // 失败发送信号：error
        this->tcpSocket.connectToHost(this->serverIp,this->serverPort);
    }
    // 在线
    else{
        // 向服务器发送离开聊天室的提示消息
        QString msg=this->userName+": 离开聊天室";
        this->tcpSocket.write(msg.toUtf8());
        // 关闭和服务器的连接，同时发送信号 disconnected
        this->tcpSocket.disconnectFromHost();
    }
}

// 和服务器连接成功
void ClientWidget::onConnected(){
    this->status=true;
    ui->btnSend->setEnabled(true);
    ui->editAddress->setEnabled(false);
    ui->editPort->setEnabled(false);
    ui->editUserName->setEnabled(false);
    ui->btnConnect->setText("离开聊天室");

    // 向服务器发送进入聊天室提示消息
    QString msg=this->userName+": 进入聊天室";
    this->tcpSocket.write(msg.toUtf8());
}

// 和服务器断开连接
void ClientWidget::onDisConnected(){
    this->status=false;
    ui->btnSend->setEnabled(false);
    ui->editAddress->setEnabled(true);
    ui->editPort->setEnabled(true);
    ui->editUserName->setEnabled(true);
    ui->btnConnect->setText("连接服务器");
    // 清空聊天室内容
    ui->listWidget->clear();
}

// 接收聊天消息
void ClientWidget::onReadyRead(){
    if(this->tcpSocket.bytesAvailable()){
        QByteArray buf=this->tcpSocket.readAll();
        ui->listWidget->addItem(buf);
        ui->listWidget->scrollToBottom();
    }
}

// 连接服务器异常
void ClientWidget::onError(){
    // 获取网络异常原因
    QMessageBox::critical(this,"ERROR",this->tcpSocket.errorString());
}


