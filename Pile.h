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
//class Gardien;

namespace LO21{
    class Gardien;
    class Pile: public QStack<Expression*>{
        private:
            Pile* _etat;
        public:
            Pile():_etat(this){}

            //MÃ©thodes agissant sur la pile
            void SWAP(int x, int y);
            void SUM(int n);
            void MEAN(int n);
            void CLEAR();
            void DUP();
            void DROP();

            //Méthodes de sauvegarde et de chargement
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

            //void mementoSuivant(){}

            Memento* sauverDansMemento();
            void restaurerDepuisMemento(const Memento* m);
            Pile* get_etat()const;
    };
}

#endif // PILE_H
