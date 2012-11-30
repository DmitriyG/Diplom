#include <QtGui>
#include "tab.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"

L_TAB::L_TAB(QWidget *parent)
    : QDialog(parent)
{
    setupUi(this);
}

void L_TAB::on_pushButton_clicked()
{
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM settings");
    tableView->setFocus();
    QModelIndex index = tableView->currentIndex();
    QSqlRecord record;
    record = model->record(index.row());
    model->setQuery ("DELETE FROM settings WHERE table_name = '"
                       +record.value("table_name").toString()
                       +"'");
    model->setQuery("SELECT * FROM settings");
    tableView->setModel(model);
}
