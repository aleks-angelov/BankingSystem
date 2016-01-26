#include "accountadddialog.h"
#include "ui_accountadddialog.h"

#include <time.h>

accountAddDialog::accountAddDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::accountAddDialog)
{
    qsrand(time(nullptr));

    ui->setupUi(this);

    ui->accountAddType->setCurrentIndex(0);
}

accountAddDialog::~accountAddDialog()
{
    delete ui;
}

/*
Enables the Add Account dialog to access the customer tree. Needed
for checking whether the customer specified for the owner exists.
*/
void accountAddDialog::setTree(AvlTree<Customer> *cTree)
{
    custTree = cTree;
}

// Prevents the user from entering invalid data.
void accountAddDialog::setFieldValidations()
{
    QIntValidator *intValid = new QIntValidator(1, 999999999);
    QDoubleValidator *doubleValid = new QDoubleValidator(1.00, 999999999.99, 2);
    doubleValid->setNotation(QDoubleValidator::StandardNotation);
    QDoubleValidator *percentValid = new QDoubleValidator(1.00, 99.99, 2);
    percentValid->setNotation(QDoubleValidator::StandardNotation);

    ui->accountAddBalance->setValidator(doubleValid);
    ui->accountAddIban->setValidator(intValid);
    ui->accountAddOwner->setValidator(intValid);
    ui->checkingMonthlyFee->setValidator(doubleValid);
    ui->creditGracePeriod->setValidator(intValid);
    ui->creditAnnualRate->setValidator(percentValid);
    ui->debitTransactionLimit->setValidator(doubleValid);
    ui->debitAtmLimit->setValidator(doubleValid);
    ui->savingsInterestRate->setValidator(percentValid);
    ui->savingsMinimumBalance->setValidator(doubleValid);
    ui->certificateDepositTerm->setValidator(intValid);
    ui->certificateWithdrawalPenalty->setValidator(percentValid);
    ui->moneyAllowedTransactions->setValidator(intValid);
    ui->moneyTransactionFee->setValidator(doubleValid);
}

/*
Empties and hides all fields. Used
when the account type is changed.
*/
void accountAddDialog::resetFields()
{
    ui->checkingMonthlyFeeLabel->setVisible(false);
    ui->checkingMonthlyFee->setText("");
    ui->checkingMonthlyFee->setVisible(false);
    ui->creditGracePeriodLabel->setVisible(false);
    ui->creditGracePeriod->setText("");
    ui->creditGracePeriod->setVisible(false);
    ui->creditAnnualRateLabel->setVisible(false);
    ui->creditAnnualRate->setText("");
    ui->creditAnnualRate->setVisible(false);
    ui->debitTransactionLimitLabel->setVisible(false);
    ui->debitTransactionLimit->setText("");
    ui->debitTransactionLimit->setVisible(false);
    ui->debitAtmLimitLabel->setVisible(false);
    ui->debitAtmLimit->setText("");
    ui->debitAtmLimit->setVisible(false);
    ui->savingsInterestRateLabel->setVisible(false);
    ui->savingsInterestRate->setText("");
    ui->savingsInterestRate->setVisible(false);
    ui->savingsMinimumBalanceLabel->setVisible(false);
    ui->savingsMinimumBalance->setText("");
    ui->savingsMinimumBalance->setVisible(false);
    ui->certificateDepositTermLabel->setVisible(false);
    ui->certificateDepositTerm->setText("");
    ui->certificateDepositTerm->setVisible(false);
    ui->certificateWithdrawalPenaltyLabel->setVisible(false);
    ui->certificateWithdrawalPenalty->setText("");
    ui->certificateWithdrawalPenalty->setVisible(false);
    ui->moneyAllowedTransactionsLabel->setVisible(false);
    ui->moneyAllowedTransactions->setText("");
    ui->moneyAllowedTransactions->setVisible(false);
    ui->moneyTransactionFeeLabel->setVisible(false);
    ui->moneyTransactionFee->setText("");
    ui->moneyTransactionFee->setVisible(false);
}

int accountAddDialog::getAccountType()
{
    return ui->accountAddType->currentIndex();
}

double accountAddDialog::getAccountBalance()
{
    return ui->accountAddBalance->text().toDouble();
}

int accountAddDialog::getAccountIban()
{
    return ui->accountAddIban->text().toInt();
}

int accountAddDialog::getAccountOwner()
{
    return ui->accountAddOwner->text().toInt();
}

double accountAddDialog::getCheckingMonthlyFee()
{
    return ui->checkingMonthlyFee->text().toDouble();
}

int accountAddDialog::getCreditGracePeriod()
{
    return ui->creditGracePeriod->text().toInt();
}

double accountAddDialog::getCreditAnnualRate()
{
    return ui->creditGracePeriod->text().toDouble();
}

double accountAddDialog::getDebitTransactionLimit()
{
    return ui->debitTransactionLimit->text().toDouble();
}

double accountAddDialog::getDebitAtmLimit()
{
    return ui->debitAtmLimit->text().toDouble();
}

double accountAddDialog::getSavingsInterestRate()
{
    return ui->savingsInterestRate->text().toDouble();
}

double accountAddDialog::getSavingsMinimumBalance()
{
    return ui->savingsMinimumBalance->text().toDouble();
}

int accountAddDialog::getCertificateDepositTerm()
{
    return ui->certificateDepositTerm->text().toInt();
}

double accountAddDialog::getCertificateWithdrawalPenalty()
{
    return ui->certificateWithdrawalPenalty->text().toDouble();
}

int accountAddDialog::getMoneyAllowedTransactions()
{
    return ui->moneyAllowedTransactions->text().toInt();
}

