#ifndef DEL_STUDENT_H
#define DEL_STUDENT_H

#include <QDialog>
#include <QFile>
#include <QList>
#include <QTextStream>
#include <QMessageBox>
#include <QCloseEvent>
namespace Ui {
class Del_student;
}

class Del_student : public QDialog
{
    Q_OBJECT

public:
    explicit Del_student(QWidget *parent = 0);
    ~Del_student();
    void display(int index);
   static void readfile(QList<QString>&stu);
private slots:
    void on_pushButton_ok_clicked();

    void on_pushButton_ok_2_clicked();

    void on_pushButton_cancel_clicked();
protected:
    virtual void  closeEvent(QCloseEvent *event);
private:
    Ui::Del_student *ui;
    int m_id;
    QList<QString> stu_lines;
};

#endif // DEL_STUDENT_H
