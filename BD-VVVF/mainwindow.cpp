#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "databasehandler.h"
#include <QSqlTableModel>
#include <QDebug>
#include <QFileInfo>

#include "nuevoevento.h"
#include "asociarfalla.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow),
    modelEventos(nullptr),
    modelFallasBCH(nullptr),
    modelFallasPW(nullptr),
    modelBCHRep(nullptr),
    modelPWRep(nullptr)
{
    ui->setupUi(this); //carga interfaz visual

     actualizarTablaEventos();  // Cargar datos iniciales

    // Verificar la base de datos ANTES de abrirla
    QString appDir = QApplication :: applicationDirPath();
    QString dbPath = appDir+ "/historico_VVVF.db"; // o la ruta que uses
    QFileInfo dbFile(dbPath);
    qDebug() << "Verificando base de datos:";
    qDebug() << "Ruta:" << dbFile.absoluteFilePath();
    qDebug() << "Existe:" << dbFile.exists();
    qDebug() << "Se puede escribir:" << dbFile.isWritable();
    //verificar conexión a la base de datos
    if(!DatabaseHandler::instance()->openDatabase()){
        qDebug() << "Error: No se pudo conectar a la base de datos";
        return; //si falla, detiene aquí
    }

    setupTableView();
    actualizarTablaEventos();  // Cargar datos iniciales
}

void MainWindow::setupTableView()
{

    // 📊 1. CONFIGURAR TABLA DE EVENTOS - Usar el miembro de la clase
    modelEventos = new QSqlTableModel(this, DatabaseHandler::instance()->database());
    modelEventos->setTable("eventos");    // 🎯 Especificar qué tabla de la base de datos usar
    modelEventos->select();                         // 🚀 Cargar los datos de la tabla "eventos" desde la base de datos
    ui->tableViewEventos->setModel(modelEventos);       // 🎯 Vincular el modelo de datos con la tabla visual en la interfaz

    // 📊 2. CONFIGURAR TABLA DE FALLAS BCH
    modelFallasBCH = new QSqlTableModel(this, DatabaseHandler::instance()->database());
    modelFallasBCH->setTable("FALLA_BCH");
    modelFallasBCH->select();
    ui->tableViewFallasBCH->setModel(modelFallasBCH);

    // 📊 3. CONFIGURAR TABLA DE FALLAS PW
    modelFallasPW = new QSqlTableModel(this, DatabaseHandler::instance()->database());
    modelFallasPW->setTable("FALLA_PW");
    modelFallasPW->select();
    ui->tableViewFallasPW->setModel(modelFallasPW);

    // 📊 4. CONFIGURAR TABLA DE REPARACIONES BCH
    modelBCHRep = new QSqlTableModel(this, DatabaseHandler::instance()->database());
    modelBCHRep->setTable("REPARACION_BCH");
    modelBCHRep->select();
    ui->tableViewBCHR->setModel(modelBCHRep);

    // 📊 5. CONFIGURAR TABLA DE REPARACIONES PW
    modelPWRep = new QSqlTableModel(this, DatabaseHandler::instance()->database());
    modelPWRep->setTable("REPARACION_PW");
    modelPWRep->select();
    ui->tableViewPWR->setModel(modelPWRep);

    qDebug() << "✅ Tablas configuradas correctamente";
    qDebug() << "📍 modelEventos pointer:" << modelEventos; // Debería mostrar una dirección, no 0x0

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_NuevoEvento_clicked()
{

    qDebug() << "Abriendo diálogo NuevoEvento";
    qDebug() << "Conexión de base de datos:" << QSqlDatabase::database().connectionName();
    qDebug() << "Archivo de base de datos:" << QSqlDatabase::database().databaseName();

    //  SOLO UN diálogo
    NuevoEvento *dialogo = new NuevoEvento(this);

    //  CONECTAR la señal ANTES de abrir el diálogo
    connect(dialogo, &NuevoEvento::eventoAgregado, this, &MainWindow::actualizarTablaEventos);
    qDebug() << "✅ Señal eventoAgregado conectada a actualizarTablaEventos";

    dialogo->exec();  // Abrir modalmente
    dialogo->deleteLater();  // Liberar memoria

    qDebug() << "🔊 Diálogo cerrado";

}

void MainWindow::actualizarTablaEventos()
{
    qDebug() << "🎯 actualizarTablaEventos() EJECUTADO";
    qDebug() << "📍 modelEventos pointer:" << modelEventos;

    if (modelEventos) {
        qDebug() << "🔄 Ejecutando modelEventos->select()...";
        bool success = modelEventos->select();
        qDebug() << "📊 Tabla eventos actualizada:" << success
                 << "Registros:" << modelEventos->rowCount();

        // Forzar actualización visual
        ui->tableViewEventos->viewport()->update();
        ui->tableViewEventos->reset();

        qDebug() << "✅ Vista de tabla actualizada";
    } else {
        qDebug() << "❌ modelEventos es nullptr - Los modelos no se crearon correctamente";
    }

    // Actualizar las otras tablas si existen
    if (modelFallasBCH) {
        modelFallasBCH->select();
        qDebug() << "📊 Tabla FALLA_BCH actualizada";
    }
    if (modelFallasPW) {
        modelFallasPW->select();
        qDebug() << "📊 Tabla FALLA_PW actualizada";
    }
    if (modelBCHRep) {
        modelBCHRep->select();
        qDebug() << "📊 Tabla REPARACION_BCH actualizada";
    }
    if (modelPWRep) {
        modelPWRep->select();
        qDebug() << "📊 Tabla REPARACION_PW actualizada";
    }

    qDebug() << "✅ Proceso de actualización completado";
}

void MainWindow::on_pushButton_clicked()
{
    //  SOLO UN diálogo
    asociarFalla *dialogo2 = new asociarFalla(this);

    connect(dialogo2, &asociarFalla::fallaRegistrada, this, &MainWindow::actualizarTablaEventos);

    dialogo2->exec();  // Abrir modalmente
    dialogo2->deleteLater();  // Liberar memoria

}

