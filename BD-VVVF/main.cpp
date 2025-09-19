#include "mainwindow.h"

#include <QApplication>

#include "databasehandler.h"
#include<QMessageBox>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    if(DatabaseHandler::instance()->openDatabase()){
        QMessageBox::information(nullptr,"Éxito","BD conectada correctamente");
    } else{
        QMessageBox::critical(nullptr,"Error","Falló la conexión a BD");
    }

    return a.exec();
}
