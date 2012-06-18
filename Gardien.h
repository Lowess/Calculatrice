#ifndef GARDIEN_H
#define GARDIEN_H

#include <QString>
#include <QList>
#include <QQueue>
#include "Pile.h"

/*
 * Implémente le DP Memento
 *
*/
using namespace LO21;

namespace LO21{
    class Gardien{
        private:
            static Gardien* _gard;

            QStack<Pile::Memento*> _listeUndo;
            QQueue<Pile::Memento*> _listeRedo;

            Gardien(){}
            Gardien(const Gardien&){}
            ~Gardien(){}

        public:
            static Gardien* getInstance();
            static void libereInstance();


            void ajouterMementoUndo(Pile::Memento* pMemento){
                _listeUndo.push(pMemento);
            }
            void ajouterMementoRedo(Pile::Memento* pMemento){
                _listeRedo.enqueue(pMemento);
            }

            Pile::Memento* getMementoUndo(){
                if(!_listeUndo.isEmpty()){
                    qDebug() << "Taille de liste "  << _listeUndo.size() << endl;
                    return _listeUndo.pop();
                }
                throw CalculatriceException(typeid(this).name(),PILE,"Opération de undo impossible pile vide");
            }
            Pile::Memento* getMementoRedo(){
                if(!_listeRedo.isEmpty()){
                    qDebug() << "Taille de liste "  << _listeRedo.size() << endl;
                    return _listeRedo.dequeue();
                }
                throw CalculatriceException(typeid(this).name(),PILE,"Opération de redo impossible pile vide");
            }
            void afficher(){
                QStack<Pile::Memento*>::iterator it;
                Pile::Memento* m;
                for(it=_listeUndo.begin(); it!=_listeUndo.end(); ++it){
                    m=*it;
                    m->get_etat()->afficherPileMemoire();
                }
            }

            //int get_index()const{ qDebug() << "index:" << _index << endl; return _index; }
    };
}

#endif // GARDIEN_H
