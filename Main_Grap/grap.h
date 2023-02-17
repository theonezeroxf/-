#ifndef GRAP_H
#define GRAP_H

#include <QMainWindow>
#include "ui_grap.h"
#include "funall.h"
namespace Ui {
class grap;
}

class grap : public QMainWindow
{
    Q_OBJECT

public:
    explicit grap(QWidget *parent = 0);
    void upDateG();
    QChart *chart;
    QButtonGroup *grp;
    int start;
    QString choice;
    int g_choice;
    ~grap();
public slots:
    void onButtonClick(QAbstractButton *btn);
private:
    Ui::grap *ui;
};

#endif // GRAP_H
