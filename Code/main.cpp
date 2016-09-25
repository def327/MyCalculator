#include "calculator.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
        Calculator *calc = new Calculator;
        calc->setWindowTitle("Calculator v 1.1");
        QApplication::setStyle(QStyleFactory::create("fusion"));
        calc->show();    
        return a.exec();
}
