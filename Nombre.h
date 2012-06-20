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
#include "LogSystem.h"

/*! \namespace LO21
 *  \brief Désigne les classes définies dans le but du projet de LO21 P12
 */
namespace LO21{
    class Entier;
    class Reel;
    class Rationnel;

    /*! \class Complexe
     * \brief Classe permettant de gérer les nombres complexes
     */
    class Nombre: public Constante {
        private:

        public:
            //Méthodes virtuelles
        /*! \class Complexe
         * \brief Classe permettant de gérer les nombres complexes
         */
            virtual Constante& SIN() const;
        /*! \class Complexe
         * \brief Classe permettant de gérer les nombres complexes
         */
        virtual Constante& COS() const;
        /*! \class Complexe
         * \brief Classe permettant de gérer les nombres complexes
         */
        virtual Constante& TAN() const;
        /*! \class Complexe
         * \brief Classe permettant de gérer les nombres complexes
         */
        virtual Constante& SINH() const;
        /*! \class Complexe
         * \brief Classe permettant de gérer les nombres complexes
         */
        virtual Constante& COSH() const;
        /*! \class Complexe
         * \brief Classe permettant de gérer les nombres complexes
         */
        virtual Constante& TANH() const;
        /*! \class Complexe
         * \brief Classe permettant de gérer les nombres complexes
         */
        virtual Constante& LN() const;
        /*! \class Complexe
         * \brief Classe permettant de gérer les nombres complexes
         */
        virtual Constante& LOG() const;
        /*! \class Complexe
         * \brief Classe permettant de gérer les nombres complexes
         */
        virtual Constante& INV() const;
        /*! \class Complexe
         * \brief Classe permettant de gérer les nombres complexes
         */
        virtual Constante& SQRT() const;
        /*! \class Complexe
         * \brief Classe permettant de gérer les nombres complexes
         */
        virtual Constante& POW(const Nombre& nb) const;

        /*! \class Complexe
         * \brief Classe permettant de gérer les nombres complexes
         */
        virtual Entier& toEntier() const;

        /*! \class Complexe
         * \brief Classe permettant de gérer les nombres complexes
         */
        virtual Reel& toReel() const;

        /*! \class Complexe
         * \brief Classe permettant de gérer les nombres complexes
         */
        virtual Rationnel& toRationnel() const;

        /*! \class Complexe
         * \brief Classe permettant de gérer les nombres complexes
         */
        QString toString() const =0;

        /*! \class Complexe
         * \brief Classe permettant de gérer les nombres complexes
         */
        Nombre& SIGN() const;

            //ImplÃ©mentation du Template/Methode
        /*! \class Complexe
         * \brief Classe permettant de gérer les nombres complexes
         */
        virtual Constante& addition(const Constante& nb) const=0;

        /*! \class Complexe
         * \brief Classe permettant de gérer les nombres complexes
         */
        virtual Constante& soustraction(const Constante& nb) const=0;

        /*! \class Complexe
         * \brief Classe permettant de gérer les nombres complexes
         */
        virtual Constante& multiplication(const Constante& nb) const=0;

        /*! \class Complexe
         * \brief Classe permettant de gérer les nombres complexes
         */
        virtual Constante& division(const Constante& nb) const=0;

            //Méthode qui va permettre d'appliquer le mode de constante utilisateur;

        /*! \class Complexe
         * \brief Classe permettant de gérer les nombres complexes
         */
        Constante& hookOperation();


        /*! \class Complexe
         * \brief Classe permettant de gérer les nombres complexes
         */
        bool operator==(const Nombre& nb) const;

        /*! \class Complexe
         * \brief Classe permettant de gérer les nombres complexes
         */
        bool operator==(int nb) const;


        /*! \class Complexe
         * \brief Classe permettant de gérer les nombres complexes
         */
        Nombre* clone() const=0;
    };
}
#endif // NOMBRE_H
