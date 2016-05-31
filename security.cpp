#include "security.h"
#include "socketclass.h"

Security::Security()
{
    status = CLOSE;
    people_status = false;
}

void Security::WriteToSerial(const QByteArray &)
{

}

qint8 Security::GetID(qint8 &id)
{
    return id = 0x05;
}

void Security::HandleSerialMsg(const QByteArray &byte)
{
    Moudle::HandleSerialMsg(byte);

    people_status = byte[5]?true:false;

    if(status == OPEN)
    {
        SocketClass *service = SocketClass::GetSocket();
        service->WriteToSocket(GetSensorInfo());
    }
}

void Security::HandleSocketMsg(qint8 &, qint8 &content)
{
    status = content?OPEN:CLOSE;
}

QByteArray Security::GetSensorInfo()
{
    QString msg;
    msg = "0/5/";
    if(people_status)   msg+="1";
    else    msg +="0";

    return msg.toAscii();

}
