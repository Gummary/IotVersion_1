#ifndef MOUDLE_H
#define MOUDLE_H

#include <QObject>
#include <QByteArray>
#include <QDebug>
#include <abstracemoudle.h>
#include <serialservice.h>
#define MOUDLEDEADLINE 5000

class Moudle : public QObject, public AbstractMoudle
{
    Q_OBJECT
public:
    explicit Moudle(QObject *parent = 0);

    virtual void HandleMsg(const QByteArray &msg);

    virtual void set_coor(Coordinator *coor);

    virtual void set_serial_service(SerialService *service);

    virtual void CheckStatus();

    virtual void GetID(QByteArray &id) = 0;

    virtual void SendMsg(qint8 &cmd) = 0;

    virtual QByteArray GetJson() = 0;

    virtual void set_time_cycle(int &timecycle);
signals:

    
public slots:

protected:
    virtual SerialService *get_serial_service();

    unsigned char Varify (unsigned char  *date, unsigned short len);
private:
    SerialService *service_;
    Coordinator *coor_;
    int count_;
    static int time_cycle_;
    
};

#endif // MOUDLE_H
