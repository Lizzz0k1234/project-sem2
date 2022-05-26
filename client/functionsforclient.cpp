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
        if (t.at(k).digitValue()>n) n=t.at(k).digitValue();    //нахождение количества вершин
    }
    m=n;
    double b[12][12];

    QRegExp rx(";");
    QStringList myStringList = t.split(rx);

    for (int i=1;i<n+1;i++)
        for (int j=1;j<m+1;j++)
        {
            int flag=0;
            int index=0;
            for (int y=0;y<myStringList.length();y++)
            {
                if(flag!=1)
                {
                    QString g=QString::number(i)+","+QString::number(j);                     //создание матрицы смежности
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

          x+=b[i][j];                            //нахождение суммы одной строки
        }
        for (int g=1;g<n+1;g++)
        {
            if (i==g) b[i][g]=x;                 //вставка в диагональ значение суммы строки
            else b[i][g]=-b[i][g];               //смена знака на противоположный
        }

    }

    //удаление одной строки и столбца
    for (int i=1;i<n;i++)
         for (int j=1;j<m;j++)
        {

                 b[i][j]=b[i+1][j+1];
                 //q+=b[i][j];



        }
    //qDebug()<<QString::number(b[1][1])+QString::number(b[2][2])+QString::number(b[3][3])+QString::number(b[4][4])+QString::number(b[5][5]);


    //Алгоритм
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
    //qDebug()<<QString::number(b[1][1])+QString::number(b[2][2])+QString::number(b[3][3])+QString::number(b[4][4])+QString::number(b[5][5]);

    //перемножение диагонали
    for (int i=1;i<n;i++)
        for (int j=1;j<n;j++)
            if (i==j) z=z*b[i][j];

    //qDebug()<<z;

    w=QString::number(z);

    return w;
}

QString weight(QString rebro)
{
    //rebro = "1,2"
    int i = rebro.mid(0,rebro.indexOf(',')).toInt();
    int j = rebro.mid(rebro.indexOf(','),-1).toInt();

    return "0";
}
QString checkCircle(QString rbr, QStringList arcases)
{
    QString res = "";
  QStringList carcases={"0,5,3"};
  QStringList circle;
  circle.push_back(rbr);
  //qDebug()<<rbr;
  QString start = rbr.mid(rbr.indexOf(',')+1,rbr.lastIndexOf(','));
  QString finish = rbr.mid(rbr.lastIndexOf(',')+1,-1);
  //qDebug()<<rbr.indexOf(',')+1;
  auto it_elem = carcases.begin();
  while (it_elem->indexOf(finish)<1)
  {
      it_elem ++;
  }
  if(it_elem->indexOf(finish)==it_elem->lastIndexOf(',')+1)
  {
      circle.push_back(it_elem->mid(0,it_elem->indexOf(','))+","+finish+it_elem->mid(it_elem->indexOf(','),it_elem->lastIndexOf(',')-1));
      /*circle.push_back(finish);
      circle.push_back(start);*/


  }
  else
  {
      circle.push_back(rbr.mid(0,rbr.indexOf(','))+","+start+","+finish);
      /*circle.push_back(start);
      circle.push_back(finish);*/

  }
  finish = circle.back().mid(circle.back().lastIndexOf(',')+1,-1);
  qDebug()<<circle.back();
  for (auto it=circle.begin();it!=circle.end();it++)
  {
      res+=*it +';';
  }
  qDebug()<<res;
  return res;
}

QString solve_task3(int task_number, QString input_for_task)
{
    //QString task= input_for_task;
    //input_for_task = "1,2;1,4;1,5;1,6;2,3;2,5;3,4;3,6;4,5;5,6";
    QStringList all_rebra;// = input_for_task.split("\\s+"); //1 2 1 4 1 5 1 6 2 3 2 5 3 4 3 6 4 5 5 6
    QStringList all_cycles = {};
    QStringList carcases = {};
    QStringList hords = {};
    QRegExp rx(";");
    all_rebra = input_for_task.split(rx);
    /*for (int i=0;i<all_rebra.size();i++)
    {
        all_rebra[i] = weight(all_rebra[i])+ all_rebra[i];

    }*/
    all_rebra.sort();
    QString circle = "";
    QString rebro = "";

    rebro= all_rebra.front();
    all_rebra.pop_front();
    circle = checkCircle(rebro, carcases);
    if(circle.length()>0)
    {
        hords.push_back(rebro);
        all_cycles.push_back(circle);
    }
    else
    {
        carcases.push_back(rebro);
    }
    return circle;
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
        t="3,5,0;1,4,1;1,2,3;1,3,4;1,5,4;2,4,6;3,4,7;4,5,7;2,3,9;2,5,9";
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
