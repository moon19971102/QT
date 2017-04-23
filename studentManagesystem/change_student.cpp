#include "change_student.h"
#include "ui_change_student.h"
#include "del_student.h"

Change_student::Change_student(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Change_student)
{
    ui->setupUi(this);
    Del_student::readfile(stu_lines);
    m_id=0;
    display(m_id);
}

Change_student::~Change_student()
{
    delete ui;
}
void Change_student::display(int index)
{
    QString line=stu_lines[index];
    QStringList subs=line.split(' ');
    ui->lineEdit_name->setText(subs[0]);
    ui->lineEdit_id->setText(subs[1]);
    QList <QAbstractButton*>se=ui->sex_buttons->buttons();
    for(int i=0;i<se.size();i++)
    {
        if(se[i]->text()==subs[2])
            se[i]->setChecked(true);
    }
    int ageint=ui->comboBox->findText(subs[3]);
    ui->comboBox->setCurrentIndex(ageint);
    int subjectint=ui->comboBox_2->findText(subs[4]);
    ui->comboBox_2->setCurrentIndex(subjectint);

    QList <QAbstractButton*>inter=ui->inter_buttons->buttons();
    for(int i=0;i<inter.size();i++)
    {
       inter[i]->setChecked(false);
    }
    for(int j=5;j<subs.size();j++)
    {
        QString temp=subs[j].trimmed();//因为最后一个有问题，所以去掉\n
        for(int i=0;i<inter.size();i++)
        {
            if(inter[i]->text()==temp)
            {
                inter[i]->setChecked(true);
                break;
            }
        }
    }
}

void Change_student::on_pushButton_next_clicked()
{
    m_id=(++m_id)%stu_lines.size();//分开写，警告会消除
    display(m_id);
}

void Change_student::on_pushButton_change_clicked()
{
    QString temp="";
    temp+=ui->lineEdit_name->text();
    temp+=' ';
    temp+=ui->lineEdit_id->text();
     temp+=' ';
    temp+=ui->sex_buttons->checkedButton()->text();
     temp+=' ';
    temp+=ui->comboBox->currentText();
     temp+=' ';
    temp+=ui->comboBox_2->currentText();
    // temp+=' ';
     QList <QAbstractButton*>inter=ui->inter_buttons->buttons();
     for(int i=0;i<inter.size();i++)
     {
       if(inter[i]->isChecked())
       {
           temp.append(' ');
           temp+=inter[i]->text();
         // inter[i]->setChecked(false);
       }
     }
     stu_lines[m_id]=temp;
}
void Change_student::closeEvent(QCloseEvent *event)
{
    if(QMessageBox::Cancel==QMessageBox::warning(NULL,"Close me","Are you sure",\
                                                 QMessageBox::Cancel|QMessageBox::Ok))
    {
        event->ignore();
        return;
    }
    QFile file("student.txt");
    if(!file.open(QIODevice::WriteOnly|QIODevice::Text))
    {
        return;
    }
    QTextStream Out(&file);
    for(int i=0;i<stu_lines.size();i++)
    {
        Out<<stu_lines[i].trimmed()<<endl;
    }
    file.close();
}
void Change_student::on_pushButton_cancel_clicked()
{
    close();
}
