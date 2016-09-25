#include "calculator.h"

Calculator::Calculator(QWidget *parent):QWidget(parent)
{
    ///---Conteiners for the first number operand and the second number operand
    num1=0;
    num2=0;
    rez=0;

    ///---If you didn't chose any action opernad(+,- and etc.),this flag help to notice that!
    flag_action=false;

    ///---This flags are watching what kind of operand you have chosen
    was_plus=false;
    was_minus=false;
    was_division=false;
    was_multy=false;

    ///---Buttons---------------------------
    btn_equal = new QPushButton;
    btn_plus = new QPushButton;
    btn_minus = new QPushButton;
    btn_division = new QPushButton;
    btn_multy = new QPushButton;
    btn_clear = new QPushButton;
    btn_point = new QPushButton;
    btn_negative = new QPushButton;

    ///---Layouts---------------------------
    grd = new QGridLayout;
    grd2 = new QGridLayout;

    ///---Labels for result-------------------
    lbl1 = new QLabel;
    lbl1->setStyleSheet("background-color: white");
    lbl1->setFixedSize(375,50);
    lbl1->setFrameStyle(QFrame::Panel);

    lbl2 = new QLabel;
    lbl2->setStyleSheet("background-color: white");
    lbl2->setFixedSize(375,50);
    lbl2->setFrameStyle(QFrame::Panel);

    ///---Font for Lables---------------------
    font_lbl = new QFont;
    font_lbl->setPointSize(20);   
    lbl1->setFont((*font_lbl));
    lbl2->setFont((*font_lbl));

    ///---Font for the Buttons-------------------
    font_btn = new QFont;
    font_btn->setPointSize(15);

    ///---Make the GUI of a calculator
    btn_numb0 = new QPushButton;
    btn_numb1 = new QPushButton;
    btn_numb2 = new QPushButton;
    btn_numb3 = new QPushButton;
    btn_numb4 = new QPushButton;
    btn_numb5 = new QPushButton;
    btn_numb6 = new QPushButton;
    btn_numb7 = new QPushButton;
    btn_numb8 = new QPushButton;
    btn_numb9 = new QPushButton;

    ///---Make the font for buttons-----------------------------------
    btn_numb0->setFont(*font_btn);
    btn_numb1->setFont(*font_btn);
    btn_numb2->setFont(*font_btn);
    btn_numb3->setFont(*font_btn);
    btn_numb4->setFont(*font_btn);
    btn_numb5->setFont(*font_btn);
    btn_numb6->setFont(*font_btn);
    btn_numb7->setFont(*font_btn);
    btn_numb8->setFont(*font_btn);
    btn_numb9->setFont(*font_btn);
    btn_equal->setFont(*font_btn);
    btn_plus->setFont(*font_btn);
    btn_minus->setFont(*font_btn);
    btn_division->setFont(*font_btn);
    btn_multy->setFont(*font_btn);
    btn_clear->setFont(*font_btn);
    btn_point->setFont(*font_btn);
    btn_negative->setFont(*font_btn);
    ///----------------------------------------------------------

    btn_numb0->setText("0");
    btn_numb1->setText("1");
    btn_numb2->setText("2");
    btn_numb3->setText("3");
    btn_numb4->setText("4");
    btn_numb5->setText("5");
    btn_numb6->setText("6");
    btn_numb7->setText("7");
    btn_numb8->setText("8");
    btn_numb9->setText("9");

    grd->addWidget(btn_point,3,2);
    grd->addWidget(btn_clear,3,1);
    grd->addWidget(btn_numb0,3,0);
    grd->addWidget(btn_numb1,2,0);
    grd->addWidget(btn_numb2,2,1);
    grd->addWidget(btn_numb3,2,2);
    grd->addWidget(btn_numb4,1,0);
    grd->addWidget(btn_numb5,1,1);
    grd->addWidget(btn_numb6,1,2);
    grd->addWidget(btn_numb7,0,0);
    grd->addWidget(btn_numb8,0,1);
    grd->addWidget(btn_numb9,0,2);
    grd->addWidget(btn_plus,0,3);
    grd->addWidget(btn_minus,1,3);
    grd->addWidget(btn_multy,0,4);
    grd->addWidget(btn_equal,3,3,1,2);
    grd->addWidget(btn_division,1,4);
    grd->addWidget(btn_negative,2,3,1,2);

    btn_clear->setText("CE");
    btn_equal->setText("=");
    btn_plus->setText("+");
    btn_minus->setText("-");
    btn_division->setText("/");
    btn_multy->setText("*");
    btn_point->setText(".");
    btn_negative->setText("±");

    grd2->addWidget(lbl2,0,0);
    grd2->addWidget(lbl1,1,0);
    grd2->addLayout(grd,2,0);
    grd2->setSpacing(4);


    lbl1->setAlignment(Qt::AlignRight|Qt::AlignCenter);
    lbl2->setAlignment(Qt::AlignRight|Qt::AlignCenter);

    this->setLayout(grd2);
    this->setFixedSize(400,300);
    this->setWindowTitle("Calculator v1.0");
    this->show();

    connect(btn_numb0,SIGNAL(clicked(bool)),this,SLOT(zero()));
    connect(btn_numb1,SIGNAL(clicked(bool)),this,SLOT(one()));
    connect(btn_numb2,SIGNAL(clicked(bool)),this,SLOT(two()));
    connect(btn_numb3,SIGNAL(clicked(bool)),this,SLOT(three()));
    connect(btn_numb4,SIGNAL(clicked(bool)),this,SLOT(four()));
    connect(btn_numb5,SIGNAL(clicked(bool)),this,SLOT(five()));
    connect(btn_numb6,SIGNAL(clicked(bool)),this,SLOT(six()));
    connect(btn_numb7,SIGNAL(clicked(bool)),this,SLOT(seven()));
    connect(btn_numb8,SIGNAL(clicked(bool)),this,SLOT(eight()));
    connect(btn_numb9,SIGNAL(clicked(bool)),this,SLOT(nine()));


    connect(this,SIGNAL(sent_zero(int)),this,SLOT(get_number(int)));
    connect(this,SIGNAL(sent_one(int)),this,SLOT(get_number(int)));
    connect(this,SIGNAL(sent_two(int)),this,SLOT(get_number(int)));
    connect(this,SIGNAL(sent_three(int)),this,SLOT(get_number(int)));
    connect(this,SIGNAL(sent_four(int)),this,SLOT(get_number(int)));
    connect(this,SIGNAL(sent_five(int)),this,SLOT(get_number(int)));
    connect(this,SIGNAL(sent_six(int)),this,SLOT(get_number(int)));
    connect(this,SIGNAL(sent_seven(int)),this,SLOT(get_number(int)));
    connect(this,SIGNAL(sent_eight(int)),this,SLOT(get_number(int)));
    connect(this,SIGNAL(sent_nine(int)),this,SLOT(get_number(int)));

    connect(btn_point,SIGNAL(clicked(bool)),this,SLOT(get_point()));
    connect(btn_negative,SIGNAL(clicked(bool)),this,SLOT(get_negative()));    
    connect(btn_clear,SIGNAL(clicked(bool)),this,SLOT(do_clear()));

    connect(btn_plus,SIGNAL(clicked(bool)),this,SLOT(do_plus()));
    connect(btn_minus,SIGNAL(clicked(bool)),this,SLOT(do_minus()));
    connect(btn_division,SIGNAL(clicked(bool)),this,SLOT(do_division()));
    connect(btn_multy,SIGNAL(clicked(bool)),this,SLOT(do_multy()));
    connect(btn_equal,SIGNAL(clicked(bool)),this,SLOT(do_equal()));
}

