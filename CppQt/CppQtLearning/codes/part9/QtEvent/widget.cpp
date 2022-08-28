#include "widget.h"
#include "ui_widget.h"
#include "QTimer"
#include "QPushButton"
#include "QDebug"
#include "QMouseEvent"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    // 开启定时器
    this->id1 = this->startTimer(1000);
    this->id2 = this->startTimer(2000);

    // 创建定时器对象
    QTimer* time1=new QTimer(this);

    // 每隔 500 ms 发送信号
    this->connect(time1,&QTimer::timeout,[=](){
        // 每隔 0.5 秒，数字++
        static int num3=1;
        ui->label_4->setText(QString::number(num3++));
    });

    // 点击按钮开始
    this->connect(ui->pushButton_2,&QPushButton::clicked,[=](){
        time1->start(500);
    });
    // 点击按钮暂停
    this->connect(ui->pushButton,&QPushButton::clicked,[=](){
        time1->stop();
    });

    // 给 Label 添加事件过滤器，做更高级的拦截

    // 给控件安装过滤器
    ui->label->installEventFilter(this);

}

Widget::~Widget()
{
    delete ui;
}

// 添加定时器
void Widget::timerEvent(QTimerEvent *e){
    if(e->timerId()==this->id1){
        // 每隔一秒，数字++
        static int num=1;
        ui->label_2->setText(QString::number(num++));
    }
    if(e->timerId() == this->id2){
        // 每隔两秒，数字++
        static int num2=1;
        ui->label_3->setText(QString::number(num2++));
    }
}

// 重写过滤器事件
bool Widget::eventFilter(QObject *obj, QEvent *e){
    if(obj == ui->label){
        if(e->type() == QEvent::MouseButtonPress){
            QMouseEvent* ev = static_cast<QMouseEvent *>(e);
            // 如果是鼠标按下，拦截事件，不向下分发
            QString str = QString("eventFilter 鼠标按下了(%1, %2))").arg(ev->x()).arg(ev->y());
            qDebug()<<str;
            return true;
        }
    }

    // 其他事件抛给父类
    return QWidget::eventFilter(obj,e);
}
