#ifndef FUNALL_H
#define FUNALL_H

#include "mainwindow.h"
#include "dataread.h"
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QChart>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include <QVector>
#include <algorithm>
class funAll
{
public:
    funAll();
    static void barFun();
    static QChart* barFun2(QString choice,QString name);
    static void pieFun();
    static QChart* pieFun2(QString choice,QString name);
};

#endif // FUNALL_H
