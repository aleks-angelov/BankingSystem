#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "accountadddialog.h"
#include "accountfinddialog.h"
#include "accountdisplaydialog.h"
#include "customeradddialog.h"
#include "customerfinddialog.h"
#include "customerdisplaydialog.h"

#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

// Prevents the user from entering invalid data.
void MainWindow::setFieldValidations()
{
    QIntValidator *intValid = new QIntValidator(1, 999999999);
    QDoubleValidator *doubleValid = new QDoubleValidator(1.00, 999999999.99, 2);
    doubleValid->setNotation(QDoubleValidator::StandardNotation);

    ui->accountFindIban->setValidator(intValid);
    ui->accountDeleteIban->setValidator(intValid);
    ui->transactionBalanceIban->setValidator(intValid);
    ui->transactionDepositIban->setValidator(intValid);
    ui->transactionDepositAmount->setValidator(doubleValid);
    ui->transactionTransferSource->setValidator(intValid);
    ui->transactionTransferTarget->setValidator(intValid);
    ui->transactionTransferAmount->setValidator(doubleValid);
    ui->customerFindPin->setValidator(intValid);
    ui->customerDeletePin->setValidator(intValid);
}

void MainWindow::on_accountAdd_clicked()
{
    accountAddDialog accAddDialog;
    accAddDialog.setTree(&customerTree);
    accAddDialog.setFieldValidations();

    Account *newAcc;
    bool wasInserted = false;
    while(wasInserted == false && accAddDialog.exec() == QDialog::Accepted)
    {
        Customer *o = customerTree.find(accAddDialog.getAccountOwner());

        if(o != nullptr)
        {
            switch(accAddDialog.getAccountType())
            {
            case 0:
            {
                newAcc = new Checking(accAddDialog.getAccountBalance(), accAddDialog.getAccountIban(), o, accAddDialog.getCheckingMonthlyFee());
                break;
            }
            case 1:
            {
                newAcc = new CreditCard(accAddDialog.getAccountBalance(), accAddDialog.getAccountIban(), o, accAddDialog.getCheckingMonthlyFee(), accAddDialog.getCreditGracePeriod(), accAddDialog.getCreditAnnualRate());
                break;
            }
            case 2:
            {
                newAcc = new DebitCard(accAddDialog.getAccountBalance(), accAddDialog.getAccountIban(), o, accAddDialog.getCheckingMonthlyFee(), accAddDialog.getDebitTransactionLimit(), accAddDialog.getDebitAtmLimit());
                break;
            }
            case 3:
            {
                newAcc = new Savings(accAddDialog.getAccountBalance(), accAddDialog.getAccountIban(), o, accAddDialog.getSavingsInterestRate(), accAddDialog.getSavingsMinimumBalance());
                break;
            }
            case 4:
            {
                newAcc = new CertificateDeposit(accAddDialog.getAccountBalance(), accAddDialog.getAccountIban(), o, accAddDialog.getSavingsInterestRate(), accAddDialog.getSavingsMinimumBalance(), accAddDialog.getCertificateDepositTerm(), accAddDialog.getCertificateWithdrawalPenalty());
                break;
            }
            case 5:
            {
                newAcc = new MoneyMarket(accAddDialog.getAccountBalance(), accAddDialog.getAccountIban(), o, accAddDialog.getSavingsInterestRate(), accAddDialog.getSavingsMinimumBalance(), accAddDialog.getMoneyAllowedTransactions(), accAddDialog.getMoneyTransactionFee());
                break;
            }
            }
        }

        wasInserted = accountTree.insert(newAcc->getIban(), newAcc);
        if(wasInserted == true)
        {
            o->addAccount(newAcc);
            QMessageBox::information(this, "Add Account", "An account with the specified IBAN has been added.", QMessageBox::Ok);
        }
        else
            QMessageBox::warning(this, "Add Account", "An account with the specified IBAN already exists.", QMessageBox::Ok);
    }
}

void MainWindow::on_accountFind_clicked()
{
    Account *const *account = accountTree.find(ui->accountFindIban->text().toInt());
    if (account == nullptr)
        QMessageBox::critical(this, "Find Account", "An account with the specified IBAN does not exist.", QMessageBox::Ok);
    else
    {
        accountFindDialog accFindDialog;
        accFindDialog.displayFields((*account)->getType());
        (*account)->populateAccountFindDialog(&accFindDialog);
        accFindDialog.exec();
    }
}

