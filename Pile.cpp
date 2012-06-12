#include "Pile.h"

#include "Entier.h"
#include "Reel.h"
#include "Rationnel.h"
#include "Complexe.h"

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

void Calculatrice::Pile::SWAP(){

}

void Calculatrice::Pile::SUM(){

}

void Calculatrice::Pile::MEAN(){

}
void Calculatrice::Pile::CLEAR(){
    Pile::getInstance().clear();
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
