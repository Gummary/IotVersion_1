#include "key.h"
#include <qpushbutton.h>
#include <qlayout.h>
#include <QKeyEvent>
#include <QEvent>
#include <QCoreApplication>
#include <QApplication>
#include "login.h"
QWidget *pFocusWidget;
bool CKey::bUpper = false;
char CKey::keyCode[CKey::KEY_NUM] = {
    '0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
    '_',
    '\b',
    ' ',
    '\r',
    ' ',
    'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J',
    'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T',
    'U', 'V', 'W', 'X', 'Y', 'Z',
};

/*#define  KEY_WIDTH1                       50
#define  KEY_HEIGHT                       46
#define  KEY_HEIGHT1                      50
#define  KEY_WIDTH2                       70
#define  KEY_WIDTH3                       130
#define  KEY_WIDTH4                       290
#define  KEY_INTERVAL_COL_WIDTH           10
#define  KEY_INTERVAL_ROW_HEIGHT          5
#define  KEY_TOP_MARGIN                   3
#define  KEY_LEFT_MARGIN                  5
#define  SPECIAL_ROW_OFFSET               35*/



CKey::CKey(QWidget *parent) : QWidget(parent, Qt::Tool | Qt::WindowStaysOnTopHint | Qt::FramelessWindowHint)
{
    //this->setContentsMargins(4, 6, 0, 0);
    QPalette pal = palette();
    pal.setBrush(backgroundRole(), QBrush(QImage(":image/button/keyboard")));
    setPalette(pal);
    //setFixedSize(600, 260);
    setFixedSize(400, 172);
    for (int i = 0; i < KEY_NUM; i++)
    {
        ppbKey[i] = new QPushButton(this);
        ppbKey[i]->setFocusPolicy(Qt::NoFocus);
        if (i == KEY_BACK || i == KEY_UPPER)
        {
            ppbKey[i]->setStyleSheet("QPushButton {font:12pt;border-image:url(:/image/button/button2.png);}\
                                     QPushButton:hover {\
                                                        border-image:url(:/image/button/hoverbutton2.png);\
                                                        border-style:outset;\
                                                        background-attachment:fixed;\
                                                    }");
            ppbKey[i]->setFixedSize(KEY_WIDTH2, KEY_HEIGHT);
        }
        else if (i == KEY_DOT || i== KEY_RETURN)
        {
            ppbKey[i]->setStyleSheet("QPushButton {font:12pt;border-image:url(:/image/button/button3.png);}\
                                     QPushButton:hover {\
                                                        border-image:url(:/image/button/hoverbutton3.png);\
                                                        border-style:outset;\
                                                        background-attachment:fixed;\
                                                    }");
            ppbKey[i]->setFixedSize(KEY_WIDTH3, KEY_HEIGHT1);
        }
        else if (i == KEY_SPACE)
        {
            ppbKey[i]->setFixedSize(KEY_WIDTH4, KEY_HEIGHT1);
            ppbKey[i]->setStyleSheet("QPushButton {font:12pt;border-image:url(:/image/button/button4.png);}\
                                     QPushButton:hover {\
                                                        border-image:url(:/image/button/hoverbutton4.png);\
                                                        border-style:outset;\
                                                        background-attachment:fixed;\
                                                    }");
        }
        else
        {
            ppbKey[i]->setStyleSheet("QPushButton {font:12pt;border-image:url(:/image/button/button1.png);}\
                                     QPushButton:hover {\
                                                        border-image:url(:/image/button/hoverbutton1.png);\
                                                        border-style:outset;\
                                                        background-attachment:fixed;\
                                                    }");
            ppbKey[i]->setFixedSize(KEY_WIDTH1, KEY_HEIGHT);
        }
        ppbKey[i]->setFlat(true);
        connect(ppbKey[i], SIGNAL(clicked()), this, SLOT(rxClicked()));
    }
    updateKeyText();

    connect(this, SIGNAL(characterGenerated(QChar)), SLOT(sendCharacter(QChar)));


    QHBoxLayout *phLayout = new QHBoxLayout;
    phLayout->addSpacing(KEY_LEFT_MARGIN);
    phLayout->addWidget(ppbKey[KEY_1]);
    phLayout->addSpacing(KEY_INTERVAL_COL_WIDTH);
    phLayout->addWidget(ppbKey[KEY_2]);
    phLayout->addSpacing(KEY_INTERVAL_COL_WIDTH);
    phLayout->addWidget(ppbKey[KEY_3]);
    phLayout->addSpacing(KEY_INTERVAL_COL_WIDTH);
    phLayout->addWidget(ppbKey[KEY_4]);
    phLayout->addSpacing(KEY_INTERVAL_COL_WIDTH);
    phLayout->addWidget(ppbKey[KEY_5]);
    phLayout->addSpacing(KEY_INTERVAL_COL_WIDTH);
    phLayout->addWidget(ppbKey[KEY_6]);
    phLayout->addSpacing(KEY_INTERVAL_COL_WIDTH);
    phLayout->addWidget(ppbKey[KEY_7]);
    phLayout->addSpacing(KEY_INTERVAL_COL_WIDTH);
    phLayout->addWidget(ppbKey[KEY_8]);
    phLayout->addSpacing(KEY_INTERVAL_COL_WIDTH);
    phLayout->addWidget(ppbKey[KEY_9]);
    phLayout->addSpacing(KEY_INTERVAL_COL_WIDTH);
    phLayout->addWidget(ppbKey[KEY_0]);
    phLayout->setSpacing(0);
    QVBoxLayout *pvLayout = new QVBoxLayout;
    pvLayout->addSpacing(KEY_TOP_MARGIN);
    pvLayout->addLayout(phLayout);
    pvLayout->addSpacing(KEY_INTERVAL_ROW_HEIGHT);

    phLayout = new QHBoxLayout;
    phLayout->addSpacing(KEY_LEFT_MARGIN);
    phLayout->addWidget(ppbKey[KEY_Q]);
    phLayout->addSpacing(KEY_INTERVAL_COL_WIDTH);
    phLayout->addWidget(ppbKey[KEY_W]);
    phLayout->addSpacing(KEY_INTERVAL_COL_WIDTH);
    phLayout->addWidget(ppbKey[KEY_E]);
    phLayout->addSpacing(KEY_INTERVAL_COL_WIDTH);
    phLayout->addWidget(ppbKey[KEY_R]);
    phLayout->addSpacing(KEY_INTERVAL_COL_WIDTH);
    phLayout->addWidget(ppbKey[KEY_T]);
    phLayout->addSpacing(KEY_INTERVAL_COL_WIDTH);
    phLayout->addWidget(ppbKey[KEY_Y]);
    phLayout->addSpacing(KEY_INTERVAL_COL_WIDTH);
    phLayout->addWidget(ppbKey[KEY_U]);
    phLayout->addSpacing(KEY_INTERVAL_COL_WIDTH);
    phLayout->addWidget(ppbKey[KEY_I]);
    phLayout->addSpacing(KEY_INTERVAL_COL_WIDTH);
    phLayout->addWidget(ppbKey[KEY_O]);
    phLayout->addSpacing(KEY_INTERVAL_COL_WIDTH);
    phLayout->addWidget(ppbKey[KEY_P]);
    phLayout->setSpacing(0);
    pvLayout->addLayout(phLayout);
    pvLayout->addSpacing(KEY_INTERVAL_ROW_HEIGHT);

    phLayout = new QHBoxLayout;
    phLayout->addSpacing(SPECIAL_ROW_OFFSET);
    phLayout->addWidget(ppbKey[KEY_A]);
    phLayout->addSpacing(KEY_INTERVAL_COL_WIDTH);
    phLayout->addWidget(ppbKey[KEY_S]);
    phLayout->addSpacing(KEY_INTERVAL_COL_WIDTH);
    phLayout->addWidget(ppbKey[KEY_D]);
    phLayout->addSpacing(KEY_INTERVAL_COL_WIDTH);
    phLayout->addWidget(ppbKey[KEY_F]);
    phLayout->addSpacing(KEY_INTERVAL_COL_WIDTH);
    phLayout->addWidget(ppbKey[KEY_G]);
    phLayout->addSpacing(KEY_INTERVAL_COL_WIDTH);
    phLayout->addWidget(ppbKey[KEY_H]);
    phLayout->addSpacing(KEY_INTERVAL_COL_WIDTH);
    phLayout->addWidget(ppbKey[KEY_J]);
    phLayout->addSpacing(KEY_INTERVAL_COL_WIDTH);
    phLayout->addWidget(ppbKey[KEY_K]);
    phLayout->addSpacing(KEY_INTERVAL_COL_WIDTH);
    phLayout->addWidget(ppbKey[KEY_L]);
    phLayout->addSpacing(SPECIAL_ROW_OFFSET);
    phLayout->setSpacing(0);
    pvLayout->addLayout(phLayout);
    pvLayout->addSpacing(KEY_INTERVAL_ROW_HEIGHT);

    phLayout = new QHBoxLayout;
    phLayout->addSpacing(KEY_LEFT_MARGIN);
    phLayout->addWidget(ppbKey[KEY_UPPER]);
    phLayout->addSpacing(KEY_INTERVAL_COL_WIDTH);
    phLayout->addWidget(ppbKey[KEY_Z]);
    phLayout->addSpacing(KEY_INTERVAL_COL_WIDTH);
    phLayout->addWidget(ppbKey[KEY_X]);
    phLayout->addSpacing(KEY_INTERVAL_COL_WIDTH);
    phLayout->addWidget(ppbKey[KEY_C]);
    phLayout->addSpacing(KEY_INTERVAL_COL_WIDTH);
    phLayout->addWidget(ppbKey[KEY_V]);
    phLayout->addSpacing(KEY_INTERVAL_COL_WIDTH);
    phLayout->addWidget(ppbKey[KEY_B]);
    phLayout->addSpacing(KEY_INTERVAL_COL_WIDTH);
    phLayout->addWidget(ppbKey[KEY_N]);
    phLayout->addSpacing(KEY_INTERVAL_COL_WIDTH);
    phLayout->addWidget(ppbKey[KEY_M]);
    phLayout->addSpacing(KEY_INTERVAL_COL_WIDTH);
    phLayout->addWidget(ppbKey[KEY_BACK]);
    phLayout->setSpacing(0);
    pvLayout->addLayout(phLayout);
    pvLayout->addSpacing(KEY_INTERVAL_ROW_HEIGHT);

    phLayout = new QHBoxLayout;
    phLayout->addSpacing(KEY_LEFT_MARGIN);
    phLayout->addWidget(ppbKey[KEY_DOT]);
    phLayout->addSpacing(KEY_INTERVAL_COL_WIDTH);
    phLayout->addWidget(ppbKey[KEY_SPACE]);
    phLayout->addSpacing(KEY_INTERVAL_COL_WIDTH);
    phLayout->addWidget(ppbKey[KEY_RETURN]);
    phLayout->setSpacing(0);
    pvLayout->addLayout(phLayout);

    pvLayout->setSpacing(0);
    setLayout(pvLayout);
    pFocusWidget = QApplication::focusWidget();


}

