#include "mainwindow.h"

#include <QApplication>


Client * Client::p_instance;
ClientDestroyer Client::destroyer;
QTcpSocket Client::mysocket;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    return a.exec();
}
