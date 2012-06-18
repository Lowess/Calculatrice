#include "Gardien.h"
#include "Pile.h"

using namespace std;
using namespace LO21;

LO21::Gardien* LO21::Gardien::_gard=0;

//Méthodes publiques
LO21::Gardien* LO21::Gardien::getInstance(){
    if(_gard==0){
        _gard=new Gardien();
    }
    return _gard;
}

void LO21::Gardien::libereInstance(){
    if(_gard!=0){
        delete _gard;
    }
    _gard=0;
}


void LO21::Gardien::ajouterMementoUndo(Pile::Memento* pMemento){
    _liste.push(pMemento);
    _index++;
    afficher();
}
void LO21::Gardien::ajouterMementoRedo(Pile::Memento* pMemento){
    _liste.push(pMemento);
    _index++;
    afficher();
}

LO21::Pile::Memento* LO21::Gardien::getMementoUndo(){
    if(!_liste.isEmpty() && _index > 1){
        //qDebug() << "Taille de liste "  << _liste.size() << endl;
        //qDebug() << "index "  << _index << endl;
        //afficher();
        _index--;
        qDebug() << "index "  << _index << endl;
        return _liste.value(_index-1);
    }
    throw CalculatriceException(typeid(this).name(),PILE,"Opération de undo impossible pile vide");
}
LO21::Pile::Memento* LO21::Gardien::getMementoRedo(){
    if(!_liste.isEmpty() && _index < _liste.size()){
        //qDebug() << "Taille de liste "  << _liste.size() << endl;
        //qDebug() << "index "  << _index << endl;
        _index++;
        //afficher();
        Pile::Memento* m=_liste.value(_index-1);
        return m;


    }
    throw CalculatriceException(typeid(this).name(),PILE,"Opération de redo impossible pile vide");
}

void LO21::Gardien::afficher(){
    QStack<Pile::Memento*>::iterator it;
    Pile::Memento* m;
    for(it=_liste.begin(); it!=_liste.end(); ++it){
        m=*it;
        m->get_etat()->afficherPileMemoire();
        qDebug() << endl;
    }
}
