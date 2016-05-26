#ifndef DETECTUSB_H
#define DETECTUSB_H

#include <QObject>
#include <QString>
#include <QBasicTimer>
#include <QTimerEvent>
#include <QRegExp>
#include <QProcess>
#include <QByteArray>
#include <QDir>
#define UEVENT_BUFFER_SIZE 2048

class DetectUsb : public QObject
{
    Q_OBJECT
public:
    explicit DetectUsb(QObject *parent = 0);
    static int GetSocketFd();
    QString GetDir(QString s);
    
signals:
    void FindUsbDevice(QString usbname);
    void RemoveUsbDevice(QString usbname);

public slots:

private:
    QString ReadDir(QString path);
    static void initSocketFd();
    void timerEvent(QTimerEvent *);
    void MountUsb(QString name);
    void UnMountUsb(QString name);

private:
    static int socket_fd;
    QBasicTimer timer;
    bool findUsb;
};

#endif // DETECTUSB_H
