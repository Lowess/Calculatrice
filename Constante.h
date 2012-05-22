#ifndef CONSTANTE_H
#define CONSTANTE_H

#include "Expression.h"

namespace Calculatrice{
    class Constante: public Expression {
        private:

        public:
            void EVAL() =0;
    };

}

#endif // CONSTANTE_H
