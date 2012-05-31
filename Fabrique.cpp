#include "Fabrique.h"

using namespace Calculatrice;
using namespace std;

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


Calculatrice::Expression* Calculatrice::Fabrique::creer(const QString& text) const{
    QTextStream cout(stdout, QIODevice::WriteOnly);


    QList<QString> list=text.split(" "); //Séparation des constantes et opérateur de la lineEdit
    QList<QString>:: iterator it;
    for(it=list.begin(); it!=list.end(); ++it){
        cout << *it << " " << getTypeSousChaine(*it) <<  endl;

    }

    Expression* res=0;
/*
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
*/
    return (res);


}

/******************
 * Fonctions
 ******************
*/
bool Calculatrice::isEntier(const QString& s){
    QRegExp regexp("^[\\d]+$");
    return (s.contains(regexp));
}

bool Calculatrice::isReel(const QString& s){
    QRegExp regexp("^[\\d]+[\.][\\d]+$");
    return (s.contains(regexp));
}

bool Calculatrice::isRationnel(const QString& s){
    QRegExp regexp("^[\\d]+\/[\\d]+$");
    return (s.contains(regexp));
}

bool Calculatrice::isComplexe(const QString& s){
    QRegExp regexp("^[\\d]+(([\.]|[\/])[\\d]+)?[\$][\\d]+(([\.]|[\/])[\\d]+)?$");
    return (s.contains(regexp));
}

bool Calculatrice::isOperateur(const QString& s){
    QRegExp regexp("^[+|-|*|/]$");
    return (s.contains(regexp));
}

Calculatrice::enum_Fabrique Calculatrice::getTypeSousChaine(const QString& ss){
    if(isEntier(ss)){ return ENTIER; }
    if(isReel(ss)){ return REEL; }
    if(isRationnel(ss)){ return RATIONNEL; }
    if(isComplexe(ss)){ return COMPLEXE; }
    if(isOperateur(ss)){ return OPERATEUR; }
}


//operator<<
QTextStream& operator<<(QTextStream& s, const Calculatrice::enum_Fabrique& ef){
    switch(ef){
        case ENTIER:
            s << "entier"; break;
        case REEL:
            s << "reel"; break;
        case RATIONNEL:
            s << "rationnel"; break;
        case COMPLEXE:
            s << "complexe"; break;
        case OPERATEUR:
            s << "operateur"; break;
    }
    return s;
}
