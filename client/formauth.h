#ifndef FORMAUTH_H
#define FORMAUTH_H

#include <QWidget>
#include "functionsforclient.h"

namespace Ui {
class FormAuth;
}

class FormAuth : public QWidget
{
    Q_OBJECT

public:
    explicit FormAuth(QWidget *parent = nullptr);
    ~FormAuth();

private slots:
    void on_pushButton_reg_clicked();

    void on_pushButton_cancel_clicked();

    void on_pushButton_ok_clicked();
    void check_auth();
    void on_lineEdit_pass_returnPressed();

    void on_lineEdit_email_returnPressed();

    void on_lineEdit_log_returnPressed();

signals:
    void logged_in(QString log);
private:
    Ui::FormAuth *ui;
};

#endif // FORMAUTH_H
