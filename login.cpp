#include "login.h"
#include "ui_login.h"
#include "mainwindow.h"


CKey *keyboard;

Login::Login(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);

    this->showFullScreen();

    keyboard = new CKey;

    socket_service = SocketClass::GetSocket();


    ui->UserName_Edit->installEventFilter(this);
    ui->Passwd_Edit->installEventFilter(this);

    ui->UserName_Edit->setText("ihome_001");
    ui->Passwd_Edit->setText("123");
}

Login::~Login()
{
    delete ui;
}

void Login::on_Login_Btn_clicked()
{
    keyboard->close();

    QString homeid = ui->UserName_Edit->text();
    QString passwd = ui->Passwd_Edit->text();

//    QString homeid = "ihome_001";
//    QString passwd = "123";

    if(socket_service->OpenSocket())
    {
        connect(socket_service,SIGNAL(SocketMsg(QByteArray,qint64)),this,SLOT(ReadFromServer(QByteArray,qint64)));

        QStringList msg;
        msg << "0" << "0" << homeid << passwd;
        QByteArray test = msg.join("/").toAscii();
        qDebug() << test;
        socket_service->WriteToSocket(test);
    }
    else
    {
        qDebug() << "No Internet";
        exit(-1);
    }

}


bool Login::eventFilter(QObject *watched, QEvent *event)
{
    if(watched == ui->UserName_Edit)
    {
        if(event->type() == QEvent::MouseButtonPress)
        {
            keyboard->close();
            delete keyboard;
            keyboard = new CKey;
            keyboard->setGeometry(80, 280, KEY_WIDTH3, KEY_WIDTH4);
            keyboard->show();
        }
    }

    if(watched == ui->Passwd_Edit)
    {
        if(event->type() == QEvent::MouseButtonPress)
        {
            keyboard->close();
            delete keyboard;
            keyboard = new CKey;
            keyboard->setGeometry(80, 280, KEY_WIDTH3, KEY_WIDTH4);
            keyboard->show();
        }
    }

    return QWidget::eventFilter(watched, event);
}


void Login::ReadFromServer(QByteArray msg, qint64 length)
{
    qDebug() << msg.toHex();
    qDebug() << msg.toInt();
    QString temp1("登录失败");
    QString temp2("用户名或密码错误");
    if(msg[0] == 0x40)
    {
        QMessageBox::information(this,temp1,temp2);
        disconnect(socket_service,SIGNAL(SocketMsg(QByteArray,qint64)),this,SLOT(ReadFromServer(QByteArray,qint64)));
        socket_service->ReleaseSocket();

    }
    else if(msg[0] == 0x41)
    {

        this->close();
        emit closeLoginWidget();
    }
    else
    {
        qDebug() << msg.toHex();
    }


}


SocketClass* Login::GetSocketService()
{
    return socket_service;
}
