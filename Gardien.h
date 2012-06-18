/** \file Gardien.h
  * \author Florian Dambrine, Olivia Reaney
  * \brief Fichier d'en-tête pour déclaration de la classe Gardien
  */

#ifndef GARDIEN_H
#define GARDIEN_H

#include <QString>
#include <QList>
#include "Pile.h"
/*
 * ImplÃ©mente le DP Memento
 *
*/
namespace LO21{
    class Gardien{
        private:
            static Gardien* _gard;

            QStack<Pile::Memento*> _liste;

            Gardien(){}
            Gardien(const Gardien&){}
            ~Gardien(){}

        public:
            static Gardien* getInstance();
            static void libereInstance();


            void ajouterMemento(Pile::Memento* pMemento){ _liste.push(pMemento); }

            Pile::Memento* getMemento(){
                if(!_liste.isEmpty()){
                    qDebug() << "Taille de liste "  << _liste.size() << endl;
                    return _liste.pop();
                }
                throw CalculatriceException(typeid(this).name(),PILE,"OpÃ©ration de undo impossible pile vide");
            }
            void afficher(){
                QStack<Pile::Memento*>::iterator it;
                Pile::Memento* m;
                for(it=_liste.begin(); it!=_liste.end(); ++it){
                    m=*it;
                    m->get_etat()->afficherPileMemoire();
                }
            }

            //int get_index()const{ qDebug() << "index:" << _index << endl; return _index; }
    };
}

#endif // GARDIEN_H
