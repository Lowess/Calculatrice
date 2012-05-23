#ifndef NOMBRE_H
#define NOMBRE_H

#include <QTextStream>
#include <QString>

#include "Constante.h"
#include "CalculatriceException.h"

/**
  Nombre implémente le Design Pattern Template/Methode
  **/
namespace Calculatrice{
    class Nombre: public Constante {
        private:

        public:
            //Méthodes virtuelles pures
            virtual void SIN() =0;
            virtual void COS() =0;
            virtual void TAN() =0;
            virtual void SINH() =0;
            virtual void COSH() =0;
            virtual void TANH() =0;
            virtual void LN() =0;
            virtual void LOG() =0;
            virtual void INV() =0;
            virtual void SQRT() =0;
            virtual void POW() =0;

            virtual QString toString() const =0;

            //Méthodes virtuelles pures hérité de la class "Expression"
            void EVAL() =0;

            //Implémentation du Template/Methode
            virtual Nombre& addition(const Nombre& nb) =0;
            virtual Nombre& soustraction(const Nombre& nb) =0;
            virtual Nombre& multiplication(const Nombre& nb) =0;
            virtual Nombre& division(const Nombre& nb) =0;

            Nombre& operator+(const Nombre& nb){ return this->addition(nb); }
            Nombre& operator-(const Nombre& nb){ return this->soustraction(nb); }
            Nombre& operator*(const Nombre& nb){ return this->multiplication(nb); }
            Nombre& operator/(const Nombre& nb){ return this->division(nb); }

            void afficher() const{
                QTextStream cout(stdout, QIODevice::WriteOnly);
                cout << this->toString();
            }
    };
}

//operator<<

QTextStream& operator<<(QTextStream& s, const Calculatrice::Nombre& n);

#endif // NOMBRE_H
