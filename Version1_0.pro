#-------------------------------------------------
#
# Project created by QtCreator 2016-03-12T09:56:13
#
#-------------------------------------------------

QT       += core gui network

TARGET = Version1_0
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    posix_qextserialport.cpp \
    qextserialbase.cpp \
    qextserialport.cpp \
    serialclass.cpp \
    socketclass.cpp \
    moudle.cpp \
    ledandmotor.cpp

HEADERS  += mainwindow.h \
    posix_qextserialport.h \
    qextserialbase.h \
    qextserialport.h \
    serialclass.h \
    socketclass.h \
    serialservice.h \
    socketservice.h \
    abstracemoudle.h \
    moudle.h \
    ledandmotor.h

FORMS    += mainwindow.ui

unix:DEFINES           += _TTY_POSIX_
