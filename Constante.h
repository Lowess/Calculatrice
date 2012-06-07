#ifndef CONSTANTE_H
#define CONSTANTE_H

#include <QDebug>

#include "Expression.h"

namespace Calculatrice{
    class Constante : public Expression{
        private:

        public:
            //Méthodes spécifique

            virtual Constante& SIGN() const;
            virtual Constante& SQR() const;
            virtual Constante& CUBE() const;


            Constante& operator+(const Constante& nb){ return this->addition(nb); }
            Constante& operator-(const Constante& nb){ return this->soustraction(nb); }
            Constante& operator*(const Constante& nb){ return this->multiplication(nb); }
            Constante& operator/(const Constante& nb){ return this->division(nb); }

            //Implémentation du Template/Methode
            virtual Constante& addition(const Constante& nb) const=0;
            virtual Constante& soustraction(const Constante& nb) const=0;
            virtual Constante& multiplication(const Constante& nb) const=0;
            virtual Constante& division(const Constante& nb) const=0;

    };
}

#endif // CONSTANTE_H
