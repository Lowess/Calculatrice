#ifndef NOMBRE_H
#define NOMBRE_H

#include <QString>

#include "Constante.h"
#include "CalculatriceException.h"

/**
  Nombre implÃ©mente le Design Pattern Template/Methode
  **/
namespace Calculatrice{
    class Entier;
    class Reel;
    class Rationnel;

    class Nombre: public Constante {
        private:

        public:
            //M�thodes virtuelles
            virtual Constante& SIN() const;
            virtual Constante& COS() const;
            virtual Constante& TAN() const;
            virtual Constante& SINH() const;
            virtual Constante& COSH() const;
            virtual Constante& TANH() const;
            virtual Constante& LN() const;
            virtual Constante& LOG() const;
            virtual Constante& INV() const;
            virtual Constante& SQRT() const;
            virtual Constante& POW(const Nombre& nb) const;

            virtual Entier& toEntier() const;
            virtual Reel& toReel() const;
            virtual Rationnel& toRationnel() const;

            QString toString() const =0;
            Nombre& SIGN() const;

            //Implémentation du Template/Methode
            virtual Constante& addition(const Constante& nb) const=0;
            virtual Constante& soustraction(const Constante& nb) const=0;
            virtual Constante& multiplication(const Constante& nb) const=0;
            virtual Constante& division(const Constante& nb) const=0;

/*
            Nombre& operator+(const Nombre& nb){ return this->addition(nb); }
            Nombre& operator-(const Nombre& nb){ return this->soustraction(nb); }
            Nombre& operator*(const Nombre& nb){ return this->multiplication(nb); }
            Nombre& operator/(const Nombre& nb){ return this->division(nb); }
*/

            bool operator==(const Nombre& nb) const;
            bool operator==(int nb) const;

            //Nombre& operator=(const Nombre& nb){ return this=affectation(nb); }
            //virtual Nombre& affectation(const Nombre& nb) =0;
    };
}
#endif // NOMBRE_H
