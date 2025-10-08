#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "nuevoevento.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_NuevoEvento_clicked();

private:
    Ui::MainWindow *ui;

    //Función para configurar las tablas
    void setupTableView();
    NuevoEvento *formNuevoEvento= nullptr;
};
#endif // MAINWINDOW_H
