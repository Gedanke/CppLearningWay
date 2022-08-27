/********************************************************************************
** Form generated from reading UI file 'minewidget.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MINEWIDGET_H
#define UI_MINEWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MineWidget
{
public:
    QHBoxLayout *horizontalLayout;
    QSpinBox *spinBox;
    QSlider *horizontalSlider;

    void setupUi(QWidget *MineWidget)
    {
        if (MineWidget->objectName().isEmpty())
            MineWidget->setObjectName(QString::fromUtf8("MineWidget"));
        MineWidget->resize(285, 44);
        horizontalLayout = new QHBoxLayout(MineWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        spinBox = new QSpinBox(MineWidget);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));

        horizontalLayout->addWidget(spinBox);

        horizontalSlider = new QSlider(MineWidget);
        horizontalSlider->setObjectName(QString::fromUtf8("horizontalSlider"));
        horizontalSlider->setOrientation(Qt::Horizontal);

        horizontalLayout->addWidget(horizontalSlider);


        retranslateUi(MineWidget);

        QMetaObject::connectSlotsByName(MineWidget);
    } // setupUi

    void retranslateUi(QWidget *MineWidget)
    {
        MineWidget->setWindowTitle(QCoreApplication::translate("MineWidget", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MineWidget: public Ui_MineWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MINEWIDGET_H
