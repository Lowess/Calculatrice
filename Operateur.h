#ifndef OPERATEUR_H
#define OPERATEUR_H

#include "Expression.h"
#include <QString>

namespace Calculatrice{
    class Operateur: public Expression {
        private:
            Calculatrice::Expression** _exp;
            unsigned int _length;

        public:
            //Operateur(const unsigned int length_nb = 1, const QString& sign = "");

            virtual QString getOperator() = 0;

            //Expression& EVAL();
            void EVAL();

    };
}

#endif // OPERATEUR_H