void Calculator::zero()
{
    emit sent_zero(0);
}

void Calculator::one()
{
    emit sent_one(1);
}

void Calculator::two()
{
    emit sent_two(2);
}

void Calculator::three()
{
    emit sent_three(3);
}

void Calculator::four()
{
    emit sent_four(4);
}

void Calculator::five()
{
    emit sent_five(5);
}

void Calculator::six()
{
    emit sent_six(6);
}

void Calculator::seven()
{
    emit sent_seven(7);
}

void Calculator::eight()
{
    emit sent_eight(8);
}

void Calculator::nine()
{
    emit sent_nine(9);
}

void Calculator:: get_number(int a)
{
    str.push_back((QString::number(a)));
    lbl1->setText(str);
}

void Calculator:: get_point()
{
    str.push_back('.');
    lbl1->setText(str);
    btn_point->setEnabled(false);
}

void Calculator:: get_negative()
{
    if(str.isEmpty()== true && stack.isEmpty()== true)
    {
        lbl1->clear();
        str.clear();
        stack.clear();
    }
        else
        {
            double b=str.toDouble();
            b=b*(-1);
            str.clear();
            str.push_back((QString::number(b)));
            lbl1->setText(str);
        }
}

void Calculator:: do_clear()
{
    lbl1->clear();
    lbl2->clear();
    str.clear();
    stack.clear();
    flag_action=false;
    num1=0;
    num2=0;
    btn_point->setEnabled(true);
    btn_minus->setEnabled(true);
    btn_multy->setEnabled(true);
    btn_division->setEnabled(true);
    btn_plus->setEnabled(true);
    was_plus=false;
    was_minus=false;
    was_division=false;
    was_multy=false;
}

