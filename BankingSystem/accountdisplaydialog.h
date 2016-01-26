#ifndef ACCOUNTDISPLAYDIALOG_H
#define ACCOUNTDISPLAYDIALOG_H

#include <QDialog>

namespace Ui {
class accountDisplayDialog;
}

class accountDisplayDialog : public QDialog
{
    Q_OBJECT

public:
    explicit accountDisplayDialog(QWidget *parent = 0);
    ~accountDisplayDialog();

    void setAccountIbans(QString ibans);

private:
    Ui::accountDisplayDialog *ui;
};

#endif // ACCOUNTDISPLAYDIALOG_H
