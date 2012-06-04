#ifndef CONSTANTE_H
#define CONSTANTE_H

#include <QDebug>

#include "Expression.h"

namespace Calculatrice{
    class Constante : public Expression{
        private:

        public:
            //Méthodes spécifique

            virtual Constante& SIGN() const =0;
            virtual Constante& SQR() const =0;
            virtual Constante& CUBE() const =0;

    };
}

#endif // CONSTANTE_H
