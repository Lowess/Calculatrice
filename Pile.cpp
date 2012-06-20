#include "Pile.h"
#include "Gardien.h"

#include "Entier.h"
#include "Reel.h"
#include "Rationnel.h"
#include "Complexe.h"
#include "Exp.h"

using namespace LO21;
/*
LO21::Pile(const LO21::Pile& p){
    qDebug()<< "pd";
}
*/
//Methodes privées
void LO21::Pile::SWAP(int x, int y){
    if(x >= size() || x < 0 || y < 0 || y >= size()){
        LogSystem::ecrireLog(LogMessage("Erreur classe pile ",ERREUR));
        throw CalculatriceException(typeid(this).name(),PILE,"SWAP impossible une des valeurs X ou Y est incorrecte");
    }
    Expression* tmp;
    tmp=value(x);
    replace(x, value(y));
    replace(y, tmp);
}

void LO21::Pile::SUM(int n){
    if(n >= size() || n < 0){
        LogSystem::ecrireLog(LogMessage("Erreur classe pile ",ERREUR));
        throw CalculatriceException(typeid(this).name(),PILE,"SUM impossible la valeurs X est incorrecte");
    }
    if(n >= 1){
        do{
            Expression* x=pop();
            Expression* y=pop();
            //On test ce que vaut x et y (Constantes ou Expressions?)
            Constante* cx=dynamic_cast<Constante*>(x);
            Constante* cy=dynamic_cast<Constante*>(y);
            if(cx!=0 || cy!=0){ //Deux constantes
                Expression& res=*cx + *cy;
                push(&res);

                delete x;
                delete y;
            }
            n--;
        }while(n > 0);
    }
}

void LO21::Pile::MEAN(int n){
    if(n > size() || n < 0){
        LogSystem::ecrireLog(LogMessage("Erreur classe pile ",ERREUR));
        throw CalculatriceException(typeid(this).name(),PILE,"MEAN impossible la valeurs X est incorrecte");
    }
    SUM(n);
    Entier diviseur(n);

    Expression* x=pop();
    Constante* cx=dynamic_cast<Constante*>(x);
    if(cx!=0){
        Expression& res=*cx / diviseur;
        push(&res);

        delete x;
    }
}

void LO21::Pile::CLEAR(){
    clear();
}

void LO21::Pile::DUP(){
    if(isEmpty()){
        LogSystem::ecrireLog(LogMessage("Erreur classe pile ",ERREUR));
        throw CalculatriceException(typeid(this).name(),PILE,"Opération impossible la pile est vide");
    }

    Expression* e=top();
    Entier* pt_ent=dynamic_cast<Entier*>(e);
    if(pt_ent!=0){
        push(new Entier(pt_ent->get_x()));
    } else {
        Reel* pt_ree=dynamic_cast<Reel*>(e);
        if (pt_ree != 0){
            push(new Reel(pt_ree->get_x()));
        } else {
            Rationnel* pt_rat=dynamic_cast<Rationnel*>(e);
            if(pt_rat != 0){
                push(new Rationnel(*pt_rat));
            }
            else{
                Exp* pt_exp=dynamic_cast<Exp*>(e);
                if(pt_exp != 0){
                    push(new Exp(pt_exp->toString()));
                }
                else{
                    Complexe* pt_com=dynamic_cast<Complexe*>(e);
                    if(pt_com != 0){
                        push(new Complexe(*pt_com));
                    }
                    else{
                        LogSystem::ecrireLog(LogMessage("Erreur classe pile ",ERREUR));
                        throw CalculatriceException(typeid(this).name(),PILE,"Impossible de dupliquer ce type de constante");
                    }
                }
            }
        }
    }
}

void LO21::Pile::DROP(){
    if(isEmpty()){
        LogSystem::ecrireLog(LogMessage("Erreur classe pile ",ERREUR));
        throw CalculatriceException(typeid(this).name(),PILE,"Opération impossible la pile est vide");
    }

    Expression* e=pop();
    delete e;
}

LO21::Pile* LO21::Pile::clone() const{
    Pile* np= new Pile();
    //Parcours la pile pour cloner chaque éléments
    QStack<Expression*>::const_iterator it;
    Expression* exp=0;
    for(it=begin(); it!=end(); ++it){ //On parcourt la liste de pile
        exp=*it;
        np->push(exp->clone());
    }
    return np;
}

void LO21::Pile::afficherPileCourante() const{
    //Parcours la pile pour afficher ce qu'elle contient
    QStack<Expression*>::const_iterator it;
    Expression* exp=0;
    for(it=begin(); it!=end(); ++it){ //On parcourt la liste de pile
        exp=*it;
        qDebug() << exp->toString();
    }
}

void LO21::Pile::afficherPileMemoire() const{
    //Parcours la pile pour afficher ce qu'elle contient
    QStack<Expression*>::const_iterator it;
    Expression* exp=0;
    for(it=_etat->begin(); it!=_etat->end(); ++it){ //On parcourt la liste de pile
        exp=*it;
        qDebug() << exp->toString();
    }
}

LO21::Pile::Memento* LO21::Pile::sauverDansMemento(){ return new Pile::Memento(_etat); }

void LO21::Pile::restaurerDepuisMemento(const Pile::Memento* m){
    _etat=m->get_etat();
    //Gardien::getInstance()->set_index(_etat->size()+1);
}

LO21::Pile* LO21::Pile::get_etat()const{ return _etat; }
