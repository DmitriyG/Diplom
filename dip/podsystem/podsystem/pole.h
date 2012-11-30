#ifndef POLE_H
#define POLE_H
#include <QDialog>
#include "ui_pole.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"

class Pole: public QDialog, public Ui::pole
{
    Q_OBJECT
public:
    Pole(QWidget *parent = 0);
private slots:
    void on_comboBox_currentIndexChanged(QString );
    void on_pushButton_clicked();
};
#endif

