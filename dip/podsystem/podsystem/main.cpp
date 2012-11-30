#include <QtDebug>
#include <QtGui>
#include <QtSql>
#include <QSqlDatabase>
#include <QSqlQueryModel>
#include <QSqlError>
#include <QTableView>
#include <QSqlDriver>
#include "enter.h"
#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QString  st1;
    QString  st2;

    Enter dialog;
    dialog.show();
    while (dialog.exec()){}
    st1=dialog.st_e1;
    st2=dialog.st_e2;

    QSqlDatabase db;
    db = QSqlDatabase::addDatabase("QPSQL");
    db.setHostName("localhost");
    db.setDatabaseName("postgres");
    //db.setUserName(st1);
    db.setPort(5432);
    //db.setPassword(st2);

    db.setUserName("postgres");
    db.setPassword("1");
    MainWindow main;
    if (!db.open()) {
             qDebug() << QObject::trUtf8("Ne smogla ya otkrit bazu!") << db.lastError().text();
          qDebug() << QApplication::libraryPaths();
          return -1;
      } else {
        main.show();
        }
    return app.exec();
}
