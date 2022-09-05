#ifndef SERVERWIDGET_H
#define SERVERWIDGET_H

#include <QWidget>
#include <QTcpServer>
#include <QTcpSocket>
#include <QDebug>
#include <QMessageBox>
#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui { class ServerWidget; }
QT_END_NAMESPACE

class ServerWidget : public QWidget
{
    Q_OBJECT

public:
    ServerWidget(QWidget *parent = nullptr);
    ~ServerWidget();

private slots:
    // 创建服务器按钮的槽函数
    void on_pushButton_clicked();
    // 响应客户端链接请求的槽函数
    void onNewConnection();
    // 接收客户端消息的槽函数
    void onReayRead();
    // 转发聊天消息给其他客户端
    void sendMessage(const QByteArray& buf);
    // 定时器将执行的槽函数
    void onTimeOut();

private:
    Ui::ServerWidget *ui;

    QTcpServer tcpServer;

    // 服务器端口
    quint16 port;

    // 保存所有与客户端通信的套接字容器
    QList<QTcpSocket*> tcpClientList;

    // 定时器定时检查无效套接字，并移除
    QTimer timer;

};
#endif // SERVERWIDGET_H
