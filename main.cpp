// main.cpp

#include "const.h"
#include "logindialog.h"
#include "mainwindow.h"
#include <QApplication>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

int main(int argc, char *argv[])
{
    // Connect to the database
    QSqlDatabase db = QSqlDatabase::addDatabase(DB_TYPE);
    db.setDatabaseName(DB_PATH);

    if (!db.open())
    {
        qDebug() << "Failed to open database:" << db.lastError();
        return -1;
    }

    // Create tables if they don't exist
    QSqlQuery query;
    if (!query.exec("CREATE TABLE IF NOT EXISTS items (id INTEGER PRIMARY KEY, name TEXT, category TEXT, quantity INTEGER)"))
    {
        qDebug() << "Failed to create items table:" << query.lastError();
        return -1;
    }

    if (!query.exec("CREATE TABLE IF NOT EXISTS users (id INTEGER PRIMARY KEY, username TEXT, password TEXT)"))
    {
        qDebug() << "Failed to create users table:" << query.lastError();
        return -1;
    }

    QApplication app(argc, argv);
    LoginDialog ld;

    if (ld.exec() == QDialog::Accepted)
    {
        MainWindow mw;
        mw.show();
        return app.exec();
    }
    else
    {
        db.close();
        return 0;
    }
}
