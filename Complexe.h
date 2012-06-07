#ifndef COMPLEXE_H
#define COMPLEXE_H

#include "Constante.h"
#include "Nombre.h"

#include <QString>

namespace Calculatrice{
    class Complexe: public Constante{
        private:
            Nombre* _a;
            Nombre* _b;

        public:
            Complexe();

            QString toString(){
                return (QString(_a->toString() + "+" + _b->toString() + "i"));
            }

            //ImplÃ©mentation des mÃ©thodes virtuelles pures de la class "Expression"
            void EVAL();

            //MÃ©thodes publiques
            void conjugue();
            Constante& module() const;
            Constante& addition(const Complexe& c) const;
            Constante& soustraction(const Complexe& c) const;
            Constante& multiplication(const Complexe& c) const;
            Constante& division(const Complexe& c) const;

    };
}

#endif // COMPLEXE_H