CKey::~CKey()
{

}

void CKey::rxClicked()
{
    QObject *pObj = sender();
    for (int i = 0; i < KEY_NUM; i++)
    {
        if (ppbKey[i] == pObj)
        {
            if (i <= KEY_UPPER)
            {
                if (i == KEY_UPPER)
                {
                    bUpper = !bUpper;
                    updateAlphaKeyText();
                }
                else
                {
                     emit characterGenerated(keyCode[i]);
                }
            }
            else
            {
                int keyValue = keyCode[i];
                if (!bUpper)
                {
                    if (i != KEY_BACK)
                        keyValue += 'a' - 'A';
                }
                emit characterGenerated(keyValue);
            }
            break;
        }
    }
}

void CKey::updateAlphaKeyText()
{
    if (bUpper)
    {
        ppbKey[KEY_A]->setText("A");
        ppbKey[KEY_B]->setText("B");
        ppbKey[KEY_C]->setText("C");
        ppbKey[KEY_D]->setText("D");
        ppbKey[KEY_E]->setText("E");
        ppbKey[KEY_F]->setText("F");

        ppbKey[KEY_G]->setText("G");
        ppbKey[KEY_H]->setText("H");
        ppbKey[KEY_I]->setText("I");
        ppbKey[KEY_J]->setText("J");
        ppbKey[KEY_K]->setText("K");
        ppbKey[KEY_L]->setText("L");

        ppbKey[KEY_M]->setText("M");
        ppbKey[KEY_N]->setText("N");
        ppbKey[KEY_O]->setText("O");
        ppbKey[KEY_P]->setText("P");
        ppbKey[KEY_Q]->setText("Q");
        ppbKey[KEY_R]->setText("R");

        ppbKey[KEY_S]->setText("S");
        ppbKey[KEY_T]->setText("T");
        ppbKey[KEY_U]->setText("U");
        ppbKey[KEY_V]->setText("V");
        ppbKey[KEY_W]->setText("W");
        ppbKey[KEY_X]->setText("X");

        ppbKey[KEY_Y]->setText("Y");
        ppbKey[KEY_Z]->setText("Z");
        ppbKey[KEY_UPPER]->setText("Caps");
    }
    else
    {
        ppbKey[KEY_A]->setText("a");
        ppbKey[KEY_B]->setText("b");
        ppbKey[KEY_C]->setText("c");
        ppbKey[KEY_D]->setText("d");
        ppbKey[KEY_E]->setText("e");
        ppbKey[KEY_F]->setText("f");

        ppbKey[KEY_G]->setText("g");
        ppbKey[KEY_H]->setText("h");
        ppbKey[KEY_I]->setText("i");
        ppbKey[KEY_J]->setText("j");
        ppbKey[KEY_K]->setText("k");
        ppbKey[KEY_L]->setText("l");

        ppbKey[KEY_M]->setText("m");
        ppbKey[KEY_N]->setText("n");
        ppbKey[KEY_O]->setText("o");
        ppbKey[KEY_P]->setText("p");
        ppbKey[KEY_Q]->setText("q");
        ppbKey[KEY_R]->setText("r");

        ppbKey[KEY_S]->setText("s");
        ppbKey[KEY_T]->setText("t");
        ppbKey[KEY_U]->setText("u");
        ppbKey[KEY_V]->setText("v");
        ppbKey[KEY_W]->setText("w");
        ppbKey[KEY_X]->setText("x");

        ppbKey[KEY_Y]->setText("y");
        ppbKey[KEY_Z]->setText("z");
        ppbKey[KEY_UPPER]->setText("Caps");
    }
}

