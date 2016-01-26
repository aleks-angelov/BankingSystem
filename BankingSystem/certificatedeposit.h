#ifndef CERTIFICATEDEPOSIT_H
#define CERTIFICATEDEPOSIT_H

#include "savings.h"

class CertificateDeposit : public Savings
{
public:
    CertificateDeposit()
    {
        type = 4;
        term = 0;
        withdrawalPenalty = 0.0;
    }

    CertificateDeposit(double b, int i, Customer *o, double iR, double mB, int t, double wP) : Savings(b, i, o, iR, mB)
    {
        type = 4;
        term = t;
        withdrawalPenalty = wP;
    }

    int withdraw(double amount)
    {
        if(balance - amount - amount * (withdrawalPenalty / 100) >= minimumBalance)
        {
            balance -= amount + amount * (withdrawalPenalty / 100);
            return 0;   // Withdrawal successful.
        }
        else
            return 1;   // Insufficient balance.
    }

    int transfer(double amount, Account *target)
    {
        if(balance - amount - amount * (withdrawalPenalty / 100) >= minimumBalance)
        {
            balance -= amount + amount * (withdrawalPenalty / 100);
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
    void populateAccountFindDialog(accountFindDialog *aCF)
    {
        Savings::populateAccountFindDialog(aCF);
        aCF->setCertificateDepositTerm(term);
        aCF->setCertificateWithdrawalPenalty(withdrawalPenalty);
    }

private:
    int term;

    double withdrawalPenalty;
};

#endif // CERTIFICATEDEPOSIT_H
