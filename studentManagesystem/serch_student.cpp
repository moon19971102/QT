#include "serch_student.h"
#include "ui_serch_student.h"
#include "del_student.h"

Serch_student::Serch_student(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Serch_student)
{
   Del_student::readfile(stu_lines);
    ui->setupUi(this);
     mytable=new QStandardItemModel;
     mytable->setHorizontalHeaderItem(0,new QStandardItem(QObject::tr("Name")));
     mytable->setHorizontalHeaderItem(1,new QStandardItem(QObject::tr("Id")));
     mytable->setHorizontalHeaderItem(2,new QStandardItem(QObject::tr("Sex")) );
     mytable->setHorizontalHeaderItem(3,new QStandardItem(QObject::tr("Age")));
     mytable->setHorizontalHeaderItem(4,new QStandardItem(QObject::tr("Subject")));
     mytable->setHorizontalHeaderItem(5,new QStandardItem(QObject::tr("Interest")));
     ui->tableView->setModel(mytable);
     ui->tableView->setColumnWidth(0,50);
     ui->tableView->setColumnWidth(1,50);
     ui->tableView->setColumnWidth(2,50);
     ui->tableView->setColumnWidth(3,50);
     ui->tableView->setColumnWidth(4,100);
     ui->tableView->setColumnWidth(5,200);

}

Serch_student::~Serch_student()
{
    delete ui;
}
void Serch_student::closeEvent(QCloseEvent *event)
{
    if(QMessageBox::Cancel==QMessageBox::warning(NULL,"Close me","Are you sure",\
                                                 QMessageBox::Cancel|QMessageBox::Ok))
    {
        event->ignore();
        return;
    }
}
void Serch_student::doquery(int num,QString line_name)
{
     int k=0;
     for(int i=0;i<stu_lines.size();i++)
  {
        QString line=stu_lines[i];
        QStringList subs=line.split(' ');//这两步合在一块，不然会有错误
        if(num==0)
        {
            if(line_name!=subs[0])
                continue;
        }
        if(num==1)
        {
            if(line_name!=subs[1])
                continue;
        }
        if(num==2)
        {
            if(line_name!=subs[2])
                continue;
        }
        if(num==3)
        {
            if(line_name!=subs[3])
                continue;
        }
        if(num==4)
        {
            if(line_name!=subs[4])
                continue;
        }
        for(int j=0;j<5;j++)
        {
            mytable->setItem(k,j,new QStandardItem(subs[j]));
        }
         QString temp="";

        for(int m=5;m<subs.size();m++)
        {
           temp+=subs[m];
           temp.append("_");
        }
        mytable->setItem(k++,5,new QStandardItem(temp));
   }
      /*   int t=6;
         QString temp(subs[5]);
         while(t<subs.size())
         {
             temp.append("__");
             temp.append(subs[t++]);
         }
         mytable->setItem(k++,5,new QStandardItem(temp));//这样写，必须有一个兴趣
    */

}
void Serch_student::on_pushButton_clicked()
{
      mytable->clear();
      mytable->setHorizontalHeaderItem(0,new QStandardItem(QObject::tr("Name")));
      mytable->setHorizontalHeaderItem(1,new QStandardItem(QObject::tr("Id")));
      mytable->setHorizontalHeaderItem(2,new QStandardItem(QObject::tr("Sex")) );
      mytable->setHorizontalHeaderItem(3,new QStandardItem(QObject::tr("Age")));
      mytable->setHorizontalHeaderItem(4,new QStandardItem(QObject::tr("Subject")));
      mytable->setHorizontalHeaderItem(5,new QStandardItem(QObject::tr("Interest")));
      //ui->tableView->setModel(mytable);
      ui->tableView->setColumnWidth(0,50);
      ui->tableView->setColumnWidth(1,50);
      ui->tableView->setColumnWidth(2,80);
      ui->tableView->setColumnWidth(3,50);
      ui->tableView->setColumnWidth(4,100);
      ui->tableView->setColumnWidth(5,200);
      int Num=ui->comboBox->currentIndex();
      QString buff=ui->lineEdit->text();
      doquery(Num,buff);
}
