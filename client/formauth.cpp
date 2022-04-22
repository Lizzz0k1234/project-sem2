#include "formauth.h"
#include "ui_formauth.h"
#include"client.h"
#include <QMessageBox>
FormAuth::FormAuth(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormAuth)
{
    ui->setupUi(this);
    ui->lineEdit_email->setVisible(false);
    ui->pushButton_cancel->setVisible(false);
    //Client::getInstance();
    //connect (Client::getInstance(), &Client::inbox_msg, this, &FormAuth::on_inbox);
}

FormAuth::~FormAuth()
{
    delete ui;
}

void FormAuth::on_pushButton_reg_clicked()
{
    ui->lineEdit_email->setVisible(true);
    ui->pushButton_cancel->setVisible(true);
    ui->pushButton_reg->setVisible(false);
}


void FormAuth::on_pushButton_cancel_clicked()
{
    ui->lineEdit_email->setVisible(false);
    ui->pushButton_cancel->setVisible(false);
    ui->pushButton_reg->setVisible(true);
}

void FormAuth::check_auth()
{
    QString log = ui -> lineEdit_log -> text();
    QString pass = ui -> lineEdit_pass -> text();
    bool g = true;
    if (ui -> lineEdit_email -> isVisible())
    {
        //reg
        QString email = ui -> lineEdit_email -> text();
        if (email!="") reg(log, pass, email);
        else
        {
            QMessageBox temp;
            temp.setText("Please, write your email");
            temp.exec();
            g = false;

        }
    }

    else
    {
        //auth
        //g = true;
        if (auth(log,pass)=="true"){
            //auth(log,pass);
           g=true;
        }

//        QMessageBox temp;
//        temp.setText(auth(log,pass));
//        temp.exec();
        else{
                    g=false;
                    QMessageBox temp;
                    temp.setText("Что-то пошло не так");
                    temp.exec();
        }


    }

    if (g==true)
    {
        emit logged_in(log);
        //goto MainWindow();
        hide();
    }
}
void FormAuth::on_pushButton_ok_clicked()
{
    QString log = ui -> lineEdit_log -> text();
    QString pass = ui -> lineEdit_pass -> text();

    if (pass!="")
    {
        if (log!="") check_auth();
        else
        {
            QMessageBox temp;
            temp.setText("Please, Fill in all the fields");
            temp.exec();
        }
    }
    else
    {
        QMessageBox temp;
        temp.setText("Please, Fill in all the fields");
        temp.exec();
    }
}


void FormAuth::on_lineEdit_pass_returnPressed()
{
    on_pushButton_ok_clicked();
}


void FormAuth::on_lineEdit_email_returnPressed()
{
    on_pushButton_ok_clicked();
}


void FormAuth::on_lineEdit_log_returnPressed()
{
    on_pushButton_ok_clicked();
}
void FormAuth::on_inbox(QString msg)
{
    if(msg == "auth done")
    {
        emit logged_in(ui -> lineEdit_log -> text());
        hide();
    }
    on_pushButton_ok_clicked();
}

