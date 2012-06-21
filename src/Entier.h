#ifndef ENTIER_H
#define ENTIER_H

/*! \file Entier.h
  * \author Florian Dambrine, Olivia Reaney
  * \brief Fichier d'en-tete pour declaration de la classe Entier
  */

#include <iostream>
#include <typeinfo>
#include "Reel.h"
#include "CalculatriceException.h"

/*! \namespace LO21
 *  \brief Designe les classes definies dans le but du projet de LO21 P12
 */
namespace LO21{
    /*! \class Entier
     * \brief Classe representant un entier
     *  La classe gere les operations sur les entiers positifs et negatifs
     */
    class Entier: public Reel{
        private:
            int _x; /*! L'entier */
        public:

            /*! \fn Constante& addition(const Constante& nb) const
             * \brief Gere l'addition entre un entier et une constante quelle qu'elle soit
             * \param nb une reference vers une constante
             * \return Constante& une reference vers la constante creee a partir du resultat
             */
            Constante& addition(const Constante& nb) const;

            /*! \fn Constante& soustraction(const Constante& nb) const
             * \brief Gere la soustraction entre un entier et une constante quelle qu'elle soit
             * \param nb une reference vers une constante
             * \return Constante& une reference vers la constante creee a partir du resultat
             */
            Constante& soustraction(const Constante& nb) const;

            /*! \fn Constante& multiplication(const Constante& nb) const
             * \brief Gere la multiplication entre un entier et une constante quelle qu'elle soit
             * \param nb une reference vers une constante
             * \return Constante& une reference vers la constante creee a partir du resultat
             */
            Constante& multiplication(const Constante& nb) const;

            /*! \fn Constante& division(const Constante& nb) const
             * \brief Gere la division entre un entier et une constante quelle qu'elle soit
             * \param nb une reference vers une constante
             * \return Constante& une reference vers la constante creee a partir du resultat
             */
            Constante& division(const Constante& nb) const;

            /*! \fn QString toString() const
             * \brief Permet d'afficher sous forme textuelle un objet Entier
             * \return QString contenant le texte representant l'Entier
             */
            QString toString() const;

            //MÃƒa©thodes

            /*! \fn Rationnel& toRationnel() const
             * \brief Transforme un entier en rationnel
             * \return Rationnel& une reference vers le rationnel cree
             */
            Rationnel& toRationnel() const;

            /*! \fn Reel& toReel() const
             * \brief Transforme un entier en reel
             * \return Reel& une reference vers le reel cree
             */
            Reel& toReel() const;

            /*! \fn Complexe& toComplexe() const
             * \brief Transforme un entier en complexe
             * \return Complexe& une reference vers le complexe cree
             */
            Complexe& toComplexe() const;

            /*! \fn Entier& MOD(const Entier& nb) const
             * \brief Permet d'appliquer l'operateur modulo sur un entier
             * \param nb l'entier parametre du modulo
             * \return Entier& une reference vers l'entier resultant du modulo
             */
            Entier& MOD(const Entier& nb);

            /*! \fn Entier& FACTORIELLE()
             * \brief Permet de calculer la factorielle d'un entier
             * \return Entier& une reference vers l'entier cree a partir du resultat
             */
            Entier& FACTORIELLE();

            /*! \fn int get_x() const
             * \brief Retourne l'entier utilise dans l'objet Entier
             * \return int l'entier utilise comme attribut de l'objet Entier
             */
            int get_x() const{ return _x;}

            //Constructeurs
            /*! \fn Entier(int x)
             * \brief Constructeur de la classe Entier
             * \param x l'entier dont on veut la correspondance dans notre classe Entier
             */
            Entier(int x=0):Reel(x),_x(x){}

            /*! \fn bool operator==(const Entier& e)
             * \brief Teste si la valeur d'un Entier est egale a la valeur d'un autre Entier
             * \param e l'Entier dont la valeur est a tester
             * \return bool determinant la veracite de la proposition logique
             */
            bool operator==(const Entier& e){
                return _x == e._x;
            }

            /*! \fn Entier* clone() const
             * \brief Recopie l'objet Entier appelant
             * \return Entier* un pointeur vers l'objet Entier cree
             */
            Entier* clone() const;
    };
}

/*! \fn int factorielle(int n)
 * \brief Execute la factorielle du nombre n passe en argument
 * \param n Entier a partir duquel la factorielle va etre calculee
 * \return int le resultat de la factorielle
 */
int factorielle(int n);

#endif // ENTIER_H
