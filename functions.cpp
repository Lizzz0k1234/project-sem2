#include "functions.h"

QByteArray parsing(QString data_from_client){
    /* data_from_client = NameOfFunc&Param1&Param2&Param3
    * Цель парсинга:
    * return NameOfFunc(Param1&Param2&Param3)
    */
    QStringList data_from_client_list = data_from_client.split(QLatin1Char('&'));

    QString nameOfFunc = data_from_client_list.front();
    data_from_client_list.pop_front();


    if (nameOfFunc == "auth"){
        return auth(data_from_client_list.at(0), data_from_client_list.at(1));}
    else if (nameOfFunc == "reg"){
        return reg(data_from_client_list.at(0), data_from_client_list.at(1), data_from_client_list.at(2));
    }else
        return "error\n";



}

QByteArray auth(QString log, QString pass)
{
return Db::Test1();
}

QByteArray reg(QString log, QString pass, QString mail)
{
return "reg done\n";
}

