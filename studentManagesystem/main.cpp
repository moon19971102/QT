#include "studentmanagesystem.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    StudentManageSystem w;
    w.show();

    return a.exec();
}
