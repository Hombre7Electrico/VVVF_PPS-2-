#ifndef DATABASEHANDLER_H
#define DATABASEHANDLER_H

#include <QObject>
#include <QSqlDatabase>
#include <QSqlError>

class DatabaseHandler : public QObject
{
    Q_OBJECT
public:
    static DatabaseHandler* instance();
    bool openDatabase();
    QSqlDatabase database() const;

private:
    DatabaseHandler(QObject *parent = nullptr);
    ~DatabaseHandler();

    QSqlDatabase m_db;
    static DatabaseHandler* m_instance;
};


#endif // DATABASEHANDLER_H
