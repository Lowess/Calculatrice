#include <QtGui/QApplication>
#include "mainwindow.h"

#include <QTextStream>
#include <cstdio>

#include "Nombre.h"
#include "Entier.h"
#include "Reel.h"
#include "Rationnel.h"


using namespace std;
using namespace Calculatrice;


int main(int argc, char *argv[])
{
    /*
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    
    return a.exec();
    */

    cout << endl << endl << "Début programme" << endl;

    QTextStream cout(stdout, QIODevice::WriteOnly);

    const Nombre& a=Rationnel(3,2);
    a.afficher();

    cout << endl;
}
