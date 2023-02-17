#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "funall.h"
#include <QDebug>
#include "grap.h"
QString name;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    name="未登录";
    start_day=1;
    from_net=0;
    //数据视图
    connect(ui->dataButton,&QPushButton::clicked,this,[=](){
        DataForm *form=new DataForm();
        form->resize(1000,800);
        form->show();
    });
    //登录
    connect(ui->logBtn,&QPushButton::clicked,this,[=](){
        name=ui->textEdit->toPlainText();
        start_day=1;
        ui->userlbl->setText(name);
    });
    //chartView
    connect(ui->barBtn,&QPushButton::clicked,this,[=](){
        qDebug()<<"chart clicked";


        //qDebug()<<"chart construct";
        funAll::barFun();

    });
    //pieView
    connect(ui->pieBtn,&QPushButton::clicked,this,[=](){
        qDebug()<<"pie clicked"<<endl;
        funAll::pieFun();
    });
    connect(ui->Btn,&QPushButton::clicked,this,[=](){
        if(name.compare("未登录")==0){
            QMessageBox::warning(this, tr("My Application"),
                                             tr("请先登录"),
                                              QMessageBox::Ok|QMessageBox::Cancel);

        }else{
            qDebug()<<"try clicked"<<endl;
            grap *g=new grap();
            g->show();
        }
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}
