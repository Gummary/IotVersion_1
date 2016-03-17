#ifndef SERIALSERVICE_H
#define SERIALSERVICE_H
#include <QByteArray>

class CommunicateService
{
public:
    virtual qint64 ReadFromService(QByteArray &byte) = 0;
    virtual void WriteToService(QByteArray &byte) = 0;
    virtual bool OpenSerivce() = 0;
    virtual bool CloseService() = 0;
    virtual void ReleaseService() = 0;
};

#endif // SERIALSERVICE_H
