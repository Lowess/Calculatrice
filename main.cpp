#include <QtGui/QApplication>
#include "mainwindow.h"

#include <QTextStream>
#include <cstdio>

#include "Nombre.h"
#include "Entier.h"
#include "Reel.h"
#include "Rationnel.h"
#include "Fabrique.h"
#include "Pile.h"
#include "Complexe.h"

using namespace std;
using namespace LO21;


int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    Ui::MainWindow w;
    w.show();
    w.adjustSize();
    return a.exec();
}
