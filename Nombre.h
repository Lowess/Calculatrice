#ifndef NOMBRE_H
#define NOMBRE_H

/*! \file Nombre.h
  * \author Florian Dambrine, Olivia Reaney
  * \brief Fichier d'en-t�te pour d�claration de la classe Nombre
  */

#include <QString>
#include "Constante.h"
#include "CalculatriceException.h"
#include "Option.h"
#include "LogSystem.h"

/*! \namespace LO21
 *  \brief D�signe les classes d�finies dans le but du projet de LO21 P12
 */
namespace LO21{
    class Entier;
    class Reel;
    class Rationnel;

    /*! \class Nombre
     * \brief Classe encapsulant les classes Entier, Rationnel et R�el
     */
    class Nombre: public Constante {
        public:

        /*! \fn virtual Constante& SIN() const
         * \brief Calcule le sinus du nombre
         * \return Constante& une r�f�rence vers la constante issue du r�sultat
         */
        virtual Constante& SIN() const;

        /*! \fn virtual Constante& COS() const
         * \brief Calcule le cosinus du nombre
         * \return Constante& une r�f�rence vers la constante issue du r�sultat
         */
        virtual Constante& COS() const;

        /*! \fn virtual Constante& TAN() const
         * \brief Calcule la tangente du nombre
         * \return Constante& une r�f�rence vers la constante issue du r�sultat
         */
        virtual Constante& TAN() const;

        /*! \fn virtual Constante& SINH() const
         * \brief Calcule le sinus hyperbolique du nombre
         * \return Constante& une r�f�rence vers la constante issue du r�sultat
         */
        virtual Constante& SINH() const;

        /*! \fn virtual Constante& COSH() const
         * \brief Calcule le cosinus hyperbolique du nombre
         * \return Constante& une r�f�rence vers la constante issue du r�sultat
         */
        virtual Constante& COSH() const;

        /*! \fn virtual Constante& TANH() const
         * \brief Calcule la tangente hyperbolique du nombre
         * \return Constante& une r�f�rence vers la constante issue du r�sultat
         */
        virtual Constante& TANH() const;

        /*! \fn virtual Constante& LN() const
         * \brief Calcule le logarithme n�p�rien du nombre
         * \return Constante& une r�f�rence vers la constante issue du r�sultat
         */
        virtual Constante& LN() const;

        /*! \fn virtual Constante& LOG() const
         * \brief Calcule le logarithme du nombre
         * \return Constante& une r�f�rence vers la constante issue du r�sultat
         */
        virtual Constante& LOG() const;

        /*! \fn virtual Constante& INV() const
         * \brief Calcule l'inverse du nombre
         * \return Constante& une r�f�rence vers la constante issue du r�sultat
         */
        virtual Constante& INV() const;

        /*! \fn virtual Constante& SQRT() const
         * \brief Calcule la racine carr� du nombre
         * \return Constante& une r�f�rence vers la constante issue du r�sultat
         */
        virtual Constante& SQRT() const;

        /*! \fn virtual Constante& POW(const Nombre& nb) const
         * \brief Calcule le nombre � la puissance pass�e en argument
         * \param nb un nombre repr�sentant la puissance associ� au Nombre appelant
         * \return Constante& une r�f�rence vers la constante r�sultant du calcul de la puissance
         */
        virtual Constante& POW(const Nombre& nb) const;

        /*! \fn virtual Entier& toEntier() const
         * \brief Transforme un Nombre en entier
         * \return Entier& une r�f�rence vers l'Entier cr��
         */
        virtual Entier& toEntier() const;

        /*! \fn virtual Reel& toReel() const
         * \brief Transforme un Nombre en reel
         * \return R�el& une r�f�rence vers le r�el cr��
         */
        virtual Reel& toReel() const;

        /*! \fn virtual Rationnel& toRationnel() const
         * \brief Transforme un Nombre en rationnel
         * \return Rationnel& une r�f�rence vers le rationnel cr��
         */
        virtual Rationnel& toRationnel() const;

        /*! \fn QString toString() const
         * \brief M�thode virtuelle servant � donner une repr�sentation textuelle d'un nombre
         * \return QString contenant le texte d�crivant le nombre
         */
        QString toString() const =0;

        /*! \fn Nombre& SIGN() const
         * \brief Inverse le signe d'un nombre
         * \return Nombre& la r�f�rence vers le Nombre cr�� � partir de l'oppos� de l'objet appelant
         */
        Nombre& SIGN() const;

        /*! \fn virtual Constante& addition(const Constante& nb) const
         * \brief G�re l'addition entre deux constantes quelles qu'elles soient
         * \param nb une r�f�rence vers une constante
         * \return Constante& une r�f�rence vers la constante cr��e � partir du r�sultat
         */
        virtual Constante& addition(const Constante& nb) const=0;

        /*! \fn virtual Constante& soustraction(const Constante& nb) const
         * \brief G�re la soustraction entre deux constantes quelles qu'elles soient
         * \param nb une r�f�rence vers une constante
         * \return Constante& une r�f�rence vers la constante cr��e � partir du r�sultat
         */
        virtual Constante& soustraction(const Constante& nb) const=0;

        /*! \fn virtual Constante& multiplication(const Constante& nb) const
         * \brief G�re la multiplication entre deux constantes quelles qu'elles soient
         * \param nb une r�f�rence vers une constante
         * \return Constante& une r�f�rence vers la constante cr��e � partir du r�sultat
         */
        virtual Constante& multiplication(const Constante& nb) const=0;

        /*! \fn virtual Constante& division(const Constante& nb) const
         * \brief G�re la division entre deux constantes quelles qu'elles soient
         * \param nb une r�f�rence vers une constante
         * \return Constante& une r�f�rence vers la constante cr��e � partir du r�sultat
         */
        virtual Constante& division(const Constante& nb) const=0;

        /*! \fn Constante& hookOperation()
         * \brief
         * \return Constante& Une r�f�rence vers une constante instanci�e
         */
        Constante& hookOperation();


        /*! \fn bool operator==(const Nombre& e) const
         * \brief Teste si la valeur d'un Nombre est �gale � la valeur d'un autre Nombre
         * \param nb le Nombre � comparer avec l'objet appelant
         * \return bool d�terminant la v�racit� de la proposition logique
         */
        bool operator==(const Nombre& nb) const;

        /*! \fn bool operator==(int nb) const
         * \brief Teste si la valeur d'un Nombre est �gale � la valeur d'un entier
         * \param nb l'entier � tester avec l'objet appelant
         * \return bool d�terminant la v�racit� de la proposition logique
         */
        bool operator==(int nb) const;


        /*! \fn Nombre* clone() const
         * \brief Recopie le nombre appelant
         * \return Nombre* un pointeur vers le nombre cr�� par recopie
         */
        Nombre* clone() const=0;
    };
}
#endif // NOMBRE_H
