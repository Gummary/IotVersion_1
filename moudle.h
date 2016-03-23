#ifndef MOUDLE_H
#define MOUDLE_H

#include <QObject>
#include <QByteArray>
#include <QDebug>
#include "abstracemoudle.h"

#define MOUDLEDEADLINE 5000

class Moudle : public QObject, public AbstractMoudle
{
    Q_OBJECT
public:
    explicit Moudle(QObject *parent = 0);

    virtual void HandleMsg(const QByteArray &msg);

    virtual void set_coor(Coordinator *coor);

    virtual void set_serial_service(SerialService *service);

    virtual void set_socket_service(SocketClass *service);

    virtual void CheckStatus();

    virtual void GetID(QByteArray &id) = 0;

    virtual void SendMsg(qint8 &cmd) = 0;

    virtual QByteArray GetJson() = 0;

    virtual void set_time_cycle(int &timecycle);
signals:

    
public slots:

protected:
    virtual SerialService *get_serial_service();
    virtual SocketClass *get_socket_service();

    unsigned char Varify (unsigned char  *date, unsigned short len);
private:
    SerialService *serial_service_;
    SocketClass *socket_serivce_;
    Coordinator *coor_;
    int count_;
    static int time_cycle_;
    
};

#endif // MOUDLE_H
