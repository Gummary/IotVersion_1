#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QDebug>
#include <QByteArray>
#include <QImage>
#include <QPixmap>
#include <QHash>
#include <QPalette>
#include "posix_qextserialport.h"
#include "camerainit.h"

#include "abstracemoudle.h"
#include "serialclass.h"
#include "socketclass.h"
#include "clock.h"
#include "moudleset.h"
#include "wifiset.h"
#include "login.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);

    void SendPicture(unsigned char *);

    ~MainWindow();

private:
    void InitCamera();
    
private slots:

    void on_OPEN_clicked();

    void on_CLOSE_clicked();

    void UpdateCamera();

    void on_wifibtn_clicked();

    void on_Close_Login_Widget();

private:
    Ui::MainWindow *ui;


private:
    MoudleSet *moudle_set_;
    Clock *c;

    Login *login_;

    QImage qimage_;
    QPixmap pixmap_;
    bool pic_write_;
    bool camera_start_;
    QTimer *camera_timer_;

    wifiset *wifi_;
};

#endif // MAINWINDOW_H
