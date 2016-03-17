#ifndef SERIALCLASS_H
#define SERIALCLASS_H

#include <QObject>
#include <posix_qextserialport.h>
#include "communicateservice.h"

class SerialClass : public QObject, public CommunicateService
{
    Q_OBJECT
public:
    explicit SerialClass(QObject *parent = 0);
    static CommunicateService *GetService();
private://From SerialService
    qint64 ReadFromService(QByteArray &byte);
    void WriteToService(QByteArray &byte);
    bool OpenSerivce();
    bool CloseService();
    void ReleaseService();
    
signals:
    
public slots:

private:
    Posix_QextSerialPort *my_com_;
    static CommunicateService *serial_service_;
    enum{OPEN, CLOSE};
    int com_state_;
};

#endif // SERIALCLASS_H
