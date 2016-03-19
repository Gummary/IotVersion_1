#ifndef MOUDLE_H
#define MOUDLE_H

#include <QObject>
#include <QByteArray>
#include <QDebug>
#include <abstracemoudle.h>
#include <serialservice.h>

class Moudle : public QObject, public AbstractMoudle
{
    Q_OBJECT
public:
    explicit Moudle(QObject *parent = 0);

    virtual void HandleMsg(const QByteArray &msg);

    virtual void set_coor(Coordinator *coor);

    virtual void set_serial_service(SerialService *service);

    virtual void GetID(QByteArray &id) = 0;

    virtual void SendMsg(qint8 &cmd) = 0;
signals:

    
public slots:

protected:
    virtual SerialService *get_serial_service();

    unsigned char Varify (unsigned char  *date, unsigned short len);
private:
    SerialService *service_;
    Coordinator *coor_;
    
};

#endif // MOUDLE_H
