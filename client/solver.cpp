#include "solver.h"
#include <QStringList>
#include <QDebug>
QString solve_task1(int task_number, QString input_for_task)
{
    QString w="";
    QString t=input_for_task;
    int n=0,m=0;
    QStringList List = t.split(';');
    //QStringList sList;
    int first,second;
    for (int i=0;i<List.size();i++)
    {
        QStringList sList=List.at(i).split(',');
        first=sList.at(0).toInt();
        second=sList.at(1).toInt();
        if ((first>n)&&(first>second)) n=first;
        if ((second>first)&&(second>n)) n=second;
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
  QStringList carcases={"0,3,5","1,1,4","3,1,2","4,1,3"};
  //rbr= "7,3,4"
  QStringList circle;
  circle.push_back(rbr); //{"7,3,4"}
  //qDebug()<<rbr;
  QString start = rbr.mid(rbr.indexOf(',')+1,rbr.lastIndexOf(',')-rbr.indexOf(',')-1); //start=3
  QString finish = rbr.mid(rbr.lastIndexOf(',')+1,-1); //finish = 4
  while (start!=finish)
  {


  //qDebug()<<rbr.indexOf(',')+1;
  auto it_elem = carcases.begin(); // *it_elem = "0,3,5"
  //qDebug()<< it_elem->indexOf(finish);
  while (it_elem->indexOf(finish)<1)
  {
      qDebug()<< *it_elem;
      if (it_elem==carcases.end()-1)
      {
          /*вернуться на шаг назад - 1) убрать последнее ребро из циклов. 2)исправить finish на предыдущее значение 3) добавить это ребро в конец каркаса
           *  4)заново искать

            */
          if (circle.length()<2)
              return "";
          auto t = circle.back();
          circle.pop_back(); // circle = {"7,3,4","1,4,1"}
          finish = circle.back().mid(circle.back().lastIndexOf(',')+1,-1); //finish=1
          carcases.push_back(t); //carcases={"0,3,5","4,1,3","3,1,2"};
          it_elem = carcases.begin();

          //return "";
      }
      else
          it_elem ++; //*it_elem = "1,1,4" //*it_elem = "3,1,2"
  }

  if(it_elem->indexOf(finish)==it_elem->lastIndexOf(',')+1)
  {
      circle.push_back(it_elem->mid(0,it_elem->indexOf(','))+","+finish+it_elem->mid(it_elem->indexOf(','),it_elem->lastIndexOf(',')-1));
      qDebug()<<circle.back()+"iiii";
      /*circle.push_back(finish);
      circle.push_back(start);*/
      // circle = {"7,3,4","1,4,1"}
  }
  else if(it_elem->indexOf(finish)==it_elem->lastIndexOf(',')-1)
  {
      circle.push_back(rbr.mid(0,it_elem->indexOf(','))+it_elem->mid(it_elem->indexOf(','),it_elem->lastIndexOf(',')-1)+","+it_elem->mid(it_elem->lastIndexOf(',')+1,-1));
      /*circle.push_back(start);

      circle.push_back(finish);*/
      // circle = {"7,3,4","1,4,1","3,1,2"}
      qDebug()<<circle.back();
  }
  qDebug()<<carcases.at(it_elem-carcases.begin())+"gggg";
  carcases.removeAt(it_elem-carcases.begin()); //carcases={"0,3,5","3,1,2","4,1,3"}; //carcases={"0,3,5","4,1,3"};

  if (circle.length()>=1)
    finish = circle.back().mid(circle.back().lastIndexOf(',')+1,-1); //finish = 1 //finish=2
  }
  for (auto it=circle.begin();it!=circle.end();it++)
  {
      res+=*it +';';
  }


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
    //all_rebra.sort();
    QString circle = "";
    QString rebro = "";

    rebro= all_rebra.front();
    all_rebra.pop_front();
    //circle = checkCircle(rebro, carcases);
    while (all_rebra.length()>0)
    {
        QString rbr=all_rebra.front();
        circle = checkCircle(rbr, all_rebra);
    }
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
