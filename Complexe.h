#ifndef COMPLEXE_H
#define COMPLEXE_H

#include <iostream>
#include "Constante.h"
#include "Nombre.h"

#include <QString>

namespace Calculatrice{
    class Complexe: public Constante{
        private:
            Nombre& _a;
            Nombre& _b;

        public:
            Complexe(Nombre& a, Nombre& b):_a(a),_b(b){}

            QString toString() const{
                return (QString(_a.toString() + "+" + _b.toString() + "i"));
            }

            //MÃ©thodes publiques
            void conjugue();
            Constante& module() const;
            Constante& addition(const Complexe& c) const;
            Constante& soustraction(const Complexe& c) const;
            Constante& multiplication(const Complexe& c) const;
            Constante& division(const Complexe& c) const;

            Constante& SIGN() const;
            Constante& SQR() const;
            Constante& CUBE() const;

    };
}

#endif // COMPLEXE_H
