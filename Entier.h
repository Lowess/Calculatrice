#ifndef ENTIER_H
#define ENTIER_H

/*!
 * \file Entier.h
 * \brief Manipulation d'entiers
 * \author Dambrine.F
 * \version 0.1
 */

#include <iostream>
#include <typeinfo>

#include "Reel.h"
#include "CalculatriceException.h"

/*! \namespace Calculatrice
 *
 * espace de nommage regroupant les outils composants
 * la calculatrice
 */
namespace Calculatrice{
    /*! \class Entier
     * \brief classe representant un entier
     *
     *  La classe gere les opÃƒÂ©rations sur les entiers positifs et nÃƒÂ©gatifs
     */
    class Entier: public Reel{
        private:
            int _x; /*!< L'entier */
        public:

            Constante& addition(const Constante& nb) const;
            Constante& soustraction(const Constante& nb) const;
            Constante& multiplication(const Constante& nb) const;
            Constante& division(const Constante& nb) const;

            QString toString() const;

            //MÃ©thodes
            Rationnel& toRationnel() const;
            Reel& toReel() const;
            Complexe& toComplexe() const;

            void MOD();
            void FACTORIELLE();

            int get_x() const{ return _x;}

            //Constructeurs
            Entier(int x=0):Reel(x),_x(x){}

            bool operator==(const Entier& e) {
                return _x == e._x;
            }

    };
}


#endif // ENTIER_H
