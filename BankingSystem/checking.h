#ifndef CHECKING_H
#define CHECKING_H

#include "account.h"

class Checking : public Account
{
public:
    Checking()
    {
        type = 0;
        monthlyFee = 0.0;
    }

    Checking(double b, int i, Customer *o, double mF) : Account(b, i, o)
    {
        type = 0;
        monthlyFee = mF;
    }

    virtual int withdraw(double amount)
    {
        if(balance - amount > 0.0)
        {
            balance -= amount;
            return 0;   // Withdrawal successful.
        }
        else
            return 1;   // Insufficient balance.
    }

    virtual int transfer(double amount, Account *target)
    {
        if(balance - amount > 0.0)
        {
            balance -= amount;
            target->deposit(amount);
            return 0;   // Transfer successful.
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
        aCF->setCheckingMonthlyFee(monthlyFee);
    }

protected:
    double monthlyFee;
};

#endif // CHECKING_H
