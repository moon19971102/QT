#include "studentmanagesystem.h"
#include "ui_studentmanagesystem.h"

StudentManageSystem::StudentManageSystem(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::StudentManageSystem)
{
    ui->setupUi(this);
}

StudentManageSystem::~StudentManageSystem()
{
    delete ui;
}

void StudentManageSystem::on_actionDEL_triggered()
{
  AddStudent add;
  add.exec();
}

void StudentManageSystem::on_actionChange_triggered()
{
    Del_student del;
    del.exec();

}

void StudentManageSystem::on_actionSerch_triggered()
{
    Change_student change;
    change.exec();
}

void StudentManageSystem::on_actionSerch_2_triggered()
{
   Serch_student serch;
   serch.exec();
}
