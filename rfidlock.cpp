#include "rfidlock.h"

RFIDLock::RFIDLock()
{
}

void RFIDLock::WriteToSerial(const QByteArray &byte)
{
    SerialService *serivce = Moudle::get_serial_service();
    serivce->WriteToSerial(byte);
}

QByteArray RFIDLock::msg_("\x40\x06\x01\x12\x01\x00", 6);

qint8 RFIDLock::GetID(qint8 &id)
{
    return id = 0x15;
}

void RFIDLock::HandleSerialMsg(const QByteArray &byte)
{
    Moudle::HandleSerialMsg(byte);

    if((byte[5] == 0x4a)&&(byte[6] == 0xac)&&(byte[7] == 0xbf)&&(byte[8] == 0xd5))
    {
        qDebug() << "Open door via zigbee";
        unsigned char var;
        char *str;
        str = msg_.data();
        var = Moudle::Varify((unsigned char *)str, 5);
        msg_[5] = var;
        WriteToSerial(msg_);
    }
}

void RFIDLock::HandleSocketMsg(qint8 &, qint8 &)
{
    qDebug() << "Open door via Socket";
    unsigned char var;
    char *str;
    str = msg_.data();
    var = Moudle::Varify((unsigned char *)str, 5);
    msg_[5] = var;
    WriteToSerial(msg_);
}

QByteArray RFIDLock::GetSensorInfo()
{

}
