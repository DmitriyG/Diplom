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
    int flag;
  //  int name;
 //    QWidget *win;
protected:
    void closeEvent( QCloseEvent *);
private slots:
    void on_tableWidget_clicked(QModelIndex index);
    void on_comboBox_currentIndexChanged(QString );
    void on_pushButton_clicked();
};
#endif

