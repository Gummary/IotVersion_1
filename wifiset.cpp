#include "wifiset.h"
#include "ui_wifiset.h"

wifiset::wifiset(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::wifiset)
{
    ui->setupUi(this);

    ui->closewifi->setEnabled(false);
    ui->connectwifi->setEnabled(false);
    ui->label->hide();

}

wifiset::~wifiset()
{
    delete ui;
}

void wifiset::on_openwifi_clicked()
{

    ui->wifipwd->installEventFilter(this);
    ui->label->show();
//    ui->wifipwd->show();

    QString wifinamepattern = "\"(.*)\"";
    QRegExp wnrx(wifinamepattern);

    QString signalpatter = "level=(.*)/";
    QRegExp signalrx(signalpatter);



    ui->openwifi->setEnabled(false);
    ui->closewifi->setEnabled(true);

//    system("ifconfig eth0 down");
    system("ifconfig wlan0 up");


    system("iwlist wlan0 scan | grep -E -e ESSID -e Signal> temp");


    QFile file("temp");

    if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        return ;
    }

    QTextStream in(&file);

    QString essid = in.readLine();
    QString signallevel = in.readLine();
//    ui->listWidget->clear();
    while(!essid.isNull())
    {

        QString wifiname = "";
        QString signal = "";
        if(wnrx.indexIn(essid)!=-1)
        {
            wifiname = wnrx.cap(1);
        }
        if(signalrx.indexIn(signallevel)!=-1)
        {
            signal = signalrx.cap(1);
        }


        int sigstr = signal.toInt();
        QIcon signalicon;
        if(sigstr > 90)
        {
            signalicon.addFile(":/icon/wifi/lv1");
        }
        else if(sigstr > 60 && sigstr < 90)
        {
            signalicon.addFile(":/icon/wifi/lv2");
        }
        else if(sigstr > 40 && sigstr <60)
        {
            signalicon.addFile(":/icon/wifi/lv3");
        }
        else
        {
            signalicon.addFile(":/icon/wifi/lv4");
        }
        if(wifiname != "" && signal != "" && !signalicon.isNull())
            ui->wifilist->addItem(new QListWidgetItem(signalicon,wifiname.toUtf8()));
        essid = in.readLine();
        signallevel = in.readLine();
    }
}

void wifiset::on_closewifi_clicked()
{
    ui->openwifi->setEnabled(true);
    ui->closewifi->setEnabled(false);
    ui->connectwifi->setEnabled(false);
//    system("ifconfig wlan0 down");
    ui->wifilist->clear();


}

void wifiset::on_wifilist_itemClicked(QListWidgetItem *item)
{
    ui->connectwifi->setEnabled(true);
}



void wifiset::on_connectwifi_clicked()
{
    wifipwd = ui->wifipwd->text();
    ssid = ui->wifilist->currentItem()->text();
    connectToWifi();
}


