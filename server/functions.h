#ifndef FUNCTIONSFORSERVER_H
#define FUNCTIONSFORSERVER_H

#include "db.h"

#include <QString>
#include <QStringList>

QByteArray parsing(QString data_from_client);

QByteArray auth(QString login, QString pass);
QByteArray reg(QString login, QString pass, QString mail);
QByteArray check_ans(QString ans);
#endif // FUNCTIONSFORSERVER_H
