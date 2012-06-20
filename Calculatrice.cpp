#include "Calculatrice.h"

using namespace LO21;
using namespace std;

//Initialisation des attributs Statics
LO21::Calculatrice* LO21::Calculatrice::_calc=0;

//Constructeur

//Méthodes publiques
LO21::Calculatrice& LO21::Calculatrice::getInstance(){
    if(_calc==0){
        _calc=new Calculatrice();
        LogSystem::ecrireLog(LogMessage("Creation d'une instance de calculatrice ",SYSTEME));
    }
    return *_calc;
}

void LO21::Calculatrice::libereInstance(){
    if(_calc!=0){
        delete _calc;
    }
    _calc=0;
}
