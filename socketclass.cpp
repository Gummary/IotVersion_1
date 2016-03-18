#include "socketclass.h"

SocketClass::SocketClass(QObject *parent) :
    QObject(parent)
{
}


qint64 SocketClass::ReadFromSocket(QByteArray &byte)
{

}

void SocketClass::WriteToSocket(QByteArray &byte)
{

}

bool SocketClass::OpenSocket()
{
    if(0 == my_socket_)
    {
        my_socket_ = new QTcpSocket(this);
    }

    my_socket_->connectToHost("115.159.127.79", 23456);

}

bool SocketClass::CloseSocket()
{

}

void SocketClass::ReleaseSocket()
{

}


