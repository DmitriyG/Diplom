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

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
     MainWindow(QWidget *parent = 0);
    ~MainWindow();
     Ui::MainWindow *ui;
private:
     QSqlTableModel* model;
     QTableView *view;
public slots:
    void tab();
    void pole();
};

#endif // MAINWINDOW_H
