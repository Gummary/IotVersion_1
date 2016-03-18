#ifndef SOCKETCLASS_H
#define SOCKETCLASS_H

#include <QObject>
#include <QTcpSocket>

class SocketClass : public QObject
{
    Q_OBJECT
public:
    explicit SocketClass(QObject *parent = 0);
    
signals:
    
public slots:

private:
    QTcpSocket *my_socket_;
    enum{OPEN, CLOSE};
    int com_state_;

private:
    qint64 ReadFromSocket(QByteArray &byte);
    void WriteToSocket(QByteArray &byte);
    bool OpenSocket();
    bool CloseSocket();
    void ReleaseSocket();
    
};

#endif // SOCKETCLASS_H
