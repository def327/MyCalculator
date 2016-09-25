#ifndef MYCLASS_H
#define MYCLASS_H

#include <QtWidgets>
#include <QString>

class myclass : public QObject
{
    Q_OBJECT

public:
    explicit myclass(QObject *parent = 0);
    QWidget *window;

    QPushButton *btn1;

    QTextEdit *txt1;
    QTextEdit *txt2;

    QHBoxLayout *layout1;
    QVBoxLayout *layout2;


signals:
    void mysignal_1(QString);
public slots:
    void myslot1()
     {
        emit mysignal_1(txt1->toPlainText());// transfer the text are writing to slot 'myslot2(QString str)'
     }
    void myslot2(QString str)
    {
       txt2->setText(str);
       txt1->clear();
    }

};

#endif // MYCLASS_H

