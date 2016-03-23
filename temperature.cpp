#include "temperature.h"

Temperature::Temperature():
    temperature_(0),
    light_(0),
    humidity_(0)
{
}


void Temperature::WriteToSerial(const QByteArray &)
{

}

void Temperature::GetID(QByteArray &id)
{
    id.append("0x02");
}

void Temperature::HandleMsg(const QByteArray &byte)
{
    unsigned char adc_value[2];

    Moudle::HandleMsg(byte);
    if (0x01 == byte[4])
    {
        temperature_ = (byte[5] << 8) + byte[6];//计算温度值公式
        humidity_ = (byte[7] << 8) + byte[8];//计算湿度值公式

        adc_value[0] = byte[10];
        adc_value[1] = byte[9];
        adc_value[0] = adc_value[0] >> 2;
        light_ = (adc_value[1]*256 + adc_value[0]) * 3.3 / 8192;
        light_ = light_ / 4;
        light_ = light_ * 913;
    }
    QByteArray json_msg = GetJson();
    SocketClass* service = get_socket_service();
    service->WriteToSocket(json_msg);
}

void Temperature::SendMsg(qint8 &)
{

}

QByteArray Temperature::GetJson()
{
    QString temp;
    using namespace std;
    Json::Value root;
    root["ID"] = "6";

    temp = QString::number(temperature_);
    root["TEMPERATURE"] = temp.toStdString();

    temp = QString::number(humidity_);
    root["HUMBILITY"] = temp.toStdString();

    temp = QString::number(light_,'f',1);
    root["LIGHT"] = temp.toStdString();

    std::string out = root.toStyledString();
    const char* status = out.c_str();
    return QByteArray((char*)status);
}
