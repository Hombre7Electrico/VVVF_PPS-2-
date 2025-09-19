#include "databasehandler.h"
#include <QDebug>
#include <QFileInfo>
#include <QDir>
#include<QApplication>

DatabaseHandler* DatabaseHandler::m_instance = nullptr;

DatabaseHandler::DatabaseHandler(QObject *parent) : QObject(parent)
{
    m_db = QSqlDatabase::addDatabase("QSQLITE");
    //m_db.setDatabaseName(":/new/VVVF-BD/resources/BD/historialFallas.db");
    QString appDir = QApplication :: applicationDirPath();
    QString dbPath= appDir+ "/resources/BD/historialFallas.db";

    m_db.setDatabaseName(dbPath);
    qDebug()<< "Ruta de BD configurada: "<<dbPath;
}

DatabaseHandler::~DatabaseHandler()
{
    if (m_db.isOpen()) {
        m_db.close();
    }
}

DatabaseHandler* DatabaseHandler::instance()
{
    if (!m_instance) {
        m_instance = new DatabaseHandler();
    }
    return m_instance;
}

bool DatabaseHandler::openDatabase()
{
    //verificar que el archivo BD existe
    QFileInfo dbFile(m_db.databaseName());

    //si el archivo no existe -> error
    if (!dbFile.exists()) {
        qDebug() << "❌ Archivo no encontrado:" << dbFile.absoluteFilePath();
        qDebug()<<"Existe el archivo?"<< dbFile.exists();
        qDebug() << "📁 Directorio actual: " << QDir::currentPath();
        qDebug()<<"Directorio del ejecutable: "<< QApplication::applicationDirPath();

        return false;
    }

    //si el archivo existe -> continuar
    qDebug() << "✅ Archivo encontrado:" << dbFile.absoluteFilePath();

    //intentar abrir la conexion a la BD
    if (!m_db.open()) {
        qDebug() << "❌ Error al abrir:" << m_db.lastError().text();
        return false;
    }

    //salio bien
    qDebug() << "✅ BD abierta correctamente!";
    return true;
}

QSqlDatabase DatabaseHandler::database() const
{
    return m_db;
}
