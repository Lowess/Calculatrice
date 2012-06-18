#include "Fabrique.h"
#include "Pile.h"
#include "OperateurBinaire.h"
#include "OperateurUnaire.h"
#include "LogSystem.h"

using namespace LO21;
using namespace std;

LO21::Fabrique* LO21::Fabrique::_f=0;

LO21::Fabrique& LO21::Fabrique::getInstance(){
    if(_f==0){
        _f=new Fabrique();
    }
    return *_f;
}

void LO21::Fabrique::libereInstance(){
    if(_f!=0){
        delete _f;
    }
    _f=0;
}


QList<QString> LO21::Fabrique::preTraitement(QList<QString>& text) const{
    bool exp=false;

    QTextStream cout(stdout, QIODevice::WriteOnly);
    cout << endl;

    QList<QString> result;

    QList<QString>::iterator it;

    int index=0;


    for(it=text.begin(); it!=text.end(); ++it){ //On parcours notre expression otée des espaces
        //cout << *it << " " << getTypeSousChaine(*it) <<  endl;

        switch (getTypeSousChaine(*it)){
            case EXPRESSION:{

                if(exp==true){//Fin d'exp
                    result.replace(index,result.value(index)+" "+*it);
                    exp=false;
                }
                else{
                    result.append(*it);
                    exp=true;
                    index=result.size()-1;
                }
            break;
            }
            default:{
                //On ne traite pas une exp alors on ajoute normalement
                if(!exp){
                    result.append(*it); break;
                }
                else{
                    result.replace(index,result.value(index).simplified()+" "+*it);
                }
                break;
            }
        }
    }
/*
    for(it=result.begin(); it!=result.end(); ++it) //On parcours notre expression otée des espaces
        cout << *it <<  endl;
*/
    return result;
}


void LO21::Fabrique::creer(const QString& text) const{
    Pile* p=Calculatrice::getInstance().get_pile();

    Expression* res=0;

    QTextStream cout(stdout, QIODevice::WriteOnly);
    cout << endl;

    QList<QString> list=text.simplified().split(" "); //Séparation des constantes et opérateur de la lineEdit par les espaces
    QList<QString>::iterator it;

    QList<QString> result=preTraitement(list); //On réorganise la liste pour séparer les expressions des constantes

    for(it=result.begin(); it!=result.end(); ++it){ //On parcours notre expression otée des espaces
        cout << *it << " " << getTypeSousChaine(*it) <<  endl;

        switch (getTypeSousChaine(*it)){
            case ENTIER:{
                Nombre* nb=new Entier(QString(*it).toInt());
                Expression* res=&nb->hookOperation();
                p->push(res);

                LogSystem::ecrireLog(LogMessage("Creation d'une constante de type Entier de valeur " + res->toString()));
                break;
            }
            case REEL:{
                Nombre* nb=new Reel(QString(*it).toDouble());
                Expression* res=&nb->hookOperation();
                p->push(res);

                LogSystem::ecrireLog(LogMessage("Creation d'une constante de type Reel de valeur " + res->toString()));
                break;
            }
            case RATIONNEL:{
                QString tmp(*it);
                QStringList tmpl=tmp.split("/"); //Séparation num / den
                Nombre* nb=new Rationnel(tmpl.value(0).toInt(), tmpl.value(1).toInt());
                Expression* res=&nb->hookOperation();
                p->push(res);

                LogSystem::ecrireLog(LogMessage("Creation d'une constante de type Rationnel de valeur " + res->toString()));
                break;
            }
            case COMPLEXE:{

                QString tmp(*it);
                QStringList tmpl=tmp.split("$"); //Séparation Re $ Im
                creer(tmpl.value(0));
                creer(tmpl.value(1));
                //Expression* im=p->pop();
                //Expression* re=p->pop();

                const Nombre* cy=dynamic_cast<const Nombre*>(p->pop());
                const Nombre* cx=dynamic_cast<const Nombre*>(p->pop());
                if(cx!=0 || cy!=0){ //Deux constantes
                    Complexe* res=new Complexe(*cx, *cy);
                    p->push(res);
                    LogSystem::ecrireLog(LogMessage("Creation d'une constante de type Complexe de valeur " + res->toString()));
                }
                break;

            }
            case OPERATEUR_BINAIRE:{
                OperateurBinaire* res=new OperateurBinaire(*it);
                res->appliqueOperateur();
                LogSystem::ecrireLog(LogMessage("Application d'un operateur binaire de valeur " + res->toString()));
                break;
            }
            case OPERATEUR_UNAIRE:{
                OperateurUnaire* res=new OperateurUnaire(*it);
                res->appliqueOperateur();
                LogSystem::ecrireLog(LogMessage("Application d'un operateur unaire de valeur " + res->toString()));
                break;
            }
            case EXPRESSION:{
                QString tmp(*it);
                tmp.replace(QString("'"), QString(""));
                Expression* res=new Exp(tmp);
                p->push(res);
                LogSystem::ecrireLog(LogMessage("Creation d'une constante de type Expression de valeur " + res->toString()));
                break;
            }
            default:{
                LogSystem::ecrireLog(LogMessage("Construction d'objet invalide",ERREUR));
                throw CalculatriceException(typeid(this).name(),OTHER,"Construction d'objet invalide");
                break;
            }
        }
    }
}

/*
 ******************
 * Fonctions
 ******************
*/

bool LO21::isEntier(const QString& s){
    QRegExp regexp("^\\-?[\\d]+$");
    return (s.contains(regexp));
}

bool LO21::isReel(const QString& s){
    QRegExp regexp("^\\-?[\\d]+[\.][\\d]+$");
    return (s.contains(regexp));
}

bool LO21::isRationnel(const QString& s){
    QRegExp regexp("^\\-?[\\d]+\/[\\d]+$");
    return (s.contains(regexp));
}

bool LO21::isComplexe(const QString& s){
    QRegExp regexp("^\\-?[\\d]+(([\.]|[\/])[\\d]+)?[\$]\\-?[\\d]+(([\.]|[\/])[\\d]+)?$");
    return (s.contains(regexp));
}

bool LO21::isOperateurBinaire(const QString& s){
    QRegExp regexp("^[\+|\\-|\*|/]|MOD|POW$");
    return (s.contains(regexp));
}

bool LO21::isOperateurUnaire(const QString& s){
    QRegExp regexp("^[\\w]{1,}|\\!$");
    return (s.contains(regexp));
}

bool LO21::isExpression(const QString& s){
    QRegExp regexp("'");
    return (s.contains(regexp));
}

LO21::enum_Fabrique LO21::getTypeSousChaine(const QString& ss){
    if(isEntier(ss)){ return ENTIER; }
    if(isReel(ss)){ return REEL; }
    if(isRationnel(ss)){ return RATIONNEL; }
    if(isComplexe(ss)){ return COMPLEXE; }
    if(isOperateurBinaire(ss)){ return OPERATEUR_BINAIRE; }
    if(isOperateurUnaire(ss)){ return OPERATEUR_UNAIRE; }
    if(isExpression(ss)){ return EXPRESSION; }
}


//operator<<
QTextStream& operator<<(QTextStream& s, const LO21::enum_Fabrique& ef){
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
        case EXPRESSION:
            s << "expression"; break;
    }
    return s;
}
