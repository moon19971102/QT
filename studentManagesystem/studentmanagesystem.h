#ifndef STUDENTMANAGESYSTEM_H
#define STUDENTMANAGESYSTEM_H

#include <QMainWindow>
#include "addstudent.h"
#include "del_student.h"
#include "change_student.h"
#include "serch_student.h"
namespace Ui {
class StudentManageSystem;
}

class StudentManageSystem : public QMainWindow
{
    Q_OBJECT

public:
    explicit StudentManageSystem(QWidget *parent = 0);
    ~StudentManageSystem();

private slots:
    void on_actionDEL_triggered();

    void on_actionChange_triggered();

    void on_actionSerch_triggered();

    void on_actionSerch_2_triggered();

private:
    Ui::StudentManageSystem *ui;
};

#endif // STUDENTMANAGESYSTEM_H
