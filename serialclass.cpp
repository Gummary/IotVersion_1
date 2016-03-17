#include "serialclass.h"

SerialClass::SerialClass(QObject *parent) :
    QObject(parent),
    my_com_(0),
    com_state_(CLOSE)
{

}

CommunicateService* SerialClass::serial_service_(0);

CommunicateService *SerialClass::GetService()
{
    if(0 == serial_service_)
    {
        serial_service_ = new SerialClass;
    }
    return serial_service_;
}

qint64 SerialClass::ReadFromService(QByteArray &byte)
{
    if(my_com_&&OPEN == com_state_)
    {
        byte = my_com_->readAll();
        return byte.length();
    }
    return -1;
}

void SerialClass::WriteToService(QByteArray &byte)
{
    if(my_com_&&OPEN == com_state_)
    {
        my_com_->write(byte);
    }
}




bool SerialClass::OpenSerivce()
{
    if(my_com_)
    {
        CloseService();
    }
    else
    {
        QString com_name_ = "/dev/ttySAC1";
        my_com_ = new Posix_QextSerialPort(com_name_, QextSerialBase::Polling);
    }

    my_com_->open(QIODevice::ReadWrite);
    my_com_->setBaudRate(BAUD115200);
    my_com_->setDataBits(DATA_8);
    my_com_->setParity(PAR_NONE);
    my_com_->setStopBits(STOP_1);
    my_com_->setFlowControl(FLOW_OFF);
    my_com_->setTimeout(50);
    com_state_ = OPEN;

    return true;
}

bool SerialClass::CloseService()
{
    if(my_com_&&CLOSE!=com_state_)
    {
        my_com_->close();
    }
    com_state_ = CLOSE;

    return com_state_;
}

void SerialClass::ReleaseService()
{
    if(my_com_)
    {
        CloseService();
        delete my_com_;
        my_com_ = 0;
    }
}
