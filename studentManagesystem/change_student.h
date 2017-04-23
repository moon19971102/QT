#ifndef CHANGE_STUDENT_H
#define CHANGE_STUDENT_H

#include <QDialog>
#include <QList>
#include <QCloseEvent>
namespace Ui {
class Change_student;
}

class Change_student : public QDialog
{
    Q_OBJECT

public:
    explicit Change_student(QWidget *parent = 0);
    ~Change_student();
    void display(int index);

private slots:
    void on_pushButton_next_clicked();

    void on_pushButton_change_clicked();

    void on_pushButton_cancel_clicked();
protected:
    virtual  void closeEvent(QCloseEvent *event);
private:
    Ui::Change_student *ui;
    QList <QString> stu_lines;
    int m_id;
};

#endif // CHANGE_STUDENT_H
