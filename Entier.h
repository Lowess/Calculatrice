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

            /*! \fn Constante& addition(const Constante& nb) const
             * \brief Gère l'addition entre un entier et une constante quelle qu'elle soit
             * \param nb une référence vers une constante
             * \return Constante& une référence vers la constante créée à partir du résultat
             */
            Constante& addition(const Constante& nb) const;

            /*! \fn Constante& soustraction(const Constante& nb) const
             * \brief Gère la soustraction entre un entier et une constante quelle qu'elle soit
             * \param nb une référence vers une constante
             * \return Constante& une référence vers la constante créée à partir du résultat
             */
            Constante& soustraction(const Constante& nb) const;

            /*! \fn Constante& multiplication(const Constante& nb) const
             * \brief Gère la multiplication entre un entier et une constante quelle qu'elle soit
             * \param nb une référence vers une constante
             * \return Constante& une référence vers la constante créée à partir du résultat
             */
            Constante& multiplication(const Constante& nb) const;

            /*! \fn Constante& division(const Constante& nb) const
             * \brief Gère la division entre un entier et une constante quelle qu'elle soit
             * \param nb une référence vers une constante
             * \return Constante& une référence vers la constante créée à partir du résultat
             */
            Constante& division(const Constante& nb) const;

            /*! \fn QString toString() const
             * \brief Permet d'afficher sous forme textuelle un objet Entier
             * \return QString contenant le texte représentant l'Entier
             */
            QString toString() const;

            //MÃƒÂ©thodes

            /*! \fn Rationnel& toRationnel() const
             * \brief Transforme un entier en rationnel
             * \return Rationnel& une référence vers le rationnel créé
             */
            Rationnel& toRationnel() const;

            /*! \fn Reel& toReel() const
             * \brief Transforme un entier en reel
             * \return Reel& une référence vers le réel créé
             */
            Reel& toReel() const;

            /*! \fn Complexe& toComplexe() const
             * \brief Transforme un entier en complexe
             * \return Complexe& une référence vers le complexe créé
             */
            Complexe& toComplexe() const;

            /*! \fn Entier& MOD(const Entier& nb) const
             * \brief Permet d'appliquer l'opérateur modulo sur un entier
             * \param nb l'entier paramètre du modulo
             * \return Entier& une référence vers l'entier résultant du modulo
             */
            Entier& MOD(const Entier& nb);

            /*! \fn Entier& FACTORIELLE()
             * \brief Permet de calculer la factorielle d'un entier
             * \return Entier& une référence vers l'entier créé à partir du résultat
             */
            Entier& FACTORIELLE();

            /*! \fn int get_x() const
             * \brief Retourne l'entier utilisé dans l'objet Entier
             * \return int l'entier utilisé comme attribut de l'objet Entier
             */
            int get_x() const{ return _x;}

            //Constructeurs
            /*! \fn Entier(int x)
             * \brief Constructeur de la classe Entier
             * \param x l'entier dont on veut la correspondance dans notre classe Entier
             */
            Entier(int x=0):Reel(x),_x(x){}

            /*! \fn bool operator==(const Entier& e)
             * \brief Teste si la valeur d'un Entier est égale à la valeur d'un autre Entier
             * \param e l'Entier dont la valeur est à tester
             * \return bool déterminant la véracité de la proposition logique
             */
            bool operator==(const Entier& e){
                return _x == e._x;
            }

            /*! \fn Entier* clone() const
             * \brief Recopie l'objet Entier appelant
             * \return Entier* un pointeur vers l'objet Entier créé
             */
            Entier* clone() const;
    };
}

/*! \fn int factorielle(int n)
 * \brief Exécute la factorielle du nombre n passé en argument
 * \param n Entier à partir duquel la factorielle va être calculée
 * \return int le résultat de la factorielle
 */
int factorielle(int n);

#endif // ENTIER_H
