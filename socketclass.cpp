#include "socketclass.h"

SocketClass::SocketClass(QObject *parent) :
    QObject(parent),
    socket_service_(0)
{
}


qint64 SocketClass::ReadFromService(QByteArray &byte)
{

}

void SocketClass::WriteToService(QByteArray &byte)
{

}

bool SocketClass::OpenSerivce()
{
    if(0 == my_socket_)
    {
        my_socket_ = new QTcpSocket(this);
    }

    my_socket_->connectToHost("115.159.127.79", 23456);

}

bool SocketClass::CloseService()
{

}

void SocketClass::ReleaseService()
{

}

CommunicateService* SocketClass::GetService()
{
    if(!socket_service_)
    {
        socket_service_ = new SocketClass();
    }

    return socket_service_;
}
