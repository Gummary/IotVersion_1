#ifndef RFIDLOCK_H
#define RFIDLOCK_H
#include "moudle.h"

class RFIDLock : public Moudle
{
public:
    RFIDLock();

    void WriteToSerial(const QByteArray &byte);

    qint8 GetID(qint8 &id);

    void HandleSerialMsg(const QByteArray &byte);

    void HandleSocketMsg(qint8 &, qint8 &);

    QByteArray GetSensorInfo();

private:
    void SendMsg(qint8 &cmd, qint8 &content);

private:
    static QByteArray msg_;

};

#endif // RFIDLOCK_H