void MainWindow::on_accountDelete_clicked()
{
    Account *const *account = accountTree.find(ui->accountDeleteIban->text().toInt());
    if (account == nullptr)
        QMessageBox::critical(this, "Delete Account", "An account with the specified IBAN does not exist.", QMessageBox::Ok);
    else
    {
        (*account)->getOwner()->removeAccount(*account);
        accountTree.remove((*account)->getIban());
        QMessageBox::information(this, "Delete Account", "The account with the specified IBAN has been deleted.", QMessageBox::Ok);
    }
}

void MainWindow::on_accountDisplayIbans_clicked()
{
    QString accountIbans;
    if(accountTree.printTree(accountIbans) == false)
        QMessageBox::warning(this, "Display All IBANs", "No account records exist.", QMessageBox::Ok);
    else
    {
        accountDisplayDialog accDisplayDialog;
        accDisplayDialog.setAccountIbans(accountIbans);
        accDisplayDialog.exec();
    }
}

void MainWindow::on_accountDeleteAll_clicked()
{
    if(accountTree.makeEmpty() == false)
        QMessageBox::warning(this, "Delete All Accounts", "No account records exist.", QMessageBox::Ok);
    else
    {
        customerTree.emptyAccountLists();
        QMessageBox::information(this, "Delete All Customers", "All account records have been deleted.", QMessageBox::Ok);
    }
}


void MainWindow::on_transactionBalance_clicked()
{
    Account *const *account = accountTree.find(ui->transactionBalanceIban->text().toInt());
    if(account == nullptr)
        QMessageBox::critical(this, "Current Balance", "An account with the specified IBAN does not exist.", QMessageBox::Ok);
    else
        QMessageBox::information(this, "Current Balance", "The balance of the account is $" + QString::number((*account)->getBalance(), 'f', 2), QMessageBox::Ok);
}

void MainWindow::on_transactionDeposit_clicked()
{
    Account *const *account = accountTree.find(ui->transactionDepositIban->text().toInt());
    if(account == nullptr)
        QMessageBox::critical(this, "Deposit Funds", "An account with the specified IBAN does not exist.", QMessageBox::Ok);
    else
    {
        (*account)->deposit(ui->transactionDepositAmount->text().toDouble());
        QMessageBox::information(this, "Deposit Funds", "The specified amount has been deposited.", QMessageBox::Ok);
    }
}

void MainWindow::on_transactionWithdraw_clicked()
{
    Account *const *account = accountTree.find(ui->transactionDepositIban->text().toInt());
    if(account == nullptr)
        QMessageBox::critical(this, "Withdraw Funds", "An account with the specified IBAN does not exist.", QMessageBox::Ok);
    else
    {
        int withdrawalResult = (*account)->withdraw(ui->transactionDepositAmount->text().toDouble());
        switch(withdrawalResult)
        {
        case 0:
        {
            QMessageBox::information(this, "Withdraw Funds", "The specified amount has been withdrawn.", QMessageBox::Ok);
            break;
        }
        case 1:
        {
            QMessageBox::warning(this, "Withdraw Funds", "The account's balance is insufficient.", QMessageBox::Ok);
            break;
        }
        case 2:
        {
            QMessageBox::warning(this, "Withdraw Funds", "The ATM withdrawal limit has been reached.", QMessageBox::Ok);
            break;
        }
        case 3:
        {
            QMessageBox::warning(this, "Withdraw Funds", "The transaction number limit has been reached.", QMessageBox::Ok);
            break;
        }
        }
    }
}

