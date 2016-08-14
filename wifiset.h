#ifndef WIFISET_H
#define WIFISET_H

#include <QWidget>
#include <QRegExp>
#include <QDebug>
#include <QFile>
#include <QListWidgetItem>
#include <QIcon>
#include <QPushButton>
#include <QLineEdit>
#include <QLabel>
#include <QMessageBox>
#include "key.h"

#define TESTWIFI

namespace Ui {
class wifiset;
}

class wifiset : public QWidget
{
    Q_OBJECT
    
public:
    explicit wifiset(QWidget *parent = 0);
    ~wifiset();


private:
    void connectToWifi();

    bool eventFilter(QObject *, QEvent *);
    
private slots:
    void on_openwifi_clicked();

    void on_closewifi_clicked();


    void on_wifilist_itemClicked(QListWidgetItem *item);

    void on_connectwifi_clicked();

private:
    Ui::wifiset *ui;

    QString ssid;
    QString wifipwd;
};

extern CKey *keyboard;


#endif // WIFISET_H
