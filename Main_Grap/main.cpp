#include "mainwindow.h"
#include <QApplication>
#include "funall.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowTitle("主界面");
    w.show();
//    DataRead::inputData_net();
//    return 1;
    return a.exec();
}
