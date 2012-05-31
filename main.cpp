#include <QtGui/QApplication>
#include "mainwindow.h"

#include <QTextStream>
#include <cstdio>

#include "Nombre.h"
#include "Entier.h"
#include "Reel.h"
#include "Rationnel.h"
#include "Fabrique.h"

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

    QTextStream cout(stdout, QIODevice::WriteOnly);

    cout << endl << endl << "Début programme" << endl;



    Nombre* a=new Entier(3);
    Nombre* b=new Reel(4.5);
    Nombre* c=new Rationnel(12,10);

    Fabrique& factory=Fabrique::getInstance();


    cout << "ref a Entier: " << endl;
    cout << *a << endl;

    cout << "ref b Entier: " << endl;
    cout << *b << endl;

    cout << "ref c Reel " << endl;
    cout << *c << endl;

    Nombre* tab_ref[3]={a,b,c};
/*
    cout << a->toEntier() << endl;
    cout << b->toEntier() << endl;
    cout << c->toEntier() << endl;

    cout << endl;

    cout << a->toReel() << endl;
    cout << b->toReel() << endl;
    cout << c->toReel() << endl;

    cout << endl;

    cout << a->toRationnel() << endl;
    cout << b->toRationnel() << endl;
    cout << c->toRationnel() << endl;
*/
    cout << endl;
    /*
    cout << a->SIGN() << endl;
    cout << b->SIGN() << endl;
    cout << c->SIGN() << endl;
    */

/*
    cout << a->INV() << endl;
    cout << b->INV() << endl;
    cout << c->INV() << endl;
*/

    //Additions
    cout << "---- Additions ----" << endl;
    for(int i=0; i < 3; i++){
        for(int j=0; j < 3; j++){
            try{
                cout << *tab_ref[i] << endl << " + " << endl << *tab_ref[j] << endl << " = " << endl << *tab_ref[i]+ *tab_ref[j] << endl << "-----------" << endl;
            }catch (exception& e){ cout << e.what() << " i=" << i << "j=" << j << endl; }
        }

    }
    cout << endl;
    cout << endl;


    cout << "---- Soustractions ----" << endl;
    //Soustractions
    for(int i=0; i < 3; i++){
        for(int j=0; j < 3; j++){
            try{
                cout << *tab_ref[i] << endl << " - " << endl << *tab_ref[j] << endl << " = " << endl << *tab_ref[i]-*tab_ref[j] << endl << "-----------" << endl;
            }catch (exception& e){ cout << e.what() << " i=" << i << "j=" << j << endl; }
        }

    }

    cout << endl;
    cout << endl;


    cout << "---- Multiplications ----" << endl;
    //Multiplications
    for(int i=0; i < 3; i++){
        for(int j=0; j < 3; j++){
            try{
                cout << *tab_ref[i] << endl << " * " << endl << *tab_ref[j] << endl << " = " << endl << *tab_ref[i]* *tab_ref[j] << endl << "-----------" << endl;
            }catch (exception& e){ cout << e.what() << " i=" << i << "j=" << j << endl; }
        }
    }

    cout << endl;
    cout << endl;

    cout << "---- Divisions ----" << endl;
    //Divisions
    for(int i=0; i < 3; i++){
        for(int j=0; j < 3; j++){
            try{
                cout << *tab_ref[i] << endl << " / " << endl << *tab_ref[j] << endl << " = " << endl << *tab_ref[i] / *tab_ref[j] << endl << "-----------" << endl;
            }catch (exception& e){ cout << e.what() << " i=" << i << "j=" << j << endl; }
        }
    }


    cout << endl;
}
