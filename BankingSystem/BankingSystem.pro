#-------------------------------------------------
#
# Project created by QtCreator 2014-10-27T15:22:16
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = BankingSystem
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    customeradddialog.cpp \
    customerfinddialog.cpp \
    accountadddialog.cpp \
    accountfinddialog.cpp \
    customerdisplaydialog.cpp \
    accountdisplaydialog.cpp

HEADERS  += mainwindow.h \
    account.h \
    checking.h \
    savings.h \
    creditcard.h \
    debitcard.h \
    certificatedeposit.h \
    moneymarket.h \
    customer.h \
    avltree.h \
    customeradddialog.h \
    customerfinddialog.h \
    accountadddialog.h \
    accountfinddialog.h \
    customerdisplaydialog.h \
    accountdisplaydialog.h

FORMS    += mainwindow.ui \
    customeradddialog.ui \
    customerfinddialog.ui \
    accountadddialog.ui \
    accountfinddialog.ui \
    customerdisplaydialog.ui \
    accountdisplaydialog.ui

QMAKE_CXXFLAGS += -std=c++11
