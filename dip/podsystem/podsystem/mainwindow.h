#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <qtableview>
#include <QtGui/QMainWindow>
#include "ui_mainwindow.h"
#include <QSqlQueryModel>
#include <QLineEdit>
#include <QtSql>
 #include <QDialog>
#include <QSqlDatabase>


#include <QMainWindow>

namespace Ui {
    class MainWindow;

}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

     MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:

    QSqlTableModel* model;
    QTableView *view;

    Ui::MainWindow *ui;

//public slots:

};

#endif // MAINWINDOW_H
