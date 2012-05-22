#ifndef RATIONNEL_H
#define RATIONNEL_H

#include "Nombre.h"
#include "Entier.h"

namespace Calculatrice{
    class Rationnel: public Nombre {
        private:
            Calculatrice::Entier _n;
            Calculatrice::Entier _d;
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

#endif // RATIONNEL_H
