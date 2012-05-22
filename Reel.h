#ifndef REEL_H
#define REEL_H

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

            //Implementation des méthodes virtuelles pures de la class "Expression"
            void EVAL();

    };
}

#endif // REEL_H
