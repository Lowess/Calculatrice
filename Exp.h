#ifndef EXP_H
#define EXP_H


#include "Constante.h"

namespace Calculatrice{
    class Exp: public Constante {
        private:
            const QString _exp;
        public:
            Exp(const QString& s):_exp(s){}

            Constante& addition(const Constante& nb) const;
            Constante& soustraction(const Constante& nb) const;
            Constante& multiplication(const Constante& nb) const;
            Constante& division(const Constante& nb) const;

            void EVAL();

            QString toString() const;

    };
}

#endif // EXP_H
