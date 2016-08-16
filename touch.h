#ifndef TOUCH_H
#define TOUCH_H

#include "moudle.h"

class Touch : public Moudle
{
public:
    Touch();
    void WriteToSerial(const QByteArray &byte);

    qint8 GetID(qint8 &id);

    void HandleSerialMsg(const QByteArray &byte);

    void HandleSocketMsg(qint8 &, qint8 &);

    QByteArray GetSensorInfo();

private:
    void SendMsg(qint8 &cmd, qint8 &content);

private:
    bool touch_state_;
};

#endif // TOUCH_H
