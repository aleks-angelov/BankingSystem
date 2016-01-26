#ifndef CUSTOMERFINDDIALOG_H
#define CUSTOMERFINDDIALOG_H

#include "account.h"

#include <QDialog>

namespace Ui {
class customerFindDialog;
}

class customerFindDialog : public QDialog
{
    Q_OBJECT

public:
    explicit customerFindDialog(QWidget *parent = 0);
    ~customerFindDialog();

    void setCustomerName(QString name);
    void setCustomerPin(int pin);
    void setCustomerId(int id);
    void setCustomerAddress(QString address);
    void setCustomerEmail(QString email);
    void setCustomerAccounts(const std::list<Account*> *accounts);

private:
    Ui::customerFindDialog *ui;
};

#endif // CUSTOMERFINDDIALOG_H
