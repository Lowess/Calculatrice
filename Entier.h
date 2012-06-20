#ifndef ENTIER_H
#define ENTIER_H

/*! \file Entier.h
  * \author Florian Dambrine, Olivia Reaney
  * \brief Fichier d'en-t�te pour d�claration de la classe Entier
  */

#include <iostream>
#include <typeinfo>
#include "Reel.h"
#include "CalculatriceException.h"

/*! \namespace LO21
 *  \brief D�signe les classes d�finies dans le but du projet de LO21 P12
 */
namespace LO21{
    /*! \class Entier
     * \brief Classe repr�sentant un entier
     *  La classe g�re les op�rations sur les entiers positifs et n�gatifs
     */
    class Entier: public Reel{
        private:
            int _x; /*! L'entier */
        public:

            /*! \fn Constante& addition(const Constante& nb) const
             * \brief G�re l'addition entre un entier et une constante quelle qu'elle soit
             * \param nb une r�f�rence vers une constante
             * \return Constante& une r�f�rence vers la constante cr��e � partir du r�sultat
             */
            Constante& addition(const Constante& nb) const;

            /*! \fn Constante& soustraction(const Constante& nb) const
             * \brief G�re la soustraction entre un entier et une constante quelle qu'elle soit
             * \param nb une r�f�rence vers une constante
             * \return Constante& une r�f�rence vers la constante cr��e � partir du r�sultat
             */
            Constante& soustraction(const Constante& nb) const;

            /*! \fn Constante& multiplication(const Constante& nb) const
             * \brief G�re la multiplication entre un entier et une constante quelle qu'elle soit
             * \param nb une r�f�rence vers une constante
             * \return Constante& une r�f�rence vers la constante cr��e � partir du r�sultat
             */
            Constante& multiplication(const Constante& nb) const;

            /*! \fn Constante& division(const Constante& nb) const
             * \brief G�re la division entre un entier et une constante quelle qu'elle soit
             * \param nb une r�f�rence vers une constante
             * \return Constante& une r�f�rence vers la constante cr��e � partir du r�sultat
             */
            Constante& division(const Constante& nb) const;

            /*! \fn QString toString() const
             * \brief Permet d'afficher sous forme textuelle un objet Entier
             * \return QString contenant le texte repr�sentant l'Entier
             */
            QString toString() const;

            //MÃ©thodes

            /*! \fn Rationnel& toRationnel() const
             * \brief Transforme un entier en rationnel
             * \return Rationnel& une r�f�rence vers le rationnel cr��
             */
            Rationnel& toRationnel() const;

            /*! \fn Reel& toReel() const
             * \brief Transforme un entier en reel
             * \return Reel& une r�f�rence vers le r�el cr��
             */
            Reel& toReel() const;

            /*! \fn Complexe& toComplexe() const
             * \brief Transforme un entier en complexe
             * \return Complexe& une r�f�rence vers le complexe cr��
             */
            Complexe& toComplexe() const;

            /*! \fn Entier& MOD(const Entier& nb) const
             * \brief Permet d'appliquer l'op�rateur modulo sur un entier
             * \param nb l'entier param�tre du modulo
             * \return Entier& une r�f�rence vers l'entier r�sultant du modulo
             */
            Entier& MOD(const Entier& nb);

            /*! \fn Entier& FACTORIELLE()
             * \brief Permet de calculer la factorielle d'un entier
             * \return Entier& une r�f�rence vers l'entier cr�� � partir du r�sultat
             */
            Entier& FACTORIELLE();

            /*! \fn int get_x() const
             * \brief Retourne l'entier utilis� dans l'objet Entier
             * \return int l'entier utilis� comme attribut de l'objet Entier
             */
            int get_x() const{ return _x;}

            //Constructeurs
            /*! \fn Entier(int x)
             * \brief Constructeur de la classe Entier
             * \param x l'entier dont on veut la correspondance dans notre classe Entier
             */
            Entier(int x=0):Reel(x),_x(x){}

            /*! \fn bool operator==(const Entier& e)
             * \brief Teste si la valeur d'un Entier est �gale � la valeur d'un autre Entier
             * \param e l'Entier dont la valeur est � tester
             * \return bool d�terminant la v�racit� de la proposition logique
             */
            bool operator==(const Entier& e){
                return _x == e._x;
            }

            /*! \fn Entier* clone() const
             * \brief Recopie l'objet Entier appelant
             * \return Entier* un pointeur vers l'objet Entier cr��
             */
            Entier* clone() const;
    };
}

/*! \fn int factorielle(int n)
 * \brief Ex�cute la factorielle du nombre n pass� en argument
 * \param n Entier � partir duquel la factorielle va �tre calcul�e
 * \return int le r�sultat de la factorielle
 */
int factorielle(int n);

#endif // ENTIER_H
