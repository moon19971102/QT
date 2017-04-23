#ifndef SERCH_STUDENT_H
#define SERCH_STUDENT_H

#include <QDialog>
#include <QCloseEvent>
#include <QMessageBox>
#include <QAbstractItemModel>
#include<QStandardItemModel>

namespace Ui {
class Serch_student;
}

class Serch_student : public QDialog
{
    Q_OBJECT

public:
    explicit Serch_student(QWidget *parent = 0);
    ~Serch_student();
     void doquery(int num,QString line_name);
private:
    Ui::Serch_student *ui;
    QStandardItemModel * mytable;
    QList <QString> stu_lines;
protected:
    virtual void closeEvent(QCloseEvent *event);
private slots:
    void on_pushButton_clicked();

};

#endif // SERCH_STUDENT_H
