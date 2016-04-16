#include "smoke.h"
#include "socketclass.h"

Smoke::Smoke():
    smoke_state_(false)
{
}


void Smoke::WriteToSerial(const QByteArray &byte)
{

}

void Smoke::GetID(QByteArray &id)
{
    id.append("0x04");
}

void Smoke::HandleMsg(const QByteArray &byte)
{
    Moudle::HandleMsg(byte);
    if(byte[5] == 0x01)
    {
        smoke_state_ = true;
        qDebug() << "Have Smoke";
    }
    else
    {
        qDebug() << "Smoke disapper";
        smoke_state_ = false;
    }

    QByteArray json_msg = GetJson();
    SocketClass* service = get_socket_service();
    service->WriteToSocket(json_msg);
}

void Smoke::SendMsg(qint8 &, qint8 &)
{

}

QByteArray Smoke::GetJson()
{
    using namespace std;
    Json::Value root;
    root["ID"] = "4";
    if(smoke_state_)
        root["STATE"] = "TRUE";
    else
        root["STATE"] = "FALSE";

    std::string out = root.toStyledString();
    const char* status = out.c_str();
    return QByteArray((char*)status);
}
