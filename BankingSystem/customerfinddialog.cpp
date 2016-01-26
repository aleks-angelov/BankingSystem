#include "customerfinddialog.h"
#include "ui_customerfinddialog.h"

customerFindDialog::customerFindDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::customerFindDialog)
{
    ui->setupUi(this);
}

customerFindDialog::~customerFindDialog()
{
    delete ui;
}

void customerFindDialog::setCustomerName(QString name)
{
    ui->customerFindName->setText(ui->customerFindName->text() + name);
}

void customerFindDialog::setCustomerPin(int pin)
{
    ui->customerFindPin->setText(ui->customerFindPin->text() + QString::number(pin));
}

void customerFindDialog::setCustomerId(int id)
{
    ui->customerFindId->setText(ui->customerFindId->text() + QString::number(id));
}

void customerFindDialog::setCustomerAddress(QString address)
{
    ui->customerFindAddress->setText(ui->customerFindAddress->text() + address);
}

void customerFindDialog::setCustomerEmail(QString email)
{
    ui->customerFindEmail->setText(ui->customerFindEmail->text() + email);
}

void customerFindDialog::setCustomerAccounts(const std::list<Account *> *accounts)
{
    for (std::list<Account*>::const_iterator it = accounts->begin(); it != accounts->end(); it++)
        ui->customerFindAccounts->setText(ui->customerFindAccounts->toPlainText() + QString::number((*it)->getIban()) + "\t");
}
