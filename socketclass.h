#ifndef SOCKETCLASS_H
#define SOCKETCLASS_H

#include <QObject>
#include <QTcpSocket>
#include "communicateservice.h"

class SocketClass : public QObject, public CommunicateService
{
    Q_OBJECT
public:
    explicit SocketClass(QObject *parent = 0);
    
signals:
    
public slots:

private:
    static CommunicateService *socket_service_;
    QTcpSocket *my_socket_;
    enum{OPEN, CLOSE};
    int com_state_;

private:
    qint64 ReadFromService(QByteArray &byte);
    void WriteToService(QByteArray &byte);
    bool OpenSerivce();
    bool CloseService();
    void ReleaseService();
    
};

#endif // SOCKETCLASS_H
