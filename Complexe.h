#ifndef COMPLEXE_H
#define COMPLEXE_H

#include "Constante.h"
#include "Nombre.h"

namespace Calculatrice{
    class Complexe: public Constante{
        private:
            //Calculatrice::Nombre _a;
            //Calculatrice::Nombre _b;
        public:
            //Implementation des méthodes virtuelles pures de la class "Expression"
            void EVAL();

            //Méthodes publiques
            void conjugue();
            void module();
    };
}

#endif // COMPLEXE_H
