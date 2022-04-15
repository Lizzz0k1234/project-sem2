#ifndef FUNCTIONSFORCLIENT_H
#define FUNCTIONSFORCLIENT_H

#include <QString>
#include <QDebug>
void auth(QString log, QString pass);
void reg(QString log, QString pass, QString email);
void update_stat(int n, QString upd);

QString generate_input_for_task();
QString generate_text_task(int task_number, QString input_for_task);
QString solve_task(int task_number, QString input_for_task);
bool chek_answer(QString answer, QString input_for_task, int task_number);

#endif // FUNCTIONSFORCLIENT_H
