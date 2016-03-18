#ifndef SOCKETSERVICE_H
#define SOCKETSERVICE_H

#endif // SOCKETSERVICE_H
class SockerService
{
    virtual qint64 ReadFromSocket(QByteArray &byte) = 0;
    virtual void WriteToSocket(QByteArray &byte) = 0;
    virtual bool OpenSocket() = 0;
    virtual bool CloseSocket() = 0;
    virtual void ReleaseSocket() = 0;
};
