#include <QApplication>
#include <QDialog>
#include "enter.h"
int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    
    Enter *dialog = new Enter;
   
    dialog->show();
    return app.exec();
}
