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
        private:
            unsigned int _nbItems;
            Expression** _exp;
            bool _expEntiere;

        public:
            QString& afficher();

            QString toString() const =0;

            virtual QString& getOperator() const = 0 ;

            void appliqueOperateur();

            //Expression EVAL();
            void EVAL();


    };
}

#endif // OPERATEUR_H
