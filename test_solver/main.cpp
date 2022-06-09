#include <QCoreApplication>
#include "..\client\solver.h"
#include <QString>
#include <QStringList>
#include <QDebug>
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QStringList t = {"0,3,5","1,1,4","3,1,2","4,2,3"};
    QString r = "4,5,3";
    qDebug()<< checkCircle(r,t)+"-circle";

    return a.exec();
}
