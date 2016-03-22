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

    void GetID(QByteArray &id);

    void HandleMsg(const QByteArray &byte);

    void SendMsg(qint8 &cmd);

    QByteArray GetJson();


private:
    int temperature_;
    int humidity_;
    float light_;
};

#endif // TEMPERATURE_H
