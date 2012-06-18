/** \file Pile.h
  * \author Florian Dambrine, Olivia Reaney
  * \brief Fichier d'en-tête pour déclaration de la classe Pile
  */

#ifndef PILE_H
#define PILE_H

#include <QStack>
#include <QDebug>

#include "Expression.h"
#include "Rationnel.h"
/**
  * DP Singleton
  *
**/
namespace LO21{
    class Pile: public QStack<Expression*>{
        private:
            Pile* _etat;
        public:
            Pile():_etat(this){}

            //MÃƒÂ©thodes agissant sur la pile
            void SWAP(int x, int y);
            void SUM(int n);
            void MEAN(int n);
            void CLEAR();
            void DUP();
            void DROP();

            //MÃ©thodes de sauvegarde et de chargement
            void sauvegarder();
            void charger();

            Pile* clone() const;

            void afficherPileCourante() const;
            void afficherPileMemoire() const;

            //DP Memento
            class Memento{
                private:
                    Pile* _etat;
                public:
                    Memento(const Pile* petat):_etat(petat->clone()){}

                    Pile* get_etat() const {return _etat; }
            };

            void mementoSuivant(){

            }

            Memento* sauverDansMemento(){ return new Memento(_etat); }
            void restaurerDepuisMemento(const Memento* m){ _etat=m->get_etat(); }
            Pile* get_etat()const{ return _etat; }
    };
}

#endif // PILE_H
