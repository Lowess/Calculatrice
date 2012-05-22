#ifndef NOMBRE_H
#define NOMBRE_H

#include "Constante.h"

namespace Calculatrice{
    class Nombre: public Constante {
        private:

        public:
            //Méthodes virtuelles pures
            virtual void SIN() =0;
            virtual void COS() =0;
            virtual void TAN() =0;
            virtual void SINH() =0;
            virtual void COSH() =0;
            virtual void TANH() =0;
            virtual void LN() =0;
            virtual void LOG() =0;
            virtual void INV() =0;
            virtual void SQRT() =0;
            virtual void POW() =0;
            //Méthodes virtuelles pures hérité de la class "Expression"
            void EVAL() =0;

    };

}

#endif // NOMBRE_H
