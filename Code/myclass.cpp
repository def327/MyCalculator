#include "myclass.h"

myclass::myclass(QObject *parent) : QObject (parent)
{
    window = new QWidget;
    txt1 = new QTextEdit;
    txt2 = new QTextEdit;
    btn1 = new QPushButton;
    layout1 = new QHBoxLayout;
    layout2 = new QVBoxLayout;

    window->setWindowTitle("Hello World");

    txt1->setTextColor(Qt::blue);
    txt2->setTextColor(Qt::green);
    txt1->setFrameStyle(Qt::AA_MacDontSwapCtrlAndMeta);
    txt2->setFrameStyle(Qt::AA_MacDontSwapCtrlAndMeta);
    txt1->setFrameStyle(QFrame::Panel);
    txt2->setFrameStyle(QFrame::Panel);
    txt1->setFontUnderline(true);
    txt2->setFontUnderline(true);
    txt1->setFixedHeight(56);
    txt2->setFixedHeight(56);

    layout1->addWidget(txt1);
    layout1->addWidget(txt2);
    layout2->addLayout(layout1);
    layout2->addWidget(btn1);
    window->setLayout(layout2);

    window->show();
    btn1->setText("OK!");

    connect(btn1,SIGNAL(clicked(bool)),this,SLOT(myslot1()));
    connect(this,SIGNAL(mysignal_1(QString)),this,SLOT(myslot2(QString)));    
}


