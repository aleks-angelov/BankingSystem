#ifndef DEBITCARD_H
#define DEBITCARD_H

#include "checking.h"

class DebitCard : public Checking
{
public:
    DebitCard()
    {
        type = 2;
        transactionLimit = 0.0;
        transactionBalance = 0.0;
        atmWithdrawalLimit = 0.0;
        atmWithdrawalBalance = 0.0;
    }

    DebitCard(double b, int i, Customer *o, double mF, double tL, double aWL) : Checking(b, i, o, mF)
    {
        type = 2;
        transactionLimit = tL;
        transactionBalance = 0.0;
        atmWithdrawalLimit = aWL;
        atmWithdrawalBalance = 0.0;
    }

    int withdraw(double amount)
    {
        if(balance - amount > 0.0)
        {
            if(atmWithdrawalBalance + amount <= atmWithdrawalLimit)
            {
                balance -= amount;
                atmWithdrawalBalance += amount;
                return 0;   // Withdrawal successful.
            }
            else
                return 2;   // Atm withdrawal limit reached.
        }
        else
            return 1;   // Insufficient balance.
    }

    int transfer(double amount, Account *target)
    {
        if(balance - amount > 0.0)
        {
            if(transactionBalance + amount <= transactionLimit)
            {
                balance -= amount;
                target->deposit(amount);
                transactionBalance += amount;
                return 0;   // Transfer successful.
            }

            return 2;   // Transaction amount limit reached.
        }
        else
            return 1;   // Insufficient balance.
    }

    /*
    Populates the fields of the Find Account dialog window
    with data, appropriate for the type of the found account.
    */
    void populateAccountFindDialog(accountFindDialog *aCF)
    {
        Checking::populateAccountFindDialog(aCF);
        aCF->setDebitTransactionLimit(transactionLimit);
        aCF->setDebitTransactionBalance(transactionBalance);
        aCF->setDebitAtmLimit(atmWithdrawalLimit);
        aCF->setDebitAtmBalance(atmWithdrawalBalance);
    }

private:
    double transactionLimit;

    double transactionBalance;

    double atmWithdrawalLimit;

    double atmWithdrawalBalance;
};

#endif // DEBITCARD_H
