#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private:
    //
    bool check();

private slots:
    // 发送按钮槽函数
    void on_btnSend_clicked();

    // 浏览文件按钮槽函数
    void on_btnSelect_clicked();

    // 选择服务器地址下拉框槽函数
    void on_comboBoxAddress_currentIndexChanged(int index);

    // 选择服务器端口下拉框槽函数
    void on_comboBoxPort_currentIndexChanged(int index);

    //
    void initForm();

    //
    void reveiveEmailResult(const QString &result);

private:
    Ui::Widget *ui;
};
#endif // WIDGET_H
