#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    // tableWidget

    // 设置列数
    ui->tableWidget->setColumnCount(3);

    // 设置水平表头
    ui->tableWidget->setHorizontalHeaderLabels(QStringList()<<"姓名"<<"系"<<"地区");

    // 设置行数
    ui->tableWidget->setRowCount(5);

    QList<QString> nameList;
    nameList<<"雷电将军"<<"八重神子"<<"枫原万叶"<<"行秋"<<"砂糖";
    QStringList xiList;
    xiList<<"雷"<<"雷"<<"风"<<"水"<<"风";
    QList<QString> areaList;
    areaList<<"稻妻"<<"稻妻"<<"稻妻"<<"璃月"<<"蒙德";
    for(int i=0;i<5;i++){
        ui->tableWidget->setItem(i,0,new QTableWidgetItem(nameList[i]));
        ui->tableWidget->setItem(i,1,new QTableWidgetItem(xiList[i]));
        ui->tableWidget->setItem(i,2,new QTableWidgetItem(areaList[i]));
    }

}

Widget::~Widget()
{
    delete ui;
}

