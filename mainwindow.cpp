#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "temperature.h"
#include "ledandmotor.h"
#include "replays.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    c = new Clock(ui->ClockWidget);
    c->show();

    this->showFullScreen();

    my_serial_service_ = SerialClass::GetService();
    my_serial_service_->CloseCom();
    my_serial_service_->OpenCom();

    my_socket_service_ = SocketClass::GetSocket();
    my_socket_service_->CloseSocket();
    bool state = my_socket_service_->OpenSocket();
    connect(my_socket_service_,SIGNAL(SocketMsg(QByteArray,qint64)), this, SLOT(ReadSocket(QByteArray,qint64)));

    int time = READTIME;
    led_moudle_ = new LedAndMotor();
    led_moudle_->set_serial_service(my_serial_service_);
    led_moudle_->set_socket_service(my_socket_service_);
    led_moudle_->set_time_cycle(time);

    temp_moudle_ = new Temperature();
    temp_moudle_->set_serial_service(my_serial_service_);
    temp_moudle_->set_socket_service(my_socket_service_);
    temp_moudle_->set_time_cycle(time);

    replay_moudle_ = new Replays();
    replay_moudle_->set_serial_service(my_serial_service_);
    replay_moudle_->set_socket_service(my_socket_service_);
    replay_moudle_->set_time_cycle(time);



    read_timer_ = new QTimer();
    connect(read_timer_, SIGNAL(timeout()), this, SLOT(ReadTimerOut()));
    read_timer_->start(READTIME);

}

MainWindow::~MainWindow()
{
    my_serial_service_->ReleaseSerial();
    my_socket_service_->ReleaseSocket();
    delete ui;
}

void MainWindow::ReadTimerOut()
{
    //读取串口消息
    QByteArray byte;
    qint64 length_ = my_serial_service_->ReadFromSerial(byte);
    char *msg = byte.data();
    if(msg[3] == 0x06) led_moudle_->HandleMsg(byte);
    if(msg[3] == 0x02) temp_moudle_->HandleMsg(byte);
    if(msg[3] == 0x0A) replay_moudle_->HandleMsg(byte);
}

void MainWindow::ReadSocket(QByteArray byte, qint64 length)
{
    qDebug()<<byte;
    qint8 msg = 0x00;


    if(byte[0] == 0x0a)
    {
        char id = (char)byte[1];
        if(id == 1)
        {
            if(byte[2] == 1)    msg = 1;
            else                msg = 2;
        }
        else if(id == 2)
        {
            if(byte[2] == 1)    msg = 3;
            else                msg = 4;
        }
        else if(id == 3)
        {
            if(byte[2] == 1)    msg = 5;
            else                msg = 6;
        }
        else if(id == 4)
        {
            if(byte[2] == 1)    msg = 7;
            else                msg = 8;
        }
    }
    replay_moudle_->SendMsg(msg);
}


void MainWindow::on_OPEN_clicked()
{
    qint8 msg = 1;
    replay_moudle_->SendMsg(msg);
}

void MainWindow::on_CLOSE_clicked()
{
    qint8 msg = 2;
    replay_moudle_->SendMsg(msg);
}
