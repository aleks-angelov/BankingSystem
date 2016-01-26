#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <QString>

#include <list>

class Account;

class Customer
{
public:
    Customer()
    {
        name = "";
        pin = 0;
        idNumber = 0;
        address = "";
        email = "";
        accounts = std::list<Account*>();
    }

    Customer(QString n, long p, long iN, QString a, QString e)
    {
        name = n;
        pin = p;
        idNumber = iN;
        address = a;
        email = e;
        accounts = std::list<Account*>();
    }

    QString getName() const
    {
        return name;
    }

    int getPin() const
    {
        return pin;
    }

    int getIdNumber() const
    {
        return idNumber;
    }

    QString getAddress() const
    {
        return address;
    }

    QString getEmail() const
    {
        return email;
    }

    const std::list<Account*> *getAccounts() const
    {
        return &accounts;
    }

    void addAccount(Account *account)
    {
        accounts.push_back(account);
    }

    void removeAccount(Account *account)
    {
        accounts.remove(account);
    }

    void removeAllAccounts()
    {
        accounts.clear();
    }

private:
    QString name;

    int pin;

    int idNumber;

    QString address;

    QString email;

    std::list<Account*> accounts;
};

#endif // CUSTOMER_H
