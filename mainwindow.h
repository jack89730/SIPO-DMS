#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QFileSystemModel>
#include<QModelIndex>

#include "dialog.h"
#include "ui_dialog.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    Dialog* exmnDlg;

    QFileSystemModel *fsModel;

    void initdb();

public slots:
    void openDoc(QModelIndex);
    void showExaminer();
};

#endif // MAINWINDOW_H
