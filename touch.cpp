#include "touch.h"

Touch::Touch():
    touch_state_(false)
{
}


void Touch::WriteToSerial(const QByteArray &byte)
{

}

qint8 Touch::GetID(qint8 &id)
{
    id=0x07;
}

void Touch::HandleSerialMsg(const QByteArray &byte)
{
    Moudle::HandleSerialMsg(byte);
    if(byte[5] == 0x01)
    {
        touch_state_ = true;
        qDebug() << "Have Touch";
        QByteArray json_msg = GetSensorInfo();
        SocketClass* service = get_socket_service();
        service->WriteToSocket(json_msg);
    }
    else
    {
        if(touch_state_)
        {
//            return;
            qDebug() << "Touch disapper";
//            Touch_state_ = false;
//            QByteArray json_msg = GetSensorInfo();
//            SocketClass* service = get_socket_service();
//            service->WriteToSocket(json_msg);
        }
    }

}

void Touch::SendMsg(qint8 &, qint8 &)
{

}

QByteArray Touch::GetSensorInfo()
{
    QString info;
    info+="0/6";
    return info.toAscii();
}
void Touch::HandleSocketMsg(qint8 &, qint8 &)
{

}
