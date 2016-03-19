#ifndef LEDANDMOTOR_H
#define LEDANDMOTOR_H

#include <QObject>
#include <QByteArray>
#include <QDebug>
#include <moudle.h>
#include <serialservice.h>



class LedAndMotor :public Moudle
{
    Q_OBJECT
public:
    explicit LedAndMotor();

    
signals:
    
public slots:

private:
    void WriteToSerial(const QByteArray &byte);

    void GetID(QByteArray &id);

    void HandleMsg(const QByteArray &byte);

    void SendMsg(qint8 &cmd);

private:    
    static QByteArray msg_;
    
};

#endif // LEDANDMOTOR_H
