#include "account.h"

Account::Account()
{
    balance = 0.0;
    iban = 0;
    owner = nullptr;
}

Account::Account(double b, long i, Customer* o)
{
    balance = b;
    iban = i;
    owner = o;
}

bool Account::operator <(const Account & account)
{
    return Account::iban < account.Account::iban;
}

double Account::getBalance() const
{
    return balance;
}

void Account::setBalance(double amount)
{
    balance = amount;
}

void Account::deposit(double amount)
{
    balance += amount;
}

void Account::transfer(double amount, Account* account)
{
    balance -= amount;
    account->balance += amount;
}

void Account::withdraw(double amount)
{
    balance -= amount;
}
