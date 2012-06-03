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
            virtual Nombre& SIN() const;
            virtual Nombre& COS() const;
            virtual Nombre& TAN() const;
            virtual Nombre& SINH() const;
            virtual Nombre& COSH() const;
            virtual Nombre& TANH() const;
            virtual Nombre& LN() const;
            virtual Nombre& LOG() const;
            virtual Nombre& INV() const;
            virtual Nombre& SQRT() const;
            virtual Nombre& POW() const;

            virtual Entier& toEntier() const;
            virtual Reel& toReel() const;
            virtual Rationnel& toRationnel() const;

            QString toString() const =0;

            Nombre& SIGN() const;
            Nombre& SQR() const;
            Nombre& CUBE() const;

            //ImplÃ©mentation du Template/Methode
            virtual Nombre& addition(const Nombre& nb) const=0;
            virtual Nombre& soustraction(const Nombre& nb) const=0;
            virtual Nombre& multiplication(const Nombre& nb) const=0;
            virtual Nombre& division(const Nombre& nb) const=0;

            //virtual Nombre& affectation(const Nombre& nb) =0;

            Nombre& operator+(const Nombre& nb){ return this->addition(nb); }
            Nombre& operator-(const Nombre& nb){ return this->soustraction(nb); }
            Nombre& operator*(const Nombre& nb){ return this->multiplication(nb); }
            Nombre& operator/(const Nombre& nb){ return this->division(nb); }

            //Nombre& operator=(const Nombre& nb){ return this=affectation(nb); }

    };
}
#endif // NOMBRE_H
