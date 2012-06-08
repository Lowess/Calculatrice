#include "Calculatrice.h"

using namespace std;

//Initialisation des attributs Statics
Calculatrice::Calculatrice* Calculatrice::Calculatrice::_calc=0;

//Constructeur

//Méthodes publiques
Calculatrice::Calculatrice& Calculatrice::Calculatrice::getInstance(){
    if(_calc==0){
        _calc=new Calculatrice::Calculatrice();
    }
    return *_calc;
}

void Calculatrice::Calculatrice::libereInstance(){
    if(_calc!=0){
        delete _calc;
    }
    _calc=0;
}