void Calculator:: do_plus()
{
    if(str.isEmpty())
    {
        stack.clear();
        str.clear();
        flag_action=false;
        btn_point->setEnabled(true);
    }
        else
        {
            if( *str.begin() == '.')
            {
                str.prepend("0");
            }
            stack.push(str.toDouble());
            ///---Turn off buttons of other operands------
            btn_minus->setEnabled(false);
            btn_multy->setEnabled(false);
            btn_division->setEnabled(false);
            btn_plus->setEnabled(false);
            ///-------------------------------------------
            btn_point->setEnabled(true);
            lbl1->clear();

            ///---New code!
            lbl2->setText(str + "+");
            ///---New code!
            str.clear();

            was_plus=true;
            flag_action=true;
        }
}

void Calculator:: do_minus()
{
    if(str.isEmpty())
    {
        stack.clear();
        str.clear();
        flag_action=false;
        btn_point->setEnabled(true);
    }
        else
        {
            if( *str.begin() == '.')
            {
                str.prepend("0");
            }
            stack.push(str.toDouble());
            ///---Turn off buttons of other operands------
            btn_minus->setEnabled(false);
            btn_multy->setEnabled(false);
            btn_division->setEnabled(false);
            btn_plus->setEnabled(false);
            ///-------------------------------------------
            btn_point->setEnabled(true);
            lbl1->clear();

            ///---New code!
            lbl2->setText(str + "-");
            ///---New code!
            str.clear();

            was_minus=true;
            flag_action=true;
        }
}

void Calculator:: do_division()
{
    if(str.isEmpty())
    {
        stack.clear();
        str.clear();
        flag_action=false;
        btn_point->setEnabled(true);
    }
        else
        {
            if( *str.begin() == '.')
            {
                str.prepend("0");
            }
            stack.push(str.toDouble());
            ///---Turn off buttons of other operands------
            btn_minus->setEnabled(false);
            btn_multy->setEnabled(false);
            btn_division->setEnabled(false);
            btn_plus->setEnabled(false);
            ///-------------------------------------------
            btn_point->setEnabled(true);
            lbl1->clear();

            ///---New code!
            lbl2->setText(str + "/");
            ///---New code!
            str.clear();

            was_division=true;
            flag_action=true;
        }
}

void Calculator:: do_multy()
{
    if(str.isEmpty())
    {
        stack.clear();
        str.clear();
        flag_action=false;
        btn_point->setEnabled(true);
    }
        else
        {
            if( *str.begin() == '.')
            {
                str.prepend("0");
            }
            stack.push(str.toDouble());
            ///---Turn off buttons of other operands------
            btn_minus->setEnabled(false);
            btn_multy->setEnabled(false);
            btn_division->setEnabled(false);
            btn_plus->setEnabled(false);
            ///-------------------------------------------
            btn_point->setEnabled(true);
            lbl1->clear();

            ///---New code!
            lbl2->setText(str + "*");
            ///---New code!
            str.clear();

            was_multy=true;
            flag_action=true;
        }
}

