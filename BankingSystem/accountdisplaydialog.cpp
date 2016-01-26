#include "accountdisplaydialog.h"
#include "ui_accountdisplaydialog.h"

accountDisplayDialog::accountDisplayDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::accountDisplayDialog)
{
    ui->setupUi(this);
}

accountDisplayDialog::~accountDisplayDialog()
{
    delete ui;
}

void accountDisplayDialog::setAccountIbans(QString ibans)
{
    ui->accountDisplayIbans->setText(ibans);
}
