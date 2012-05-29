#ifndef REEL_H
#define REEL_H

#include <iostream>
#include <math.h>

#include <QString>
#include <QStringList>

#include "Nombre.h"
#include "Entier.h"

namespace Calculatrice{
    class Rationnel;
    class Entier;

    class Reel: public Nombre{
        private:
            double _x;
        public:
            //Implémentation des méthodes virtuelles pures de la class "Nombre"
            Nombre& SIN() const;
            Nombre& COS() const;
            Nombre& TAN() const;
            Nombre& SINH() const;
            Nombre& COSH() const;
            Nombre& TANH() const;
            Nombre& LN() const;
            Nombre& LOG() const;
            //Nombre& INV() const;
            Nombre& SQRT() const;
            Nombre& POW() const;

            Nombre& addition(const Nombre& nb) const;
            Nombre& soustraction(const Nombre& nb) const;
            Nombre& multiplication(const Nombre& nb) const;
            Nombre& division(const Nombre& nb) const;

            QString toString() const;

            //Implementation des méthodes virtuelles pures de la class "Expression"
            void EVAL();

            //Méthodes
            Rationnel& toRationnel() const;
            Entier& toEntier() const;


            //Setter Getter

            float get_x() const{ return _x; }

            //Constructeurs
            Reel(const double x=0.):_x(x){}
    };
}

#endif // REEL_H
