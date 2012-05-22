#ifndef ENTIER_H
#define ENTIER_H

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

            //Implementation des méthodes virtuelles pures de la class "Expression"
            void EVAL();

            //Méthodes
            void MOD();
            void FACTORIELLE();
    };
}

#endif // ENTIER_H