void CKey::updateKeyText()
{
    updateAlphaKeyText();
    ppbKey[KEY_0]->setText("0");
    ppbKey[KEY_1]->setText("1");
    ppbKey[KEY_2]->setText("2");
    ppbKey[KEY_3]->setText("3");
    ppbKey[KEY_4]->setText("4");
    ppbKey[KEY_5]->setText("5");

    ppbKey[KEY_6]->setText("6");
    ppbKey[KEY_7]->setText("7");
    ppbKey[KEY_8]->setText("8");
    ppbKey[KEY_9]->setText("9");
    ppbKey[KEY_BACK]->setText("Back");
    ppbKey[KEY_DOT]->setText("_");
    ppbKey[KEY_SPACE]->setText("Space");
    ppbKey[KEY_RETURN]->setText("Close");
}

void CKey::sendCharacter(QChar character)
{
    if (pFocusWidget != NULL)
    {
        if (character.toAscii() == '\b')
        {
            QKeyEvent keyPress(QEvent::KeyPress, Qt::Key_Backspace, Qt::NoModifier, QString());
            QCoreApplication::sendEvent(pFocusWidget, &keyPress);

            QKeyEvent keyRelease(QEvent::KeyRelease, Qt::Key_Backspace, Qt::NoModifier, QString());
            QCoreApplication::sendEvent(pFocusWidget, &keyRelease);
        }
        else if (character.toAscii() == '\r')
        {
            QKeyEvent keyPress(QEvent::KeyPress, Qt::Key_Enter, Qt::NoModifier, QString());
            QCoreApplication::sendEvent(pFocusWidget, &keyPress);

            QKeyEvent keyRelease(QEvent::KeyRelease, Qt::Key_Enter, Qt::NoModifier, QString());
            QCoreApplication::sendEvent(pFocusWidget, &keyRelease);
            pFocusWidget->clearFocus();

            keyboard->hide();

            //emit txPopupKeyboard(false);
            //startMyTimer(false);
        }
        else
        {
            QKeyEvent keyPress(QEvent::KeyPress, character.unicode(), Qt::NoModifier, QString(character));
            QCoreApplication::sendEvent(pFocusWidget, &keyPress);

            QKeyEvent keyRelease(QEvent::KeyRelease, character.unicode(), Qt::NoModifier, QString());
            QCoreApplication::sendEvent(pFocusWidget, &keyRelease);
        }

    }
}





