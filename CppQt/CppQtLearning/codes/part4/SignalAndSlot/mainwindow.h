#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "teacher.h"
#include "student.h"
#include <QDebug>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    // 下课了
    void classOver(QString str = "");
    // 点击按钮关闭主窗口
    void closeWindow();
    ~MainWindow();

public:
    Teacher *teacher;
    Student *student;

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
