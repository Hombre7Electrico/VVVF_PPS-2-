#include "databasehandler.h"
#include <QDebug>
#include <QFileInfo>
#include <QDir>

DatabaseHandler* DatabaseHandler::m_instance = nullptr;

DatabaseHandler::DatabaseHandler(QObject *parent) : QObject(parent)
{
    m_db = QSqlDatabase::addDatabase("QSQLITE");
    m_db.setDatabaseName(":/new/VVVF-BD/resources/BD/historialFallas.db");
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
    QFileInfo dbFile(m_db.databaseName());

    if (!dbFile.exists()) {
        qDebug() << "❌ Archivo no encontrado:" << dbFile.absoluteFilePath();
        qDebug() << "📁 Directorio actual:" << QDir::currentPath();
        return false;
    }

    qDebug() << "✅ Archivo encontrado:" << dbFile.absoluteFilePath();

    if (!m_db.open()) {
        qDebug() << "❌ Error al abrir:" << m_db.lastError().text();
        return false;
    }

    qDebug() << "✅ BD abierta correctamente!";
    return true;
}

QSqlDatabase DatabaseHandler::database() const
{
    return m_db;
}
