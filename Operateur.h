#ifndef OPERATEUR_H
#define OPERATEUR_H

#include "Expression.h"

#include "Fabrique.h"
#include "Pile.h"
#include <QString>
#include <QStringList>

namespace Calculatrice{
    enum enumOperateurs {ADD, MUL, SOU, DIV, COS, SIN, TAN, COSH, SINH, TANH, SQR, CUBE, SQRT, INV, SIGN, LN, LOG, POW};

    class Operateur: public Expression {
        protected:
            enumOperateurs _operateur;

        public:

            QString toString() const;

            //Expression& EVAL();

            virtual QString getOperator() const{ return toString(); }

            void appliqueOperateur();

            void EVAL();

            QString& afficher();

    };
}

#endif // OPERATEUR_H
