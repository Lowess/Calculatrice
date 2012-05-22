#ifndef ENTIER_H
#define ENTIER_H

#include <iostream>
#include <typeinfo>

#include "Reel.h"

namespace Calculatrice{
    class Entier: public Reel{
        private:
            unsigned int _x;
        public:
            //Méthodes virtuelles pures de la class "Nombre"
            void SIN();
            void COS();
            void TAN();
            void SINH();
            void COSH();
            void TANH();
            void LN();
            void LOG();
            void INV();
            void SQRT();
            void POW();

            Nombre& addition(const Nombre& nb);
            Nombre& soustraction(const Nombre& nb);
            Nombre& multiplication(const Nombre& nb);
            Nombre& division(const Nombre& nb);

            //Implementation des méthodes virtuelles pures de la class "Expression"
            void EVAL();

            //Méthodes
            void MOD();
            void FACTORIELLE();

            //Constructeurs
            Entier(unsigned int x=0):Reel(x),_x(x){}
    };
}

#endif // ENTIER_H
