#ifndef CLIENT_H
#define CLIENT_H

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include <QString>
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
        inline static QString ans_from_serv;
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
signals:
        void inbox_msg(QString msg);
    public:
        static Client* getInstance(){
            if (!p_instance)
            {
                p_instance = new Client();
                destroyer.initialize(p_instance);
            }
            return p_instance;
        }
        static QString send_to_server(QString res)
        {
            ans_from_serv = "Read";
            QByteArray a;
            a+=res.toUtf8();
            mysocket.write(a);
            mysocket.waitForReadyRead(100);
//            ans_from_serv = a;
            return ans_from_serv;
        }
    public slots:


    void slotDisconnected()
    {
        mysocket.close();
    }
    static void slotClientRead()
    {


        QString res="";
        while(mysocket.bytesAvailable()>0)
        {
        QByteArray array =mysocket.readAll();
        res.append(array);
        //emit inbox_msg(res);
        qDebug()<<res;
        }
        ans_from_serv = res;
    };

};
#endif // CLIENT_H
