#ifndef SENDEMAIL_H
#define SENDEMAIL_H

#include <QThread>
#include <QMutex>
#include <QStringList>

class SendEmail : public QThread
{
    Q_OBJECT
public:
    // 单例模式
    static SendEmail *Instance();

    explicit SendEmail(QObject *parent = nullptr);

    ~SendEmail();

protected:
    void run() override;

private:
    // 维护指针
    static QScopedPointer<SendEmail> self;

    // 互斥量
    QMutex mutex;

    // 锁
    volatile bool stopped;

    // 邮件标题
    QString emailTitle;
    // 发件人邮箱
    QString sendEmailAddress;
    // 发件人密码
    QString sendEmailPassword;
    // 收件人邮箱，多个邮箱可用 ; 分开
    QString receiveEmailAddresses;
    // 正文
    QStringList contents;
    // 附件
    QStringList fileNames;

signals:
    void receiveEmailResult(const QString &result);

public slots:
    void stop();
    void setEmailTitle(const QString &emailTitle);
    void setSendEmailAddress(const QString &sendEmailAddress);
    void setSendEmailPassword(const QString &sendEmailPassword);
    void setReceiveEmailAddresses(const QString &receiveEmailAddresses);
    void append(const QString &content,const QString &fileName);

};

#endif // SENDEMAIL_H
