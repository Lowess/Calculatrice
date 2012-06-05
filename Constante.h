#ifndef CONSTANTE_H
#define CONSTANTE_H

#include <QDebug>

#include "Expression.h"

namespace Calculatrice{

    class Complexe;

    class Constante : public Expression{

        public:

            Constante(){}

            //Méthodes spécifique

            virtual Constante& SIGN() const =0;
            virtual Constante& SQR() const =0;
            virtual Constante& CUBE() const =0;

            Expression& EVAL();

    };
}

#endif // CONSTANTE_H
