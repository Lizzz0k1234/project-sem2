#ifndef FORMTASK_H
#define FORMTASK_H

#include <QWidget>
#include "functionsforclient.h"
namespace Ui {
class FormTask;
}

class FormTask : public QWidget
{
    Q_OBJECT

public:
    explicit FormTask(QWidget *parent = nullptr);
    ~FormTask();
    void set_task_number(int n);

private slots:
    void on_pushButton_send_clicked();


    void on_lineEdit_answer_returnPressed();


private:
    Ui::FormTask *ui;
    int task_number;
    QString input_for_task;
};

#endif // FORMTASK_H
