#ifndef SOCKETCLASS_H
#define SOCKETCLASS_H

#include <QObject>
#include <QTcpSocket>
#include <QDebug>
#include <socketservice.h>


class SocketClass :public QObject, SocketService
{
    Q_OBJECT
public:
    explicit SocketClass(QObject *parent = 0);

    static SocketService* GetService();
    
signals:
    
public slots:

private:
    static SocketService *socket_service_;
    QTcpSocket *my_socket_;
    enum{OPEN, CLOSE};
    int socket_state_;

private:
    qint64 ReadFromSocket(QByteArray &byte);
    void WriteToSocket(const QByteArray &byte);
    bool OpenSocket(MainWindow *mw);
    bool CloseSocket();
    void ReleaseSocket();    
};

#endif // SOCKETCLASS_H
