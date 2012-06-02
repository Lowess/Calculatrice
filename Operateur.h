#ifndef OPERATEUR_H
#define OPERATEUR_H

#include "Expression.h"

namespace Calculatrice{
    class Operateur: public Expression {
        private:
            Calculatrice::Expression** _exp;
            bool _firstOp;
            unsigned int _length;

        public:
            Calculatrice::Operateur(unsigned int length_nb = 1, string sign = ''):_firstOp(false) {

            }

            virtual string getOperator() = 0;

            Expression& Calculatrice::EVAL();

    };

}

#endif // OPERATEUR_H
