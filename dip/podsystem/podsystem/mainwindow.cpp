#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtGui>
#include <QtSql>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    model = new QSqlTableModel();
    model->setTable("logs");
    model->select();
    view = new QTableView;
    view->setModel(model);
    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addWidget(view);
    ui->centralWidget->setLayout(mainLayout);
//     setLayout(mainLayout);

}

MainWindow::~MainWindow()
{
    delete ui;
}


