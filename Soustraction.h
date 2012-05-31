#ifndef SOUSTRACTION_H
#define SOUSTRACTION_H

#include "Operateur.h"

namespace Calculatrice{
    class Soustraction: public Operateur {
        private:
            static char op;

        public:
            string getOperateur() const {
                return op;
            }

    };

}

#endif // SOUSTRACTION_H
