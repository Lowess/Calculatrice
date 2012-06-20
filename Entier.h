#ifndef ENTIER_H
#define ENTIER_H

/*! \file Entier.h
  * \author Florian Dambrine, Olivia Reaney
  * \brief Fichier d'en-tête pour déclaration de la classe Entier
  */

#include <iostream>
#include <typeinfo>
#include "Reel.h"
#include "CalculatriceException.h"

/*! \namespace LO21
 *  \brief Désigne les classes définies dans le but du projet de LO21 P12
 */
namespace LO21{
    /*! \class Entier
     * \brief Classe représentant un entier
     *  La classe gère les opérations sur les entiers positifs et négatifs
     */
    class Entier: public Reel{
        private:
            int _x; /*! L'entier */
        public:

            /*! \class Complexe
             * \brief Classe permettant de gérer les nombres complexes
             */
            Constante& addition(const Constante& nb) const;

            /*! \class Complexe
             * \brief Classe permettant de gérer les nombres complexes
             */
            Constante& soustraction(const Constante& nb) const;

            /*! \class Complexe
             * \brief Classe permettant de gérer les nombres complexes
             */
            Constante& multiplication(const Constante& nb) const;

            /*! \class Complexe
             * \brief Classe permettant de gérer les nombres complexes
             */
            Constante& division(const Constante& nb) const;

            /*! \class Complexe
             * \brief Classe permettant de gérer les nombres complexes
             */
            QString toString() const;

            //MÃƒÂ©thodes

            /*! \class Complexe
             * \brief Classe permettant de gérer les nombres complexes
             */
            Rationnel& toRationnel() const;

            /*! \class Complexe
             * \brief Classe permettant de gérer les nombres complexes
             */
            Reel& toReel() const;

            /*! \class Complexe
             * \brief Classe permettant de gérer les nombres complexes
             */
            Complexe& toComplexe() const;

            /*! \class Complexe
             * \brief Classe permettant de gérer les nombres complexes
             */
            Entier& MOD(const Entier& nb);

            /*! \class Complexe
             * \brief Classe permettant de gérer les nombres complexes
             */
            Entier& FACTORIELLE();

            /*! \class Complexe
             * \brief Classe permettant de gérer les nombres complexes
             */
            int get_x() const{ return _x;}

            //Constructeurs
            /*! \class Complexe
             * \brief Classe permettant de gérer les nombres complexes
             */
            Entier(int x=0):Reel(x),_x(x){}

            /*! \class Complexe
             * \brief Classe permettant de gérer les nombres complexes
             */
            bool operator==(const Entier& e) {
                return _x == e._x;
            }

            /*! \class Complexe
             * \brief Classe permettant de gérer les nombres complexes
             */
            Entier* clone() const;
    };
}

/*! \class Complexe
 * \brief Classe permettant de gérer les nombres complexes
 */
int factorielle(int n);

#endif // ENTIER_H
