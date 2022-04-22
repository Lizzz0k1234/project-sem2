#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    Client::getInstance();
    ui_auth = new FormAuth;
    ui_task = new FormTask;
    ui_auth->show();
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
    show();
}



void MainWindow::on_pushButton_task1_clicked()
{
    ui_task -> set_task_number(1);
    ui_task ->show();
}

void MainWindow::on_pushButton_task2_clicked()
{
    ui_task -> set_task_number(2);
    ui_task ->show();
}

void MainWindow::on_pushButton_task3_clicked()
{
    ui_task -> set_task_number(3);
    ui_task ->show();
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
    close();
}


void MainWindow::on_pushButton_stat_clicked()
{
    QMessageBox temp;
    temp.setText("srfwrsfvrsf");
    temp.exec();
}
