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
            /*!
             *  \brief TrigonomÃƒÂ©trie Sinus
             *
             *  Calcul le sinus de l'entier
             *
             */
            /*!
             *  \brief Addition d'un entier
             *
             *  Methode qui permet d'additionner un entier
             *  avec un nombre
             *
             *  \param nb: le nombre Ãƒ  ajouter Ãƒ  l'entier
             */
            Nombre& addition(const Nombre& nb) const;
            /*!
             *  \brief Soustraction d'un entier
             *
             *  Methode qui permet de soustraire un nombre
             *  Ãƒ  un entier
             *
             *  \param nb: le nombre effectuant la soustraction sur l'entier
             */
            Nombre& soustraction(const Nombre& nb) const;
            Nombre& multiplication(const Nombre& nb) const;
            Nombre& division(const Nombre& nb) const;

            QString toString() const;

            //Implementation des mÃ©thodes virtuelles pures de la class "Expression"
            void EVAL();

            //MÃ©thodes
            Rationnel& toRationnel() const;
            Reel& toReel() const;

            void MOD();
            void FACTORIELLE();

            int get_x() const{ return _x;}

            //Constructeurs
            Entier(int x=0):Reel(x),_x(x){}

    };
}


#endif // ENTIER_H
