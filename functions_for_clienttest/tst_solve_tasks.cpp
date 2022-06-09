#include <QtTest>
#include "..\client\solver.h";
// add necessary includes here

class solve_tasks : public QObject
{
    Q_OBJECT

public:
    solve_tasks();
    ~solve_tasks();

private slots:
    void test_solve_task_1();

};

solve_tasks::solve_tasks()
{

}

solve_tasks::~solve_tasks()
{

}

void solve_tasks::test_solve_task_1()
{
        QString t="1,2;1,4;1,5;1,6;2,3;2,5;3,4;3,6;4,5;5,6";

        QCOMPARE("135",solve_task1(1,t));



}

QTEST_APPLESS_MAIN(solve_tasks)

#include "tst_solve_tasks.moc"
