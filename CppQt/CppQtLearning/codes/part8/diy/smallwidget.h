#ifndef SMALLWIDGET_H
#define SMALLWIDGET_H
#include "QWidget"
#include "QSpinBox"
#include "QSlider"

class SmallWidget : public QWidget
{
    Q_OBJECT
public:
    explicit SmallWidget(QWidget *parent = 0);

signals:

public slots:
private:
    QSpinBox* spin;
    QSlider* slider;
};

#endif // SMALLWIDGET_H
