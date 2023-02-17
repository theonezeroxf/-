#include "funall.h"


funAll::funAll()
{

}
void funAll::barFun(){
    QBarSet *set0 = new QBarSet("温度");
    QBarSet *set1 = new QBarSet("建议温度");
    //QBarSet *set2 = new QBarSet("湿度");
    //QBarSet *set3 = new QBarSet("sleepTime");
    //QBarSet *set4 = new QBarSet("Samantha");

//    *set0 << 1 << 2 << 3 << 4 << 5 << 6;
//    *set1 << 5 << 0 << 0 << 4 << 0 << 7;
//    *set2 << 3 << 5 << 8 << 13 << 8 << 5;
//    *set3 << 5 << 6 << 7 << 3 << 4 << 5;
//    *set4 << 9 << 7 << 5 << 3 << 1 << 2;

    //准备数据（一周）
    DataRead::getData_std();
    DataRead::inputData();
    for(int i=0;i<7;i++){
        qreal q1=v[i].tem*1.0;
        qreal q2=ns[i].tem*1.0;
        set0->append(q1);
        set1->append(q2);
    }
//![1]

//![2]
    QBarSeries *series = new QBarSeries();
    series->append(set0);
    series->append(set1);
   // series->append(set2);
    //series->append(set3);
    //series->append(set4);

//![2]

//![3]
    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("温度汇总");
    chart->setAnimationOptions(QChart::SeriesAnimations);
//![3]

//![4]
    QStringList categories;
    categories << "Mon" << "Tues" << "Wed" << "Turs" << "Fri" << "Sat"<<"Sun";
    QBarCategoryAxis *axis = new QBarCategoryAxis();
    axis->append(categories);
    chart->createDefaultAxes();
    chart->setAxisX(axis, series);
//![4]

//![5]
    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignBottom);
//![5]

//![6]
    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
//![6]

//![7]
    QMainWindow *window=new QMainWindow();
    window->setCentralWidget(chartView);
    window->resize(600, 500);
    window->show();
}

QChart* funAll::barFun2(QString choice,QString name){
    QBarSet *set0 = new QBarSet(choice);
    QBarSet *set1 = new QBarSet(QString("建议").append(choice));
    //QBarSet *set2 = new QBarSet("湿度");
    //QBarSet *set3 = new QBarSet("sleepTime");
    //QBarSet *set4 = new QBarSet("Samantha");

//    *set0 << 1 << 2 << 3 << 4 << 5 << 6;
//    *set1 << 5 << 0 << 0 << 4 << 0 << 7;
//    *set2 << 3 << 5 << 8 << 13 << 8 << 5;
//    *set3 << 5 << 6 << 7 << 3 << 4 << 5;
//    *set4 << 9 << 7 << 5 << 3 << 1 << 2;

    //准备数据（一周）
    DataRead::getData_std();
    if(from_net==0)
        DataRead::inputData();
    else
        DataRead::inputData_net(name);
    double sum=0;
    QVector<double> v_m;
    for(int i=0;i<7;i++){
        if(choice.compare("光照")==0){
            sum+=v[i].light*1.0;
            v_m.push_back(v[i].light*1.0);
            set0->append(v[i].light*1.0);
            set1->append(ns[i].light*1.0);
        }else if(choice.compare("湿度")==0){
            sum+=v[i].voice*1.0;
            v_m.push_back(v[i].voice*1.0);
            set0->append(v[i].voice*1.0);
            set1->append(ns[i].voice*1.0);
        }else{
            sum+=v[i].tem*1.0;
            v_m.push_back(v[i].tem*1.0);
            qreal q1=v[i].tem*1.0;
            qreal q2=ns[i].tem*1.0;
            set0->append(q1);
            set1->append(q2);
        }
    }
    std::sort(v_m.begin(),v_m.end());
    mediu_shu=v_m[4];
    average=sum/7;
//![1]

//![2]
    QBarSeries *series = new QBarSeries();
    series->append(set0);
    series->append(set1);
   // series->append(set2);
    //series->append(set3);
    //series->append(set4);

    series->setLabelsPosition(QAbstractBarSeries::LabelsCenter);
    series->setLabelsVisible();

//![2]

//![3]
    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle(choice.append("汇总"));
    chart->setAnimationOptions(QChart::SeriesAnimations);
//![3]

//![4]
    QStringList categories;
    categories << "Mon" << "Tues" << "Wed" << "Turs" << "Fri" << "Sat"<<"Sun";
    QBarCategoryAxis *axis = new QBarCategoryAxis();
    axis->append(categories);
    chart->createDefaultAxes();
    chart->setAxisX(axis, series);
//![4]

//![5]
    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignBottom);
