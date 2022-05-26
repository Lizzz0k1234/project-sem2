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
QString del_status(QString log);
QString generate_input_for_task(int n);
QString generate_text_task(int task_number, QString input_for_task);
QString solve_task(int task_number, QString input_for_task);
bool chek_answer(QString answer, QString input_for_task, int task_number);
QString solve_task1(int task_number, QString input_for_task);
QString solve_task3(int task_number, QString input_for_task);
QString checkCircle(QString rbr, QStringList arcases);
QString weight(QString rebro);

#endif // FUNCTIONSFORCLIENT_H
