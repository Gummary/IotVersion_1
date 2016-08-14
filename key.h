#ifndef _KEY_H
#define _KEY_H

#include <qwidget.h>

#define  KEY_WIDTH1                       33
#define  KEY_HEIGHT                       30
#define  KEY_HEIGHT1                      33
#define  KEY_WIDTH2                       46
#define  KEY_WIDTH3                       86
#define  KEY_WIDTH4                       193
#define  KEY_INTERVAL_COL_WIDTH           6
#define  KEY_INTERVAL_ROW_HEIGHT          3
#define  KEY_TOP_MARGIN                   2
#define  KEY_LEFT_MARGIN                  3
#define  SPECIAL_ROW_OFFSET               23

class QPushButton;
class CKey : public QWidget {
    Q_OBJECT

public:
    enum {KEY_0, KEY_1, KEY_2, KEY_3,
          KEY_4, KEY_5, KEY_6, KEY_7,
          KEY_8, KEY_9,
          KEY_DOT,
          KEY_BACK,
          KEY_SPACE,
          KEY_RETURN,
          KEY_UPPER,

      KEY_A, KEY_B, KEY_C, KEY_D,
      KEY_E, KEY_F, KEY_G, KEY_H,
      KEY_I, KEY_J, KEY_K, KEY_L,
      KEY_M, KEY_N, KEY_O, KEY_P,
      KEY_Q, KEY_R, KEY_S, KEY_T,
      KEY_U, KEY_V, KEY_W, KEY_X,
      KEY_Y, KEY_Z,
      KEY_NUM,};
    CKey(QWidget *parent = NULL);
    ~CKey();


private:
    void updateKeyText();
    void updateAlphaKeyText();

signals:
    void characterGenerated(QChar keyValue);

private slots:
    void rxClicked();
    void sendCharacter(QChar character);

private:
    QPushButton *ppbKey[KEY_NUM];
    static bool bUpper;
    static char keyCode[KEY_NUM];
    QPoint panelStartPos;
    int increment;
};

extern QWidget *pFocusWidget;

#endif
