#ifndef NOMBRE_H
#define NOMBRE_H

#include <QTextStream>
#include <QString>

#include "Constante.h"
#include "CalculatriceException.h"


using namespace Calculatrice;

/**
  Nombre implémente le Design Pattern Template/Methode
  **/
namespace Calculatrice{
    class Nombre: public Constante {
        private:

        public:
            //Méthodes virtuelles pures
            virtual Nombre& SIN() const = 0;
            virtual Nombre& COS() const = 0;
            virtual Nombre& TAN() const = 0;
            virtual Nombre& SINH() const = 0;
            virtual Nombre& COSH() const = 0;
            virtual Nombre& TANH() const = 0;
            virtual Nombre& LN() const = 0;
            virtual Nombre& LOG() const = 0;
            virtual Nombre& INV() const;
            virtual Nombre& SQRT() const = 0;
            virtual Nombre& POW() const = 0;

            virtual QString toString() const =0;

            Nombre& SIGN() const;

            //Méthodes virtuelles pures hérité de la class "Expression"
            void EVAL() =0;

            //Implémentation du Template/Methode
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

            void afficher() const{
                QTextStream cout(stdout, QIODevice::WriteOnly);
                cout << this->toString();
            }
    };
}

//operator<<

QTextStream& operator<<(QTextStream& s, const Calculatrice::Nombre& n);

#endif // NOMBRE_H
