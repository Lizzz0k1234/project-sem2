#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtTextToSpeech/QTextToSpeech>
#include <QtMultimedia/QMediaPlayer>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setStyleSheet("background: #9370db");
    ui->pushButton_task1->setStyleSheet("color: blue; background-color: #7fffd4");
    ui->pushButton_task2->setStyleSheet("color: blue; background-color: #7fffd4");
    ui->pushButton_task3->setStyleSheet("color: blue; background-color: #7fffd4");
    ui->pushButton_stat->setStyleSheet("color: blue; background-color: #00ffff");
    ui->pushButton_exit->setStyleSheet("color: blue; background-color: #da70d6");
    ui->menuMenu->setStyleSheet("color: blue; background-color: #7fffd4; selection-color: cyan;"
                                "selection-background-color: black;");
    ui->menuAbout->setStyleSheet("color: blue; background-color: #7fffd4; selection-color: cyan;"
                                 "selection-background-color: black;");
    ui->menubar->setStyleSheet("color: blue; background-color: #90ee90; selection-color: blue;"
                               "selection-background-color: black;");
    Client::getInstance();
    ui_auth = new FormAuth;
    ui_task = new FormTask;
    ui_auth->show();
    QString i="Здравствуйте, введите пожалуйста логин и пароль";
    QTextToSpeech *speech;
    speech=new QTextToSpeech;
    //QUrl ur("https://audio.mp3set.info/play/9446242.mp3");
    QUrl ur("https://audio.mp3set.info/play/10563245.mp3");
    QMediaPlayer* player;
    player=new QMediaPlayer;
    player->setMedia(ur);
    player->setVolume(100);
    player->play();
    speech->say(i);

    connect(ui_auth, &FormAuth::logged_in, this, &MainWindow::slot_show);
}

MainWindow::~MainWindow()
{
    delete ui_auth;
    delete ui_task;
    delete ui;
}

void MainWindow::slot_show(QString log)
{
    ui -> label -> setText(log);
    ui->label->setStyleSheet("color: cyan");
    show();

}




void MainWindow::on_pushButton_task1_clicked()
{
    ui_task -> set_task_number(1);
    ui_task ->show();
    QString i="Решите задание 1";
    QTextToSpeech *speech;
    speech=new QTextToSpeech;
    speech->say(i);
}

void MainWindow::on_pushButton_task2_clicked()
{
    ui_task -> set_task_number(2);
    ui_task ->show();
    QString i="Решите задание 2";
    QTextToSpeech *speech;
    speech=new QTextToSpeech;
    speech->say(i);
}

void MainWindow::on_pushButton_task3_clicked()
{
    ui_task -> set_task_number(3);
    ui_task ->show();
    QString i="Решите задание 3";
    QTextToSpeech *speech;
    speech=new QTextToSpeech;
    speech->say(i);
}


void MainWindow::on_actionTask_1_triggered()
{
    on_pushButton_task1_clicked();
}

void MainWindow::on_actionTask_2_triggered()
{
    on_pushButton_task2_clicked();
}

void MainWindow::on_actionTask_3_triggered()
{
    on_pushButton_task3_clicked();
}

void MainWindow::on_pushButton_exit_clicked()
{
    QString log = ui -> label->text();
    del_status(log);
    QString i="До свидания";
    QTextToSpeech *speech;
    speech=new QTextToSpeech;
    speech->say(i);
    QMessageBox temp;
    temp.setStyleSheet("color: #dc143c; background-color: #87cefa; selection-color: ;"
                       "selection-background-color: black;");
    temp.setText("До свидания");
    temp.exec();
    close();
}


void MainWindow::on_pushButton_stat_clicked()
{
    QString log = ui -> label->text();
    QMessageBox temp;
    temp.setStyleSheet("color: #dc143c; background-color: #87cefa; selection-color: ;"
                       "selection-background-color: black;");
    temp.setText("Общее количество баллов: " + look_stat(log) + "   Баллы за 1 задание: " + look_stat1(log) + "   Баллы за 2 задание: " + look_stat2(log) + "   Баллы за 3 задание: " + look_stat3(log) );
    temp.exec();

}


void MainWindow::on_actionOur_project_triggered()
{
    QMessageBox temp;
    temp.setStyleSheet("color: #dc143c; background-color: #87cefa; selection-color: ;"
                       "selection-background-color: black;");
    temp.setText("Программа для решения задач по дискретной математике");
    QString i="Программа для решения задач по дискретной математике";
    QTextToSpeech *speech;
    speech=new QTextToSpeech;
    speech->say(i);
    temp.exec();
}


void MainWindow::on_actionExit_triggered()
{
    on_pushButton_exit_clicked();
}


void MainWindow::on_actionDevelopers_triggered()
{
    QMessageBox temp;
    temp.setStyleSheet("color: #dc143c; background-color: #87cefa; selection-color: ;"
                       "selection-background-color: black;");
    temp.setText("Дьяконов Павел    Войтович Владислав    Кузьмич Елизавета");
    QString i="Над приложением работали: Дьяконов Павел, Войтович Владислав и Кузьмич Елизавета";
    QTextToSpeech *speech;
    speech=new QTextToSpeech;
    speech->say(i);
    temp.exec();
}


void MainWindow::on_actionOur_website_triggered()
{
    QUrl url("https://github.com/Lizzz0k1234/project-sem2/wiki");
    QDesktopServices::openUrl(url);
}

