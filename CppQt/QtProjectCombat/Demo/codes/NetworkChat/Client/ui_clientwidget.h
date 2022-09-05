/********************************************************************************
** Form generated from reading UI file 'clientwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLIENTWIDGET_H
#define UI_CLIENTWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ClientWidget
{
public:
    QVBoxLayout *verticalLayout;
    QListWidget *listWidget;
    QHBoxLayout *horizontalLayout;
    QLineEdit *editSend;
    QPushButton *btnSend;
    QGridLayout *gridLayout;
    QLabel *labelAddress;
    QLineEdit *editAddress;
    QLabel *labelPort;
    QLineEdit *editPort;
    QLabel *labelUserName;
    QLineEdit *editUserName;
    QPushButton *btnConnect;

    void setupUi(QWidget *ClientWidget)
    {
        if (ClientWidget->objectName().isEmpty())
            ClientWidget->setObjectName(QString::fromUtf8("ClientWidget"));
        ClientWidget->resize(800, 729);
        QFont font;
        font.setPointSize(6);
        ClientWidget->setFont(font);
        verticalLayout = new QVBoxLayout(ClientWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        listWidget = new QListWidget(ClientWidget);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));

        verticalLayout->addWidget(listWidget);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        editSend = new QLineEdit(ClientWidget);
        editSend->setObjectName(QString::fromUtf8("editSend"));
        QFont font1;
        font1.setPointSize(16);
        editSend->setFont(font1);

        horizontalLayout->addWidget(editSend);

        btnSend = new QPushButton(ClientWidget);
        btnSend->setObjectName(QString::fromUtf8("btnSend"));
        btnSend->setEnabled(false);
        btnSend->setFont(font1);

        horizontalLayout->addWidget(btnSend);


        verticalLayout->addLayout(horizontalLayout);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        labelAddress = new QLabel(ClientWidget);
        labelAddress->setObjectName(QString::fromUtf8("labelAddress"));
        labelAddress->setFont(font1);

        gridLayout->addWidget(labelAddress, 0, 0, 1, 1);

        editAddress = new QLineEdit(ClientWidget);
        editAddress->setObjectName(QString::fromUtf8("editAddress"));
        editAddress->setFont(font1);

        gridLayout->addWidget(editAddress, 0, 1, 1, 1);

        labelPort = new QLabel(ClientWidget);
        labelPort->setObjectName(QString::fromUtf8("labelPort"));
        labelPort->setFont(font1);

        gridLayout->addWidget(labelPort, 1, 0, 1, 1);

        editPort = new QLineEdit(ClientWidget);
        editPort->setObjectName(QString::fromUtf8("editPort"));
        editPort->setFont(font1);

        gridLayout->addWidget(editPort, 1, 1, 1, 1);

        labelUserName = new QLabel(ClientWidget);
        labelUserName->setObjectName(QString::fromUtf8("labelUserName"));
        labelUserName->setFont(font1);

        gridLayout->addWidget(labelUserName, 2, 0, 1, 1);

        editUserName = new QLineEdit(ClientWidget);
        editUserName->setObjectName(QString::fromUtf8("editUserName"));
        editUserName->setFont(font1);

        gridLayout->addWidget(editUserName, 2, 1, 1, 1);


        verticalLayout->addLayout(gridLayout);

        btnConnect = new QPushButton(ClientWidget);
        btnConnect->setObjectName(QString::fromUtf8("btnConnect"));
        btnConnect->setEnabled(true);
        btnConnect->setFont(font1);

        verticalLayout->addWidget(btnConnect);


        retranslateUi(ClientWidget);

        QMetaObject::connectSlotsByName(ClientWidget);
    } // setupUi

    void retranslateUi(QWidget *ClientWidget)
    {
        ClientWidget->setWindowTitle(QCoreApplication::translate("ClientWidget", "\350\201\212\345\244\251\345\256\244\345\256\242\346\210\267\347\253\257", nullptr));
        btnSend->setText(QCoreApplication::translate("ClientWidget", "\345\217\221\351\200\201", nullptr));
        labelAddress->setText(QCoreApplication::translate("ClientWidget", "\346\234\215\345\212\241\345\231\250\345\234\260\345\235\200\357\274\232", nullptr));
        editAddress->setText(QCoreApplication::translate("ClientWidget", "127.0.0.1", nullptr));
        labelPort->setText(QCoreApplication::translate("ClientWidget", "\346\234\215\345\212\241\345\231\250\347\253\257\345\217\243\357\274\232", nullptr));
        editPort->setText(QCoreApplication::translate("ClientWidget", "8080", nullptr));
        labelUserName->setText(QCoreApplication::translate("ClientWidget", "\350\201\212\345\244\251\345\256\244\345\221\242\347\247\260\357\274\232", nullptr));
        editUserName->setText(QCoreApplication::translate("ClientWidget", "Jerry", nullptr));
        btnConnect->setText(QCoreApplication::translate("ClientWidget", "\350\277\236\346\216\245\346\234\215\345\212\241\345\231\250", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ClientWidget: public Ui_ClientWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLIENTWIDGET_H
