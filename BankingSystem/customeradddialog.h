#ifndef CUSTOMERADDDIALOG_H
#define CUSTOMERADDDIALOG_H

#include <QDialog>

namespace Ui {
class customerAddDialog;
}

class customerAddDialog : public QDialog
{
    Q_OBJECT

public:
    explicit customerAddDialog(QWidget *parent = 0);
    ~customerAddDialog();

    void setFieldValidations();
    QString getCustomerName();
    int getCustomerPin();
    int getCustomerId();
    QString getCustomerAddress();
    QString getCustomerEmail();

private slots:
    void on_customerAddRandomize_clicked();

private:
    Ui::customerAddDialog *ui;
};

#endif // CUSTOMERADDDIALOG_H
