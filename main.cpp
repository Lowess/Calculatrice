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

    Entier e1(3);

    Entier e2(1);
    Reel r1(1.55);
    Rationnel r2(8,4);

    Nombre& a=e1;
    Nombre& b=e2;
    Nombre& c=r1;
    Nombre& d=r2;

    cout << "ref b Entier: " << endl;
    b.afficher();
    cout << endl;

    cout << "ref c Reel " << endl;
    c.afficher();
    cout << endl;

    cout << "ref d Rationnel " << endl;
    d.afficher();
    cout << endl;
    /*
    //Additions ENTIER
    cout << "### Additions: " << endl;
    {
        cout << a << "+" << b << "=" << endl;
        a+b;

        cout << a << endl;
        cout << endl;

        cout << a << "+" << c << "=" << endl;
        a+c;

        cout << a << endl;
        cout << endl;

        cout << a << "+" << d << "=" << endl;
        a+d;

        cout << a << endl;
        cout << endl;
    }

    //Soustractions
    cout << "### Soustractions: " << endl;
    {
        cout << a << "-" << b << "=" << endl;
        a-b;

        cout << a << endl;
        cout << endl;

        cout << a << "-" << c << "=" << endl;
        a-c;

        cout << a << endl;
        cout << endl;

        cout << a << "-" << d << "=" << endl;
        a-d;

        cout << a << endl;
        cout << endl;
    }

    //Multiplications
    cout << "### Multiplications: " << endl;
    {
        cout << a << "*" << b << "=" << endl;
        a*b;

        cout << a << endl;
        cout << endl;

        cout << a << "*" << c << "=" << endl;
        a*c;

        cout << a << endl;
        cout << endl;

        cout << a << "*" << d << "=" << endl;
        a*d;

        cout << a << endl;
        cout << endl;
    }

    //Divisions
    cout << "### Divisions: " << endl;
    {
        try{
            cout << a << "/" << b << "=" << endl;
            a/b;
        }catch (exception& e){ cout << e.what() << endl; }

        cout << a << endl;
        cout << endl;

        try{
            cout << a << "/" << c << "=" << endl;
            a/c;
        }catch (exception& e){ cout << e.what() << endl; }

        cout << a << endl;
        cout << endl;

        try{
            cout << a << "/" << d << "=" << endl;
            a/d;
        }catch (exception& e){ cout << e.what() << endl; }

        cout << a << endl;
        cout << endl;
    }
    */
    /////////////////////////////////////////////////////////

    //Additions REEL
    cout << "### Additions: " << endl;
    {
        cout << c << "+" << b << "=" << endl;
        c+b;

        cout << c << endl;
        cout << endl;

        cout << c << "+" << c << "=" << endl;
        c+c;

        cout << c << endl;
        cout << endl;

        cout << c << "+" << d << "=" << endl;
        c+d;

        cout << c << endl;
        cout << endl;
    }

    //Soustractions
    cout << "### Soustractions: " << endl;
    {
        cout << c << "-" << b << "=" << endl;
        c-b;

        cout << c << endl;
        cout << endl;

        cout << c << "-" << c << "=" << endl;
        c-c;

        cout << c << endl;
        cout << endl;

        cout << c << "-" << d << "=" << endl;
        c-d;

        cout << c << endl;
        cout << endl;
    }

    //Multiplications
    cout << "### Multiplications: " << endl;
    {
        cout << c << "*" << b << "=" << endl;
        c*b;

        cout << c << endl;
        cout << endl;

        cout << c << "*" << c << "=" << endl;
        c*c;

        cout << c << endl;
        cout << endl;

        cout << c << "*" << d << "=" << endl;
        c*d;

        cout << c << endl;
        cout << endl;
    }

    //Divisions
    cout << "### Divisions: " << endl;
    {
        try{
            cout << c << "/" << b << "=" << endl;
            c/b;
        }catch (exception& e){ cout << e.what() << endl; }

        cout << c << endl;
        cout << endl;

        try{
            cout << c << "/" << c << "=" << endl;
            c/c;
        }catch (exception& e){ cout << e.what() << endl; }

        cout << c << endl;
        cout << endl;

        try{
            cout << c << "/" << d << "=" << endl;
            c/d;
        }catch (exception& e){ cout << e.what() << endl; }

        cout << c << endl;
        cout << endl;
    }

    cout << endl;
}
