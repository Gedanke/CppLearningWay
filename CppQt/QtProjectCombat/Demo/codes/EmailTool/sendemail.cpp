#include "sendemail.h"
#include "3rd_smtpclient/smtpmime.h"

#define TIMES qPrintable(QTime::currentTime().toString("hh:mm:ss"))

QScopedPointer<SendEmail> SendEmail::self;

SendEmail *SendEmail::Instance()
{
    // 双重锁定，减少每次开销
    if(SendEmail::self.isNull()){
        static QMutex mutex;
        QMutexLocker locker(&mutex);
        if(SendEmail::self.isNull()){
            SendEmail::self.reset(new SendEmail);
        }
    }
    return SendEmail::self.data();
}

SendEmail::SendEmail(QObject *parent) : QThread(parent)
{
    this->stopped=false;
    this->emailTitle="邮件标题";
    this->sendEmailAddress="xxx@xx.xx";
    this->sendEmailPassword="xxx";
    this->receiveEmailAddresses="xxx@xx.xx";
    this->contents.clear();
    this->fileNames.clear();
}

SendEmail::~SendEmail()
{
    this->stop();
    this->wait(1000);
}

void SendEmail::run(){
    while(!this->stopped){
        int count=this->contents.count();
        if(count>0){
            this->mutex.lock();
            // 取出头部
            QString content=this->contents.takeFirst();
            QString fileName=this->fileNames.takeFirst();
            this->mutex.unlock();

            QString result;
            QStringList list=this->sendEmailAddress.split("@");
            QString tmpSmtp=list.at(1).split(".").at(0);
            int tmpPort=25;

            // QQ 邮箱端口号为 465，必须启用 SSL 协议
            if(tmpSmtp.toUpper() == "QQ"){
                tmpPort=465;
            }
            SmtpClient smtp(
                        QString("smtp.%1.com").arg(tmpSmtp),tmpPort,
                        tmpPort==25?SmtpClient::TcpConnection:SmtpClient::SslConnection
                                    );
            smtp.setUser(this->sendEmailAddress);
            smtp.setPassword(this->sendEmailPassword);

            // 构建邮件主题，包含发件人，收件人附件等
            MimeMessage message;
            message.setSender(new EmailAddress(this->sendEmailAddress));

            // 逐个添加收件人
            QStringList receiver=this->receiveEmailAddresses.split(";");
            for(int i=0;i<receiver.size();i++){
                message.addRecipient(new EmailAddress(receiver.at(i)));
            }

            // 构建邮件标题
            message.setSubject(this->emailTitle);

            // 构建邮件正文
            MimeHtml text;
            text.setHtml(content);
            message.addPart(&text);

            // 构建附件-报警图片
            if(fileName.length()>0){
                QStringList attas=fileName.split(";");
                foreach(QString tmpAtta,attas){
                    QFile* file=new QFile(tmpAtta);
                    if(file->exists()){
                        message.addPart(new MimeAttachment(file));
                    }
                }
            }

            if(!smtp.connectToHost()){
                result="邮件服务器连接失败";
            }else{
                if(!smtp.login()){
                    result="邮件用户登陆失败";
                }else{
                    if(!smtp.sendMail(message)){
                        result="邮件发送失败";
                    }else{
                        result="邮件发送成功";
                    }
                }
            }

            smtp.quit();
            if(!result.isEmpty()){
                emit this->receiveEmailResult(result);
            }
            msleep(1000);
        }
        msleep(100);
    }
    this->stopped=false;
}

void SendEmail::stop(){
    this->stopped=true;
}

void SendEmail::setEmailTitle(const QString &emailTitle){
    this->emailTitle=emailTitle;
}

void SendEmail::setSendEmailAddress(const QString &sendEmailAddress){
    this->sendEmailAddress=sendEmailAddress;
}

void SendEmail::setSendEmailPassword(const QString &sendEmailPassword){
    this->sendEmailPassword=sendEmailPassword;
}

void SendEmail::setReceiveEmailAddresses(const QString &receiveEmailAddresses){
    this->receiveEmailAddresses=receiveEmailAddresses;
}

void SendEmail::append(const QString &content,const QString &fileName){
    this->mutex.lock();
    this->contents.append(content);
    this->fileNames.append(fileName);
    this->mutex.unlock();
}
