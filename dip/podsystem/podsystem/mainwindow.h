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

class MyItemDelegate: public QItemDelegate
{
public:
        MyItemDelegate(QObject * parent) : QItemDelegate(parent) {}

        QSize sizeHint(const QStyleOptionViewItem& option, const QModelIndex & index) const
        {
                QSize newSize = QItemDelegate::sizeHint(option, index);
                newSize.setHeight(20); // ”станавливаем любую высоту строки, например 30
                return newSize;
        }
};
#endif // MAINWINDOW_H
