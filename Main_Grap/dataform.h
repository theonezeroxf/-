#ifndef DATAFORM_H
#define DATAFORM_H

#include <QWidget>

namespace Ui {
class DataForm;
}

class DataForm : public QWidget
{
    Q_OBJECT

public:
    explicit DataForm(QWidget *parent = 0);
    ~DataForm();

private:
    Ui::DataForm *ui;
};

#endif // DATAFORM_H
