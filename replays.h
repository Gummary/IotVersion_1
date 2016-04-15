#ifndef REPLAYS_H
#define REPLAYS_H

#include <QByteArray>
#include <QDebug>
#include <moudle.h>
#include <QTimer>
#include <serialservice.h>
#include "json/json.h"



class Replays :public Moudle
{
    Q_OBJECT
public:
    explicit Replays();

    void WriteToSerial(const QByteArray &byte);

    void GetID(QByteArray &id);

    void HandleMsg(const QByteArray &byte);

    void SendMsg(qint8 &cmd, qint8 &content);

    QByteArray GetJson();

signals:

public slots:
    void ConfirmOpen();

private:


private:
    static QByteArray msg_;
    bool replays_status_[4];
    bool pre_status_[4];
    QTimer *confirm_timer_;

};

#endif // REPLAYS_H
