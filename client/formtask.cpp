#include "formtask.h"
#include "ui_formtask.h"

FormTask::FormTask(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormTask)
{
    ui->setupUi(this);
    this->setStyleSheet("background: #9370db");
    ui->textBrowser_task->setStyleSheet("color: blue; background-color: #87cefa; selection-color: cyan;"
                                        "selection-background-color: black;");
    ui->lineEdit_answer->setStyleSheet("color: blue; background-color: #90ee90; selection-color: cyan;"
                                       "selection-background-color: black;");
    ui->pushButton_send->setStyleSheet("color: blue; background-color: #da70d6;selection-color: blue;"
                                       "selection-background-color: black;");
}

FormTask::~FormTask()
{
    delete ui;
}

void FormTask::set_task_number(int n)
{
    task_number = n;
    input_for_task=generate_input_for_task(n);
    ui->textBrowser_task->setText(generate_text_task(task_number,input_for_task));

}

void FormTask::on_pushButton_send_clicked()
{
    QString answer = ui -> lineEdit_answer -> text();
    QString ans=solve_task(task_number,input_for_task);
    bool b = chek_answer(answer, ans, task_number);
    //Client::send_to_server(answer);
    if (b)
    {
        QMessageBox temp;
                temp.setStyleSheet("color: #dc143c; background-color: #87cefa; selection-color: ;"
                                   "selection-background-color: black;");
                temp.setText("Правильно!!!");
                QString i="Поздравляю";
                QTextToSpeech *speech;
                speech=new QTextToSpeech;
                speech->say(i);
                temp.exec();
    }
    else
    {
        QMessageBox temp;
        temp.setStyleSheet("color: #dc143c; background-color: #87cefa; selection-color: ;"
                           "selection-background-color: black;");
        temp.setText("Неправильно!!!       Правильный ответ: "+ans+"       Ваш ответ: "+answer);
        QString i="Не расстраивайтесь, всё получится";
        QTextToSpeech *speech;
        speech=new QTextToSpeech;
        speech->say(i);
        temp.exec();

    }
    ui -> lineEdit_answer -> setText("");
    hide();
}

void FormTask::on_lineEdit_answer_returnPressed()
{
    on_pushButton_send_clicked();

}

