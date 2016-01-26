#ifndef CUSTOMERDISPLAYALL_H
#define CUSTOMERDISPLAYALL_H

#include <QDialog>

namespace Ui {
class customerDisplayDialog;
}

class customerDisplayDialog : public QDialog
{
    Q_OBJECT

public:
    explicit customerDisplayDialog(QWidget *parent = 0);
    ~customerDisplayDialog();

    void setCustomerPins(QString pins);

private:
    Ui::customerDisplayDialog *ui;
};

#endif // CUSTOMERDISPLAYALL_H
