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
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QPushButton *pushButton;
    QToolButton *toolButton;
    QGroupBox *groupBox;
    QRadioButton *rbtn_men;
    QRadioButton *rbtn_women;
    QGroupBox *groupBox_2;
    QRadioButton *rbtn_dog;
    QRadioButton *rbtn_cat;
    QGroupBox *groupBox_3;
    QCheckBox *cbx1;
    QCheckBox *cbx2;
    QCheckBox *cbx3;
    QCheckBox *cbx4;
    QCheckBox *cbx5;
    QListWidget *listWidget;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(1576, 1028);
        pushButton = new QPushButton(Widget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(180, 160, 141, 61));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/Image/down.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton->setIcon(icon);
        pushButton->setIconSize(QSize(32, 16));
        toolButton = new QToolButton(Widget);
        toolButton->setObjectName(QString::fromUtf8("toolButton"));
        toolButton->setGeometry(QRect(120, 320, 101, 81));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/Image/Luffy.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton->setIcon(icon1);
        toolButton->setIconSize(QSize(64, 64));
        toolButton->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        toolButton->setAutoRaise(true);
        groupBox = new QGroupBox(Widget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(760, 150, 191, 141));
        rbtn_men = new QRadioButton(groupBox);
        rbtn_men->setObjectName(QString::fromUtf8("rbtn_men"));
        rbtn_men->setGeometry(QRect(10, 40, 91, 18));
        rbtn_women = new QRadioButton(groupBox);
        rbtn_women->setObjectName(QString::fromUtf8("rbtn_women"));
        rbtn_women->setGeometry(QRect(10, 80, 91, 18));
        groupBox_2 = new QGroupBox(Widget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(1110, 90, 191, 141));
        rbtn_dog = new QRadioButton(groupBox_2);
        rbtn_dog->setObjectName(QString::fromUtf8("rbtn_dog"));
        rbtn_dog->setGeometry(QRect(10, 40, 91, 18));
        rbtn_cat = new QRadioButton(groupBox_2);
        rbtn_cat->setObjectName(QString::fromUtf8("rbtn_cat"));
        rbtn_cat->setGeometry(QRect(10, 80, 91, 18));
        groupBox_3 = new QGroupBox(Widget);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setGeometry(QRect(430, 110, 241, 311));
        cbx1 = new QCheckBox(groupBox_3);
        cbx1->setObjectName(QString::fromUtf8("cbx1"));
        cbx1->setGeometry(QRect(20, 50, 73, 18));
        cbx2 = new QCheckBox(groupBox_3);
        cbx2->setObjectName(QString::fromUtf8("cbx2"));
        cbx2->setGeometry(QRect(20, 90, 73, 18));
        cbx3 = new QCheckBox(groupBox_3);
        cbx3->setObjectName(QString::fromUtf8("cbx3"));
        cbx3->setGeometry(QRect(20, 140, 73, 18));
        cbx4 = new QCheckBox(groupBox_3);
        cbx4->setObjectName(QString::fromUtf8("cbx4"));
        cbx4->setGeometry(QRect(20, 190, 73, 18));
        cbx5 = new QCheckBox(groupBox_3);
        cbx5->setObjectName(QString::fromUtf8("cbx5"));
        cbx5->setGeometry(QRect(20, 240, 73, 18));
        listWidget = new QListWidget(Widget);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        listWidget->setGeometry(QRect(210, 510, 311, 291));

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        pushButton->setText(QCoreApplication::translate("Widget", "PushButton", nullptr));
        toolButton->setText(QCoreApplication::translate("Widget", "\351\200\211\346\213\251", nullptr));
        groupBox->setTitle(QCoreApplication::translate("Widget", "GroupBox", nullptr));
        rbtn_men->setText(QCoreApplication::translate("Widget", "\347\224\267", nullptr));
        rbtn_women->setText(QCoreApplication::translate("Widget", "\345\245\263", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("Widget", "GroupBox", nullptr));
        rbtn_dog->setText(QCoreApplication::translate("Widget", "dog", nullptr));
        rbtn_cat->setText(QCoreApplication::translate("Widget", "cat", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("Widget", "GroupBox", nullptr));
        cbx1->setText(QCoreApplication::translate("Widget", "AAA", nullptr));
        cbx2->setText(QCoreApplication::translate("Widget", "BBB", nullptr));
        cbx3->setText(QCoreApplication::translate("Widget", "CCC", nullptr));
        cbx4->setText(QCoreApplication::translate("Widget", "DDD", nullptr));
        cbx5->setText(QCoreApplication::translate("Widget", "...", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
