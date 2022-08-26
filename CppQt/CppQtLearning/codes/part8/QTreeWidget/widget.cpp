#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    // TreeWidget 树控件使用
    // 设置头
    ui->treeWidget->setHeaderLabels(QStringList()<<"角色"<<"角色简介");
    // 创建根
    QTreeWidgetItem* itemLei = new QTreeWidgetItem(QStringList()<<"雷系");
    QTreeWidgetItem* itemFeng = new QTreeWidgetItem(QStringList()<<"风系");
    QTreeWidgetItem* itemShui = new QTreeWidgetItem(QStringList()<<"水系");
    // 将根放入到树中
    ui->treeWidget->addTopLevelItem(itemLei);
    ui->treeWidget->addTopLevelItem(itemFeng);
    ui->treeWidget->addTopLevelItem(itemShui);
    QTreeWidgetItem* itemLei1 = new QTreeWidgetItem(QStringList()<<"雷电将军"<<"副 C");
    QTreeWidgetItem* itemFeng1 = new QTreeWidgetItem(QStringList()<<"温迪"<<"辅助");
    QTreeWidgetItem* itemShui1 = new QTreeWidgetItem(QStringList()<<"莫娜"<<"副 C");
    QTreeWidgetItem* itemLei2 = new QTreeWidgetItem(QStringList()<<"八重神子"<<"副 C");
    QTreeWidgetItem* itemFeng2 = new QTreeWidgetItem(QStringList()<<"枫原万叶"<<"辅助");
    QTreeWidgetItem* itemShui2 = new QTreeWidgetItem(QStringList()<<"行秋"<<"副 C");
    QTreeWidgetItem* itemLei3 = new QTreeWidgetItem(QStringList()<<"菲谢尔"<<"副 C");
    QTreeWidgetItem* itemFeng3 = new QTreeWidgetItem(QStringList()<<"砂糖"<<"主 C");
    QTreeWidgetItem* itemShui3 = new QTreeWidgetItem(QStringList()<<"芭芭拉"<<"辅助");

    itemLei->addChild(itemLei1);
    itemLei->addChild(itemLei2);
    itemLei->addChild(itemLei3);

    itemFeng->addChild(itemFeng1);
    itemFeng->addChild(itemFeng2);
    itemFeng->addChild(itemFeng3);

    itemShui->addChild(itemShui1);
    itemShui->addChild(itemShui2);
    itemShui->addChild(itemShui3);

}

Widget::~Widget()
{
    delete ui;
}

