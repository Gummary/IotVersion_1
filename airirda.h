#ifndef AIRIRDA_H
#define AIRIRDA_H
#include <moudle.h>

class AirIrDA : public Moudle
{
public:
    AirIrDA();

    void WriteToSerial(const QByteArray &byte);

    void GetID(qint8 &id);

    void HandleMsg(const QByteArray &byte);

    void SendMsg(qint8 &cmd, qint8 &content);

    QByteArray GetSensorInfo();
private:
    static QByteArray msg_;
    static qint8 current_temp_;
};

#endif // AIRIRDA_H
