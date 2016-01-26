#ifndef ACCOUNTADDDIALOG_H
#define ACCOUNTADDDIALOG_H

#include "avltree.h"

#include <QDialog>

namespace Ui {
class accountAddDialog;
}

class accountAddDialog : public QDialog
{
    Q_OBJECT

public:
    explicit accountAddDialog(QWidget *parent = 0);
    ~accountAddDialog();

    void setTree(AvlTree<Customer> *cTree);
    void setFieldValidations();
    void resetFields();
    int getAccountType();
    double getAccountBalance();
    int getAccountIban();
    int getAccountOwner();
    double getCheckingMonthlyFee();
    int getCreditGracePeriod();
    double getCreditAnnualRate();
    double getDebitTransactionLimit();
    double getDebitAtmLimit();
    double getSavingsInterestRate();
    double getSavingsMinimumBalance();
    int getCertificateDepositTerm();
    double getCertificateWithdrawalPenalty();
    int getMoneyAllowedTransactions();
    double getMoneyTransactionFee();

private slots:
    void on_accountAddType_currentIndexChanged(int index);

    void on_accountAddOwner_textChanged(const QString &arg1);

    void on_accountAddRandomize_clicked();

private:
    Ui::accountAddDialog *ui;

    AvlTree<Customer> *custTree;
};

#endif // ACCOUNTADDDIALOG_H
