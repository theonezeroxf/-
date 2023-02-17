#include "dataform.h"
#include "ui_dataform.h"
#include "dataread.h"

DataForm::DataForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DataForm)
{
    ui->setupUi(this);
    //DataRead::getData(ns,7);
    DataRead::inputData();
    //QString str="123";
    for(int i=0;i<7;i++){
        ui->textEdit->append(v[i].name);
        ui->textEdit_2->append(QString::number(v[i].light));
        ui->textEdit_3->append(QString::number(v[i].voice));
        ui->textEdit_4->append(QString::number(v[i].tem));
    }
}

DataForm::~DataForm()
{
    delete ui;
}