void wifiset::connectToWifi()
{
#ifdef TESTWIFI
    QFile file("/home/user/wpa_supplicant.conf");
#else
    QFile file("/etc/wpa_supplicant.conf");
#endif

    qDebug() << ssid << wifipwd;

   // 保存信息
    if (file.exists())
    {
        if (file.open(QIODevice::ReadWrite))
        {
            QString str;
            int iReadLen = 0;
            char cData[1024];

            iReadLen = file.read(cData, sizeof(cData));
            str = QString(cData).mid(0, iReadLen);

            if (iReadLen > 0)
            {
                int iStart = str.indexOf("ssid", 0);
                int iEnd = str.indexOf("\n", iStart);
                str.replace(iStart + 6, iEnd - iStart - 6 - 1, ssid);

                iStart = str.indexOf("psk", 0);
                if (iStart < 0)
                {
                    iStart = str.indexOf("wep_key0", 0);
                    iEnd = str.indexOf("=", iStart);
                    str.replace(iEnd + 1, 1, "\"");
                    iEnd = str.indexOf("\n", iStart);
                    str.replace(iEnd - 1, 1, "\"");
                    iEnd = str.indexOf("=", iStart);
                    str.replace(iStart, iEnd - iStart, "psk");
                }
                iEnd = str.indexOf("\n", iStart);
                str.replace(iStart + 5, iEnd - iStart - 5 - 1, wifipwd);

                iStart = str.indexOf("scan_ssid", 0);
                iEnd = str.indexOf("\n", iStart);
                if (iStart < 0)
                {
                    iStart = str.indexOf("key_mgmt", 0);
                    iEnd = str.indexOf("\n", iStart);
                    str.replace(iStart, iEnd - iStart, "scan_ssid=1");
                }

                file.resize(0);
                file.write(str.toLocal8Bit().data());
                file.close();
            }
        }
    }

#ifdef TESTWIFI
    //连接wifi
    system("ifconfig eth0 down");
    system("ifconfig wlan0 up");

    QString strCmd;
    QFile fwpa("/home/user/wpa_supplicant.conf");
    if (fwpa.exists())
    {
        system("wpa_supplicant  -Dwext -iwlan0 -c /home/user/wpa_supplicant.conf -dd&");
    }

    sleep(15);
        //DHCP动态ip
    system("killall udhcpc &");
    strCmd = "udhcpc -b -i wlan0";

    system(strCmd.toStdString().c_str());

#endif
    system("ping www.baidu.com -q -c 1 -W 3 -s 8 > /tmp/connStatus");
    QFile fwifi("/tmp/connStatus");
    if (fwifi.exists())
    {
        if (fwifi.open(QIODevice::ReadWrite))
        {
            //QString str;
            int iReadLen = 0;
            char cData[1024];
            iReadLen = fwifi.read(cData, sizeof(cData));

            if (QString(cData).contains("0% packet loss", Qt::CaseInsensitive))
            {
                QMessageBox::information(this, trUtf8("信息"), trUtf8("连接成功！"),
                        QMessageBox::Ok);
            }
            else
            {
                QMessageBox::information(this, trUtf8("信息"), trUtf8("连接失败！"),
                        QMessageBox::Ok);
                system("killall wpa_supplicant");
                fwifi.close();
                return;
            }
        }
    }
    fwifi.close();


    //连接wifi
//    system("ifconfig eth0 down");
//    system("ifconfig wlan0 up");

//    QString strCmd;
//    QFile fwpa("/etc/wpa_supplicant.conf");
//    if (fwpa.exists())
//    {
//        system("wpa_supplicant  -Dwext -iwlan0 -c/etc/wpa_supplicant.conf -dd&");
//    }

//    sleep(15);
//    if(ui->wifi_DHCP->isChecked())
//    {
//        //DHCP动态ip
//        system("killall udhcpc &");
//        strCmd = "udhcpc -b -i wlan0";

//        system(strCmd.toStdString().c_str());
//    }
//    else
//    {
//        //静态ip
//        //IP地址
//        QString str = "ifconfig wlan0 " + g_strIP + " netmask " + g_strNetMask + " up";
//        system(str.toStdString().c_str());

//        //网关
//        str = "route add default gw " + g_strGateWay;

//        system(str.toStdString().c_str());
//    }

//    system("ping www.baidu.com -q -c 1 -W 3 -s 8 > /tmp/connStatus");
//    QFile fwifi("/tmp/connStatus");
//    if (fwifi.exists())
//    {
//        if (fwifi.open(QIODevice::ReadWrite))
//        {
//            //QString str;
//            int iReadLen = 0;
//            char cData[1024];
//            iReadLen = fwifi.read(cData, sizeof(cData));

//            if (QString(cData).contains("0% packet loss", Qt::CaseInsensitive))
//            {
//                QMessageBox::information(this, trUtf8("信息"), trUtf8("连接成功！"),
//                        QMessageBox::Ok);
//            }
//            else
//            {
//                QMessageBox::information(this, trUtf8("信息"), trUtf8("连接失败！"),
//                        QMessageBox::Ok);
//                system("killall wpa_supplicant");
//                fwifi.close();
//                return;
//            }
//        }
//    }
//    fwifi.close();

//    setCursor(Qt::ArrowCursor);
}


bool wifiset::eventFilter(QObject *watched, QEvent *event)
{
    if(watched == ui->wifipwd)
    {
        if(event->type() == QEvent::MouseButtonPress)
        {
            keyboard->close();
            delete keyboard;
            keyboard = new CKey;
            keyboard->setGeometry(0/*640-KEY_WIDTH4*/, 280, KEY_WIDTH3, KEY_WIDTH4);
            keyboard->show();
        }
    }


    return QWidget::eventFilter(watched, event);
}