void Calculator:: do_equal()
{
    if(flag_action==false)
    {
        lbl1->clear();
        lbl2->clear();
        str.clear();
        stack.clear();
    }
        else
        {
            if(was_plus==true)
            {
                was_plus=false;
                stack.push(str.toDouble());
                num2=stack.pop();
                num1=stack.pop();
                rez=(num1+num2);

                ///---New code
                QString lbl2_str;
                if( *str.begin() == '.')
                {
                    str.prepend("0");
                }
                if( str.isEmpty())
                {
                    str = "0";
                }
                if( str.contains("-"))
                {
                    lbl2_str = lbl2->text() + "(" + str + ")" + "=";
                }
                    else
                    {
                        lbl2_str = lbl2->text() + str + "=";
                    }
                if( rez < 0)
                {
                    lbl2_str.append("(" + QString::number(rez) + ")");
                }
                if( rez > 0)
                {
                    lbl2_str.append(QString::number(rez));
                }
                if( rez == 0)
                {
                    lbl2_str.append("0");
                }
                lbl2->setText(lbl2_str);
                ///---New code
                str=QString::number(rez);
                lbl1->setText(str);
            }
            if(was_minus==true)
            {
                was_minus=false;
                stack.push(str.toDouble());
                num2=stack.pop();
                num1=stack.pop();
                rez=(num1-num2);

                ///---New code
                QString lbl2_str;
                if( *str.begin() == '.')
                {
                    str.prepend("0");
                }
                if( str.isEmpty())
                {
                    str = "0";
                }
                if( str.contains("-"))
                {
                    lbl2_str = lbl2->text() + "(" + str + ")" + "=";
                }
                    else
                    {
                        lbl2_str = lbl2->text() + str + "=";
                    }
                if( rez < 0)
                {
                    lbl2_str.append("(" + QString::number(rez) + ")");
                }
                if( rez > 0)
                {
                    lbl2_str.append(QString::number(rez));
                }
                if( rez == 0)
                {
                    lbl2_str.append("0");
                }
                lbl2->setText(lbl2_str);
                ///---New code
                str=QString::number(rez);
                lbl1->setText(str);
            }
            if(was_division==true)
            {
                was_division=false;
                stack.push(str.toDouble());
                num2=stack.pop();
                if(num2==0)
                {
                    lbl2->setText("Error");
                    lbl1->clear();
                    str.clear();
                    stack.clear();
                }
                    else
                    {
                        num1=stack.pop();
                        rez=(num1/num2);

                        ///---New code
                        QString lbl2_str;
                        if( *str.begin() == '.')
                        {
                            str.prepend("0");
                        }
                        if( str.isEmpty())
                        {
                            str = "0";
                        }
                        if( str.contains("-"))
                        {
                            lbl2_str = lbl2->text() + "(" + str + ")" + "=";
                        }
                            else
                            {
                                lbl2_str = lbl2->text() + str + "=";
                            }
                        if( rez < 0)
                        {
                            lbl2_str.append("(" + QString::number(rez) + ")");
                        }
                        if( rez > 0)
                        {
                            lbl2_str.append(QString::number(rez));
                        }
                        lbl2->setText(lbl2_str);
                        ///---New code
                        str=QString::number(rez);
                        lbl1->setText(str);
                    }
            }
            if(was_multy==true)
            {
                was_multy=false;
                stack.push(str.toDouble());
                num2=stack.pop();
                num1=stack.pop();
                rez=(num1*num2);

                ///---New code
                QString lbl2_str;
                if( *str.begin() == '.')
                {
                    str.prepend("0");
                }
                if( str.isEmpty())
                {
                    str = "0";
                }
                if( str.contains("-"))
                {
                    lbl2_str = lbl2->text() + "(" + str + ")" + "=";
                }
                    else
                    {
                        lbl2_str = lbl2->text() + str + "=";
                    }
                if( rez < 0)
                {
                    lbl2_str.append("(" + QString::number(rez) + ")");
                }
                if( rez > 0)
                {
                    lbl2_str.append(QString::number(rez));
                }
                if( rez == 0)
                {
                    lbl2_str.append("0");
                }
                lbl2->setText(lbl2_str);
                ///---New code
                str=QString::number(rez);
                lbl1->setText(str);
            }
        }
    flag_action=false;
    num1=0;
    num2=0;
    btn_minus->setEnabled(true);
    btn_multy->setEnabled(true);
    btn_division->setEnabled(true);
    btn_plus->setEnabled(true);
    if(str.contains('.'))
    {
        btn_point->setEnabled(false);
    }
        else
        {
            btn_point->setEnabled(true);
        }
    if(str.contains(QRegExp("r")) == true)
    {
        stack.clear();
        str.clear();
        flag_action=false;
        btn_point->setEnabled(true);
    }
}

