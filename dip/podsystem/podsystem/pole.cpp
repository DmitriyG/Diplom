#include <QtGui>
#include "pole.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"

Pole::Pole(QWidget *parent)
    : QDialog(parent)
{
    setupUi(this);
}

void Pole::on_pushButton_clicked()
{
    QStringList list;
    QModelIndexList mlist = listView->selectionModel()->selectedIndexes();
    QString list_pole;
    QSqlQueryModel *model = new QSqlQueryModel();

    for(int i = 0;i < mlist.count();i++){
    //Получаем отображаемое имя
    list.append(mlist.at(i).data(Qt::DisplayRole).toString());
    }

    for(int i = 0; i < list.count();i++){
    //Записываем отображаемое имя
    list_pole += list.at(i) + ";";
    }

    model->setQuery ("INSERT INTO settings (table_name, pole_name) VALUES ('"
                     + comboBox->currentText()
                     +"','"
                     +list_pole
                     +"')");
}

void Pole::on_comboBox_currentIndexChanged(QString )
{
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("SELECT attname FROM pg_attribute, pg_type WHERE typname = '"
                    +comboBox->currentText()
                    +"' AND attrelid = typrelid AND attname NOT IN ('cmin', 'cmax', 'ctid', 'oid', 'tableoid', 'xmin', 'xmax')");
    listView->setModel(model);
}
