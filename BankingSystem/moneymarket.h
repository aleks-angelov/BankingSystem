#ifndef MONEYMARKET_H
#define MONEYMARKET_H

#include "savings.h"

class MoneyMarket : public Savings
{
public:
    MoneyMarket()
    {
        type = 5;
        allowedTransactions = 0;
        currentTransactions = 0;
        transactionFee = 0.0;
    }

    MoneyMarket(double b, int i, Customer *o, double iR, double mB, int aT, double tF) : Savings(b, i, o, iR, mB)
    {
        type = 5;
        allowedTransactions = aT;
        currentTransactions = 0;
        transactionFee = tF;
    }

    int withdraw(double amount)
    {
        if(balance - amount - transactionFee >= minimumBalance)
        {
            if(currentTransactions < allowedTransactions)
            {
                balance -= amount + transactionFee;
                currentTransactions++;
                return 0;   // Withdrawal successful.
            }
            else
                return 3; // Transaction number limit reached.
        }
        else
            return 1;   // Insufficient balance.
    }

    int transfer(double amount, Account *target)
    {
        if(balance - amount - transactionFee >= minimumBalance)
        {
            if(currentTransactions < allowedTransactions)
            {
                balance -= amount + transactionFee;
                target->deposit(amount);
                currentTransactions++;
                return 0;   // Transfer successful.
            }
            else
                return 3; // Transaction number limit reached.
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
        Savings::populateAccountFindDialog(aCF);
        aCF->setMoneyAllowedTransactions(allowedTransactions);
        aCF->setMoneyCurrentTransactions(currentTransactions);
        aCF->setMoneyTransactionFee(transactionFee);
    }

private:
    int allowedTransactions;

    int currentTransactions;

    double transactionFee;
};

#endif // MONEYMARKET_H