void Calculator::keyPressEvent(QKeyEvent *ev)   // the func-on to work with  keyboard
{
    switch(ev->key())
    {
    ///---Work with number keys
    case Qt::Key_0:
    {
        emit sent_zero(0);
        break;
    }
    case Qt::Key_1:
    {
        emit sent_one(1);
        break;
    }
    case Qt::Key_2:
    {
        emit sent_two(2);
        break;
    }
    case Qt::Key_3:
    {
        emit sent_three(3);
        break;
    }
    case Qt::Key_4:
    {
        emit sent_four(4);
        break;
    }
    case Qt::Key_5:
    {
        emit sent_five(5);
        break;
    }
    case Qt::Key_6:
    {
        emit sent_six(6);
        break;
    }
    case Qt::Key_7:
    {
        emit sent_seven(7);
        break;
    }
    case Qt::Key_8:
    {
        emit sent_eight(8);
        break;
    }
    case Qt::Key_9:
    {
        emit sent_nine(9);
        break;
    }
        ///---Work with operands keys
    case Qt::Key_Backspace:
    {
        lbl1->clear();
        str.clear();
        stack.clear();
        flag_action=false;
        num1=0;
        num2=0;
        btn_point->setEnabled(true);
        btn_minus->setEnabled(true);
        btn_multy->setEnabled(true);
        btn_division->setEnabled(true);
        btn_plus->setEnabled(true);
        was_plus=false;
        was_minus=false;
        was_division=false;
        was_multy=false;
        break;
    }
    case Qt::Key_Plus:
    {
        if(btn_plus->isEnabled()== true)  //--Check the btn_plus for enable status
        {
            if(str.isEmpty())
            {
                stack.clear();
                str.clear();
                flag_action=false;
                btn_point->setEnabled(true);
            }
                else
                {
                    if( *str.begin() == '.')
                    {
                        str.prepend("0");
                    }
                    stack.push(str.toDouble());
                    ///---Turn off buttons of other operands------
                    btn_minus->setEnabled(false);
                    btn_multy->setEnabled(false);
                    btn_division->setEnabled(false);
                    btn_plus->setEnabled(false);
                    ///-------------------------------------------
                    btn_point->setEnabled(true);
                    lbl1->clear();

                    ///---New code!
                    lbl2->setText(str + "+");
                    ///---New code!
                    str.clear();

                    was_plus=true;
                    flag_action=true;
                }
            break;
        }
            else
            {
                break;
            }
    }
    case Qt::Key_Minus:
    {
        if(btn_minus->isEnabled()== true)
        {
            if(str.isEmpty())
            {
                stack.clear();
                str.clear();
                flag_action=false;
                btn_point->setEnabled(true);
            }
                else
                {
                    if( *str.begin() == '.')
                    {
                        str.prepend("0");
                    }
                    stack.push(str.toDouble());
                    ///---Turn off buttons of other operands------
                    btn_minus->setEnabled(false);
                    btn_multy->setEnabled(false);
                    btn_division->setEnabled(false);
                    btn_plus->setEnabled(false);
                    ///-------------------------------------------
                    btn_point->setEnabled(true);
                    lbl1->clear();

                    ///---New code!
                    lbl2->setText(str + "-");
                    ///---New code!
                    str.clear();

                    was_minus=true;
                    flag_action=true;
                }
            break;
        }
            else
            {
                break;
            }
    }
    case Qt::Key_division:
    {
        if(btn_division->isEnabled()== true)
        {
                if(str.isEmpty())
                {
                    stack.clear();
                    str.clear();
                    flag_action=false;
                    btn_point->setEnabled(true);
                }
                    else
                    {
                        if( *str.begin() == '.')
                        {
                            str.prepend("0");
                        }
                        stack.push(str.toDouble());
                        ///---Turn off buttons of other operands------
                        btn_minus->setEnabled(false);
                        btn_multy->setEnabled(false);
                        btn_division->setEnabled(false);
                        btn_plus->setEnabled(false);
                        ///-------------------------------------------
                        btn_point->setEnabled(true);
                        lbl1->clear();

                        ///---New code!
                        lbl2->setText(str + "/");
                        ///---New code!
                        str.clear();

                        was_division=true;
                        flag_action=true;
                    }
            break;
        }
            else
            {
                break;
            }
    }
    case Qt::Key_multiply:
    {
        if(btn_multy->isEnabled()==true)
        {
            if(str.isEmpty())
            {
                stack.clear();
                str.clear();
                flag_action=false;
                btn_point->setEnabled(true);
            }
                else
                {
                    if( *str.begin() == '.')
                    {
                        str.prepend("0");
                    }
                    stack.push(str.toDouble());
                    ///---Turn off buttons of other operands------
                    btn_minus->setEnabled(false);
                    btn_multy->setEnabled(false);
                    btn_division->setEnabled(false);
                    btn_plus->setEnabled(false);
                    ///-------------------------------------------
                    btn_point->setEnabled(true);
                    lbl1->clear();

                    ///---New code!
                    lbl2->setText(str + "*");
                    ///---New code!
                    str.clear();
                    was_multy=true;
                    flag_action=true;
                }
            break;
        }
            else
            {
                break;
            }
    }
    case Qt::Key_NumLock: // to make a negative/positive number
    {
        if(str.isEmpty()== true && stack.isEmpty()== true)
        {
            lbl1->clear();
            str.clear();
            stack.clear();
        }
            else
            {
                double b=str.toDouble();
                b=b*(-1);
                str.clear();
                str.push_back((QString::number(b)));
                lbl1->setText(str);
            }
        break;
    }
    case Qt::Key_Delete:
    {
        lbl1->clear();
        lbl2->clear();
        str.clear();
        stack.clear();
        flag_action=false;
        num1=0;
        num2=0;
        btn_point->setEnabled(true);
        btn_minus->setEnabled(true);
        btn_multy->setEnabled(true);
        btn_division->setEnabled(true);
        btn_plus->setEnabled(true);
        was_plus=false;
        was_minus=false;
        was_division=false;
        was_multy=false;
        break;
    }
    case Qt::Key_Equal:
    {
        if(flag_action==false)
        {
            lbl1->clear();
            lbl2->clear();
            str.clear();
            stack.clear();
        }
            else
            {

                if(was_plus==true)
                {
                    was_plus=false;
                    stack.push(str.toDouble());
                    num2=stack.pop();
                    num1=stack.pop();
                    rez=(num1+num2);

                    ///---New code
                    QString lbl2_str;
                    if( *str.begin() == '.')
                    {
                        str.prepend("0");
                    }
                    if( str.isEmpty())
                    {
                        str = "0";
                    }
                    if( str.contains("-"))
                    {
                        lbl2_str = lbl2->text() + "(" + str + ")" + "=";
                    }
                        else
                        {
                            lbl2_str = lbl2->text() + str + "=";
                        }
                    if( rez < 0)
                    {
                        lbl2_str.append("(" + QString::number(rez) + ")");
                    }
                    if( rez > 0)
                    {
                        lbl2_str.append(QString::number(rez));
                    }
                    if( rez == 0)
                    {
                        lbl2_str.append("0");
                    }
                    lbl2->setText(lbl2_str);
                    ///---New code
                    str=QString::number(rez);
                    lbl1->setText(str);
                }
                if(was_minus==true)
                {
                    was_minus=false;
                    stack.push(str.toDouble());
                    num2=stack.pop();
                    num1=stack.pop();
                    rez=(num1-num2);

                    ///---New code
                    QString lbl2_str;
                    if( *str.begin() == '.')
                    {
                        str.prepend("0");
                    }
                    if( str.isEmpty())
                    {
                        str = "0";
                    }
                    if( str.contains("-"))
                    {
                        lbl2_str = lbl2->text() + "(" + str + ")" + "=";
                    }
                        else
                        {
                            lbl2_str = lbl2->text() + str + "=";
                        }
                    if( rez < 0)
                    {
                        lbl2_str.append("(" + QString::number(rez) + ")");
                    }
                    if( rez > 0)
                    {
                        lbl2_str.append(QString::number(rez));
                    }
                    if( rez == 0)
                    {
                        lbl2_str.append("0");
                    }
                    lbl2->setText(lbl2_str);
                    ///---New code
                    str=QString::number(rez);
                    lbl1->setText(str);
                }
                if(was_division==true)
                {
                    was_division=false;
                    stack.push(str.toDouble());
                    num2=stack.pop();
                    if(num2==0)
                    {
                        lbl2->setText("Error");
                        lbl1->clear();
                        str.clear();
                        stack.clear();
                    }
                        else
                        {
                            num1=stack.pop();
                            rez=(num1/num2);

                            ///---New code
                            QString lbl2_str;
                            if( *str.begin() == '.')
                            {
                                str.prepend("0");
                            }
                            if( str.isEmpty())
                            {
                                str = "0";
                            }
                            if( str.contains("-"))
                            {
                                lbl2_str = lbl2->text() + "(" + str + ")" + "=";
                            }
                                else
                                {
                                    lbl2_str = lbl2->text() + str + "=";
                                }
                            if( rez < 0)
                            {
                                lbl2_str.append("(" + QString::number(rez) + ")");
                            }
                            if( rez > 0)
                            {
                                lbl2_str.append(QString::number(rez));
                            }
                            lbl2->setText(lbl2_str);
                            ///---New code
                            str=QString::number(rez);
                            lbl1->setText(str);
                        }
                }
                if(was_multy==true)
                {
                    was_multy=false;
                    stack.push(str.toDouble());
                    num2=stack.pop();
                    num1=stack.pop();
                    rez=(num1*num2);

                    ///---New code
                    QString lbl2_str;
                    if( *str.begin() == '.')
                    {
                        str.prepend("0");
                    }
                    if( str.isEmpty())
                    {
                        str = "0";
                    }
                    if( str.contains("-"))
                    {
                        lbl2_str = lbl2->text() + "(" + str + ")" + "=";
                    }
                        else
                        {
                            lbl2_str = lbl2->text() + str + "=";
                        }
                    if( rez < 0)
                    {
                        lbl2_str.append("(" + QString::number(rez) + ")");
                    }
                    if( rez > 0)
                    {
                        lbl2_str.append(QString::number(rez));
                    }
                    if( rez == 0)
                    {
                        lbl2_str.append("0");
                    }
                    lbl2->setText(lbl2_str);
                    ///---New code
                    str=QString::number(rez);
                    lbl1->setText(str);
                }
            }
        flag_action=false;
        num1=0;
        num2=0;
        btn_point->setEnabled(true);
        btn_minus->setEnabled(true);
        btn_multy->setEnabled(true);
        btn_division->setEnabled(true);
        btn_plus->setEnabled(true);
        if(str.contains('.'))
        {
            btn_point->setEnabled(false);
        }
            else
            {
                btn_point->setEnabled(true);
            }
        if(str.contains(QRegExp("r")) == true)
        {
            stack.clear();
            str.clear();
            flag_action=false;
            btn_point->setEnabled(true);
        }
    }
    default:
    {
        QWidget::keyPressEvent(ev);
    }
    }
}
