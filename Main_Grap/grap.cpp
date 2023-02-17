#include "grap.h"

grap::grap(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::grap)
{
    this->choice="温度";
    this->g_choice=0;
    ui->setupUi(this);
    //ui->chartView->setChart(funAll::barFun2(this->choice,name));
    this->start=1;
    this->chart=funAll::barFun2(this->choice,name);
    ui->chartView->setChart(this->chart);

    //
    grp=new QButtonGroup();
    grp->addButton(ui->tem);
    grp->setId(ui->tem,0);

    grp->addButton(ui->wet);
    grp->setId(ui->wet,1);

    grp->addButton(ui->light);
    grp->setId(ui->light,2);

    connect(ui->nextBtn,&QPushButton::clicked,this,[=](){

          start_day++;
          upDateG();
    });
    connect(ui->beforeBtn,&QPushButton::clicked,this,[=](){

          start_day--;
          upDateG();
    });

    connect(grp, static_cast<void(QButtonGroup::*)(QAbstractButton *)>(&QButtonGroup::buttonClicked),[=](QAbstractButton *button){
        int id=this->grp->checkedId();
        if(id==0){
            this->choice="温度";
            upDateG();
        }else if(id==1){
            this->choice="湿度";
            upDateG();
        }else{
            this->choice="光照";
            upDateG();
        }
        this->setWindowTitle(this->choice);

    });

    //
    QButtonGroup* g_grp=new QButtonGroup();
    g_grp->addButton(ui->bar_Btn,0);
    g_grp->addButton(ui->pie_Btn,1);
    connect(g_grp, static_cast<void(QButtonGroup::*)(QAbstractButton *)>(&QButtonGroup::buttonClicked),[=](QAbstractButton *button){
        int id=g_grp->checkedId();
        if(id==0){
            this->g_choice=0;
            upDateG();
        }else{
            this->g_choice=1;
            upDateG();
        }

    });


}
void grap::upDateG(){

    if(this->g_choice==0)
        ui->chartView->setChart(funAll::barFun2(this->choice,name));
    else
        ui->chartView->setChart(funAll::pieFun2(this->choice,name));
     ui->aver_lbl->setText(QString("平均数:%1").arg(average));
     ui->medium_lbl->setText(QString("中位数:%1").arg(mediu_shu));
}
void grap::onButtonClick(QAbstractButton *btn){
    int id=this->grp->checkedId();
    if(id==0)   this->choice="温度";
    else if(id==1)  this->choice="湿度";
    else this->choice="光照";
    this->setWindowTitle(this->choice);


}
grap::~grap()
{
    delete ui;
}
