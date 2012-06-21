#ifndef REEL_H
#define REEL_H

/*! \file Reel.h
  * \author Florian Dambrine, Olivia Reaney
  * \brief Fichier d'en-tete pour declaration de la classe Reel
  */

#include <iostream>
#include <math.h>
#include <QString>
#include <QStringList>

#include "Nombre.h"
#include "Complexe.h"

/*! \namespace LO21
 *  \brief Designe les classes definies dans le but du projet de LO21 P12
 */
namespace LO21{
    class Rationnel;
    class Entier;

    /*! \class Reel
     * \brief Classe permettant de gerer les nombres reels
     */
    class Reel: public Nombre{
        private:
            double _x; /*! Le nombre reel */
        public:
            /*! \fn Constante& addition(const Constante& nb) const
             * \brief Gere l'addition entre un reel et une constante quelle qu'elle soit
             * \param nb une reference vers une constante
             * \return Constante& une reference vers la constante creee a partir du resultat
             */
            Constante& addition(const Constante& nb) const;

            /*! \fn Constante& soustraction(const Constante& nb) const
             * \brief Gere la soustraction entre un reel et une constante quelle qu'elle soit
             * \param nb une reference vers une constante
             * \return Constante& une reference vers la constante creee a partir du resultat
             */
            Constante& soustraction(const Constante& nb) const;

            /*! \fn Constante& multiplication(const Constante& nb) const
             * \brief Gere la multiplication entre un reel et une constante quelle qu'elle soit
             * \param nb une reference vers une constante
             * \return Constante& une reference vers la constante creee a partir du resultat
             */
            Constante& multiplication(const Constante& nb) const;

            /*! \fn Constante& division(const Constante& nb) const
             * \brief Gere la division entre un reel et une constante quelle qu'elle soit
             * \param nb une reference vers une constante
             * \return Constante& une reference vers la constante creee a partir du resultat
             */
            Constante& division(const Constante& nb) const;

            /*! \fn QString toString() const
             * \brief Permet l'affichage du reel
             * \return QString contenant le texte representant le reel
             */
            QString toString() const;

            //MÃƒa©thodes

            /*! \fn Rationnel& toRationnel() const
             * \brief Transforme un reel en rationnel
             * \return Rationnel& une reference vers le rationnel cree a partir du reel
             */
            Rationnel& toRationnel() const;

            /*! \fn Entier& toEntier() const
             * \brief Transforme un reel en entier
             * \return Entier& une reference vers l'entier cree a partir du reel
             */
            Entier& toEntier() const;

            /*! \fn Complexe& toComplexe() const
             * \brief Transforme un reel en nombre complexe
             * \return Complexe& une reference vers le complexe cree a partir du reel
             */
            Complexe& toComplexe() const;

            //Setter Getter

            /*! \fn float get_x() const
             * \brief Recupere la valeur du reel
             * \return float contenant la valeur du reel
             */
            float get_x() const{ return _x; }

            //Constructeurs
            /*! \fn Reel(const double x)
             * \brief Constructeur de la classe Reel
             * \param x un double afin d'instancier un objet Reel
             */
            Reel(const double x=0.):_x(x){}

            /*! \fn Reel* clone() const
             * \brief Fais une copie de l'objet appelant
             * \return Reel* un pointeur vers le reel cree a partir de l'objet
             */
            Reel* clone() const;
    };
}

#endif // REEL_H
