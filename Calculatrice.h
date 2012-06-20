#ifndef CALCULATRICE_H
#define CALCULATRICE_H

#include "Pile.h"
#include "Fabrique.h"
#include "Gardien.h"
#include "LogSystem.h"

namespace LO21{
    class Calculatrice{
        private:
            static Calculatrice* _calc;
            Gardien* _gard;
            Pile* _pile;

            Calculatrice():_gard(Gardien::getInstance()),_pile(new Pile()){}

            Calculatrice(const Calculatrice& c){
                delete _pile;
                _pile=c._pile->clone();
            }

            ~Calculatrice(){
                delete _pile;
                Gardien::libereInstance();
            }
        public:
            static Calculatrice& getInstance();
            static void libereInstance();

            Pile* get_pile() const{ return _pile; }
            void set_pile(Pile* p) {
                _pile=p;
                qDebug() << "Taille de la pile courante" << _pile->size();
            }

            Gardien* get_gardien() const{ return _gard; }

    };
}
#endif // CALCULATRICE_H
