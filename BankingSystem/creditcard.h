#ifndef CREDITCARD_H
#define CREDITCARD_H

#include "checking.h"

class CreditCard : public Checking
{
public:
    CreditCard()
    {
        type = 1;
        gracePeriod = 0;
        annualPercentageRate = 0.0;
    }

    CreditCard(double b, int i, Customer *o, double mF, int gP, double aPR) : Checking(b, i, o, mF)
    {
        type = 1;
        gracePeriod = gP;
        annualPercentageRate = aPR;
    }

    int withdraw(double amount)
    {
        balance -= amount;
        return 0;   // Withdrawal successful.
    }

    int transfer(double amount, Account *target)
    {
        balance -= amount;
        target->deposit(amount);
        return 0;   // Transfer successful.
    }

    /*
    Populates the fields of the Find Account dialog window
    with data, appropriate for the type of the found account.
    */
    void populateAccountFindDialog(accountFindDialog *aCF)
    {
        Checking::populateAccountFindDialog(aCF);
        aCF->setCreditGracePeriod(gracePeriod);
        aCF->setCreditAnnualRate(annualPercentageRate);
    }

private:
    int gracePeriod;

    double annualPercentageRate;
};

#endif // CREDITCARD_H