//![5]

//![6]
    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
//![6]

//![7]
    return chart;
}

void funAll::pieFun(){
    //![1]
        QPieSeries *series = new QPieSeries();
        series->append("合理", 10);
        series->append("温度过高", 3);
        series->append("温度过低", 2);
        //series->append("Barbara", 4);
       // series->append("Axel", 5);
    //![1]

    //![2]
        QPieSlice *slice = series->slices().at(0);
        slice->setExploded();
        slice->setLabelVisible();
        slice->setPen(QPen(Qt::darkGreen, 2));
        slice->setBrush(Qt::green);
        series->slices().at(1)->setLabelVisible();
        series->slices().at(2)->setLabelVisible();

    //![2]


    //![3]
        QChart *chart = new QChart();
        chart->addSeries(series);
        chart->setTitle("温度饼状图15天");
        chart->legend()->hide();
    //![3]

    //![4]
        QChartView *chartView = new QChartView(chart);
        chartView->setRenderHint(QPainter::Antialiasing);
    //![4]

        QMainWindow *window=new QMainWindow();

    //![5]


        window->setCentralWidget(chartView);
        window->resize(400, 300);
        window->show();
    //![5]

}
QChart *funAll::pieFun2(QString choice,QString name){
    QPieSeries *series = new QPieSeries();
    int day_n=0,day_h=0,day_l=0,std=20;
    for(int i=0;i<15;i++)
    if(choice.compare("温度")==0) std=23;
    else if(choice.compare("湿度")==0)    std=60;
    else std=100;
    double sum=0;
    QVector<double> v_m;
    for(int i=0;i<15;i++){
        if(choice.compare("温度")==0){
            sum+=v2[i].tem*1.0;
            v_m.push_back(v2[i].tem*1.0);
            if(v2[i].tem>=std-3&&v2[i].tem<=std+3)  day_n++;
            else if(v2[i].tem>std+3) day_h++;
            else day_l++;
        }else if(choice.compare("湿度")==0){
            sum+=v2[i].voice*1.0;
            v_m.push_back(v2[i].voice*1.0);
            if(v2[i].voice>=std-3&&v2[i].voice<=std+3)  day_n++;
            else if(v2[i].voice>std+3) day_h++;
            else day_l++;
        }else{
            sum+=v2[i].light*1.0;
            v_m.push_back(v2[i].light*1.0);
            if(v2[i].light>=std-3&&v2[i].light<=std+3)  day_n++;
            else if(v2[i].light>std+3) day_h++;
            else day_l++;
        }

    }
    average=sum/15;
    std::sort(v_m.begin(),v_m.end());
    mediu_shu=v_m[7];

    series->append("合理", day_n);
    series->append("过高", day_h);
    series->append("过低", day_l);
    //series->append("Barbara", 4);
   // series->append("Axel", 5);
//![1]

//![2]
    QPieSlice *slice = series->slices().at(0);
    slice->setExploded();
    slice->setLabelVisible();
    slice->setPen(QPen(Qt::darkGreen, 2));
    slice->setBrush(Qt::green);
    series->slices().at(1)->setLabelVisible();
    series->slices().at(2)->setLabelVisible();

//![2]


//![3]
    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle(choice.append("饼状图15天"));
    chart->legend()->hide();

//![4]


    return chart;


}
