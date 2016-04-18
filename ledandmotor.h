#ifndef LEDANDMOTOR_H
#define LEDANDMOTOR_H

#include <QByteArray>
#include <QDebug>
#include <moudle.h>
#include <serialservice.h>
#include "json/json.h"



class LedAndMotor :public Moudle
{
public:
    explicit LedAndMotor();

    void WriteToSerial(const QByteArray &byte);

    void GetID(qint8 &id);

    void HandleMsg(const QByteArray &byte);

    void SendMsg(qint8 &cmd, qint8 &content);

    QByteArray GetSensorInfo();
    
signals:
    
public slots:

private:


private:    
    static QByteArray msg_;
    bool led_status_[4];
    int motor_status_;

    
};

#endif // LEDANDMOTOR_H
