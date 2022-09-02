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
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QComboBox *cBoxID;
    QComboBox *cBoxSort;
    QPushButton *btnSort;
    QTableView *tableView;
    QGridLayout *gridLayout;
    QLabel *labelID;
    QLineEdit *lineEditID;
    QLabel *labelName;
    QLineEdit *lineEditName;
    QLabel *labelScore;
    QLineEdit *lineEditScore;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *btnInsert;
    QPushButton *btnDelete;
    QPushButton *btnModify;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(450, 600);
        verticalLayout = new QVBoxLayout(Widget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        cBoxID = new QComboBox(Widget);
        cBoxID->addItem(QString());
        cBoxID->addItem(QString());
        cBoxID->setObjectName(QString::fromUtf8("cBoxID"));
        QFont font;
        font.setPointSize(16);
        cBoxID->setFont(font);

        horizontalLayout->addWidget(cBoxID);

        cBoxSort = new QComboBox(Widget);
        cBoxSort->addItem(QString());
        cBoxSort->addItem(QString());
        cBoxSort->setObjectName(QString::fromUtf8("cBoxSort"));
        cBoxSort->setFont(font);

        horizontalLayout->addWidget(cBoxSort);

        btnSort = new QPushButton(Widget);
        btnSort->setObjectName(QString::fromUtf8("btnSort"));
        btnSort->setFont(font);

        horizontalLayout->addWidget(btnSort);


        verticalLayout->addLayout(horizontalLayout);

        tableView = new QTableView(Widget);
        tableView->setObjectName(QString::fromUtf8("tableView"));

        verticalLayout->addWidget(tableView);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        labelID = new QLabel(Widget);
        labelID->setObjectName(QString::fromUtf8("labelID"));
        labelID->setFont(font);

        gridLayout->addWidget(labelID, 0, 0, 1, 1);

        lineEditID = new QLineEdit(Widget);
        lineEditID->setObjectName(QString::fromUtf8("lineEditID"));

        gridLayout->addWidget(lineEditID, 0, 1, 1, 1);

        labelName = new QLabel(Widget);
        labelName->setObjectName(QString::fromUtf8("labelName"));
        labelName->setFont(font);

        gridLayout->addWidget(labelName, 1, 0, 1, 1);

        lineEditName = new QLineEdit(Widget);
        lineEditName->setObjectName(QString::fromUtf8("lineEditName"));

        gridLayout->addWidget(lineEditName, 1, 1, 1, 1);

        labelScore = new QLabel(Widget);
        labelScore->setObjectName(QString::fromUtf8("labelScore"));
        labelScore->setFont(font);

        gridLayout->addWidget(labelScore, 2, 0, 1, 1);

        lineEditScore = new QLineEdit(Widget);
        lineEditScore->setObjectName(QString::fromUtf8("lineEditScore"));

        gridLayout->addWidget(lineEditScore, 2, 1, 1, 1);


        verticalLayout->addLayout(gridLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        btnInsert = new QPushButton(Widget);
        btnInsert->setObjectName(QString::fromUtf8("btnInsert"));
        btnInsert->setFont(font);

        horizontalLayout_2->addWidget(btnInsert);

        btnDelete = new QPushButton(Widget);
        btnDelete->setObjectName(QString::fromUtf8("btnDelete"));
        btnDelete->setFont(font);

        horizontalLayout_2->addWidget(btnDelete);

        btnModify = new QPushButton(Widget);
        btnModify->setObjectName(QString::fromUtf8("btnModify"));
        btnModify->setFont(font);

        horizontalLayout_2->addWidget(btnModify);


        verticalLayout->addLayout(horizontalLayout_2);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        cBoxID->setItemText(0, QCoreApplication::translate("Widget", "ID", nullptr));
        cBoxID->setItemText(1, QCoreApplication::translate("Widget", "Score", nullptr));

        cBoxSort->setItemText(0, QCoreApplication::translate("Widget", "\345\215\207\345\272\217", nullptr));
        cBoxSort->setItemText(1, QCoreApplication::translate("Widget", "\351\231\215\345\272\217", nullptr));

        btnSort->setText(QCoreApplication::translate("Widget", "\346\216\222\345\272\217", nullptr));
        labelID->setText(QCoreApplication::translate("Widget", "\345\255\246\347\224\237\345\255\246\345\217\267\357\274\232", nullptr));
        labelName->setText(QCoreApplication::translate("Widget", "\345\255\246\347\224\237\345\247\223\345\220\215\357\274\232", nullptr));
        labelScore->setText(QCoreApplication::translate("Widget", "\345\255\246\347\224\237\346\210\220\347\273\251\357\274\232", nullptr));
        btnInsert->setText(QCoreApplication::translate("Widget", "\346\217\222\345\205\245", nullptr));
        btnDelete->setText(QCoreApplication::translate("Widget", "\345\210\240\351\231\244", nullptr));
        btnModify->setText(QCoreApplication::translate("Widget", "\344\277\256\346\224\271", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
