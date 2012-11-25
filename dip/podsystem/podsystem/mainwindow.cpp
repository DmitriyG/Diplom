#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtGui>
#include <QtSql>
#include "tab.h"
#include "pole.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    model = new QSqlTableModel();
    model->setTable("logs");
    model->select();

    ui->tableView->setModel(model);
    ui->tableView->horizontalHeader()->setResizeMode( QHeaderView::Stretch );
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    connect(ui->action, SIGNAL(triggered()), this, SLOT(tab()));
    connect(ui->action_2,SIGNAL(triggered()), this, SLOT(pole()));
}


void MainWindow::tab()
{
   QSqlQueryModel *model = new QSqlQueryModel();
   model->setQuery("SELECT tablename FROM pg_tables WHERE tablename NOT LIKE 'pg\\_%' AND tablename NOT LIKE 'sql\\_%'");

   L_TAB *dialog = new L_TAB;
   dialog->tableView->setModel(model);
   dialog->tableView->horizontalHeader()->setResizeMode( QHeaderView::Stretch );
   dialog->show();
}

void MainWindow::pole()
{
   QSqlQueryModel *model = new QSqlQueryModel();
   model->setQuery("SELECT attname FROM pg_attribute, pg_type WHERE typname = 'jilci' AND attrelid = typrelid AND attname NOT IN ('cmin', 'cmax', 'ctid', 'oid', 'tableoid', 'xmin', 'xmax')");
   Pole *dialog = new Pole;
   dialog->listView->setModel(model);
   dialog->show();
}

MainWindow::~MainWindow()
{
    delete ui;
}


