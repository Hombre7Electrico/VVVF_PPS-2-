#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "nuevoevento.h"
#include <QSqlTableModel>

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

public slots:
        void actualizarTablaEventos();       // Slot para actualizar la tabla

private slots:
    void on_pushButton_NuevoEvento_clicked();




    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;

    // ✅ Agregar punteros a los modelos como miembros de la clase
    QSqlTableModel *modelEventos;
    QSqlTableModel *modelFallasBCH;
    QSqlTableModel *modelFallasPW;
    QSqlTableModel *modelBCHRep;
    QSqlTableModel *modelPWRep;
    //Función para configurar las tablas
    void setupTableView();
    NuevoEvento *formNuevoEvento= nullptr;
};
#endif // MAINWINDOW_H
