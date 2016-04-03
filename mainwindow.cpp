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


    pic_write_ = false;
    camera_start_ = false;
    camera_timer_ = new QTimer();
    connect(camera_timer_,SIGNAL(timeout()), this, SLOT(UpdateCamera()));
    deviceOpen();
    deviceInit();



}

MainWindow::~MainWindow()
{
    my_serial_service_->ReleaseSerial();
    my_socket_service_->ReleaseSocket();
    delete ui;
}

void MainWindow::UpdateCamera()
{
    unsigned char image_buf[1536000+54];

    frameRead(image_buf);
    qDebug()<<"image_buf"<<*image_buf<<endl;
    this->qimage_ = QImage::fromData(image_buf,800*480*4+54,NULL);

    pixmap_ = QPixmap::fromImage(this->qimage_, 0);
    ui->labelvideo->setPixmap(this->pixmap_);
    qDebug()<<"start get vedio............................."<<endl;

    if (pic_write_)
    {
        FILE* bmp_f = fopen("a.bmp", "w+");
        fwrite(image_buf, 1, 800*480*4+54, bmp_f);  //debug by liaoxp 2013-11-28
        fclose(bmp_f);
        pic_write_ = false;
        qDebug()<<"take photoshop............................."<<endl;
    }
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
    if(camera_start_)
    {
        camera_start_ = false;
        camera_timer_->stop();
    }
    else
    {
        camera_start_ = true;
        captureStart();
        camera_timer_->start(300);

    }
}

void MainWindow::on_CLOSE_clicked()
{
    //qint8 msg = 2;
    //replay_moudle_->SendMsg(msg);
}
