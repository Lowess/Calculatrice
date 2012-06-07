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
/*
            Constante& SIGN() const;
            Constante& SQR() const;
            Constante& CUBE() const;
*/
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

            //Nombre& operator=(const Nombre& nb){ return this=affectation(nb); }

            bool operator==(const Constante& nb);
            bool operator==(int nb);

            //virtual Nombre& affectation(const Nombre& nb) =0;
    };
}
#endif // NOMBRE_H
