#include "customerdisplaydialog.h"
#include "ui_customerdisplaydialog.h"

customerDisplayDialog::customerDisplayDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::customerDisplayDialog)
{
    ui->setupUi(this);
}

customerDisplayDialog::~customerDisplayDialog()
{
    delete ui;
}

void customerDisplayDialog::setCustomerPins(QString pins)
{
    ui->customerDisplayPins->setText(pins);
}
