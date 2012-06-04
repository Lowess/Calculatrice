#ifndef CALCULATRICE_H
#define CALCULATRICE_H

#include "Pile.h"
#include "Fabrique.h"

namespace Calculatrice{
    class Calculatrice{
        private:
            static Calculatrice* _calc;

            Calculatrice(){}
            Calculatrice(const Calculatrice& c);
            ~Calculatrice(){}
        public:
            static Calculatrice& getInstance();
            static void libereInstance();

    };
}
#endif // CALCULATRICE_H
