#ifndef OPERATEUR_H
#define OPERATEUR_H

#include "Expression.h"

namespace Calculatrice{
    class Operateur: public Expression {
        private:
            Calculatrice::Expression** _exp;
            unsigned int _length;

        public:
            Calculatrice::Operateur(unsigned int length_nb = 1, string sign = '');

            virtual string getOperator() = 0;

            Expression& Calculatrice::EVAL();

    };

}

#endif // OPERATEUR_H
