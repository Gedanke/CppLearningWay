#ifndef CLIENTWIDGET_H
#define CLIENTWIDGET_H

#include <QWidget>
#include <QTcpSocket>
#include <QHostAddress>
#include <QMessageBox>
#include <QDebug>

QT_BEGIN_NAMESPACE
namespace Ui { class ClientWidget; }
QT_END_NAMESPACE

class ClientWidget : public QWidget
{
    Q_OBJECT

public:
    ClientWidget(QWidget *parent = nullptr);
    ~ClientWidget();

private slots:
    // 发送消息
    void on_btnSend_clicked();

    // 连接服务器
    void on_btnConnect_clicked();

    // 和服务器连接成功
    void onConnected();

    // 和服务器断开连接
    void onDisConnected();

    // 接收聊天消息
    void onReadyRead();

    // 连接服务器异常
    void onError();

private:
    Ui::ClientWidget *ui;

    // 当前客户端状态，在线/离线
    bool status;

    // 和服务器通信的套接字
    QTcpSocket tcpSocket;

    // 服务器端口
    QHostAddress serverIp;

    // 服务器端口
    quint16 serverPort;

    // 聊天室呢称
    QString userName;
};
#endif // CLIENTWIDGET_H
