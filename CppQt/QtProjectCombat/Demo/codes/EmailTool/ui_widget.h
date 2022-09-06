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
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QLineEdit *lineEditEmail;
    QLineEdit *lineEditPassword;
    QComboBox *comboBoxAddress;
    QLabel *labelPort;
    QComboBox *comboBoxPort;
    QCheckBox *checkBoxSSL;
    QLabel *labelTitle;
    QLineEdit *lineEditTitle;
    QLabel *labelReceive;
    QLineEdit *lineEditReceive;
    QPushButton *btnSend;
    QLabel *labelPassword;
    QLabel *labelAddress;
    QLabel *labelEmail;
    QHBoxLayout *horizontalLayout;
    QLabel *labelFile;
    QLineEdit *lineEditFile;
    QPushButton *btnSelect;
    QTextBrowser *textBrowser;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(800, 669);
        QFont font;
        font.setPointSize(12);
        Widget->setFont(font);
        verticalLayout = new QVBoxLayout(Widget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        lineEditEmail = new QLineEdit(Widget);
        lineEditEmail->setObjectName(QString::fromUtf8("lineEditEmail"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Arial"));
        font1.setPointSize(14);
        lineEditEmail->setFont(font1);
        lineEditEmail->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(lineEditEmail, 0, 1, 1, 1);

        lineEditPassword = new QLineEdit(Widget);
        lineEditPassword->setObjectName(QString::fromUtf8("lineEditPassword"));
        lineEditPassword->setFont(font1);
        lineEditPassword->setEchoMode(QLineEdit::Password);
        lineEditPassword->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(lineEditPassword, 0, 3, 1, 1);

        comboBoxAddress = new QComboBox(Widget);
        comboBoxAddress->addItem(QString());
        comboBoxAddress->addItem(QString());
        comboBoxAddress->addItem(QString());
        comboBoxAddress->addItem(QString());
        comboBoxAddress->addItem(QString());
        comboBoxAddress->addItem(QString());
        comboBoxAddress->addItem(QString());
        comboBoxAddress->setObjectName(QString::fromUtf8("comboBoxAddress"));
        QFont font2;
        font2.setPointSize(14);
        comboBoxAddress->setFont(font2);
        comboBoxAddress->setInsertPolicy(QComboBox::InsertAtBottom);

        gridLayout->addWidget(comboBoxAddress, 1, 1, 1, 1);

        labelPort = new QLabel(Widget);
        labelPort->setObjectName(QString::fromUtf8("labelPort"));
        labelPort->setFont(font2);
        labelPort->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(labelPort, 1, 2, 1, 1);

        comboBoxPort = new QComboBox(Widget);
        comboBoxPort->addItem(QString());
        comboBoxPort->addItem(QString());
        comboBoxPort->addItem(QString());
        comboBoxPort->setObjectName(QString::fromUtf8("comboBoxPort"));
        comboBoxPort->setFont(font2);

        gridLayout->addWidget(comboBoxPort, 1, 3, 1, 1);

        checkBoxSSL = new QCheckBox(Widget);
        checkBoxSSL->setObjectName(QString::fromUtf8("checkBoxSSL"));
        checkBoxSSL->setFont(font2);

        gridLayout->addWidget(checkBoxSSL, 1, 4, 1, 1);

        labelTitle = new QLabel(Widget);
        labelTitle->setObjectName(QString::fromUtf8("labelTitle"));
        labelTitle->setFont(font2);
        labelTitle->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(labelTitle, 2, 0, 1, 1);

        lineEditTitle = new QLineEdit(Widget);
        lineEditTitle->setObjectName(QString::fromUtf8("lineEditTitle"));
        lineEditTitle->setFont(font2);
        lineEditTitle->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(lineEditTitle, 2, 1, 1, 1);

        labelReceive = new QLabel(Widget);
        labelReceive->setObjectName(QString::fromUtf8("labelReceive"));
        labelReceive->setFont(font2);
        labelReceive->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(labelReceive, 2, 2, 1, 1);

        lineEditReceive = new QLineEdit(Widget);
        lineEditReceive->setObjectName(QString::fromUtf8("lineEditReceive"));
        lineEditReceive->setFont(font2);
        lineEditReceive->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(lineEditReceive, 2, 3, 1, 1);

        btnSend = new QPushButton(Widget);
        btnSend->setObjectName(QString::fromUtf8("btnSend"));
        btnSend->setFont(font2);

        gridLayout->addWidget(btnSend, 2, 4, 1, 1);

        labelPassword = new QLabel(Widget);
        labelPassword->setObjectName(QString::fromUtf8("labelPassword"));
        labelPassword->setFont(font2);
        labelPassword->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(labelPassword, 0, 2, 1, 1);

        labelAddress = new QLabel(Widget);
        labelAddress->setObjectName(QString::fromUtf8("labelAddress"));
        labelAddress->setFont(font2);
        labelAddress->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(labelAddress, 1, 0, 1, 1);

        labelEmail = new QLabel(Widget);
        labelEmail->setObjectName(QString::fromUtf8("labelEmail"));
        labelEmail->setFont(font2);
        labelEmail->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(labelEmail, 0, 0, 1, 1);


        verticalLayout->addLayout(gridLayout);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        labelFile = new QLabel(Widget);
        labelFile->setObjectName(QString::fromUtf8("labelFile"));
        labelFile->setEnabled(true);
        labelFile->setFont(font2);
        labelFile->setScaledContents(true);
        labelFile->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(labelFile);

        lineEditFile = new QLineEdit(Widget);
        lineEditFile->setObjectName(QString::fromUtf8("lineEditFile"));
        lineEditFile->setFont(font2);
        lineEditFile->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(lineEditFile);

        btnSelect = new QPushButton(Widget);
        btnSelect->setObjectName(QString::fromUtf8("btnSelect"));
        btnSelect->setFont(font2);

        horizontalLayout->addWidget(btnSelect);


        verticalLayout->addLayout(horizontalLayout);

        textBrowser = new QTextBrowser(Widget);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setEnabled(true);
        QFont font3;
        font3.setPointSize(16);
        textBrowser->setFont(font3);
        textBrowser->setAutoFillBackground(false);
        textBrowser->setOverwriteMode(true);
        textBrowser->setTextInteractionFlags(Qt::LinksAccessibleByKeyboard|Qt::LinksAccessibleByMouse|Qt::TextBrowserInteraction|Qt::TextEditable|Qt::TextEditorInteraction|Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);
        textBrowser->setOpenExternalLinks(false);

        verticalLayout->addWidget(textBrowser);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "\351\202\256\347\256\261", nullptr));
        comboBoxAddress->setItemText(0, QCoreApplication::translate("Widget", "smtp.163.com", nullptr));
        comboBoxAddress->setItemText(1, QCoreApplication::translate("Widget", "smtp.126.com", nullptr));
        comboBoxAddress->setItemText(2, QCoreApplication::translate("Widget", "smtp.qq.com", nullptr));
        comboBoxAddress->setItemText(3, QCoreApplication::translate("Widget", "smt.sina.com", nullptr));
        comboBoxAddress->setItemText(4, QCoreApplication::translate("Widget", "smtp.sohu.com", nullptr));
        comboBoxAddress->setItemText(5, QCoreApplication::translate("Widget", "smtp.139.com", nullptr));
        comboBoxAddress->setItemText(6, QCoreApplication::translate("Widget", "smtp.189.com", nullptr));

        labelPort->setText(QCoreApplication::translate("Widget", "\346\234\215\345\212\241\347\253\257\345\217\243", nullptr));
        comboBoxPort->setItemText(0, QCoreApplication::translate("Widget", "25", nullptr));
        comboBoxPort->setItemText(1, QCoreApplication::translate("Widget", "465", nullptr));
        comboBoxPort->setItemText(2, QCoreApplication::translate("Widget", "587", nullptr));

        checkBoxSSL->setText(QCoreApplication::translate("Widget", "SSL", nullptr));
        labelTitle->setText(QCoreApplication::translate("Widget", "\351\202\256\344\273\266\346\240\207\351\242\230", nullptr));
        labelReceive->setText(QCoreApplication::translate("Widget", "\346\224\266\344\273\266\345\234\260\345\235\200", nullptr));
        btnSend->setText(QCoreApplication::translate("Widget", "\345\217\221\351\200\201", nullptr));
        labelPassword->setText(QCoreApplication::translate("Widget", "\347\224\250\346\210\267\345\257\206\347\240\201", nullptr));
        labelAddress->setText(QCoreApplication::translate("Widget", "\346\234\215\345\212\241\345\234\260\345\235\200", nullptr));
        labelEmail->setText(QCoreApplication::translate("Widget", "\347\224\250\346\210\267\345\220\215\347\247\260", nullptr));
        labelFile->setText(QCoreApplication::translate("Widget", "\351\200\211\346\213\251\351\231\204\344\273\266", nullptr));
        btnSelect->setText(QCoreApplication::translate("Widget", "\346\265\217\350\247\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
