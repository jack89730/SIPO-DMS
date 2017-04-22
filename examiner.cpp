#include "examiner.h"
#include "ui_examiner.h"

Examiner::Examiner(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Examiner)
{
    ui->setupUi(this);
}

Examiner::~Examiner()
{
    delete ui;
}
