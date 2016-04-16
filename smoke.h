#ifndef SMOKE_H
#define SMOKE_H
#include <QDebug>
#include "moudle.h"
#include "json/json.h"

class Smoke : public Moudle
{
public:
    Smoke();
    void WriteToSerial(const QByteArray &byte);

    void GetID(QByteArray &id);

    void HandleMsg(const QByteArray &byte);

    void SendMsg(qint8 &cmd, qint8 &content);

    QByteArray GetJson();

private:
    bool smoke_state_;
};

#endif // SMOKE_H
