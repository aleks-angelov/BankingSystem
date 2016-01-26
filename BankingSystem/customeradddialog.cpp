#include "customeradddialog.h"
#include "ui_customeradddialog.h"

#include <time.h>

customerAddDialog::customerAddDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::customerAddDialog)
{
    qsrand(time(nullptr));

    ui->setupUi(this);
}

customerAddDialog::~customerAddDialog()
{
    delete ui;
}

// Prevents the user from entering invalid data.
void customerAddDialog::setFieldValidations()
{
    QIntValidator *intValid = new QIntValidator(1, 999999999);

    ui->customerAddPin->setValidator(intValid);
    ui->customerAddId->setValidator(intValid);
}

QString customerAddDialog::getCustomerName()
{
    return ui->customerAddName->text();
}

int customerAddDialog::getCustomerPin()
{
    return ui->customerAddPin->text().toInt();
}

int customerAddDialog::getCustomerId()
{
    return ui->customerAddId->text().toInt();
}

QString customerAddDialog::getCustomerAddress()
{
    return ui->customerAddAddress->text();
}

QString customerAddDialog::getCustomerEmail()
{
    return ui->customerAddEmail->text();
}

// Generates random customer data.
void customerAddDialog::on_customerAddRandomize_clicked()
{
    if(qrand() % 2 == 0)
        ui->customerAddName->setText("Jane Shepard");
    else
        ui->customerAddName->setText("John Shepard");

    ui->customerAddPin->setText(QString::number(qrand() % 90 + 10));
    ui->customerAddId->setText(QString::number(qrand() % 9000 + 1000));
    ui->customerAddAddress->setText(QString::number(qrand() % 800 + 200) + " Skaptopara Street");
    ui->customerAddEmail->setText("js" + QString::number(qrand() % 100 + 100) + "@aubg.edu");
}
