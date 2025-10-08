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
    QString dbPath= appDir+ "/historico_VVVF.db";

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
        qDebug() << "=== DEBUG COMPLETO DE CONEXIÓN ===";
        qDebug() << "1. Ruta BD configurada:" << m_db.databaseName();
        qDebug() << "2. Ruta absoluta BD:" << dbFile.absoluteFilePath();
        qDebug() << "3. ¿Existe archivo?" << dbFile.exists();
        qDebug() << "4. ¿Es legible?" << dbFile.isReadable();
        qDebug() << "5. ¿Es escribible?" << dbFile.isWritable();
        qDebug() << "6. Tamaño archivo:" << dbFile.size() << "bytes";

        qDebug() << "7. Directorio actual:" << QDir::currentPath();
        qDebug() << "8. Directorio ejecutable:" << QApplication::applicationDirPath();

        // Verificar estructura de carpetas completa
        QDir dir(QApplication::applicationDirPath());
        qDebug() << "9. Contenido directorio ejecutable:";
        foreach (QString entry, dir.entryList(QDir::AllEntries | QDir::NoDotAndDotDot)) {
            qDebug() << "   - " << entry;

        return false;
    }
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
