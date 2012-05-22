#ifndef OPERATEUR_H
#define OPERATEUR_H

#include "Expression.h"

namespace Calculatrice{
    class Operateur: public Expression {
        private:
            char _sign;
            Calculatrice::Expression* _exp;
        public:

    };

}

#endif // OPERATEUR_H
