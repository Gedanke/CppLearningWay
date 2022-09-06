#include "widget.h"
#include "ui_widget.h"
#include "sendemail.h"
#include <QFileDialog>
#include <QMessageBox>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->initForm();
}

Widget::~Widget()
{
    delete ui;
}

//
bool Widget::check(){
    if (ui->lineEditEmail->text() == "") {
        QMessageBox::critical(this, "错误", "用户名不能为空!");
        ui->lineEditEmail->setFocus();
        return false;
    }

    if (ui->lineEditPassword->text() == "") {
        QMessageBox::critical(this, "错误", "用户密码不能为空!");
        ui->lineEditPassword->setFocus();
        return false;
    }

    if (ui->lineEditEmail->text() == "") {
        QMessageBox::critical(this, "错误", "发件人不能为空!");
        ui->lineEditEmail->setFocus();
        return false;
    }

    if (ui->lineEditReceive->text() == "") {
        QMessageBox::critical(this, "错误", "收件人不能为空!");
        ui->lineEditReceive->setFocus();
        return false;
    }

    if (ui->lineEditTitle->text() == "") {
        QMessageBox::critical(this, "错误", "邮件标题不能为空!");
        ui->lineEditTitle->setFocus();
        return false;
    }

    return true;
}

void Widget::on_btnSend_clicked()
{
    if(!this->check()){
        return;
    }

    SendEmail::Instance()->setEmailTitle(ui->lineEditTitle->text());
    SendEmail::Instance()->setSendEmailAddress(ui->lineEditEmail->text());
    SendEmail::Instance()->setSendEmailPassword(ui->lineEditPassword->text());
    SendEmail::Instance()->setReceiveEmailAddresses(ui->lineEditReceive->text());

    // 配置好后，使用 append() 方法进行发送邮件
    SendEmail::Instance()->append(ui->textBrowser->toHtml(),ui->lineEditFile->text());
}

void Widget::on_btnSelect_clicked()
{
    QFileDialog dialog(this);
    dialog.setFileMode(QFileDialog::ExistingFiles);

    if(dialog.exec()){
        ui->lineEditFile->clear();
        QStringList files=dialog.selectedFiles();
        ui->lineEditFile->setText(files.join(";"));
    }
}

void Widget::on_comboBoxAddress_currentIndexChanged(int index)
{
    if(index==2){
        ui->comboBoxPort->setCurrentIndex(1);
        ui->checkBoxSSL->setChecked(true);
    }else{
        ui->comboBoxPort->setCurrentText(0);
        ui->checkBoxSSL->setChecked(false);
    }
}

void Widget::on_comboBoxPort_currentIndexChanged(int index)
{
    if(index==1){
        ui->checkBoxSSL->setChecked(true);
    }else{
        ui->checkBoxSSL->setChecked(false);
    }
}

//
void Widget::initForm(){
    ui->comboBoxAddress->setCurrentIndex(1);
    void(SendEmail::*send) (const QString&)=&SendEmail::receiveEmailResult;
    void(Widget::*receive) (const QString&)=&Widget::reveiveEmailResult;
    this->connect(SendEmail::Instance(),send,this,receive);
    SendEmail::Instance()->start();
}

//
void Widget::reveiveEmailResult(const QString& result){
    QMessageBox::information(this,"提示",result);
}
