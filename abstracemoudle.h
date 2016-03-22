#ifndef ABSTRACEMOUDLE_H
#define ABSTRACEMOUDLE_H

#include <QByteArray>
#include <serialservice.h>
#include <socketservice.h>



class Coordinator
{
public:
    virtual void EmitConnected() = 0;
    virtual void EmitDisconnected() = 0;
};

class AbstractMoudle
{
public:
    virtual void GetID(QByteArray &id) = 0;
    virtual void HandleMsg(const QByteArray &msg) = 0;
    virtual void set_serial_service(SerialService *service) = 0;
    virtual void set_socket_service(SocketService *service) = 0;
    virtual void SendMsg(qint8 &cmd) = 0;
    virtual QByteArray GetJson() = 0;
    virtual void CheckStatus() = 0;
    virtual void set_time_cycle(int &cycle) = 0;
protected:
    virtual SerialService * get_serial_service() = 0;
};

#endif // ABSTRACEMOUDLE_H
