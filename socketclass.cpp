#include "socketclass.h"

SocketClass::SocketClass(QObject *parent):
    QObject(parent),
    socket_state_(CLOSE)
{
}


SocketService *SocketClass::socket_service_(0);

SocketService *SocketClass::GetService()
{
    if(0 == socket_service_)
    {
        socket_service_ = new SocketClass();
    }
    return socket_service_;
}

qint64 SocketClass::ReadFromSocket(QByteArray &byte)
{

}

void SocketClass::WriteToSocket(QByteArray &byte)
{

}

bool SocketClass::OpenSocket(MainWindow *mw)
{
    if(0 == my_socket_)
    {
        my_socket_ = new QTcpSocket();
    }

    //my_socket_->connectToHost("115.159.127.79", 23456);
    my_socket_->connectToHost("115.159.120.160", 9527);
    qDebug() << "sock1";
    if(my_socket_->waitForConnected())
    {
        socket_state_ = OPEN;
        connect(my_socket_, SIGNAL(readyRead()), mw, SLOT(ReadSocket()));
        //qDebug() << "sock2";
        return true;
    }

    return false;


}

bool SocketClass::CloseSocket()
{
    if(my_socket_ && socket_state_ == OPEN)
    {
        my_socket_->close();
        if(my_socket_->waitForDisconnected())
        {
            socket_state_ = CLOSE;
        }
    }
}

void SocketClass::ReleaseSocket()
{
    if(my_socket_)
    {
        delete my_socket_;
    }
    my_socket_ = 0;
}





