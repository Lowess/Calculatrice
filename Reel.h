/** \file Reel.h
  * \author Florian Dambrine, Olivia Reaney
  * \brief Fichier d'en-tête pour déclaration de la classe Reel
  */

#ifndef REEL_H
#define REEL_H

#include <iostream>
#include <math.h>

#include <QString>
#include <QStringList>

#include "Nombre.h"
#include "Complexe.h"

namespace LO21{
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

            //MÃƒÂ©thodes
            Rationnel& toRationnel() const;
            Entier& toEntier() const;
            Complexe& toComplexe() const;

            //Setter Getter

            float get_x() const{ return _x; }

            //Constructeurs
            Reel(const double x=0.):_x(x){}

            Reel* clone() const;
    };
}

#endif // REEL_H
