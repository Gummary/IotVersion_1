#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QDebug>
#include <QByteArray>
#include "posix_qextserialport.h"
#include "serialservice.h"
#include "serialclass.h"
#include "socketservice.h"
#include "socketclass.h"

#define READTIME 1000

namespace Ui {
class MainWindow;
}

class SocketService;

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();


    
private slots:
    void ReadTimerOut();
    static void ReadSocket();

private:
    Ui::MainWindow *ui;
    QTimer *read_timer_;//周期性读取串口的缓冲区
    SerialService *my_serial_service_;
    SocketService *my_socket_service_;

};

#endif // MAINWINDOW_H
