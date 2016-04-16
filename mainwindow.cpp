#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "temperature.h"
#include "ledandmotor.h"
#include "replays.h"
#include "airirda.h"
#include "smoke.h"

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
    replay_moudle_ = new Replays();
    temp_moudle_ = new Temperature();
    air_moudle_ = new AirIrDA();
    smoke_moudle_ = new Smoke();
    moudle_hash_.insert(0x0a, replay_moudle_);
    moudle_hash_.insert(0x02, temp_moudle_);
    moudle_hash_.insert(0x0f, air_moudle_);
    moudle_hash_.insert(0x04, smoke_moudle_);


    QHash<qint8, AbstractMoudle*>::const_iterator it = moudle_hash_.constBegin();
    while(it!=moudle_hash_.constEnd())
    {
        AbstractMoudle *temp = it.value();
        temp->set_serial_service(my_serial_service_);
        temp->set_socket_service(my_socket_service_);
        temp->set_time_cycle(time);
        it++;
    }

    read_timer_ = new QTimer();
    connect(read_timer_, SIGNAL(timeout()), this, SLOT(ReadTimerOut()));
    read_timer_->start(READTIME);

    InitCamera();
}

MainWindow::~MainWindow()
{
    my_serial_service_->ReleaseSerial();
    my_socket_service_->ReleaseSocket();
    deviceUninit();
    delete ui;
}

void MainWindow::InitCamera()
{
    pic_write_ = false;
    camera_start_ = false;
    camera_timer_ = new QTimer();
    connect(camera_timer_,SIGNAL(timeout()), this, SLOT(UpdateCamera()));
    deviceOpen();
    deviceInit();
}

void MainWindow::UpdateCamera()
{
    unsigned char image_buf[1536000+54];

    frameRead(image_buf);
    //qDebug()<<"image_buf"<<*image_buf<<endl;
    SendPicture(image_buf);
    this->qimage_ = QImage::fromData(image_buf,800*480*4+54,NULL);


    pixmap_ = QPixmap::fromImage(this->qimage_, 0);
    ui->labelvideo->setPixmap(this->pixmap_);

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
    QByteArray byte;
    qint64 length_ = my_serial_service_->ReadFromSerial(byte);
    if(byte.isEmpty()) return;
    qint8 node = byte[3];
    AbstractMoudle* temp = moudle_hash_.value(node, NULL);
    if(temp!=NULL) temp->HandleMsg(byte);

}

void MainWindow::ReadSocket(QByteArray byte, qint64 length)
{
    char *b = byte.data();
    qint8 node = b[0];
    qDebug()<< "Read from Socket : " << byte.toHex();
    AbstractMoudle *moudle = moudle_hash_[node];
    qint8 m1 = b[1];
    qint8 m2 = b[2];
    moudle->SendMsg(m1, m2);
}


void MainWindow::on_OPEN_clicked()
{
    /*
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

    }*/

}

void MainWindow::on_CLOSE_clicked()
{
    //camera_start_ = false;
    //camera_timer_->stop();
    //qint8 msg = 2;
    //replay_moudle_->SendMsg(msg);
    /*QByteArray m("\x40\x07\x01\x0f\x04\x00\x00", 7);
    char *str = m.data();
    m[6] = Varify((unsigned char *)str, 6);
    SerialService *service = SerialClass::GetService();
    service->WriteToSerial(m);*/
}

void MainWindow::SendPicture(unsigned char *pic)
{
    qDebug()<<"sending pic";
    char *t = (char *)pic;
    QString temp = QString(t);
    using namespace std;
    Json::Value root;
    root["ID"] = "10";
    root["PIC"] = temp.toStdString();

    std::string out = root.toStyledString();
    const char* status = out.c_str();
    my_socket_service_->WriteToSocket(QByteArray((char *)status));
}
