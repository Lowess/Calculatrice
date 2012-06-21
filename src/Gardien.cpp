#include "Gardien.h"
#include "Pile.h"

using namespace std;
using namespace LO21;

LO21::Gardien* LO21::Gardien::_gard=0;

//Methodes publiques
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
}
void LO21::Gardien::ajouterMementoRedo(Pile::Memento* pMemento){
    _liste.push(pMemento);
    _index++;
}

LO21::Pile::Memento* LO21::Gardien::getMementoUndo(){
    if(!_liste.isEmpty() && _index > 1){
        _index--;
        return _liste.value(_index-1);
    }
    throw CalculatriceException(typeid(this).name(),PILE,"Operation de undo impossible pile vide");
}
LO21::Pile::Memento* LO21::Gardien::getMementoRedo(){
    if(!_liste.isEmpty() && _index < _liste.size()){
        _index++;
        Pile::Memento* m=_liste.value(_index-1);
        return m;


    }
    throw CalculatriceException(typeid(this).name(),PILE,"Operation de redo impossible pile vide");
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
