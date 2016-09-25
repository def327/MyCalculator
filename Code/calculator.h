

#ifndef CALCULATOR
#define CALCULATOR


#include <QTWidgets>


class Calculator : public QWidget
{
    Q_OBJECT
private:

    ///---Stack for numbers
    QStack<double>stack;

    ///---Conteiners for the first number operand and the second number operand
    double num1;
    double num2;
    double rez;

    ///---QString element using to show what nu,bers you are typing at the display
    QString str;

    ///---If you didn't chose any action opernad(+,- and etc.),this flag help to notice that!
    bool flag_action;

    ///---This flags are watching what kind of operand you have chosen
    bool was_plus;
    bool was_minus;
    bool was_division;
    bool was_multy;

public:    
    explicit Calculator(QWidget *parent = 0);

    ///---Main window------------------------

    //---object of class calculator - the child of QWidget
    ///---Buttons for numbers----------------------------
    QPushButton *btn_numb0;
    QPushButton *btn_numb1;
    QPushButton *btn_numb2;
    QPushButton *btn_numb3;
    QPushButton *btn_numb4;
    QPushButton *btn_numb5;
    QPushButton *btn_numb6;
    QPushButton *btn_numb7;
    QPushButton *btn_numb8;
    QPushButton *btn_numb9;

    ///---Buttons for operands----------------------------
    QPushButton *btn_equal;
    QPushButton *btn_plus;
    QPushButton *btn_minus;
    QPushButton *btn_multy;
    QPushButton *btn_division;
    QPushButton *btn_clear;
    QPushButton *btn_point;
    QPushButton *btn_negative;

    ///---Layouts---------------------------
    QGridLayout *grd;
    QGridLayout *grd2;

    ///---Labels for result-------------------
    QLabel *lbl1;
    QLabel *lbl2;

    ///---Fonts for Label and buttons--------
    QFont *font_lbl;
    QFont *font_btn;

signals:

    void sent_zero(int);
    void sent_one(int);
    void sent_two(int);
    void sent_three(int);
    void sent_four(int);
    void sent_five(int);
    void sent_six(int);
    void sent_seven(int);
    void sent_eight(int);
    void sent_nine(int);

public slots:

///---Slots to sent numbers---------
    void zero();
    void one();
    void two();
    void three();
    void four();
    void five();
    void six();
    void seven();
    void eight();
    void nine();


///--Slots of operations----------------
    void get_number(int);// to put a number into the the stack and display at the Label
    void get_point();    //insert the point
    void get_negative(); //make a number to be negative
    void do_clear();    //to clear all!
    void do_plus();
    void do_minus();
    void do_division();
    void do_multy();
    void do_equal();     //to make '='

///--Slots for events from a keyboard
    void keyPressEvent(QKeyEvent *);
};









#endif // CALCULATOR
