#include <QtTest>

// add necessary includes here

class solve_tasks : public QObject
{
    Q_OBJECT

public:
    solve_tasks();
    ~solve_tasks();

private slots:
    void test_solve_task_1();

};

solve_tasks::solve_tasks()
{

}

solve_tasks::~solve_tasks()
{

}

void solve_tasks::test_solve_task_1()
{
    QString w="";
        QString t="1,2;1,4;1,5;1,6;2,3;2,5;3,4;3,6;4,5;5,6";
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
        QCOMPARE("135",w);



}

QTEST_APPLESS_MAIN(solve_tasks)

#include "tst_solve_tasks.moc"
