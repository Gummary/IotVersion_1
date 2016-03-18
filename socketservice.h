#ifndef SOCKETSERVICE_H
#define SOCKETSERVICE_H
#include "mainwindow.h"

class MainWindow;

class SocketService
{
public:
    virtual qint64 ReadFromSocket(QByteArray &byte) = 0;
    virtual void WriteToSocket(QByteArray &byte) = 0;
    virtual bool OpenSocket(MainWindow *mw) = 0;
    virtual bool CloseSocket() = 0;
    virtual void ReleaseSocket() = 0;
};

#endif // SOCKETSERVICE_H


