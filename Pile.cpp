#include "Pile.h"

#include "Entier.h"
#include "Reel.h"
#include "Rationnel.h"
#include "Complexe.h"
#include "Exp.h"

using namespace Calculatrice;

//Methodes privées

//Méthodes publiques
Calculatrice::Pile* Calculatrice::Pile::_pile=0;

Calculatrice::Pile& Calculatrice::Pile::getInstance(){
    if(_pile==0){
        _pile=new Pile();
    }
    return *_pile;
}

void Calculatrice::Pile::libereInstance(){
    if(_pile!=0){
        delete _pile;
    }
    _pile=0;
}

void Calculatrice::Pile::SWAP(int x, int y){
    if(x >= _pile->size() || x < 0 || y < 0 || y >= _pile->size())
        throw CalculatriceException(typeid(this).name(),PILE,"SWAP impossible une des valeurs X ou Y est incorrecte");
    Expression* tmp;
    tmp=_pile->value(x);
    _pile->replace(x, _pile->value(y));
    _pile->replace(y, tmp);
}

void Calculatrice::Pile::SUM(int n){
    if(n >= _pile->size() || n < 0)
        throw CalculatriceException(typeid(this).name(),PILE,"SUM impossible la valeurs X est incorrecte");
    do{
        Expression* x=_pile->pop();
        Expression* y=_pile->pop();
        //On test ce que vaut x et y (Constantes ou Expressions?)
        Constante* cx=dynamic_cast<Constante*>(x);
        Constante* cy=dynamic_cast<Constante*>(y);
        if(cx!=0 || cy!=0){ //Deux constantes
            Expression& res=*cx + *cy;
            _pile->push(&res);

            delete x;
            delete y;
        }
        n--;
    }while(n > 0);
}

void Calculatrice::Pile::MEAN(int n){
    if(n > _pile->size() || n < 0)
        throw CalculatriceException(typeid(this).name(),PILE,"MEAN impossible la valeurs X est incorrecte");
    SUM(n);
    Entier diviseur(n);

    Expression* x=_pile->pop();
    Constante* cx=dynamic_cast<Constante*>(x);
    if(cx!=0){
        Expression& res=*cx / diviseur;
        _pile->push(&res);

        delete x;
    }
}

void Calculatrice::Pile::CLEAR(){
    _pile->clear();
}

void Calculatrice::Pile::DUP(){
    if(Pile::getInstance().isEmpty()){
        throw CalculatriceException(typeid(this).name(),PILE,"Opération impossible la pile est vide");
    }

    Expression* e=Pile::getInstance().top();
    Entier* pt_ent=dynamic_cast<Entier*>(e);
    if(pt_ent!=0){
        Pile::getInstance().push(new Entier(pt_ent->get_x()));
    } else {
        Reel* pt_ree=dynamic_cast<Reel*>(e);
        if (pt_ree != 0){
            Pile::getInstance().push(new Entier(pt_ent->get_x()));
        } else {
            Rationnel* pt_rat=dynamic_cast<Rationnel*>(e);
            if(pt_rat != 0){
                Entier n=pt_rat->get_n();
                Entier d=pt_rat->get_d();
                Pile::getInstance().push(new Rationnel(n,d));
            }
            else{
                Exp* pt_exp=dynamic_cast<Exp*>(e);
                if(pt_exp != 0){
                    Pile::getInstance().push(new Exp(pt_exp->toString()));
                }
                else{
                    /*
                    Complexe* pt_com=dynamic_cast<Complexe*>(e);
                    if(pt_com != 0){
                    }
                    else*/
                        throw CalculatriceException(typeid(this).name(),PILE,"Impossible de dupliquer ce type de constante");
                }
            }
        }
    }
}

void Calculatrice::Pile::DROP(){
    if(Pile::getInstance().isEmpty()){
        throw CalculatriceException(typeid(this).name(),PILE,"Opération impossible la pile est vide");
    }

    Expression* e=Pile::getInstance().pop();
    delete e;
}

void test(){
    throw QString("except");
}
