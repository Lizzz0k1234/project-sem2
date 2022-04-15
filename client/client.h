#ifndef CLIENT_H
#define CLIENT_H

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>

#include <QtNetwork>
#include <QByteArray>
#include <QDebug>

class Client;

class ClientDestroyer
{
    private:
        Client * p_instance;
    public:
        ~ClientDestroyer() { delete p_instance;};
        void initialize(Client * p){p_instance = p;}
};

class Client : public QObject
{
    Q_OBJECT
    private:
        static Client * p_instance;
        static ClientDestroyer destroyer;
        static QTcpSocket mysocket;
    protected:
        Client(QObject *parent = nullptr) : QObject(parent){
            mysocket.connectToHost("127.0.0.1",33333);
            connect(&mysocket, &QTcpSocket::readyRead,this,&Client::slotClientRead);
            connect(&mysocket,&QTcpSocket::disconnected,this,&Client::slotDisconnected);
        }
        Client(const Client& )= delete;
        Client& operator = (Client &) = delete;
        ~Client() {
            mysocket.close();
        }
        friend class ClientDestroyer;
    public:
        static Client* getInstance(){
            if (!p_instance)
            {
                p_instance = new Client();
                destroyer.initialize(p_instance);
            }
            return p_instance;
        }
    public slots:

    void slotDisconnected()
    {
        mysocket.close();
    }
    void slotClientRead()
    {


        QString res="";
        while(mysocket.bytesAvailable()>0)
        {
        QByteArray array =mysocket.readAll();
        res.append(array);
        qDebug()<<res;
        }
    };

};
#endif // CLIENT_H
