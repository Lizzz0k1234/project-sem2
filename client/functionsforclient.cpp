#include "functionsforclient.h"
#include "formauth.h"
#include <QWidget>
#include <QMessageBox>
#include <QtTextToSpeech/QTextToSpeech>
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
QString del_status(QString log)
{
    QString res ="del&"+log;
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
    QString a="";
    a=solve_task(task_number, input_for_task);
    bool res = answer==a;
    if (res)
    {
        QMessageBox temp;
        temp.setStyleSheet("color: #dc143c; background-color: #87cefa; selection-color: ;"
                           "selection-background-color: black;");
        temp.setText("Правильно!!!");
        QString i="Поздравляю";
        QTextToSpeech *speech;
        speech=new QTextToSpeech;
        speech->say(i);
        temp.exec();
        tmp="+";
    }
    else {
        QMessageBox temp;
        temp.setStyleSheet("color: #dc143c; background-color: #87cefa; selection-color: ;"
                           "selection-background-color: black;");
        temp.setText("Неправильно!!!       Правильный ответ: "+a+"       Ваш ответ: "+answer);
        QString i="Не расстраивайтесь, всё получится";
        QTextToSpeech *speech;
        speech=new QTextToSpeech;
        speech->say(i);
        temp.exec();
        tmp="-";
    }
    update_stat(task_number,tmp);
    return res;
}



QString solve_task(int task_number, QString input_for_task)
{
    QString w="";
    if (task_number==1)
    {
        w=solve_task1(task_number, input_for_task);
    }
    else if (task_number==2)
    {
        w="ans"+QString::number(task_number);
    }
    else w=solve_task3(task_number, input_for_task);
    return w;
}
QString generate_input_for_task(int n)
{

    QStringList tasks={"1,2;1,4;1,5;1,6;2,3;2,5;3,4;3,6;4,5;5,6",
                       "1,2;1,3;1,5;1,6;2,3;2,4;2,6;3,4;3,5;4,5;4,6;5,6",
                       "1,4;1,5;1,6;1,7;2,4;2,7;3,4;3,5;3,6;3,7;4,7",
                       "1,6;1,8;2,6;2,7;3,4;3,5;3,6;3,8;4,5;4,6;4,8;7,8",
                       "1,2;1,3;1,4;1,6;2,3;3,4;3,6;4,5;4,6;5,6",
                       "1,2;1,3;1,5;1,6;2,4;3,4;3,5;3,6;4,5;4,6;5,6",
                       "1,2;1,4;1,5;1,6;2,3;2,4;2,8;3,8;5,6;6,7;6,8;7,8",
                       "1,8;1,9;2,5;2,9;3,5;3,6;3,7;3,9;4,5;4,9;5,6;7,9;8,9",
                       "1,4;1,5;1,6;1,7;2,4;2,7;3,4;3,7;4,5;6,7",
                       "1,2;1,3;1,5;1,6;2,3;2,4;2,6;3,4;3,5;4,5;4,6;5,6",
                       "1,2;1,3;1,4;1,5;2,4;2,6;2,7;3,4;4,5;5,6;5,7",
                       "1,4;1,9;2,5;2,9;3,5;3,7;4,6;4,7;4,9;6,7;7,8;8,9",
                       "1,2;1,3;1,6;1,7;2,3;2,5;2,6;3,4;3,7;4,7;5,6;6,7",
                       "1,2;1,3;1,5;1,6;2,5;2,6;3,7;4,6;4,7;6,7",
                       "1,2;1,3;1,5;1,7;2,6;3,4;3,6;3,7;4,5;4,6;4,7;6,7",
                       "1,2;1,8;2,3;2,5;2,8;3,4;3,6;3,7;4,6;5,6;5,7;5,8;6,8",
                       "1,2;1,3;1,5;1,8;2,3;2,4;2,6;2,7;2,8;3,4;3,7;4,5;4,6",
                       "1,2;1,3;1,4;1,5;2,3;2,4;2,5;3,4;3,5;4,5",
                       "1,4;1,5;1,6;1,7;2,4;2,5;2,6;2,7;3,4;3,5;3,6;3,7;4,8;5,8;6,8;7,8",
                       "1,2;1,4;1,6;1,8;2,3;2,5;2,7;3,4;3,6;3,8;4,5;4,7;5,6;5,8;6,7;7,8",
                       "1,5;1,6;1,7;1,9;2,4;2,5;2,6;2,7;3,4;3,5;3,6;3,9;4,8;5,8;4,9;6,8;7,8;7,9",
                       "1,2;1,4;1,7;1,8;2,3;2,4;2,6;3,5;3,7;3,8;4,5;4,8;5,6;7,8",
                       "1,2;1,4;1,5;1,6;2,3;2,4;2,7;3,4;3,5;3,7;4,5;4,6;4,7;5,6;6,7",
                       "1,2;1,3;1,6;1,7;2,3;2,7;2,8;3,4;3,8;4,5;4,7;4,8;5,6;5,7;5,8",
                       "1,7;1,8;2,4;2,6;2,8;2,9;3,6;3,8;4,8;5,6;5,7;6,8;6,9;7,8",
                       "1,2;1,3;1,5;1,9;2,3;2,6;2,8;3,4;3,9;4,5;4,7;4,8;5,6;5,7;6,8;6,9;8,9",
                       "1,2;1,6;2,3;2,4;2,7;3,6;4,5;4,9;4,11;5,7;6,8;6,10;7,9;7,11;8,9;9,10",
                       "1,3;1,5;1,8;1,10;2,4;2,7;3,4;3,6;3,7;4,7;4,9;5,10;6,9;7,10;8,10",
                       "1,2;1,3;1,4;1,5;2,3;2,4;2,5;3,4;3,5;4,5;4,6;4,7;5,6;5,7",
                       "1,2;1,3;1,5;1,6;2,3;2,4;2,6;3,4;3,5;3,7;3,8;6,7;6,8"
                      };

    QString t="";
    if (n==1)
    {

        //QRegExp rx(";");
        //int v=0;
        int v = QRandomGenerator::global()->bounded(0, tasks.size());
        t=tasks[v];
        //t="1,2;1,4;1,5;1,6;2,3;2,5;3,4;3,6;4,5;5,6";
        //QStringList myStringList = t.split(rx);
    }
    else if (n==2)
    {

    }
    else
    {
        t="3,4,7;4,5,7;2,3,9;2,5,9";
    }

    return t;
}
QString generate_text_task(int task_number, QString input_for_task)
{
    QString w;
    if (task_number==1) w="Найти число каркасов в заданном графе:   ";
    else if(task_number==2) w="bebe  ";
    else w="bebe   ";
    return "Task "+QString::number(task_number)+"   "+w+input_for_task;
}
