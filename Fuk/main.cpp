#include "mainform.h"
#include <QApplication>

#include "charakter.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainForm main;


    Charakter c;


    main.show();

    return a.exec();
}
