#ifndef ACCOUNT_H
#define ACCOUNT_H

#include "accountfinddialog.h"

class Customer;

class Account
{
public:
    Account()
    {
        type = -1;
        balance = 0.0;
        iban = 0;
        owner = nullptr;
    }

    Account(double b, int i, Customer *o)
    {
        type = -1;
        balance = b;
        iban = i;
        owner = o;
    }

    int getType() const
    {
        return type;
    }

    double getBalance() const
    {
        return balance;
    }

    int getIban() const
    {
        return iban;
    }

    Customer *getOwner() const
    {
        return owner;
    }

    void deposit(double amount)
    {
        balance += amount;
    }

    virtual int withdraw(double amount)
    {
        balance -= amount;
        return 0;   // Withdrawal successful.
    }

    virtual int transfer(double amount, Account *target)
    {
        balance -= amount;
        target->deposit(amount);
        return 0;   // Transfer successful.
    }

    /*
    Populates the fields of the Find Account dialog window
    with data, appropriate for the type of the found account.
    */
    virtual void populateAccountFindDialog(accountFindDialog *aCF)
    {
        aCF->setAccountType(type);
        aCF->setAccountBalance(balance);
        aCF->setAccountIban(iban);
        aCF->setAccountOwner(owner);
    }

protected:
    int type;

    double balance;

    int iban;

    Customer *owner;
};

#endif // ACCOUNT_H