void MainWindow::on_transactionTransfer_clicked()
{
    Account *const *sourceAccount = accountTree.find(ui->transactionTransferSource->text().toInt());
    Account *const *targetAccount = accountTree.find(ui->transactionTransferTarget->text().toInt());

    if(sourceAccount == nullptr)
        QMessageBox::critical(this, "Transfer Funds", "A source account with the specified IBAN does not exist.", QMessageBox::Ok);
    else
    {
        if(targetAccount == nullptr)
            QMessageBox::critical(this, "Transfer Funds", "A target account with the specified IBAN does not exist.", QMessageBox::Ok);
        else
        {
            int transferResult = (*sourceAccount)->transfer(ui->transactionTransferAmount->text().toDouble(), (*targetAccount));
            switch(transferResult)
            {
            case 0:
            {
                QMessageBox::information(this, "Transfer Funds", "The specified amount has been transferred.", QMessageBox::Ok);
                break;
            }
            case 1:
            {
                QMessageBox::warning(this, "Transfer Funds", "The source account's balance is insufficient.", QMessageBox::Ok);
                break;
            }
            case 2:
            {
                QMessageBox::warning(this, "Transfer Funds", "The source account's transaction amount limit has been reached.", QMessageBox::Ok);
                break;
            }
            case 3:
            {
                QMessageBox::warning(this, "Transfer Funds", "The source account's transaction number limit has been reached.", QMessageBox::Ok);
                break;
            }
            }
        }
    }
}

void MainWindow::on_customerAdd_clicked()
{
    customerAddDialog custAddDialog;
    custAddDialog.setFieldValidations();

    bool wasInserted = false;
    while(wasInserted == false && custAddDialog.exec() == QDialog::Accepted)
    {
        Customer newCust(custAddDialog.getCustomerName(), custAddDialog.getCustomerPin(), custAddDialog.getCustomerId(), custAddDialog.getCustomerAddress(), custAddDialog.getCustomerEmail());
        wasInserted = customerTree.insert(newCust.getPin(), newCust);

        if(wasInserted == true)
            QMessageBox::information(this, "Add Customer", "A customer with the specified PIN has been added.", QMessageBox::Ok);
        else
            QMessageBox::warning(this, "Add Customer", "A customer with the specified PIN already exists.", QMessageBox::Ok);
    }
}

void MainWindow::on_customerFind_clicked()
{
    const Customer *customer = customerTree.find(ui->customerFindPin->text().toInt());
    if (customer == nullptr)
        QMessageBox::critical(this, "Find Customer", "A customer with the specified PIN does not exist.", QMessageBox::Ok);
    else
    {
        customerFindDialog custFindDialog;
        custFindDialog.setCustomerName(customer->getName());
        custFindDialog.setCustomerPin(customer->getPin());
        custFindDialog.setCustomerId(customer->getIdNumber());
        custFindDialog.setCustomerAddress(customer->getAddress());
        custFindDialog.setCustomerEmail(customer->getEmail());
        custFindDialog.setCustomerAccounts(customer->getAccounts());
        custFindDialog.exec();
    }
}

void MainWindow::on_customerDelete_clicked()
{
    const Customer *customer = customerTree.find(ui->customerDeletePin->text().toInt());
    if (customer == nullptr)
        QMessageBox::critical(this, "Delete Customer", "A customer with the specified PIN does not exist.", QMessageBox::Ok);
    else
    {
        const std::list<Account*> *ownedAccounts = customer->getAccounts();
        for (std::list<Account*>::const_iterator it = ownedAccounts->begin(); it != ownedAccounts->end(); it++)
            accountTree.remove((*it)->getIban());
        customerTree.remove(customer->getPin());
        QMessageBox::information(this, "Delete Customer", "The customer with the specified PIN has been deleted.", QMessageBox::Ok);
    }
}

void MainWindow::on_customerDisplayPins_clicked()
{
    QString customerPins;
    if(customerTree.printTree(customerPins) == false)
        QMessageBox::warning(this, "Display All PINs", "No customer records exist.", QMessageBox::Ok);
    else
    {
        customerDisplayDialog custDisplayDialog;
        custDisplayDialog.setCustomerPins(customerPins);
        custDisplayDialog.exec();
    }
}

void MainWindow::on_customerDeleteAll_clicked()
{
    if(customerTree.makeEmpty() == false)
        QMessageBox::warning(this, "Delete All Customers", "No customer records exist.", QMessageBox::Ok);
    else
    {
        bool accountsDelete = accountTree.makeEmpty();
        accountsDelete = true;
        QMessageBox::information(this, "Delete All Customers", "All customer records have been deleted.", QMessageBox::Ok);
    }
}
