#-------------------------------------------------
#
# Project created by QtCreator 2017-04-16T10:27:01
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = studentManagesystem
TEMPLATE = app


SOURCES += main.cpp\
        studentmanagesystem.cpp \
    addstudent.cpp \
    del_student.cpp \
    change_student.cpp \
    serch_student.cpp

HEADERS  += studentmanagesystem.h \
    addstudent.h \
    del_student.h \
    change_student.h \
    serch_student.h

FORMS    += studentmanagesystem.ui \
    addstudent.ui \
    del_student.ui \
    change_student.ui \
    serch_student.ui
