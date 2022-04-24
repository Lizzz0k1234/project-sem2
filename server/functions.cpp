#include "functions.h"

QByteArray parsing(QString data_from_client){
    //QString login;
    qDebug() << data_from_client;
    /* data_from_client = NameOfFunc&Param1&Param2&Param3
    * Цель парсинга:
    * return NameOfFunc(Param1&Param2&Param3)
    */
    QStringList data_from_client_list = data_from_client.split(QLatin1Char('&'));

    QString nameOfFunc = data_from_client_list.front();
    data_from_client_list.pop_front();
    if (nameOfFunc == "auth") login=data_from_client_list.at(0);
    if (nameOfFunc == "reg") login=data_from_client_list.at(0);



    if (nameOfFunc == "auth"){
        //qDebug()<<data_from_client_list.at(0);
        //QString login =data_from_client_list.at(0);
        return auth(data_from_client_list.at(0), data_from_client_list.at(1));}
    else if (nameOfFunc == "reg"){
        //QString log =data_from_client_list.at(0);
        return reg(data_from_client_list.at(0), data_from_client_list.at(1), data_from_client_list.at(2));
    }else if (nameOfFunc == "updstat") {
        //qDebug()<<login;
        return check_ans(data_from_client_list.at(1), login);}
    else if (nameOfFunc == "stat")
    {
        //qDebug()<<"stat" + data_from_client_list.at(0);
        return look_stat(data_from_client_list.at(0));
    }
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
    QByteArray result = "";
    result.append(Db::reg(log, pass, mail));
    //qDebug() << result;
    return result;
//return "reg done";
}
QByteArray check_ans(QString ans, QString login)
{
    QByteArray res;
    //qDebug()<< "be";
    res.append(Db::check_ans(ans, login));
    //qDebug()<<res;
    return res;

}
QByteArray look_stat(QString login)
{
    QByteArray result;
    result.append(Db::count_stat(login).toUtf8());
    //qDebug()<<result;
    return result;
}

