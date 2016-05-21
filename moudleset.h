#ifndef MOUDLESET_H
#define MOUDLESET_H

#include <QTimer>
#include <QObject>
#include <abstracemoudle.h>
#include <QHash>
#include <serialservice.h>
#include <socketclass.h>
#include <coorimpl.h>

#define READTIME 100
class MoudleSet : public QObject
{
    Q_OBJECT
public:
    MoudleSet();
    ~MoudleSet();
    void InitMoudle();

     QHash<qint8, AbstractMoudle*> moudle_hash_;

private slots:
    void ReadTimerOut();

    void ReadSocket(QByteArray byte, qint64 length);

    void HandleMoudleStatus(qint8 id, bool status);

private:
    void CheckMoudleStatus();

private:
    QTimer *read_timer_;//周期性读取串口的缓冲区,并检查节点状态
    SerialService *my_serial_service_;
    SocketClass *my_socket_service_;
    AbstractMoudle *temp_moudle_;
    AbstractMoudle *replay_moudle_;
    AbstractMoudle *air_moudle_;
    AbstractMoudle *smoke_moudle_;
    AbstractMoudle *ultra_pwm_moudle_;
    CoorImpl *coor_;

    QHash<qint8, bool> moudle_status_;
};

#endif // MOUDLESET_H
