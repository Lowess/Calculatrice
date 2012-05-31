#ifndef MULTIPLICATION_H
#define MULTIPLICATION_H

#include "Operateur.h"

namespace Calculatrice{
    class Multiplication: public Operateur {
        private:
            static char op;
        public:
            string getOperator() const {
                return op;
            }

    };

}

#endif // MULTIPLICATION_H
