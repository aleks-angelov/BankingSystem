#ifndef SAVINGS_H
#define SAVINGS_H

#include "account.h"

class Savings : public Account
{
public:
    Savings()
    {
        type = 3;
        interestRate = 0.0;
        minimumBalance = 0.0;
    }

    Savings(double b, int i, Customer *o, double iR, double mB) : Account(b, i, o)
    {
        type = 3;
        interestRate = iR;
        minimumBalance = mB;
    }

    virtual int withdraw(double amount)
    {
        if(balance - amount >= minimumBalance)
        {
            balance -= amount;
            return 0;
        }
        else
            return 1;   // Insufficient balance.
    }

    virtual int transfer(double amount, Account *target)
    {
        if(balance - amount >= minimumBalance)
        {
            balance -= amount;
            target->deposit(amount);
            return 0;
        }
        else
            return 1;   // Insufficient balance.
    }

    /*
    Populates the fields of the Find Account dialog window
    with data, appropriate for the type of the found account.
    */
    virtual void populateAccountFindDialog(accountFindDialog *aCF)
    {
        Account::populateAccountFindDialog(aCF);
        aCF->setSavingsInterestRate(interestRate);
        aCF->setSavingsMinimumBalance(minimumBalance);
    }

protected:
    double interestRate;

    double minimumBalance;
};

#endif // SAVINGS_H
