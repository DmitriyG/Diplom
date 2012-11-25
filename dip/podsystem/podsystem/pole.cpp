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

    for(int i = 0;i < mlist.count();i++){
    //Получаем отображаемое имя
    list.append(mlist.at(i).data(Qt::DisplayRole).toString());
    }

    for(int i = 0; i < list.count();i++){
    //Записываем отображаемое имя
    list_pole += list.at(i) + ";";
    }
    qDebug() << list_pole;
}
