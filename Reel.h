/** \file Reel.h
  * \author Florian Dambrine, Olivia Reaney
  * \brief Fichier d'en-t�te pour d�claration de la classe Reel
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
 *  \brief D�signe les classes d�finies dans le but du projet de LO21 P12
 */
namespace LO21{
    class Rationnel;
    class Entier;

    /*! \class Reel
     * \brief Classe permettant de g�rer les nombres r�els
     */
    class Reel: public Nombre{
        private:
            double _x; /*! Le nombre r�el */
        public:
            /*! \fn Constante& addition(const Constante& nb) const
             * \brief G�re l'addition entre un r�el et une constante quelle qu'elle soit
             * \param nb une r�f�rence vers une constante
             * \return Constante& une r�f�rence vers la constante cr��e � partir du r�sultat
             */
            Constante& addition(const Constante& nb) const;

            /*! \fn Constante& soustraction(const Constante& nb) const
             * \brief G�re la soustraction entre un r�el et une constante quelle qu'elle soit
             * \param nb une r�f�rence vers une constante
             * \return Constante& une r�f�rence vers la constante cr��e � partir du r�sultat
             */
            Constante& soustraction(const Constante& nb) const;

            /*! \fn Constante& multiplication(const Constante& nb) const
             * \brief G�re la multiplication entre un r�el et une constante quelle qu'elle soit
             * \param nb une r�f�rence vers une constante
             * \return Constante& une r�f�rence vers la constante cr��e � partir du r�sultat
             */
            Constante& multiplication(const Constante& nb) const;

            /*! \fn Constante& division(const Constante& nb) const
             * \brief G�re la division entre un r�el et une constante quelle qu'elle soit
             * \param nb une r�f�rence vers une constante
             * \return Constante& une r�f�rence vers la constante cr��e � partir du r�sultat
             */
            Constante& division(const Constante& nb) const;

            /*! \fn QString toString() const
             * \brief Permet l'affichage du reel
             * \return QString contenant le texte repr�sentant le r�el
             */
            QString toString() const;

            //MÃ©thodes

            /*! \fn Rationnel& toRationnel() const
             * \brief Transforme un r�el en rationnel
             * \return Rationnel& une r�f�rence vers le rationnel cr�� � partir du r�el
             */
            Rationnel& toRationnel() const;

            /*! \fn Entier& toEntier() const
             * \brief Transforme un r�el en entier
             * \return Entier& une r�f�rence vers l'entier cr�� � partir du r�el
             */
            Entier& toEntier() const;

            /*! \fn Complexe& toComplexe() const
             * \brief Transforme un r�el en nombre complexe
             * \return Complexe& une r�f�rence vers le complexe cr�� � partir du r�el
             */
            Complexe& toComplexe() const;

            //Setter Getter

            /*! \fn float get_x() const
             * \brief R�cup�re la valeur du r�el
             * \return float contenant la valeur du r�el
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
             * \return Reel* un pointeur vers le r�el cr�� � partir de l'objet
             */
            Reel* clone() const;
    };
}

#endif // REEL_H
