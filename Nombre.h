/** \file Nombre.h
  * \author Florian Dambrine, Olivia Reaney
  * \brief Fichier d'en-tête pour déclaration de la classe Nombre
  */

#ifndef NOMBRE_H
#define NOMBRE_H

#include <QString>

#include "Constante.h"
#include "CalculatriceException.h"
#include "Option.h"

/**
  Nombre implÃƒÂ©mente le Design Pattern Template/Methode
  **/
namespace LO21{
    class Entier;
    class Reel;
    class Rationnel;

    class Nombre: public Constante {
        private:

        public:
            //Méthodes virtuelles
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

            //ImplÃ©mentation du Template/Methode
            virtual Constante& addition(const Constante& nb) const=0;
            virtual Constante& soustraction(const Constante& nb) const=0;
            virtual Constante& multiplication(const Constante& nb) const=0;
            virtual Constante& division(const Constante& nb) const=0;

            //Méthode qui va permettre d'appliquer le mode de constante utilisateur;
            Constante& hookOperation();


            bool operator==(const Nombre& nb) const;
            bool operator==(int nb) const;


            Nombre* clone() const=0;
    };
}
#endif // NOMBRE_H
