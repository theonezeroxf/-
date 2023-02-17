#include "bartchart.h"
#include "ui_bartchart.h"

BartChart::BartChart(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BartChart)
{
    ui->setupUi(this);

}

BartChart::~BartChart()
{
    delete ui;
}
