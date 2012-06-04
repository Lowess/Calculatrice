#include "Pile.h"

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
