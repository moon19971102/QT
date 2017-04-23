#ifndef ADDSTUDENT_H
#define ADDSTUDENT_H

#include <QDialog>
#include  <QString>
#include <QList>
#include <QAbstractButton>
#include<QFile>
#include <QTextStream>
namespace Ui {
class AddStudent;
}

class AddStudent : public QDialog
{
    Q_OBJECT

public:
    explicit AddStudent(QWidget *parent = 0);
    ~AddStudent();

private slots:
    void on_pushButton_ok_clicked();

    void on_pushButton_cancel_clicked();

private:
    Ui::AddStudent *ui;
};

#endif // ADDSTUDENT_H
