#include "functions.h"

QByteArray parsing(QString data_from_client){
    qDebug() << data_from_client;
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
    }else if (nameOfFunc == "updstat") {
        return check_ans(data_from_client_list.at(1));}
    else return "error";



}

QByteArray auth(QString log, QString pass)
{

    QByteArray result = "";
    result.append(Db::auth(log, pass));
    //qDebug() << result;
    return result;
}

QByteArray reg(QString log, QString pass, QString mail)
{
return "reg done";
}
QByteArray check_ans(QString ans)
{
    QByteArray res;
    //qDebug()<< "be";
    res.append(Db::check_ans(ans));
    //qDebug()<<res;
    return res;

}

