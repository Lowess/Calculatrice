/** \file Constante.h
  * \author Florian Dambrine, Olivia Reaney
  * \brief Fichier d'en-tête pour déclaration de la classe Constante
  */

#ifndef CONSTANTE_H
#define CONSTANTE_H

#include <QDebug>

#include "Expression.h"

/*! \namespace LO21
 *  \brief Désigne les classes définies dans le but du projet de LO21 P12
 */
namespace LO21{

    class Constante : public Expression{
        private:

        public:
            //Méthodes spécifique

            Constante& SIGN() const;
            Constante& SQR() const;
            Constante& CUBE() const;


            Constante& operator+(const Constante& nb){ return this->addition(nb).hookOperation(); }
            Constante& operator-(const Constante& nb){ return this->soustraction(nb).hookOperation(); }
            Constante& operator*(const Constante& nb){ return this->multiplication(nb).hookOperation(); }
            Constante& operator/(const Constante& nb){ return this->division(nb).hookOperation(); }

            //Implémentation du Template/Methode
            virtual Constante& addition(const Constante& nb) const=0;
            virtual Constante& soustraction(const Constante& nb) const=0;
            virtual Constante& multiplication(const Constante& nb) const=0;
            virtual Constante& division(const Constante& nb) const=0;

            virtual Constante& hookOperation()=0;

            void EVAL();

            Constante* clone() const=0;

    };
}

#endif // CONSTANTE_H
