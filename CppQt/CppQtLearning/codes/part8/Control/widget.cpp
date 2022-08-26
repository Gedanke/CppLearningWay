#include "widget.h"
#include "ui_widget.h"
#include "QtDebug"
#include "QRadioButton"
#include "QCheckBox"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    // 单选按钮默认选择
    ui->rbtn_women->setChecked(true);
    // 点击按钮，打印输出
    this->connect(ui->rbtn_women,&QRadioButton::clicked,[=](){
        qDebug()<<"选择了女性";
    });
    // 选择了女性

    // 复选按钮
    this->connect(ui->cbx1,&QCheckBox::stateChanged,[=](int state){
        if(state==2){
            qDebug()<<"AAA";
        }
    });

    // listWigdet
    QListWidgetItem *item = new QListWidgetItem("赠药山高僧惟俨二首");
    item->setTextAlignment(Qt::AlignCenter);
    ui->listWidget->addItem(item);

    // QStringList QList<QString>
    QStringList list;
    list<<"练得身形似鹤形"<<"千株松下两函经"<<"我来问道无馀说"<<"云在青霄水在瓶";
    ui->listWidget->addItems(list);
}

Widget::~Widget()
{
    delete ui;
}

