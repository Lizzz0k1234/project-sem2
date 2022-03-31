#include <QCoreApplication>
#include "mytcpserver.h"
#include "db.h"

Db * Db::p_instance;
DbDestroyer Db::destroyer;
QSqlDatabase Db::db;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    MyTcpServer myserv;
    return a.exec();
}
