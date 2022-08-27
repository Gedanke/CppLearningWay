#include "minewidget.h"
#include "ui_minewidget.h"

MineWidget::MineWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MineWidget)
{
    ui->setupUi(this);

    // 修改 SpinBox 右侧的滚动条跟着移动
    void(QSpinBox::* spinBoxP)(int) = &QSpinBox::valueChanged;
    this->connect(ui->spinBox,spinBoxP,[=](int value){
        ui->horizontalSlider->setValue(value);
    });

    // 右侧滚动条移动，左侧数字发生改变
    this->connect(ui->horizontalSlider,&QSlider::valueChanged,[=](int value){
        ui->spinBox->setValue(value);
    });
}

MineWidget::~MineWidget()
{
    delete ui;
}

// 设置值
void MineWidget::setValue(int value){
    ui->horizontalSlider->setValue(value);
}

// 获取值
int MineWidget::getValue(){
    return ui->horizontalSlider->value();
}
