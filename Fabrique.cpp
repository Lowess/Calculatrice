#include "Fabrique.h"

using namespace Calculatrice;

Calculatrice::Fabrique* Calculatrice::Fabrique::_f=0;

Calculatrice::Fabrique& Calculatrice::Fabrique::getInstance(){
    if(_f==0){
        _f=new Fabrique();
    }
    else
        return *_f;
}

Calculatrice::Fabrique& Calculatrice::Fabrique::libereInstance(){
    if(_f!=0){
        delete _f;
    }
    _f=0;
}


Calculatrice::Expression* Calculatrice::Fabrique::creer(const enum_Fabrique type, const QString& param1, const QString& param2) const{
    Expression* res=0;

    switch(type){
        case ENTIER:
            res=new Entier(param1.toInt());
            break;
        case REEL:
            res=new Reel(param1.toDouble());
            break;
        case RATIONNEL:
            res=new Rationnel(param1.toInt(), param2.toInt());
            break;
        default:
            throw CalculatriceException(typeid(this).name(),OTHER,"Construction d'objet invalide");
    }
    return (res);
}
