#include "dialog.h"
#include "ui_dialog.h"

#include<QSqlDatabase>
#include<QSqlTableModel>
#include<QtDebug>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("examiner");
    if(db.open()){
        qDebug()<<"database access!";

    } else {
        qDebug()<<"database not connected!";
    }
    if(db.isOpen()){
        qDebug()<<"connected succeed!";
        this->model = new QSqlTableModel(this, db);
        this->model->setTable("examiners");
        this->model->select();
        ui->tableView->setModel(this->model);
        ui->tableView->show();

    }

}

Dialog::~Dialog()
{
    delete ui;
}
