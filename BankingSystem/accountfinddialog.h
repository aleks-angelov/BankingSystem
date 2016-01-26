#ifndef ACCOUNTFINDDIALOG_H
#define ACCOUNTFINDDIALOG_H

#include "customer.h"

#include <QDialog>

namespace Ui {
class accountFindDialog;
}

class accountFindDialog : public QDialog
{
    Q_OBJECT

public:
    explicit accountFindDialog(QWidget *parent = 0);
    ~accountFindDialog();

    void displayFields(int accountType);
    void setAccountType(int t);
    void setAccountBalance(double b);
    void setAccountIban(int i);
    void setAccountOwner(Customer *o);
    void setCheckingMonthlyFee(double mF);
    void setCreditGracePeriod(int gP);
    void setCreditAnnualRate(double aR);
    void setDebitTransactionLimit(double tL);
    void setDebitTransactionBalance(double tB);
    void setDebitAtmLimit(double aL);
    void setDebitAtmBalance(double aB);
    void setSavingsInterestRate(double iR);
    void setSavingsMinimumBalance(double mB);
    void setCertificateDepositTerm(int t);
    void setCertificateWithdrawalPenalty(double wP);
    void setMoneyAllowedTransactions(int aT);
    void setMoneyCurrentTransactions(int cT);
    void setMoneyTransactionFee(double tF);

private:
    Ui::accountFindDialog *ui;
};

#endif // ACCOUNTFINDDIALOG_H
