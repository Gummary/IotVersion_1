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
    qDebug() << "gg1";

    my_socket_service_ = SocketClass::GetService();
    qDebug() << "gg2";
    my_socket_service_->CloseSocket();
    qDebug() << "gg3";
    bool state = my_socket_service_->OpenSocket(this);
    qDebug() << state;

    read_timer_ = new QTimer();
    connect(read_timer_, SIGNAL(timeout()), this, SLOT(ReadTimerOut()));
    read_timer_->start(READTIME);

}

MainWindow::~MainWindow()
{
    my_serial_service_->ReleaseSerial();
    delete ui;
}

void MainWindow::ReadTimerOut()
{
    //读取串口消息
    QByteArray byte;
    qint64 length_ = my_serial_service_->ReadFromSerial(byte);

}

void MainWindow::ReadSocket()
{
    QByteArray byte;

}
