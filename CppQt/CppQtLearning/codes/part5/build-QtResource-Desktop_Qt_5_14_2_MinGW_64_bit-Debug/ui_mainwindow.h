/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDockWidget>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionnew;
    QAction *actionopem;
    QAction *actionopen_recently;
    QAction *actionexot;
    QAction *actionexit;
    QAction *actionexit_2;
    QWidget *centralwidget;
    QLabel *label;
    QTextEdit *textEdit;
    QMenuBar *menubar;
    QMenu *menu;
    QStatusBar *statusbar;
    QToolBar *toolBar;
    QDockWidget *dockWidget;
    QWidget *dockWidgetContents;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        actionnew = new QAction(MainWindow);
        actionnew->setObjectName(QString::fromUtf8("actionnew"));
        actionopem = new QAction(MainWindow);
        actionopem->setObjectName(QString::fromUtf8("actionopem"));
        actionopen_recently = new QAction(MainWindow);
        actionopen_recently->setObjectName(QString::fromUtf8("actionopen_recently"));
        actionexot = new QAction(MainWindow);
        actionexot->setObjectName(QString::fromUtf8("actionexot"));
        actionexit = new QAction(MainWindow);
        actionexit->setObjectName(QString::fromUtf8("actionexit"));
        actionexit_2 = new QAction(MainWindow);
        actionexit_2->setObjectName(QString::fromUtf8("actionexit_2"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 540, 54, 12));
        textEdit = new QTextEdit(centralwidget);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(13, 9, 731, 541));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 22));
        menu = new QMenu(menubar);
        menu->setObjectName(QString::fromUtf8("menu"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        toolBar->setFloatable(false);
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);
        dockWidget = new QDockWidget(MainWindow);
        dockWidget->setObjectName(QString::fromUtf8("dockWidget"));
        dockWidget->setAllowedAreas(Qt::LeftDockWidgetArea|Qt::RightDockWidgetArea);
        dockWidgetContents = new QWidget();
        dockWidgetContents->setObjectName(QString::fromUtf8("dockWidgetContents"));
        dockWidget->setWidget(dockWidgetContents);
        MainWindow->addDockWidget(Qt::LeftDockWidgetArea, dockWidget);

        menubar->addAction(menu->menuAction());
        menu->addAction(actionnew);
        menu->addAction(actionopem);
        menu->addAction(actionexot);
        menu->addAction(actionopen_recently);
        menu->addAction(actionexit);
        menu->addAction(actionexit_2);
        menu->addSeparator();
        menu->addSeparator();
        toolBar->addAction(actionnew);
        toolBar->addSeparator();
        toolBar->addAction(actionopem);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionnew->setText(QCoreApplication::translate("MainWindow", "new", nullptr));
        actionopem->setText(QCoreApplication::translate("MainWindow", "open", nullptr));
        actionopen_recently->setText(QCoreApplication::translate("MainWindow", "open recently", nullptr));
        actionexot->setText(QCoreApplication::translate("MainWindow", "\346\267\273\345\212\240", nullptr));
        actionexit->setText(QCoreApplication::translate("MainWindow", "add from", nullptr));
        actionexit_2->setText(QCoreApplication::translate("MainWindow", "exit", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        menu->setTitle(QCoreApplication::translate("MainWindow", "\346\226\207\344\273\266", nullptr));
        toolBar->setWindowTitle(QCoreApplication::translate("MainWindow", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
