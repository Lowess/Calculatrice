#ifndef GARDIEN_H
#define GARDIEN_H

#include <QString>
#include <QStack>
#include "Pile.h"
/*
 * Implémente le DP Memento
 *
*/

namespace LO21{
    //class Pile;
    //class Pile::Memento;

    class Gardien{
        private:
            static Gardien* _gard;
            int _index;
            QStack<Pile::Memento*> _liste;

            Gardien():_index(0){}
            Gardien(const Gardien&){}
            ~Gardien(){}

        public:
            static Gardien* getInstance();
            static void libereInstance();

            void ajouterMementoUndo(Pile::Memento* pMemento);
            void ajouterMementoRedo(Pile::Memento* pMemento);

            Pile::Memento* getMementoUndo();
            Pile::Memento* getMementoRedo();

            void afficher();

            void set_index(int i){ _index=i; }
    };
}

#endif // GARDIEN_H
