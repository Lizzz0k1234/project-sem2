#ifndef DB_H
#define DB_H
#include <QString>
#include <QVariant>
#include <QDebug>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlRecord>
#include <QByteArray>


class Db;

class DbDestroyer
{
    private:
        Db * p_instance;
    public:
        ~DbDestroyer() { if (p_instance!=nullptr) delete p_instance;}
        void initialize(Db * p){p_instance = p;}
};


class Db
{
    private:
        static Db * p_instance;
        static DbDestroyer destroyer;
        static QSqlDatabase db;
    protected:
        Db()
        {
            db = QSqlDatabase::addDatabase("QSQLITE");
            QString path = "../";
            db.setDatabaseName("Test");

            if(!db.open())
                qDebug()<<db.lastError().text();
        }
        Db(const Db& );
        Db& operator = (Db &);
        ~Db()
        {db.close();}
        friend class DbDestroyer;
    public:
        static Db* getInstance(){
            if (!p_instance)
            {
                p_instance = new Db();
                destroyer.initialize(p_instance);
            }
            return p_instance;
        }
        static QByteArray Test1() {
                    return "1";
                };
};
#endif

