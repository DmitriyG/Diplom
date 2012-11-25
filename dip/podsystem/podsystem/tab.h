#ifndef GOTOCELLDIALOG_H
#define GOTOCELLDIALOG_H
#include <QDialog>
#include "ui_tab.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"

class  L_TAB : public QDialog, public Ui::tab
{
    Q_OBJECT
public:
    L_TAB(QWidget *parent = 0);
//private slots:
//    void on_lineEdit_textChanged();

private slots:
    void on_pushButton_clicked();
};
#endif