double accountAddDialog::getMoneyTransactionFee()
{
    return ui->moneyTransactionFee->text().toDouble();
}

// Displays only fields, appropriate for the selected account type.
void accountAddDialog::on_accountAddType_currentIndexChanged(int index)
{
    resetFields();

    switch(index)
    {
    case 0:
    {
        ui->checkingMonthlyFeeLabel->setVisible(true);
        ui->checkingMonthlyFee->setVisible(true);
        break;
    }
    case 1:
    {
        ui->checkingMonthlyFeeLabel->setVisible(true);
        ui->checkingMonthlyFee->setVisible(true);
        ui->creditGracePeriodLabel->setVisible(true);
        ui->creditGracePeriod->setVisible(true);
        ui->creditAnnualRateLabel->setVisible(true);
        ui->creditAnnualRate->setVisible(true);
        break;
    }
    case 2:
    {
        ui->checkingMonthlyFeeLabel->setVisible(true);
        ui->checkingMonthlyFee->setVisible(true);
        ui->debitTransactionLimitLabel->setVisible(true);
        ui->debitTransactionLimit->setVisible(true);
        ui->debitAtmLimitLabel->setVisible(true);
        ui->debitAtmLimit->setVisible(true);
        break;
    }
    case 3:
    {
        ui->savingsInterestRateLabel->setVisible(true);
        ui->savingsInterestRate->setVisible(true);
        ui->savingsMinimumBalanceLabel->setVisible(true);
        ui->savingsMinimumBalance->setVisible(true);
        break;
    }
    case 4:
    {
        ui->savingsInterestRateLabel->setVisible(true);
        ui->savingsInterestRate->setVisible(true);
        ui->savingsMinimumBalanceLabel->setVisible(true);
        ui->savingsMinimumBalance->setVisible(true);
        ui->certificateDepositTermLabel->setVisible(true);
        ui->certificateDepositTerm->setVisible(true);
        ui->certificateWithdrawalPenaltyLabel->setVisible(true);
        ui->certificateWithdrawalPenalty->setVisible(true);
        break;
    }
    case 5:
    {
        ui->savingsInterestRateLabel->setVisible(true);
        ui->savingsInterestRate->setVisible(true);
        ui->savingsMinimumBalanceLabel->setVisible(true);
        ui->savingsMinimumBalance->setVisible(true);
        ui->moneyAllowedTransactionsLabel->setVisible(true);
        ui->moneyAllowedTransactions->setVisible(true);
        ui->moneyTransactionFeeLabel->setVisible(true);
        ui->moneyTransactionFee->setVisible(true);
        break;
    }
    }
}

// Checks if the customer specified for the owner exists.
void accountAddDialog::on_accountAddOwner_textChanged(const QString &arg1)
{
    int pin = arg1.toInt();
    const Customer *cust = custTree->find(pin);
    if(cust == nullptr)
    {
        ui->accountAddBox->button(QDialogButtonBox::Ok)->setEnabled(false);
        ui->accountAddOwner->setStyleSheet("background-color: yellow");
        ui->accountAddOwner->setToolTip("A customer with the specified PIN does not exist.");
    }
    else
    {
        ui->accountAddBox->button(QDialogButtonBox::Ok)->setEnabled(true);
        ui->accountAddOwner->setStyleSheet("background-color: white");
        ui->accountAddOwner->setToolTip("");
    }
}

// Generates random data, appropriate for the selected account type.
void accountAddDialog::on_accountAddRandomize_clicked()
{
    ui->accountAddBalance->setText(QString::number(((rand() % 2476) * 4 + 100)));
    ui->accountAddIban->setText(QString::number(qrand() % 90 + 10));
    ui->accountAddOwner->setText(QString::number(qrand() % 90 + 10));

    switch(ui->accountAddType->currentIndex())
    {
    case 0:
    {
        ui->checkingMonthlyFee->setText(QString::number(qrand() % 10 + 1));
        break;
    }
    case 1:
    {
        ui->checkingMonthlyFee->setText(QString::number(qrand() % 10 + 1));
        ui->creditGracePeriod->setText(QString::number(qrand() % 31 + 30));
        ui->creditAnnualRate->setText(QString::number(qrand() % 11 + 10));
        break;
    }
    case 2:
    {
        ui->checkingMonthlyFee->setText(QString::number(qrand() % 10 + 1));
        ui->debitTransactionLimit->setText(QString::number(qrand() % 1801 + 200));
        ui->debitAtmLimit->setText(QString::number(qrand() % 3601 + 400));
        break;
    }
    case 3:
    {
        ui->savingsInterestRate->setText(QString::number(qrand() % 5 + 1));
        ui->savingsMinimumBalance->setText(QString::number(qrand() % 91 + 10));
        break;
    }
    case 4:
    {
        ui->savingsInterestRate->setText(QString::number(qrand() % 5 + 1));
        ui->savingsMinimumBalance->setText(QString::number(qrand() % 91 + 10));
        ui->certificateDepositTerm->setText(QString::number(qrand() % 12 + 1));
        ui->certificateWithdrawalPenalty->setText(QString::number(qrand() % 21 + 20));
        break;
    }
    case 5:
    {
        ui->savingsInterestRate->setText(QString::number(qrand() % 5 + 1));
        ui->savingsMinimumBalance->setText(QString::number(qrand() % 91 + 10));
        ui->moneyAllowedTransactions->setText(QString::number(qrand() % 9 + 1));
        ui->moneyTransactionFee->setText(QString::number(qrand() % 41 + 10));
        break;
    }
    }
}
