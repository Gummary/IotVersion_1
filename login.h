#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include <QDebug>
#include <QMessageBox>
#include "key.h"
#include "socketclass.h"


namespace Ui {
class Login;
}

class Login : public QWidget
{
    Q_OBJECT
    
public:
    explicit Login(QWidget *parent = 0);
    ~Login();

    SocketClass* GetSocketService();

protected:
    bool eventFilter(QObject *, QEvent *);

signals:
    void closeLoginWidget();

private slots:
    void on_Login_Btn_clicked();

    void ReadFromServer(QByteArray,qint64);

private:
    Ui::Login *ui;

    SocketClass *socket_service;
};


extern CKey *keyboard;

#endif // LOGIN_H
