#ifndef ABSTRACEMOUDLE_H
#define ABSTRACEMOUDLE_H

#include <QByteArray>
#include <serialservice.h>

class AbstraceMoudle
{
    virtual void GetID(QByteArray &id) = 0;
    virtual void HandleMsg(const QByteArray &msg) = 0;
    virtual void SetSerialService()
};

#endif // ABSTRACEMOUDLE_H
