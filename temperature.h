#ifndef TEMPERATURE_H
#define TEMPERATURE_H

#include <QByteArray>
#include <QDebug>
#include <moudle.h>
#include "json/json.h"

class Temperature : public Moudle
{
    Q_OBJECT
public:
    Temperature();

    void WriteToSerial(const QByteArray &byte);

    void GetID(qint8 &id);

    void HandleMsg(const QByteArray &byte);

    void SendMsg(qint8 &cmd, qint8 &content);

    QByteArray GetSensorInfo();


private:
    int temperature_;
    int humidity_;
    float light_;
    int time_count_;
};

#endif // TEMPERATURE_H
