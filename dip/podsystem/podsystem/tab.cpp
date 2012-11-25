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
    model->setQuery("SELECT tablename FROM pg_tables WHERE tablename NOT LIKE 'pg\\_%' AND tablename NOT LIKE 'sql\\_%'");
    tableView->setFocus();
    tableView->setSelectionMode(QAbstractItemView::ExtendedSelection);
    QModelIndex index = tableView->currentIndex();
    QSqlRecord record;
    record = model->record(index.row());
    model->setQuery ("INSERT INTO settings (table_name) VALUES ('"
                       + record.value("tablename").toString()
                       +"')");






    /*
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("SELECT tablename FROM pg_tables WHERE tablename NOT LIKE 'pg\\_%' AND tablename NOT LIKE 'sql\\_%'");
    tableView->setFocus();
    QModelIndex index = tableView->currentIndex();
    QSqlRecord record;
    record = model->record(index.row());
    model->setQuery ("INSERT INTO settings (table_name) VALUES ('"
                       + record.value("tablename").toString()
                       +"')");
                       */
}
