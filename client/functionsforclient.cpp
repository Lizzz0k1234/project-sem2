#include "functionsforclient.h"
#include "formauth.h"

QString auth(QString log, QString pass)
{
    QString res ="auth&"+log+"&"+pass;
    //qDebug()<<Client::send_to_server(res);
    return Client::send_to_server(res);
}
QString reg(QString log, QString pass, QString email)
{
    QString res ="reg&"+log+"&"+pass+"&"+email;
    //qDebug()<<res;
    return Client::send_to_server(res);
}
QString look_stat(QString log)
{
    QString res ="stat&"+log;
    //qDebug()<<res;
    return Client::send_to_server(res);
}

QString look_stat1(QString log)
{
    QString res ="stat1&"+log;
    //qDebug()<<res;
    return Client::send_to_server(res);
}
QString look_stat2(QString log)
{
    QString res ="stat2&"+log;
    //qDebug()<<res;
    return Client::send_to_server(res);
}
QString look_stat3(QString log)
{
    QString res ="stat3&"+log;
    //qDebug()<<res;
    return Client::send_to_server(res);
}
void update_stat(int n, QString upd)
{
    //QString log = Ui::FormAuth *ui -> lineEdit_log -> text();
    QString res ="updstat&"+QString::number(n)+"&"+upd;
    qDebug()<<res;
    Client::send_to_server(res);
}
bool chek_answer(QString answer, QString input_for_task, int task_number)
{
    QString tmp="";
    bool res = answer==solve_task(task_number, input_for_task);
    if (res)
    {
        tmp="+";
    }
    else tmp="-";
    update_stat(task_number,tmp);
    return res;
}

QString solve_task(int task_number, QString input_for_task)
{
    return "ans"+QString::number(task_number);
}
QString generate_input_for_task()
{
    QString t="";
    int a;
    for (int i=1;i<5;i++)
    {
        a=rand();
        t+=QString(a);
    }
    return t;
}
QString generate_text_task(int task_number, QString input_for_task)
{
    return "Task "+QString::number(task_number)+"   "+input_for_task;
}
