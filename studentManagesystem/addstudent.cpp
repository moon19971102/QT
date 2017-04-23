#include "addstudent.h"
#include "ui_addstudent.h"
#include <QDebug>
AddStudent::AddStudent(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddStudent)
{
    ui->setupUi(this);
}

AddStudent::~AddStudent()
{
    delete ui;
}

void AddStudent::on_pushButton_ok_clicked()
{
    QString name=ui->lineEdit_name->text();
    QString id=ui->lineEdit_id->text();
    QString sex=ui->sexbutton->checkedButton()->text();
    QString subject=ui->comboBox_2->currentText();
    QString  age=ui->comboBox->currentText();
    QList<QAbstractButton*>ins=ui->interest_button->buttons();
    QFile file("student.txt");
    qDebug()<<name<<" "<<id<<endl;
    QTextStream Out(&file);
    if(!file.open (QIODevice::WriteOnly|QIODevice::Text|QIODevice::Append))
            return;
     Out<<name<<" "<<id<<" "<<sex<<" "<<age<<" "<<subject;

     for(int i=0;i<ins.size();i++)
     {
         if(ins[i]->isChecked())
         Out<<" "<<ins[i]->text();
         ins[i]->setChecked(false);
     }
     Out<<endl;
     file.close();
     ui->lineEdit_id->clear();
     ui->lineEdit_name->clear();
     ui->comboBox->setCurrentIndex(0);
     ui->comboBox_2->setCurrentIndex(0);
     ui->sexbutton->setExclusive(false);
     ui->sexbutton->checkedButton()->setChecked(false);
     ui->sexbutton->setExclusive(true);
}

void AddStudent::on_pushButton_cancel_clicked()
{
    close();
}
