#include "accountfinddialog.h"
#include "ui_accountfinddialog.h"

accountFindDialog::accountFindDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::accountFindDialog)
{
    ui->setupUi(this);
}

accountFindDialog::~accountFindDialog()
{
    delete ui;
}

// Displays only fields, appropriate for the type of the found account.
void accountFindDialog::displayFields(int accountType)
{
    ui->checkingMonthlyFee->setVisible(false);
    ui->creditGracePeriod->setVisible(false);
    ui->creditAnnualRate->setVisible(false);
    ui->debitTransactionLimit->setVisible(false);
    ui->debitTransactionBalance->setVisible(false);
    ui->debitAtmLimit->setVisible(false);
    ui->debitAtmBalance->setVisible(false);
    ui->savingsInterestRate->setVisible(false);
    ui->savingsMinimumBalance->setVisible(false);
    ui->certificateDepositTerm->setVisible(false);
    ui->certificateWithdrawalPenalty->setVisible(false);
    ui->moneyAllowedTransactions->setVisible(false);
    ui->moneyCurrentTransactions->setVisible(false);
    ui->moneyTransactionFee->setVisible(false);

    switch(accountType)
    {
    case 0:
    {
        ui->checkingMonthlyFee->setVisible(true);
        break;
    }
    case 1:
    {
        ui->checkingMonthlyFee->setVisible(true);
        ui->creditGracePeriod->setVisible(true);
        ui->creditAnnualRate->setVisible(true);
        break;
    }
    case 2:
    {
        ui->checkingMonthlyFee->setVisible(true);
        ui->debitTransactionLimit->setVisible(true);
        ui->debitTransactionBalance->setVisible(true);
        ui->debitAtmLimit->setVisible(true);
        ui->debitAtmBalance->setVisible(true);
        break;
    }
    case 3:
    {
        ui->savingsInterestRate->setVisible(true);
        ui->savingsMinimumBalance->setVisible(true);
        break;
    }
    case 4:
    {
        ui->savingsInterestRate->setVisible(true);
        ui->savingsMinimumBalance->setVisible(true);
        ui->certificateDepositTerm->setVisible(true);
        ui->certificateWithdrawalPenalty->setVisible(true);
        break;
    }
    case 5:
    {
        ui->savingsInterestRate->setVisible(true);
        ui->savingsMinimumBalance->setVisible(true);
        ui->moneyAllowedTransactions->setVisible(true);
        ui->moneyCurrentTransactions->setVisible(true);
        ui->moneyTransactionFee->setVisible(true);
        break;
    }
    }
}

void accountFindDialog::setAccountType(int t)
{
    switch(t)
    {
    case 0:
    {
        ui->accountFindType->setText(ui->accountFindType->text() + "Checking Account");
        break;
    }
    case 1:
    {
        ui->accountFindType->setText(ui->accountFindType->text() + "Credit Card Account");
        break;
    }
    case 2:
    {
        ui->accountFindType->setText(ui->accountFindType->text() + "Debit Card Account");
        break;
    }
    case 3:
    {
        ui->accountFindType->setText(ui->accountFindType->text() + "Savings Account");
        break;
    }
    case 4:
    {
        ui->accountFindType->setText(ui->accountFindType->text() + "Certificate Deposit Account");
        break;
    }
    case 5:
    {
        ui->accountFindType->setText(ui->accountFindType->text() + "Money Market Account");
        break;
    }
    }
}

void accountFindDialog::setAccountBalance(double b)
{
    ui->accountFindBalance->setText(ui->accountFindBalance->text() + QString::number(b, 'f', 2));
}

void accountFindDialog::setAccountIban(int i)
{
    ui->accountFindIban->setText(ui->accountFindIban->text() + QString::number(i));
}

void accountFindDialog::setAccountOwner(Customer *o)
{
    ui->accountFindOwner->setText(ui->accountFindOwner->text() + QString::number(o->getPin()));
}

void accountFindDialog::setCheckingMonthlyFee(double mF)
{
    ui->checkingMonthlyFee->setText(ui->checkingMonthlyFee->text() + QString::number(mF, 'f', 2));
}

void accountFindDialog::setCreditGracePeriod(int gP)
{
    ui->creditGracePeriod->setText(ui->creditGracePeriod->text() + QString::number(gP) + " day(s)");
}

void accountFindDialog::setCreditAnnualRate(double aR)
{
    ui->creditAnnualRate->setText(ui->creditAnnualRate->text() + QString::number(aR, 'f', 2) + "%");
}

void accountFindDialog::setDebitTransactionLimit(double tL)
{
    ui->debitTransactionLimit->setText(ui->debitTransactionLimit->text() + QString::number(tL, 'f', 2));
}

void accountFindDialog::setDebitTransactionBalance(double tB)
{
    ui->debitTransactionBalance->setText(ui->debitTransactionBalance->text() + QString::number(tB, 'f', 2));
}

void accountFindDialog::setDebitAtmLimit(double aL)
{
    ui->debitAtmLimit->setText(ui->debitAtmLimit->text() + QString::number(aL, 'f', 2));
}

void accountFindDialog::setDebitAtmBalance(double aB)
{
    ui->debitAtmBalance->setText(ui->debitAtmBalance->text() + QString::number(aB, 'f', 2));
}

void accountFindDialog::setSavingsInterestRate(double iR)
{
    ui->savingsInterestRate->setText(ui->savingsInterestRate->text() + QString::number(iR, 'f', 2) + "%");
}

void accountFindDialog::setSavingsMinimumBalance(double mB)
{
    ui->savingsMinimumBalance->setText(ui->savingsMinimumBalance->text() + QString::number(mB, 'f', 2));
}

void accountFindDialog::setCertificateDepositTerm(int t)
{
    ui->certificateDepositTerm->setText(ui->certificateDepositTerm->text() + QString::number(t) + " month(s)");
}

void accountFindDialog::setCertificateWithdrawalPenalty(double wP)
{
    ui->certificateWithdrawalPenalty->setText(ui->certificateWithdrawalPenalty->text() + QString::number(wP, 'f', 2) + "%");
}

void accountFindDialog::setMoneyAllowedTransactions(int aT)
{
    ui->moneyAllowedTransactions->setText(ui->moneyAllowedTransactions->text() + QString::number(aT));
}

void accountFindDialog::setMoneyCurrentTransactions(int cT)
{
    ui->moneyCurrentTransactions->setText(ui->moneyCurrentTransactions->text() + QString::number(cT));
}

void accountFindDialog::setMoneyTransactionFee(double tF)
{
    ui->moneyTransactionFee->setText(ui->moneyTransactionFee->text() + QString::number(tF, 'f', 2));
}
