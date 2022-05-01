#ifndef FUNCTIONSFORCLIENT_H
#define FUNCTIONSFORCLIENT_H
#include "client.h"
#include <QString>
#include <QDebug>
QString auth(QString log, QString pass);
QString reg(QString log, QString pass, QString email);
void update_stat(int n, QString upd);
QString look_stat(QString log);
QString look_stat1(QString log);
QString look_stat2(QString log);
QString look_stat3(QString log);
QString generate_input_for_task();
QString generate_text_task(int task_number, QString input_for_task);
QString solve_task(int task_number, QString input_for_task);
bool chek_answer(QString answer, QString input_for_task, int task_number);

#endif // FUNCTIONSFORCLIENT_H
