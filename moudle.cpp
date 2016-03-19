#include "moudle.h"

Moudle::Moudle(QObject *parent) :
    QObject(parent)
{
}

void Moudle::HandleMsg(const QByteArray &)
{
    /*
    if(0!=coor_)
    {
        coor_->EmitConnected();
    }*/
    qDebug() << "Led Connect";
}

void Moudle::set_coor(Coordinator  *coor)
{
    coor_ = coor;
}

void Moudle::set_serial_service(SerialService *service)
{
    service_ = service;
}

SerialService* Moudle::get_serial_service()
{
    return service_;
}


unsigned char Moudle::Varify (unsigned char  *date, unsigned short len )
{
    unsigned char num = 0;
    unsigned short i;
    for (i = 0; i < len; i++)
    {
        num+= date[i];
    }
    return num;
}
