#ifndef BARTCHART_H
#define BARTCHART_H

#include <QWidget>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtCharts/QChartView>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QLegend>
#include <QtCharts/QBarCategoryAxis>

QT_CHARTS_USE_NAMESPACE
namespace Ui {
class BartChart;
}

class BartChart : public QWidget
{
    Q_OBJECT

public:
    explicit BartChart(QWidget *parent = 0);
    ~BartChart();

private:
    Ui::BartChart *ui;
};

#endif // BARTCHART_H
