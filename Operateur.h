#ifndef OPERATEUR_H
#define OPERATEUR_H

#include <stdexcept>
#include <QString>
#include <QStringList>

#include "Expression.h"
#include "Fabrique.h"
#include "Pile.h"
#include "Calculatrice.h"

namespace LO21{
    enum enumOperateurs {ADD, MUL, SOU, DIV, COS, SIN, TAN, COSH, SINH, TANH, SQR, CUBE, SQRT, INV, SIGN, LN, LOG, POW, FACT, MOD, EVALUATION};

    class Operateur: public Expression {
        protected:
            enumOperateurs _operateur;

        public:

            QString toString() const =0;

            QString getOperator() const{ return toString(); }

            void appliqueOperateur();

            void EVAL();

            QString& afficher();

            Operateur* clone() const;
    };
}

#endif // OPERATEUR_H
