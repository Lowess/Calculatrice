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
    MainWindow w;
    w.show();

    return a.exec();

/*
    QTextStream cout(stdout, QIODevice::WriteOnly);
    cout << endl;

    Expression* n1=new Entier(2);
    Expression* n2=new Entier(5);

    cout << n1 << endl;
    cout << n2 << endl;


    Pile* p=Calculatrice::getInstance().get_pile();
    p->push(n1);
    p->push(n2);


    Pile* p2=p->clone();

    cout << "affiche p"<<endl;
    p->afficher();
    cout << "affiche p2"<<endl;
    p2->afficher();

    p2->push(n2);
    p2->push(n2);

    cout << "affiche p"<<endl;
    p->afficher();
    cout << "affiche p2"<<endl;
    p2->afficher();


/*
    QList<QStack<Expression*>*> m=p->get_memory();
    m.append(p->clone());
    //m.append("toto");

    QStack<Expression*>* qs=m.value(0);
    Expression* e=qs->pop();
    cout << endl << e->toString() << endl;

    e=qs->pop();
    cout << endl << e->toString() << endl;

    //cout << Calculatrice::getInstance().get_pile()->get_memory().size() << endl;
*/
/*
    Expression* n2=new Reel(2.5);
    Expression* n3=new Rationnel(4,4);
    Expression* n4=new Rationnel(2,3);

    Calculatrice::getInstance().get_pile()->push(n1);
    Calculatrice::getInstance().get_pile()->push(n2);
    Calculatrice::getInstance().get_pile()->push(n3);
    Calculatrice::getInstance().get_pile()->push(n4);

    QStack<Expression*>::iterator it;
    Expression* exp=0;
    for(it=Calculatrice::getInstance().get_pile()->begin(); it!=Calculatrice::getInstance().get_pile()->end(); ++it){ //On parcourt la pile
        exp=*it;
        cout << exp->toString() << endl;
    }

    Pile* p1=new Pile();
    Pile* p2=Calculatrice::getInstance().get_pile()->clone();

    //p1->push(n1);
    //p1->push(n1);

    Calculatrice::getInstance().get_pile()->CLEAR();

    Calculatrice::getInstance().get_pile()->swap(*p2);

    cout << endl;

    for(it=Calculatrice::getInstance().get_pile()->begin(); it!=Calculatrice::getInstance().get_pile()->end(); ++it){ //On parcourt la pile
        exp=*it;
        cout << exp->toString() << endl;
    }
*/

/*

    Complexe c(n1,n2);
    Complexe c2(n3,n4);

    cout << c << endl;
    cout << c2 << endl;
    cout << c+c2 << endl;
    cout << c-c2 << endl;
    cout << c*c2 << endl;
    cout << c/c2 << endl;

*/

/*
    Fabrique& factory=Fabrique::getInstance();
    factory.creer("1   2 +");
*/
    /*
    Pile* p=&Pile::getInstance();

    cout << endl;

    while(!p->isEmpty()){
        cout << *p->pop() << endl;
    }
    cout << endl;
*/
/*
    Nombre* a=new Entier(3);
    Nombre* b=new Reel(3.0);
    Nombre* c=new Rationnel(3,1);
*/
/*
    cout << a->SIN() << endl;
    cout << b->SIN() << endl;
    cout << c->SIN() << endl;

    cout << endl;

    cout << a->COS() << endl;
    cout << b->COS() << endl;
    cout << c->COS() << endl;

    cout << endl;

    cout << a->TAN() << endl;
    cout << b->TAN() << endl;
    cout << c->TAN() << endl;

    cout << endl;

    cout << a->SINH() << endl;
    cout << b->SINH() << endl;
    cout << c->SINH() << endl;

    cout << endl;

    cout << a->COSH() << endl;
    cout << b->COSH() << endl;
    cout << c->COSH() << endl;

    cout << endl;

    cout << a->TANH() << endl;
    cout << b->TANH() << endl;
    cout << c->TANH() << endl;
*/

/*
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
/*
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
*/

    cout << endl;
}
