#include <QtGui>
#include "enter.h"
#include "mainwindow.h"
Enter::Enter(/*MainWindow *main,*/ QWidget *parent)
    : QDialog(parent)//,_main(main)
{
    setupUi(this);   
    connect(okButton, SIGNAL(clicked()), this, SLOT(enter_bd()));
}

void Enter::enter_bd()
{
    st_e1 = lineEdit->text();
    st_e2 = lineEdit_2->text();
    Enter::close();
}

Enter::~Enter()
{

}

