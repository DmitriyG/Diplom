#ifndef POLE_H
#define POLE_H
#include <QDialog>
#include "ui_pole.h"
class Pole: public QDialog, public Ui::pole
{
    Q_OBJECT
public:
    Pole(QWidget *parent = 0);


private slots:
    void on_pushButton_clicked();
};
#endif

