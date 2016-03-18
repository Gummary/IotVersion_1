#include "ledandmotor.h"

LedAndMotor::LedAndMotor(QObject *parent) :
    QObject(parent)
{
}


void LedAndMotor::SetSerialService(SerialService *service)
{
    my_service_ = service;
}

void LedAndMotor::GetID(QByteArray &id)
{
    id.append("0x06");
}

void LedAndMotor::HandleMsg(const QByteArry &byte)
{
    Moudle::HandleMsg(byte);


    if ((len == 0x07) && (msg[4]!= 0xaa))
    {
        if ((char)((msg[5] & 0xff) & 0x80) == (char)0x80) {

        }

        if ((char)((msg[5] & 0xff) & 0x80) == (char)0x00) {

        }

        if ((char)((msg[5] & 0xff) & 0x40) == (char)0x40) {

        }

        if ((char)((msg[5] & 0xff) & 0x40) == (char)0x00) {

        }

        if ((char)((msg[5] & 0xff) & 0x20) == (char)0x20) {

        }

        if ((char)((msg[5] & 0xff) & 0x20) == (char)0x00) {

        }

        if ((char)((msg[5] & 0xff) & 0x10) == (char)0x10) {

        }

        if ((char)((msg[5] & 0xff) & 0x10) == (char)0x00) {

        }
        if ((char)((msg[5] & 0xff) & 0x08) == (char)0x08) {

        }

        if ((char)((msg[5] & 0xff) & 0x04) == (char)0x04) {

        }

        if (((char)((msg[5] & 0xff) & 0x08) == (char)0x00) && ((char)((msg[5] & 0xff) & 0x04) == (char)0x00)) {

        }



    }
}
