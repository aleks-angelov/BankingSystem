#include "certificatedeposit.h"

CertificateDeposit::CertificateDeposit()
{
    Savings::Savings();
    term = 0;
    withdrawalPenalty = 0.0;
}

CertificateDeposit::CertificateDeposit(double b, long i, Customer* o, double iR, double mB, int t, double wP)
{
    Savings::Savings(b, i, o, iR, mB);
    term = t;
    withdrawalPenalty = wP;
}

void CertificateDeposit::transfer(double amount, Account* account)
{
    if(balance - amount - amount * withdrawalPenalty >= minimumBalance)
    {
        balance -= amount + amount * withdrawalPenalty;
        account->setBalance(account->getBalance() + amount);
    }

    //else Insufficient balance dialog.
}

void CertificateDeposit::withdraw(double amount)
{
    if(balance - amount - amount * withdrawalPenalty >= minimumBalance)
    {
        balance -= amount + amount * withdrawalPenalty;
    }

    //else Insufficient balance dialog.
}
