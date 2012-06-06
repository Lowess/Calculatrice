#ifndef REEL_H
#define REEL_H

#include <iostream>
#include <math.h>

#include <QString>
#include <QStringList>

#include "Nombre.h"

namespace Calculatrice{
    class Rationnel;
    class Entier;

    class Reel: public Nombre{
        private:
            double _x;
        public:
            Constante& addition(const Constante& nb) const;
            Constante& soustraction(const Constante& nb) const;
            Constante& multiplication(const Constante& nb) const;
            Constante& division(const Constante& nb) const;

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
