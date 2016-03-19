#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    my_serial_service_ = SerialClass::GetService();
    my_serial_service_->CloseCom();
    my_serial_service_->OpenCom();

    my_socket_service_ = SocketClass::GetService();   
    my_socket_service_->CloseSocket();   
    //bool state = my_socket_service_->OpenSocket(this);
    //qDebug() << state;

    led_moudle_ = new LedAndMotor();
    led_moudle_->set_serial_service(my_serial_service_);
    int time = READTIME;
    led_moudle_->set_time_cycle(time);



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
    QByteArray socket_msg = led_moudle_->GetJson();
    my_socket_service_->WriteToSocket(socket_msg);
}

void MainWindow::ReadSocket()
{
    QByteArray byte;
    my_socket_service_->ReadFromSocket(byte);
}

void MainWindow::on_OpenLed1_clicked()
{
    qint8 msg = 0x01;
    led_moudle_->SendMsg(msg);
}

void MainWindow::on_CloseLed1_clicked()
{
    qint8 msg = 0x02;
    led_moudle_->SendMsg(msg);
}
