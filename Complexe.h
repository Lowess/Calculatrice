#ifndef COMPLEXE_H
#define COMPLEXE_H

#include "Constante.h"
#include "Nombre.h"

namespace Calculatrice{
    class Complexe: public Constante{
        private:
            Calculatrice::Nombre* _a;
            Calculatrice::Nombre* _b;

        public:
            Calculatrice::Complexe();

            QString Calculatrice::toString(){
                return QString(this->_a + "+" + this->_b + "i");
            }

            //Impl�mentation des m�thodes virtuelles pures de la class "Expression"
            void EVAL();

            //M�thodes publiques
            void conjugue();
            Constante& module() const;
            Constante& addition(const Constante& c) const;
            Constante& soustraction(const Constante& c) const;
            Constante& multiplication(const Constante& c) const;
            Constante& division(const Constante& c) const;

    };
}

#endif // COMPLEXE_H
