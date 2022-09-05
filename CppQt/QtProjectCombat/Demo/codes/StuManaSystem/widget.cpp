#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->setWindowTitle("学生成绩管理系统");

    this->createDB();
    this->createTable();
    this->queryTable();
}

Widget::~Widget()
{
    delete ui;
}

// 创建数据库
void Widget::createDB(){
    // 添加数据库驱动库
    this->db=QSqlDatabase::addDatabase("QSQLITE");
    // 设置数据库的名字，文件名
    this->db.setDatabaseName("student.db");
    // 打开数据库
    if(this->db.open()){
        qDebug()<<"创建/打开数据库成功!";
    }else{
        qDebug()<<"创建/打开数据库失败!";
    }
}

// 创建数据表
void Widget::createTable(){
    QSqlQuery query;
    QString str=QString(
                "CREATE TABLE student("
                "id INT PRIMARY KEY NOT NULL,"
                "name TEXT NOT NULL,"
                "score REAL NOT NULL);"
                );
    if(query.exec(str)){
        qDebug()<<"创建数据表成功!";
    }else{
        qDebug()<<str;
    }
}

// 查询
void Widget::queryTable(){
    QString str=QString("SELECT * FROM student;");
    this->model.setQuery(str);
    ui->tableView->setModel(&this->model);
}

// 插入操作槽函数
void Widget::on_btnInsert_clicked()
{
    QSqlQuery query;
    int id=ui->lineEditID->text().toInt();
    if(id<=0){
        QMessageBox::critical(this,"Error","无效 ID");
        return ;
    }
    QString name=ui->lineEditName->text();
    if(name==""){
        QMessageBox::critical(this,"Error","姓名为空");
        return ;
    }
    double score=ui->lineEditScore->text().toDouble();
    if(score<=0 || score>100){
        QMessageBox::critical(this,"Error","分数应介于 0 到 100 之间");
        return ;
    }
    QString str=QString("INSERT INTO student VALUES(%1,'%2',%3)").arg(id).arg(name).arg(score);

    if(query.exec(str)){
        qDebug()<<"插入数据成功!";
        QMessageBox::information(this,tr("yes"),tr("插入成功!"));
        this->queryTable();
    }else{
        qDebug()<<str;
    }
}

// 删除操作槽函数：根据 ID 删除数据
void Widget::on_btnDelete_clicked()
{
    QSqlQuery query;
    int id=ui->lineEditID->text().toInt();

    QString str=QString("DELETE FROM student WHERE id = %1").arg(id);

    if((QMessageBox::question(this,"ask","是否删除该数据",QMessageBox::Yes|QMessageBox::No))==QMessageBox::No){
        return ;
    }

    if(query.exec(str)){
        qDebug()<<"删除数据成功!";
        QMessageBox::information(this,tr("yes"),tr("删除成功!"));
        this->queryTable();
    }else{
        qDebug()<<str;
        QMessageBox::critical(this,"Error","删除失败，不存在该 ID!");
    }
}

// 修改操作槽函数：根据 ID 修改数据
void Widget::on_btnModify_clicked()
{
    QSqlQuery query;
    int id=ui->lineEditID->text().toInt();
    double score=ui->lineEditScore->text().toDouble();

    if(score<=0 || score>100){
        QMessageBox::critical(this,"Error","分数应介于 0 到 100 之间");
        return ;
    }

    QString str=QString("UPDATE student SET score = %1 WHERE id = %2").arg(score).arg(id);

    if(query.exec(str)){
        qDebug()<<"修改数据成功!";
        QMessageBox::information(this,tr("yes"),tr("修改成功!"));
        this->queryTable();
    }else{
        qDebug()<<str;
        QMessageBox::critical(this,"Error","该ID 不存在!");
    }
}

// 排序操作槽函数
void Widget::on_btnSort_clicked()
{
    QSqlQuery query;
    QString sortID=ui->cBoxID->currentText();
    QString sortWay="";
    if(ui->cBoxSort->currentIndex()==0){
        sortWay="ASC";
    }else{
        sortWay="DESC";
    }

    QString str=QString("SELECT * FROM student ORDER BY %1 %2").arg(sortID.toLower()).arg(sortWay);

    if(query.exec(str)){
        qDebug()<<"排序成功!";
        QMessageBox::information(this,tr("yes"),tr("排序成功!"));
        this->model.setQuery(str);
        ui->tableView->setModel(&this->model);
    }else{
        qDebug()<<str;
    }
}
