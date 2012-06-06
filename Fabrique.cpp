#include "Fabrique.h"
#include "Pile.h"
using namespace Calculatrice;
using namespace std;

Calculatrice::Fabrique* Calculatrice::Fabrique::_f=0;

Calculatrice::Fabrique& Calculatrice::Fabrique::getInstance(){
    if(_f==0){
        _f=new Fabrique();
    }
    return *_f;
}

void Calculatrice::Fabrique::libereInstance(){
    if(_f!=0){
        delete _f;
    }
    _f=0;
}


void Calculatrice::Fabrique::creer(const QString& text) const{
    Pile* p=&Pile::getInstance();
    Expression* res=0;

    QTextStream cout(stdout, QIODevice::WriteOnly);

    QList<QString> list=text.split(" "); //Séparation des constantes et opérateur de la lineEdit
    QList<QString>:: iterator it;
    for(it=list.begin(); it!=list.end(); ++it){ //On parcours notre expression otée des espaces
        cout << *it << " " << getTypeSousChaine(*it) <<  endl;
        switch (getTypeSousChaine(*it)){
            case ENTIER:{
                res=new Entier(QString(*it).toInt());
                break;
            }
            case REEL:{
                res=new Reel(QString(*it).toDouble());
                break;
            }
            case RATIONNEL:{
                QString tmp(*it);
                QStringList tmpl=tmp.split("/"); //Séparation num / den
                res=new Rationnel(tmpl.value(0).toInt(), tmpl.value(1).toInt());
                break;
            }
            case COMPLEXE:{
/*
                QString tmp(*it);
                QStringList tmpl=tmp.split("$"); //Séparation Re $ Im
                Nombre* re=dynamic_cast<Nombre*>(&creer(tmpl.value(0)));
                Nombre* im=dynamic_cast<Nombre*>(&creer(tmpl.value(1)));
                res=new Complexe(re, im);

                res=new Rationnel();
                break;
*/
            }
            case OPERATEUR_BINAIRE:{
                //res=new Operateur();
                break;
            }
            case OPERATEUR_UNAIRE:{
                //res=new Operateur();
                break;
            }
            default:{
                throw CalculatriceException(typeid(this).name(),OTHER,"Construction d'objet invalide");
                break;
            }
        }
        p->push(res);
    }
}

/*
 ******************
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

bool Calculatrice::isOperateurBinaire(const QString& s){
    QRegExp regexp("^[+|-|*|/]$");
    return (s.contains(regexp));
}

bool Calculatrice::isOperateurUnaire(const QString& s){
    QRegExp regexp("^[\\w]{3,}$");
    return (s.contains(regexp));
}

Calculatrice::enum_Fabrique Calculatrice::getTypeSousChaine(const QString& ss){
    if(isEntier(ss)){ return ENTIER; }
    if(isReel(ss)){ return REEL; }
    if(isRationnel(ss)){ return RATIONNEL; }
    if(isComplexe(ss)){ return COMPLEXE; }
    if(isOperateurBinaire(ss)){ return OPERATEUR_BINAIRE; }
    if(isOperateurUnaire(ss)){ return OPERATEUR_UNAIRE; }
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
        case OPERATEUR_BINAIRE:
            s << "operateur binaire"; break;
        case OPERATEUR_UNAIRE:
            s << "operateur unaire"; break;
    }
    return s;
}
