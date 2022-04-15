#include "formauth.h"
#include "ui_formauth.h"

FormAuth::FormAuth(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormAuth)
{
    ui->setupUi(this);
    ui->lineEdit_email->setVisible(false);
    ui->pushButton_cancel->setVisible(false);
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


void FormAuth::on_pushButton_ok_clicked()
{
    QString log = ui -> lineEdit_log -> text();
    QString pass = ui -> lineEdit_pass -> text();
    if (ui -> lineEdit_email -> isVisible())
    {
        //reg
        QString email = ui -> lineEdit_email -> text();
        reg(log, pass, email);
    }

    else
    {
        //auth
        auth(log,pass);
    }

    emit logged_in(log);
    //goto MainWindow();
    hide();
}

