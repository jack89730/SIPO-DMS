#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "ui_dialog.h"
#include "dialog.h"


#include<QtDebug>
#include<QDesktopServices>
#include<QUrl>
#include<QSqlDatabase>
#include<QSqlQuery>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->fsModel = new QFileSystemModel;
    this->fsModel->setRootPath(QDir::currentPath());

    qDebug()<<"current path: "<<QDir::currentPath();
    ui->treeView->setModel(this->fsModel);
    qDebug()<<"treeview header length: "<<ui->treeView->header()->count();
    ui->treeView->setRootIndex(this->fsModel->index(QDir::currentPath()));
    ui->treeView->setHeaderHidden(true);
    ui->treeView->hideColumn(1);
    ui->treeView->hideColumn(2);
    ui->treeView->hideColumn(3);
    connect(ui->treeView, SIGNAL(doubleClicked(QModelIndex)), \
            this, SLOT(openDoc(QModelIndex)));

    this->initdb();

    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(showExaminer()));
}

void MainWindow::showExaminer(){
    this->exmnDlg = new Dialog(this);
    qDebug()<<"widget of examiner constructed!";
    this->hide();
    this->exmnDlg->show();
    this->show();
}

void MainWindow::initdb(){
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("examiner");
    if(db.open()){
        QSqlQuery q(db);
        q.exec(QLatin1String("create table examiners("
                                                     "id integer primary key, "
                                                     "name varchar, "
                                                     "name_en varchar, "
                                                     "sex varchar, "
                                                     "birthday, "
                                                     "home varchar, "
                                                     "major varchar, "
                                                     "graduate varchar, "
                                                     "office varchar, "
                                                     "email varchar, "
                                                     "phone varchar, "
                                                     "cellphone varchar, "
                                                     "section varchar, "
                                                     "job varchar, "
                                                     "grade varchar, "
                                                     "politics varchar)"));
        q.exec(QLatin1String("create table responsible("
                             "id integer primary key, "
                             "office varchar, "
                             "affair varchar, "
                             "examiner1, varchar, "
                             "examiner2, varchar, "
                             "examiner3, varchar"));
        q.exec("insert into examiners values(1, "
               "banguijun, "
               "nan, "
               "19890109,"
               "xinxiang, "
               "wuli, "
               "bupt, "
               "C801, "
               "banguijun@sina.com, "
               "12344444444, "
               "guangxueshi, "
               "shenchanyuan, "
               "4, "
               "tuanyuan");
        q.exec("insert into responsible values(1, "
               "guangxueshi, "
               "renwuliang, "
               "chenguiyang, "
               " ,"
               ",");

        // walk the dirs and update dirs with database
        /*
        QSqlQueryModel qModel;
        qModel.setQuery("select affair from responsible");
        QStringList affairs;
        for(int i = 0; i < qModel.rowCount(); ++i){
            affairs.append(qModel.record(i + 1).value(0).toString());
        }
        QDir dir(QDir::currentPath());

        */


        qDebug()<<"init succeed!";

}}


void MainWindow::openDoc(QModelIndex index){

    QFileInfo fileinfo = this->fsModel->fileInfo(index);
    qDebug()<<"file type: "<<fileinfo.fileName();
    if(fileinfo.isFile()){
        QDesktopServices::openUrl(QUrl::fromLocalFile(fileinfo.filePath()));
    }

}

MainWindow::~MainWindow()
{
    delete ui;
}
