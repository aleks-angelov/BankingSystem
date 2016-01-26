#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "avltree.h"
#include "certificatedeposit.h"
#include "creditcard.h"
#include "debitcard.h"
#include "moneymarket.h"

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void setFieldValidations();
    AvlTree<Account*> accountTree;
    AvlTree<Customer> customerTree;

private slots: 
    void on_accountAdd_clicked();

    void on_accountFind_clicked();

    void on_accountDelete_clicked();

    void on_accountDisplayIbans_clicked();

    void on_accountDeleteAll_clicked();

    void on_transactionBalance_clicked();

    void on_transactionDeposit_clicked();

    void on_transactionWithdraw_clicked();

    void on_transactionTransfer_clicked();

    void on_customerAdd_clicked();

    void on_customerFind_clicked();

    void on_customerDelete_clicked();

    void on_customerDisplayPins_clicked();

    void on_customerDeleteAll_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
