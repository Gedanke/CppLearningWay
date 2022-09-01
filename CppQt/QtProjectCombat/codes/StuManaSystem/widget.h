#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSqlError>
#include <QDebug>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private:
    // 创建数据库
    void createDB();

    // 创建数据表
    void createTable();

    // 查询
    void queryTable();

private slots:
    // 插入操作槽函数
    void on_btnInsert_clicked();

    // 删除操作槽函数
    void on_btnDelete_clicked();

    // 修改操作槽函数
    void on_btnModify_clicked();

    // 排序操作槽函数
    void on_btnSort_clicked();

private:
    Ui::Widget *ui;

    // 建立 Qt 和数据库链接
    QSqlDatabase db;

    // 保存结果集
    QSqlQueryModel model;
};
#endif // WIDGET_H
