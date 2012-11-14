#ifndef GOTOCELLDIALOG_H
#define GOTOCELLDIALOG_H
#include <QDialog>
#include "ui_enter.h"
class Enter : public QDialog, public Ui::Form
{
    Q_OBJECT
public:
    Enter(QWidget *parent = 0);

};
#endif
