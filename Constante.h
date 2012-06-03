#ifndef CONSTANTE_H
#define CONSTANTE_H

#include <QDebug>

#include "Expression.h"

namespace Calculatrice{
    class Constante : public Expression{

        public:
            //M�thodes sp�cifique

            virtual Constante& SIGN() const =0;
            virtual Constante& SQR() const =0;
            virtual Constante& CUBE() const =0;

            void EVAL();

    };
}

#endif // CONSTANTE_H
