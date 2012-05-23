#ifndef REEL_H
#define REEL_H

#include <iostream>

#include "Nombre.h"

namespace Calculatrice{
    class Reel: public Nombre{
        private:
            float _x;
        public:
            //Implémentation des méthodes virtuelles pures de la class "Nombre"
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

            QString toString() const;

            //Implementation des méthodes virtuelles pures de la class "Expression"
            void EVAL();

            //Méthodes
            //Setter Getter

            float get_x() const{ return _x; }

            //Constructeurs
            Reel(const float x=0):_x(x){}
    };
}

#endif // REEL_H
