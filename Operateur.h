#ifndef OPERATEUR_H
#define OPERATEUR_H

#include "Expression.h"

#include "Fabrique.h"
#include "Pile.h"
#include <QString>
#include <QStringList>

namespace Calculatrice{
    enum enumOperateurs {ADD, MUL, SOU, DIV, COS, SIN, TAN, COSH, SINH, TANH, SQR, CUBE, SQRT, INV, SIGN};

    class Operateur: public Expression {
        protected:
            enumOperateurs _operateur;

        public:
            QString& afficher();

            QString toString() const =0;

            virtual QString getOperator() const{ return toString(); }

            void appliqueOperateur();

            void EVAL();


    };
}

#endif // OPERATEUR_H
