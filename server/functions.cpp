#include "functions.h"

QByteArray parsing(QString data_from_client, int sock_desc){
    //QString login;
    qDebug() << data_from_client;
    /* data_from_client = NameOfFunc&Param1&Param2&Param3
    * Цель парсинга:
    * return NameOfFunc(Param1&Param2&Param3)
    */
    QStringList data_from_client_list = data_from_client.split(QLatin1Char('&'));
    //qDebug()<<data_from_client_list.front();

    QString nameOfFunc = data_from_client_list.front();
    data_from_client_list.pop_front();

    if (nameOfFunc == "auth"){
            change_sock_desc(data_from_client_list.at(0), sock_desc);
            return auth(data_from_client_list.at(0), data_from_client_list.at(1));
    }
    else if (nameOfFunc == "reg"){
        //QString log =data_from_client_list.at(0);
        return reg(data_from_client_list.at(0), data_from_client_list.at(1), data_from_client_list.at(2), sock_desc);
        //change_sock_desc(data_from_client_list.at(0), sock_desc);
    }else if (nameOfFunc == "updstat") {
        //qDebug()<<login;
        return check_ans(data_from_client_list.at(1), sock_desc);}
    else if (nameOfFunc == "stat")
    {
        //qDebug()<<"stat" + data_from_client_list.at(0);
        return look_stat(sock_desc);
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

QByteArray reg(QString log, QString pass, QString mail, int sock_desc)
{
    QByteArray result = "";
    result.append(Db::reg(log, pass, mail, sock_desc));
    //qDebug() << result;
    //change_sock_desc(log);
    return result;
//return "reg done";
}
QByteArray check_ans(QString ans, int sock_desc)
{
    QByteArray res;
    //qDebug()<< "be";
    res.append(Db::check_ans(ans, sock_desc));
    //qDebug()<<res;
    return res;

}
QByteArray look_stat(int sock_desc)
{
    QByteArray result;
    result.append(Db::count_stat(sock_desc));
    //qDebug()<<result;
    return result;
}

QByteArray change_sock_desc(QString login, int sock_desc)
{
    //qDebug()<<login+"tttt";
    QByteArray result;
    result.append(Db::change_status(login, sock_desc));
    //qDebug()<<result;
    return result;
}
