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
     *  La classe gere les opérations sur les entiers positifs et négatifs
     */
    class Entier: public Reel{
        private:
            int _x; /*!< L'entier */
        public:
            /*!
             *  \brief Trigonométrie Sinus
             *
             *  Calcul le sinus de l'entier
             *
             */
            //Méthodes virtuelles pures de la class "Nombre"
            void SIN();
            /*!
             *  \brief Trigonométrie Sinus
             *
             *  Calcul le cosinus de l'entier
             *
             */
            void COS();
            /*!
             *  \brief Trigonométrie Sinus
             *
             *  Calcul la tangente de l'entier
             *
             */
            void TAN();
            /*!
             *  \brief Trigonométrie Sinus
             *
             *  Calcul le sinus hyberbolique de l'entier
             *
             */
            void SINH();
            /*!
             *  \brief Trigonométrie Sinus
             *
             *  Calcul le cosinus hyperbolique de l'entier
             *
             */
            void COSH();
            /*!
             *  \brief Trigonométrie Sinus
             *
             *  Calcul la tangente hyperbolique de l'entier
             *
             */
            void TANH();
            /*!
             *  \brief Trigonométrie Sinus
             *
             *  Calcul le logarithme népérien de l'entier
             *
             */
            void LN();
            /*!
             *  \brief Trigonométrie Sinus
             *
             *  Calcul le log base X de l'entier
             *
             */
            void LOG();
            /*!
             *  \brief Trigonométrie Sinus
             *
             *  Inverse l'entier
             *
             */
            void INV();
            /*!
             *  \brief Trigonométrie Sinus
             *
             *  Calcule la racine carrée de l'entier
             *
             */
            void SQRT();
            /*!
             *  \brief Trigonométrie Sinus
             *
             *  Eléve au carré l'entier
             *
             */
            void POW();

            /*!
             *  \brief Addition d'un entier
             *
             *  Methode qui permet d'additionner un entier
             *  avec un nombre
             *
             *  \param nb: le nombre à ajouter à l'entier
             */
            Nombre& addition(const Nombre& nb);
            /*!
             *  \brief Soustraction d'un entier
             *
             *  Methode qui permet de soustraire un nombre
             *  à un entier
             *
             *  \param nb: le nombre effectuant la soustraction sur l'entier
             */
            Nombre& soustraction(const Nombre& nb);
            Nombre& multiplication(const Nombre& nb);
            Nombre& division(const Nombre& nb);

            QString toString() const;

            //Implementation des méthodes virtuelles pures de la class "Expression"
            void EVAL();

            //Méthodes
            void MOD();
            void FACTORIELLE();

            int get_x() const{ return _x;}

            //Constructeurs
            Entier(int x=0):Reel(x),_x(x){}

    };
}

#endif // ENTIER_H
