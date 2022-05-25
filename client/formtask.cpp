#include "formtask.h"
#include "ui_formtask.h"

FormTask::FormTask(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormTask)
{
    ui->setupUi(this);
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
    chek_answer(answer, input_for_task, task_number);
    //Client::send_to_server(answer);
    ui -> lineEdit_answer -> setText("");
    hide();
}


void FormTask::on_lineEdit_answer_returnPressed()
{
    on_pushButton_send_clicked();

}

