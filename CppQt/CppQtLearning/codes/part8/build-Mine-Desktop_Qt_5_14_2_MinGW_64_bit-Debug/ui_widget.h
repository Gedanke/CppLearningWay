/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>
#include <minewidget.h>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    MineWidget *widget;
    QPushButton *pBtnSet;
    QPushButton *pBtnGet;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(800, 600);
        widget = new MineWidget(Widget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(230, 200, 381, 80));
        pBtnSet = new QPushButton(Widget);
        pBtnSet->setObjectName(QString::fromUtf8("pBtnSet"));
        pBtnSet->setGeometry(QRect(280, 370, 80, 20));
        pBtnGet = new QPushButton(Widget);
        pBtnGet->setObjectName(QString::fromUtf8("pBtnGet"));
        pBtnGet->setGeometry(QRect(460, 370, 80, 20));

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        pBtnSet->setText(QCoreApplication::translate("Widget", "\350\256\276\347\275\256\344\270\200\345\215\212", nullptr));
        pBtnGet->setText(QCoreApplication::translate("Widget", "\350\216\267\345\217\226\345\200\274", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
