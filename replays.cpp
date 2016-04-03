#include "replays.h"

Replays::Replays()
{
    for(int i = 0;i<4;i++)
        pre_status_[i] = replays_status_[i] = false;
    confirm_timer_ = new QTimer();
    connect(confirm_timer_,SIGNAL(timeout()),this,SLOT(ConfirmOpen()));
}

QByteArray Replays::msg_("\x40\x07\x01\x0a\x00\x00\xFF", 7);


void Replays::WriteToSerial(const QByteArray &byte)
{
    SerialService *serivce = Moudle::get_serial_service();
    if(0!=serivce)
    {
        serivce->WriteToSerial(byte);
    }
}

void Replays::GetID(QByteArray &id)
{
    id.append("0x0a");
}

void Replays::HandleMsg(const QByteArray &byte)//处理收到的消息
{
    Moudle::HandleMsg(byte);

    qDebug()<<byte.toHex()<<"====";
    int len;
    len = byte[1];
    if (len == 8 && byte[4] != 0xaa)
    {
        if ((char)(0x08 & byte[5])== (char)0x08 && (char)(0x08 & byte[6]) == (char)0x08)
        {
            pre_status_[0] = true;
        }

        if ((char)(0x08 & byte[5])== (char)0x08 && (char)(0x08 & byte[6]) == (char)0x00)
        {
            pre_status_[0] = false;
        }

        if ((char)(0x04 & byte[5])== (char)0x04 && (char)(0x04 & byte[6]) == (char)0x04)
        {
            pre_status_[1] = true;
        }

        if ((char)(0x04 & byte[5])== (char)0x04 && (char)(0x04 & byte[6]) == (char)0x00)
        {
            pre_status_[1] = false;
        }

        if ((char)(0x02 & byte[5])== (char)0x02 && (char)(0x02 & byte[6]) == (char)0x02) {
            pre_status_[2] = true;
        }

        if ((char)(0x02 & byte[5])== (char)0x02 && (char)(0x02 & byte[6]) == (char)0x00) {
            pre_status_[2] = false;
        }

        if ((char)(0x01 & byte[5])== (char)0x01 && (char)(0x01 & byte[6]) == (char)0x01) {
            pre_status_[3] = true;
        }

        if ((char)(0x01 & byte[5])== (char)0x01 && (char)(0x01 & byte[6]) == (char)0x00) {
            pre_status_[3] = false;
        }
    }
}

void Replays::SendMsg(qint8 &cmd)//发送消息
{
    if (1 > cmd || 10 < cmd)
    {
        return ;
    }
    switch(cmd)
    {
        case 1:  //第一个继电器开
            msg_[4] = 0x08;
            msg_[5] = 0x08;
            replays_status_[0] = true;
            qDebug()<<"Open 1";
            break;
        case 2:
            msg_[4] = 0x08;
            msg_[5] = 0x00;
            replays_status_[0] = false;
            qDebug()<<"CLose 1";
            break;
        case 3:   //第二个继电器开
            msg_[4] = 0x04;
            msg_[5] = 0x04;
            replays_status_[1] = true;
            break;
        case 4:
            msg_[4] = 0x04;
            msg_[5] = 0x00;
            replays_status_[1] = false;
            break;
        case 5:   //第三个继电器开
            msg_[4] = 0x02;
            msg_[5] = 0x02;
            replays_status_[2] = true;
            break;
        case 6:
            msg_[4] = 0x02;
            msg_[5] = 0x00;
            replays_status_[2] = false;
            break;
        case 7:   //第四个继电器开
            msg_[4] = 0x01;
            msg_[5] = 0x01;
            replays_status_[3] = true;
            break;
        case 8:
            msg_[4] = 0x01;
            msg_[5] = 0x00;
            replays_status_[3] = false;
            break;
        default:
            break;
    }

    unsigned char var;
    char *str;
    str = msg_.data();
    var = Moudle::Varify((unsigned char *)str, 6);
    msg_[6] = var;
    WriteToSerial(msg_);

    confirm_timer_->start(500);
}

QByteArray Replays::GetJson()
{

}

void Replays::ConfirmOpen()
{
    if(pre_status_[0]!=replays_status_[0]
            ||pre_status_[1]!=replays_status_[1]
            ||pre_status_[2]!=replays_status_[2]
            ||pre_status_[3]!=replays_status_[3])
    {
        WriteToSerial(msg_);
        qDebug()<<"undone";
    }
    else
    {
        confirm_timer_->stop();
        qDebug()<<"done";
    }
}
