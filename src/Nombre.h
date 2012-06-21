#ifndef NOMBRE_H
#define NOMBRE_H

/*! \file Nombre.h
  * \author Florian Dambrine, Olivia Reaney
  * \brief Fichier d'en-tete pour declaration de la classe Nombre
  */

#include <QString>
#include "Constante.h"
#include "CalculatriceException.h"
#include "Option.h"
#include "LogSystem.h"

/*! \namespace LO21
 *  \brief Designe les classes definies dans le but du projet de LO21 P12
 */
namespace LO21{
    class Entier;
    class Reel;
    class Rationnel;

    /*! \class Nombre
     * \brief Classe encapsulant les classes Entier, Rationnel et Reel
     */
    class Nombre: public Constante {
        public:

        /*! \fn virtual Constante& SIN() const
         * \brief Calcule le sinus du nombre
         * \return Constante& une reference vers la constante issue du resultat
         */
        virtual Constante& SIN() const;

        /*! \fn virtual Constante& COS() const
         * \brief Calcule le cosinus du nombre
         * \return Constante& une reference vers la constante issue du resultat
         */
        virtual Constante& COS() const;

        /*! \fn virtual Constante& TAN() const
         * \brief Calcule la tangente du nombre
         * \return Constante& une reference vers la constante issue du resultat
         */
        virtual Constante& TAN() const;

        /*! \fn virtual Constante& SINH() const
         * \brief Calcule le sinus hyperbolique du nombre
         * \return Constante& une reference vers la constante issue du resultat
         */
        virtual Constante& SINH() const;

        /*! \fn virtual Constante& COSH() const
         * \brief Calcule le cosinus hyperbolique du nombre
         * \return Constante& une reference vers la constante issue du resultat
         */
        virtual Constante& COSH() const;

        /*! \fn virtual Constante& TANH() const
         * \brief Calcule la tangente hyperbolique du nombre
         * \return Constante& une reference vers la constante issue du resultat
         */
        virtual Constante& TANH() const;

        /*! \fn virtual Constante& LN() const
         * \brief Calcule le logarithme neperien du nombre
         * \return Constante& une reference vers la constante issue du resultat
         */
        virtual Constante& LN() const;

        /*! \fn virtual Constante& LOG() const
         * \brief Calcule le logarithme du nombre
         * \return Constante& une reference vers la constante issue du resultat
         */
        virtual Constante& LOG() const;

        /*! \fn virtual Constante& INV() const
         * \brief Calcule l'inverse du nombre
         * \return Constante& une reference vers la constante issue du resultat
         */
        virtual Constante& INV() const;

        /*! \fn virtual Constante& SQRT() const
         * \brief Calcule la racine carre du nombre
         * \return Constante& une reference vers la constante issue du resultat
         */
        virtual Constante& SQRT() const;

        /*! \fn virtual Constante& POW(const Nombre& nb) const
         * \brief Calcule le nombre a la puissance passee en argument
         * \param nb un nombre representant la puissance associe au Nombre appelant
         * \return Constante& une reference vers la constante resultant du calcul de la puissance
         */
        virtual Constante& POW(const Nombre& nb) const;

        /*! \fn virtual Entier& toEntier() const
         * \brief Transforme un Nombre en entier
         * \return Entier& une reference vers l'Entier cree
         */
        virtual Entier& toEntier() const;

        /*! \fn virtual Reel& toReel() const
         * \brief Transforme un Nombre en reel
         * \return Reel& une reference vers le reel cree
         */
        virtual Reel& toReel() const;

        /*! \fn virtual Rationnel& toRationnel() const
         * \brief Transforme un Nombre en rationnel
         * \return Rationnel& une reference vers le rationnel cree
         */
        virtual Rationnel& toRationnel() const;

        /*! \fn QString toString() const
         * \brief Methode virtuelle servant a donner une representation textuelle d'un nombre
         * \return QString contenant le texte decrivant le nombre
         */
        QString toString() const =0;

        /*! \fn Nombre& SIGN() const
         * \brief Inverse le signe d'un nombre
         * \return Nombre& la reference vers le Nombre cree a partir de l'oppose de l'objet appelant
         */
        Nombre& SIGN() const;

        /*! \fn virtual Constante& addition(const Constante& nb) const
         * \brief Gere l'addition entre deux constantes quelles qu'elles soient
         * \param nb une reference vers une constante
         * \return Constante& une reference vers la constante creee a partir du resultat
         */
        virtual Constante& addition(const Constante& nb) const=0;

        /*! \fn virtual Constante& soustraction(const Constante& nb) const
         * \brief Gere la soustraction entre deux constantes quelles qu'elles soient
         * \param nb une reference vers une constante
         * \return Constante& une reference vers la constante creee a partir du resultat
         */
        virtual Constante& soustraction(const Constante& nb) const=0;

        /*! \fn virtual Constante& multiplication(const Constante& nb) const
         * \brief Gere la multiplication entre deux constantes quelles qu'elles soient
         * \param nb une reference vers une constante
         * \return Constante& une reference vers la constante creee a partir du resultat
         */
        virtual Constante& multiplication(const Constante& nb) const=0;

        /*! \fn virtual Constante& division(const Constante& nb) const
         * \brief Gere la division entre deux constantes quelles qu'elles soient
         * \param nb une reference vers une constante
         * \return Constante& une reference vers la constante creee a partir du resultat
         */
        virtual Constante& division(const Constante& nb) const=0;

        /*! \fn Constante& hookOperation()
         * \brief Permet de vérifier le type d'opération et de constante pour instancier correctement un objet
         * \return Constante& Une reference vers une constante instanciee
         */
        Constante& hookOperation();


        /*! \fn bool operator==(const Nombre& e) const
         * \brief Teste si la valeur d'un Nombre est egale a la valeur d'un autre Nombre
         * \param nb le Nombre a comparer avec l'objet appelant
         * \return bool determinant la veracite de la proposition logique
         */
        bool operator==(const Nombre& nb) const;

        /*! \fn bool operator==(int nb) const
         * \brief Teste si la valeur d'un Nombre est egale a la valeur d'un entier
         * \param nb l'entier a tester avec l'objet appelant
         * \return bool determinant la veracite de la proposition logique
         */
        bool operator==(int nb) const;


        /*! \fn Nombre* clone() const
         * \brief Recopie le nombre appelant
         * \return Nombre* un pointeur vers le nombre cree par recopie
         */
        Nombre* clone() const=0;
    };
}
#endif // NOMBRE_H
