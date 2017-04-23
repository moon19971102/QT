#include "del_student.h"
#include "ui_del_student.h"
#include <QDebug>

Del_student::Del_student(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Del_student)
{
    ui->setupUi(this);
    readfile(stu_lines);
    m_id=0;
   display(0);
}

Del_student::~Del_student()
{
    delete ui;
}

void Del_student::readfile(QList<QString> &stu_lines)
{
    QFile file("student.txt");
    if(!file.open(QIODevice::ReadOnly|QIODevice::Text))
    {
        return;
    }
    while(!file.atEnd())
    {
       stu_lines.append(file.readLine());
    }
}
void Del_student::closeEvent(QCloseEvent *event)
{
    if(QMessageBox::Cancel==QMessageBox::warning(NULL,"Close me","Are you sure",\
                                                 QMessageBox::Ok|QMessageBox::Cancel))
    {
        event->ignore();
        return;
    }
    QFile file("student.txt");
    if(!file.open(QIODevice::WriteOnly|QIODevice::Text))
    {
        return;
    }
    QTextStream out(&file);
    for(int i=0;i<stu_lines.size();i++)
    {
        out<<stu_lines[i].trimmed()<<endl;
    }
    file.close();
}
void Del_student::display(int index)
{

    QString line=stu_lines[index];
    QStringList subs=line.split(' ');
    ui->lineEdit_name->setText(subs[0]);
    ui->lineEdit_id->setText(subs[1]);
    QList <QAbstractButton*>se=ui->sex_buttons->buttons();
    for(int i=0;i<se.size();i++)
    {
        if(se[i]->text()==subs[2])
        {
            se[i]->setChecked(true);
        }
    }
    int ageint=ui->comboBox->findText(subs[3]);
    ui->comboBox->setCurrentIndex(ageint);
    int subjectint=ui->comboBox_2->findText(subs[4]);
    ui->comboBox_2->setCurrentIndex(subjectint);
    QList<QAbstractButton*>inter=ui->interset_buttons->buttons();
    for(int i=0;i<inter.size();i++)
    {
       inter[i]->setChecked(false);
    }
    for(int i=5;i<subs.size();i++)
    {
        QString temp=subs[i].trimmed();//去除两端的空白，包括\n\t
        for(int j=0;j<inter.size();j++)
        {
         if(inter[j]->text()==temp)
         {
             inter[j]->setChecked(true);
             break;
         }
        }
    }
}
void Del_student::on_pushButton_ok_clicked()//delete
{
    if(stu_lines.size()<=1)
        return;
    stu_lines.removeAt(m_id); //必须放在if之前，因为如果是最后一个，删除一个之后，
                                                 //链表里的数目就会减少，那么m_id才会在if的判断下变为1，否则不存在的m_id将会导致程序崩溃
    if(m_id>=stu_lines.size())
        m_id=0;
    display(m_id);
}

void Del_student::on_pushButton_ok_2_clicked()//next
{
    m_id=(++m_id)%stu_lines.size();
    display(m_id);
}

void Del_student::on_pushButton_cancel_clicked()
{
  // QMessageBox::about(NULL,"xiaoxin","hhahah");
    close();
}
