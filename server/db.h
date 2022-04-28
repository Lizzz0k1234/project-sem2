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
            QString path = "C:/Users/Pavel/Desktop/server4/project-sem2/server/";
            db.setDatabaseName(path + "DataBase.db");


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


        static QString count_stat(int sock_desc)
        {

            QByteArray result;
            db.open();
            QSqlQuery query;
            query.prepare("SELECT stat FROM user WHERE status=:sock_desc");
            query.bindValue(":sock_desc", sock_desc);
            query.exec();
            QSqlRecord rec = query.record();
            const int statIndex = rec.indexOf("stat");
            while(query.next()) result.append(query.value(statIndex).toString());
            db.close();
            query.clear();
            //qDebug()<<result;
            return result;
        }


        static QByteArray check_ans(QString ans, int sock_desc) {

                    if (ans=="+")
                    {
                        db.open();
                        QSqlQuery query;
                        query.prepare("UPDATE user SET stat=stat+1 WHERE status=:sock_desc");
                        query.bindValue(":sock_desc", sock_desc);
                        query.exec();
                        db.close();
                        query.clear();
                        return "true";

                    }
                    else
                    {
                        db.open();
                        QSqlQuery query;
                        query.prepare("UPDATE user SET stat=stat-1 WHERE status=:sock_desc");
                        query.bindValue(":sock_desc", sock_desc);
                        query.exec();
                        db.close();
                        query.clear();
                        return "false";
                    }
                };
        static QByteArray auth(QString log, QString pass) {
                        db.open();
                        QSqlQuery query;
                        query.prepare("SELECT * FROM user where log = :login and password = :password" );
                        query.bindValue(":login", log);
                        query.bindValue(":password", pass);
                        query.exec();
                        if (query.next()){
                            qDebug()<<log;

                            return "true";
                        }
                        else{
                            return "false";
                        }
                };
        static QByteArray reg(QString log, QString pass, QString mail, int sock_desc)
        {
                        db.open();
                        QSqlQuery query;
                        query.prepare("SELECT * FROM user where log = :login" );
                        query.bindValue(":login", log);
                        query.exec();
                        if (query.next()){
                            return "Данный пользователь зарегистрирован";
                        }
                        else{
                            qDebug()<<log;
                            query.prepare("INSERT INTO user (log, password, email, stat, status) VALUES (:login, :password, :email, 0, :sock_desc)");
                            query.bindValue(":login", log);
                            query.bindValue(":password", pass);
                            query.bindValue(":email", mail);
                            query.bindValue(":sock_desc", sock_desc);
                            query.exec();
                            return "true";
                        }
        }
        static QByteArray change_status(QString log, int sock_desc)
        {
            db.open();
            QSqlQuery query;
            query.prepare("UPDATE user SET status=:sock_desc WHERE log=:login");
            query.bindValue(":sock_desc", sock_desc);
            query.bindValue(":login", log);
            query.exec();
            db.close();
            query.clear();
            return "true";
        }
};
#endif

