/** \file Reel.h
  * \author Florian Dambrine, Olivia Reaney
  * \brief Fichier d'en-tête pour déclaration de la classe Reel
  */

#ifndef REEL_H
#define REEL_H

#include <iostream>
#include <math.h>

#include <QString>
#include <QStringList>

#include "Nombre.h"
#include "Complexe.h"

/*! \namespace LO21
 *  \brief Désigne les classes définies dans le but du projet de LO21 P12
 */
namespace LO21{
    class Rationnel;
    class Entier;

    /*! \class Reel
     * \brief Classe permettant de gérer les nombres réels
     */
    class Reel: public Nombre{
        private:
            double _x; /*! Le nombre réel */
        public:
            /*! \fn Constante& addition(const Constante& nb) const
             * \brief Gère l'addition entre un réel et une constante quelle qu'elle soit
             * \param nb une référence vers une constante
             * \return Constante& une référence vers la constante créée à partir du résultat
             */
            Constante& addition(const Constante& nb) const;

            /*! \fn Constante& soustraction(const Constante& nb) const
             * \brief Gère la soustraction entre un réel et une constante quelle qu'elle soit
             * \param nb une référence vers une constante
             * \return Constante& une référence vers la constante créée à partir du résultat
             */
            Constante& soustraction(const Constante& nb) const;

            /*! \fn Constante& multiplication(const Constante& nb) const
             * \brief Gère la multiplication entre un réel et une constante quelle qu'elle soit
             * \param nb une référence vers une constante
             * \return Constante& une référence vers la constante créée à partir du résultat
             */
            Constante& multiplication(const Constante& nb) const;

            /*! \fn Constante& division(const Constante& nb) const
             * \brief Gère la division entre un réel et une constante quelle qu'elle soit
             * \param nb une référence vers une constante
             * \return Constante& une référence vers la constante créée à partir du résultat
             */
            Constante& division(const Constante& nb) const;

            /*! \fn QString toString() const
             * \brief Permet l'affichage du reel
             * \return QString contenant le texte représentant le réel
             */
            QString toString() const;

            //MÃƒÂ©thodes

            /*! \fn Rationnel& toRationnel() const
             * \brief Transforme un réel en rationnel
             * \return Rationnel& une référence vers le rationnel créé à partir du réel
             */
            Rationnel& toRationnel() const;

            /*! \fn Entier& toEntier() const
             * \brief Transforme un réel en entier
             * \return Entier& une référence vers l'entier créé à partir du réel
             */
            Entier& toEntier() const;

            /*! \fn Complexe& toComplexe() const
             * \brief Transforme un réel en nombre complexe
             * \return Complexe& une référence vers le complexe créé à partir du réel
             */
            Complexe& toComplexe() const;

            //Setter Getter

            /*! \fn float get_x() const
             * \brief Récupère la valeur du réel
             * \return float contenant la valeur du réel
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
             * \return Reel* un pointeur vers le réel créé à partir de l'objet
             */
            Reel* clone() const;
    };
}

#endif // REEL_H
