#include "moudleset.h"
#include "temperature.h"
#include "ledandmotor.h"
#include "replays.h"
#include "airirda.h"
#include "smoke.h"
#include "serialclass.h"
#include "ultrasonicandpwm.h"

MoudleSet::MoudleSet()
{
    InitMoudle();
}

void MoudleSet::InitMoudle()
{
    //初始化串口和socket类
    my_serial_service_ = SerialClass::GetService();
    my_serial_service_->CloseCom();
    my_serial_service_->OpenCom();

    my_socket_service_ = SocketClass::GetSocket();
    my_socket_service_->CloseSocket();
    bool state = my_socket_service_->OpenSocket();
    connect(my_socket_service_,SIGNAL(SocketMsg(QByteArray,qint64)), this, SLOT(ReadSocket(QByteArray,qint64)));

    coor_ = new CoorImpl();


    //初始化节点
    int time = READTIME;
    replay_moudle_      = new Replays();
    temp_moudle_        = new Temperature();
    air_moudle_         = new AirIrDA();
    smoke_moudle_       = new Smoke();
    ultra_pwm_moudle_   = new UltrasonicAndPwm();
    moudle_hash_.insert(0x0a, replay_moudle_);
    moudle_hash_.insert(0x02, temp_moudle_);
    moudle_hash_.insert(0x0f, air_moudle_);
    moudle_hash_.insert(0x04, smoke_moudle_);
    moudle_hash_.insert(0x09, ultra_pwm_moudle_);
    moudle_hash_.insert(0x08, ultra_pwm_moudle_);

    QHash<qint8, AbstractMoudle*>::const_iterator it = moudle_hash_.constBegin();
    while(it!=moudle_hash_.constEnd())
    {
        AbstractMoudle *temp = it.value();
        temp->set_serial_service(my_serial_service_);
        temp->set_socket_service(my_socket_service_);
        temp->set_time_cycle(time);
        temp->set_coor((Coordinator*)coor_);
        it++;

        qint8 id;
        temp->GetID(id);
        moudle_status_.insert(id, false);
    }

    //初始化串口定时器
    read_timer_ = new QTimer();
    connect(read_timer_, SIGNAL(timeout()), this, SLOT(ReadTimerOut()));
    read_timer_->start(READTIME);


    connect(coor_, SIGNAL(Status(qint8,bool)), this, SLOT(HandleMoudleStatus(qint8,bool)));
}


/*
  不断从串口读取信息
*/
void MoudleSet::ReadTimerOut()
{
    QByteArray byte;
    qint64 length_ = my_serial_service_->ReadFromSerial(byte);
    if(byte.isEmpty()) return;
    qint8 node = byte[3];
    AbstractMoudle* temp = moudle_hash_.value(node, NULL);
    if(temp!=NULL) temp->HandleSerialMsg(byte);

}

/*
    接收服务器发送的信息，如果节点未连接不予处理
*/

void MoudleSet::ReadSocket(QByteArray byte, qint64 length)
{
    qDebug() << "Receive Form Server : " << byte.toHex();
    char *b = byte.data();
    qint8 node = b[0];
    AbstractMoudle *moudle = moudle_hash_[node];
    if(moudle_status_.value(node, false))
    {
        //qDebug()<< "Read from Socket : " << byte.toHex();
        qint8 m1 = b[1];
        qint8 m2 = b[2];
        moudle->HandleSocketMsg(m1, m2);
        qint8 id;
        moudle->GetID(id);
        //qDebug() << "Moudle ID" <<id;
    }
    else
    {

    }

    CheckMoudleStatus();

}

MoudleSet::~MoudleSet()
{
    my_serial_service_->ReleaseSerial();
    my_socket_service_->ReleaseSocket();
}

void MoudleSet::HandleMoudleStatus(qint8 id, bool status)
{
    moudle_status_[id] = status;
    //qDebug() << id << status;
}

void MoudleSet::CheckMoudleStatus()
{
    QHash<qint8, AbstractMoudle*>::const_iterator it = moudle_hash_.constBegin();
    while(it!=moudle_hash_.constEnd())
    {
        AbstractMoudle *temp = it.value();
        temp->CheckStatus();
        it++;
    }
}
