#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "databasehandler.h"
#include <QSqlTableModel>
#include <QDebug>

#include "nuevoevento.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this); //carga interfaz visual

    //verificar conexión a la base de datos
    if(!DatabaseHandler::instance()->openDatabase()){
        qDebug() << "Error: No se pudo conectar a la base de datos";
        return; //si falla, detiene aquí
    }

    setupTableView();
}

void MainWindow::setupTableView()
{
    // 📊 1. CONFIGURAR TABLA DE EVENTOS
    QSqlTableModel *modelEventos = new QSqlTableModel(this, DatabaseHandler::instance()->database());
    // 🎯 Crear modelo que conecta la tabla SQL con la vista visual
    // 💡 'this' significa que se destruirá automáticamente cuando MainWindow se cierre

    modelEventos->setTable("eventos");
    // 🎯 Especificar qué tabla de la base de datos usar

    modelEventos->select();
    // 🚀 Cargar los datos de la tabla "eventos" desde la base de datos

    ui->tableViewEventos->setModel(modelEventos);
    // 🎯 Vincular el modelo de datos con la tabla visual en la interfaz


    // 📊 2. CONFIGURAR TABLA DE FALLAS BCH (misma lógica)
    QSqlTableModel *modelFallasBCH = new QSqlTableModel(this, DatabaseHandler::instance()->database());
    modelFallasBCH->setTable("FALLA_BCH");  // 🎯 Tu segunda tabla
    modelFallasBCH->select();
    ui->tableViewFallasBCH->setModel(modelFallasBCH);


    // 📊 3. CONFIGURAR TABLA DE FALLAS PW
    QSqlTableModel *modelFallasPW = new QSqlTableModel(this, DatabaseHandler::instance()->database());
    modelFallasPW->setTable("FALLA_PW");  // 🎯 Tu tercera tabla
    modelFallasPW->select();
    ui->tableViewFallasPW->setModel(modelFallasPW);

    // // 📊 1. CONFIGURAR TABLA DE EVENTOS
     QSqlTableModel *modelBCHRep = new QSqlTableModel(this, DatabaseHandler::instance()->database());
     modelBCHRep->setTable("REPARACION_BCH");
     modelBCHRep->select();
     ui->tableViewBCHR->setModel(modelBCHRep);

     QSqlTableModel *modelPWRep = new QSqlTableModel(this, DatabaseHandler::instance()->database());
     modelPWRep->setTable("REPARACION_PW");
     modelPWRep->select();
     ui->tableViewPWR->setModel(modelPWRep);


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_NuevoEvento_clicked()
{
    NuevoEvento form(this);
    form.exec();
}

