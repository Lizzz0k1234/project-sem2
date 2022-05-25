#include "functionsforclient.h"
#include "formauth.h"
#include <QMessageBox>
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
        temp.setText("Правильно!!!");
        temp.exec();
        tmp="+";
    }
    else {
        QMessageBox temp;
        temp.setText("Неправильно!!!       Правильный ответ: "+a+"       Ваш ответ: "+answer);
        temp.exec();
        tmp="-";
    }
    update_stat(task_number,tmp);
    return res;
}
QString solve_task1(int task_number, QString input_for_task)
{
    QString w="";
    QString t=input_for_task;
    int n=0,m=0;

    for (int k=0;k<t.length();k++)
    {
        if (t.at(k).digitValue()>n) n=t.at(k).digitValue();
    }
    m=n;
    double b[10][10];

    QRegExp rx(";");
    QStringList myStringList = t.split(rx);
    QString h="";

    for (int i=1;i<n+1;i++)
        for (int j=1;j<m+1;j++)
        {
            int flag=0;
            int index=0;
            for (int y=0;y<myStringList.length();y++)
            {
                if(flag!=1)
                {
                    QString g=QString::number(i)+","+QString::number(j);
                    QString p=QString::number(j)+","+QString::number(i);
                    if (g==myStringList.at(index))
                    {
                        b[i][j]=1;
                        flag=1;
                        myStringList.append(p);

                    }
                    else b[i][j]=0;
                    if (p==myStringList.at(index))
                    {
                        b[i][j]=1;
                        flag=1;

                    }

                    index++;
                }
            }
        }

    for (int i=1;i<n+1;i++)
    {
        int x=0;
        for (int j=1;j<m+1;j++)
        {

          x+=b[i][j];
        }
        //e=x;
        //qDebug()<<e;
        for (int g=1;g<n+1;g++)
        {
            if (i==g) b[i][g]=x;
            else b[i][g]=-b[i][g];
        }

    }

    int q=0;
    int l;
    //qDebug()<<QString::number(b[1][1])+"bebe";
    for (int i=1;i<n;i++)
         for (int j=1;j<m;j++)
        {
             if (i==j) l+=b[i][j];
                 b[i][j]=b[i+1][j+1];
                 q+=b[i][j];

         //w=QString::number(q);

        }
    qDebug()<<QString::number(b[1][1])+QString::number(b[2][2])+QString::number(b[3][3])+QString::number(b[4][4])+QString::number(b[5][5]);


    double z=1;
    for (int i=1;i<n;i++)
    {
       // k=i;
        for (int k=i+1;k<n+1;k++)
        {
            double x=0;

            double v=b[k][i];
            double w=b[i][i];
            x=-v/w;
            //qDebug()<<v;
            //qDebug()<<x;
            for (int j=1;j<n+1;j++)
            {
                b[k][j]+=x*b[i][j];
            }
        }

    }
    qDebug()<<QString::number(b[1][1])+QString::number(b[2][2])+QString::number(b[3][3])+QString::number(b[4][4])+QString::number(b[5][5]);
    /*for (int i=1;i<n;i++)
            for (int j=1;j<n;j++)
            {
                qDebug()<<b[i][j];
            }*/
    //qDebug()<<QString::number(b[6][6]);
    for (int i=1;i<n;i++)
        for (int j=1;j<n;j++)
            if (i==j) z=z*b[i][j];

    //qDebug()<<z;

    w=QString::number(z);
    //qDebug()<<w;
    //qDebug()<<b[3][3];

    return w;
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
    else w=w="ans"+QString::number(task_number);
    return w;
}
QString generate_input_for_task(int n)
{
    QString t="";
    QString a="";
    if (n==1)
    {
        QRegExp rx(";");
        t="1,2;1,4;1,5;1,6;2,3;2,5;3,4;3,6;4,5;5,6";
        QStringList myStringList = t.split(rx);
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
