#ifndef ADDITION_H
#define ADDITION_H

#include "Operateur.h"

namespace Calculatrice{
    class Addition: public Operateur {
        private:
            static char op;

        public:
            string getOperateur() const {
                return op;
            }

    };

}

#endif // ADDITION_H
