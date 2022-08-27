#ifndef MINEWIDGET_H
#define MINEWIDGET_H

#include <QWidget>

namespace Ui {
class MineWidget;
}

class MineWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MineWidget(QWidget *parent = nullptr);
    ~MineWidget();

    // 设置值
    void setValue(int value);

    // 获取值
    int getValue();

private:
    Ui::MineWidget *ui;
};

#endif // MINEWIDGET_H
