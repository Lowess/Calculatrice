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
