#ifndef FUNCTIONSFORSERVER_H
#define FUNCTIONSFORSERVER_H
#include <QString>

QByteArray parsing(QString data_from_client);

QByteArray auth(QString login, QString pass);
QByteArray reg(QString login, QString pass, QString mail);

#endif // FUNCTIONSFORSERVER_H
