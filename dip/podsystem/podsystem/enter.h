#ifndef GOTOCELLDIALOG_H
#define GOTOCELLDIALOG_H
#include <QDialog>
#include "ui_enter.h"
#include "mainwindow.h"

class Enter : public QDialog, public Ui::Form
{
    Q_OBJECT
public:
    Enter(QWidget *parent = 0);
    ~Enter();
    QString  st_e1;
    QString  st_e2;

private slots:
    void enter_bd();
};
#endif
