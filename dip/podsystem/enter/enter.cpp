#include <QtGui>
#include "enter.h"
Enter::Enter(QWidget *parent)
    : QDialog(parent)
{
    setupUi(this);

   
    connect(okButton, SIGNAL(clicked()), this, SLOT(accept()));
    
}

