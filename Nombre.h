#ifndef NOMBRE_H
#define NOMBRE_H

/*! \file Nombre.h
  * \author Florian Dambrine, Olivia Reaney
  * \brief Fichier d'en-tête pour déclaration de la classe Nombre
  */

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

    /*! \class Nombre
     * \brief Classe encapsulant les classes Entier, Rationnel et Réel
     */
    class Nombre: public Constante {
        public:

        /*! \fn virtual Constante& SIN() const
         * \brief Calcule le sinus du nombre
         * \return Constante& une référence vers la constante issue du résultat
         */
        virtual Constante& SIN() const;

        /*! \fn virtual Constante& COS() const
         * \brief Calcule le cosinus du nombre
         * \return Constante& une référence vers la constante issue du résultat
         */
        virtual Constante& COS() const;

        /*! \fn virtual Constante& TAN() const
         * \brief Calcule la tangente du nombre
         * \return Constante& une référence vers la constante issue du résultat
         */
        virtual Constante& TAN() const;

        /*! \fn virtual Constante& SINH() const
         * \brief Calcule le sinus hyperbolique du nombre
         * \return Constante& une référence vers la constante issue du résultat
         */
        virtual Constante& SINH() const;

        /*! \fn virtual Constante& COSH() const
         * \brief Calcule le cosinus hyperbolique du nombre
         * \return Constante& une référence vers la constante issue du résultat
         */
        virtual Constante& COSH() const;

        /*! \fn virtual Constante& TANH() const
         * \brief Calcule la tangente hyperbolique du nombre
         * \return Constante& une référence vers la constante issue du résultat
         */
        virtual Constante& TANH() const;

        /*! \fn virtual Constante& LN() const
         * \brief Calcule le logarithme népérien du nombre
         * \return Constante& une référence vers la constante issue du résultat
         */
        virtual Constante& LN() const;

        /*! \fn virtual Constante& LOG() const
         * \brief Calcule le logarithme du nombre
         * \return Constante& une référence vers la constante issue du résultat
         */
        virtual Constante& LOG() const;

        /*! \fn virtual Constante& INV() const
         * \brief Calcule l'inverse du nombre
         * \return Constante& une référence vers la constante issue du résultat
         */
        virtual Constante& INV() const;

        /*! \fn virtual Constante& SQRT() const
         * \brief Calcule la racine carré du nombre
         * \return Constante& une référence vers la constante issue du résultat
         */
        virtual Constante& SQRT() const;

        /*! \fn virtual Constante& POW(const Nombre& nb) const
         * \brief Calcule le nombre à la puissance passée en argument
         * \param nb un nombre représentant la puissance associé au Nombre appelant
         * \return Constante& une référence vers la constante résultant du calcul de la puissance
         */
        virtual Constante& POW(const Nombre& nb) const;

        /*! \fn virtual Entier& toEntier() const
         * \brief Transforme un Nombre en entier
         * \return Entier& une référence vers l'Entier créé
         */
        virtual Entier& toEntier() const;

        /*! \fn virtual Reel& toReel() const
         * \brief Transforme un Nombre en reel
         * \return Réel& une référence vers le réel créé
         */
        virtual Reel& toReel() const;

        /*! \fn virtual Rationnel& toRationnel() const
         * \brief Transforme un Nombre en rationnel
         * \return Rationnel& une référence vers le rationnel créé
         */
        virtual Rationnel& toRationnel() const;

        /*! \fn QString toString() const
         * \brief Méthode virtuelle servant à donner une représentation textuelle d'un nombre
         * \return QString contenant le texte décrivant le nombre
         */
        QString toString() const =0;

        /*! \fn Nombre& SIGN() const
         * \brief Inverse le signe d'un nombre
         * \return Nombre& la référence vers le Nombre créé à partir de l'opposé de l'objet appelant
         */
        Nombre& SIGN() const;

        /*! \fn virtual Constante& addition(const Constante& nb) const
         * \brief Gère l'addition entre deux constantes quelles qu'elles soient
         * \param nb une référence vers une constante
         * \return Constante& une référence vers la constante créée à partir du résultat
         */
        virtual Constante& addition(const Constante& nb) const=0;

        /*! \fn virtual Constante& soustraction(const Constante& nb) const
         * \brief Gère la soustraction entre deux constantes quelles qu'elles soient
         * \param nb une référence vers une constante
         * \return Constante& une référence vers la constante créée à partir du résultat
         */
        virtual Constante& soustraction(const Constante& nb) const=0;

        /*! \fn virtual Constante& multiplication(const Constante& nb) const
         * \brief Gère la multiplication entre deux constantes quelles qu'elles soient
         * \param nb une référence vers une constante
         * \return Constante& une référence vers la constante créée à partir du résultat
         */
        virtual Constante& multiplication(const Constante& nb) const=0;

        /*! \fn virtual Constante& division(const Constante& nb) const
         * \brief Gère la division entre deux constantes quelles qu'elles soient
         * \param nb une référence vers une constante
         * \return Constante& une référence vers la constante créée à partir du résultat
         */
        virtual Constante& division(const Constante& nb) const=0;

        /*! \fn Constante& hookOperation()
         * \brief
         * \return Constante& Une référence vers une constante instanciée
         */
        Constante& hookOperation();


        /*! \fn bool operator==(const Nombre& e) const
         * \brief Teste si la valeur d'un Nombre est égale à la valeur d'un autre Nombre
         * \param nb le Nombre à comparer avec l'objet appelant
         * \return bool déterminant la véracité de la proposition logique
         */
        bool operator==(const Nombre& nb) const;

        /*! \fn bool operator==(int nb) const
         * \brief Teste si la valeur d'un Nombre est égale à la valeur d'un entier
         * \param nb l'entier à tester avec l'objet appelant
         * \return bool déterminant la véracité de la proposition logique
         */
        bool operator==(int nb) const;


        /*! \fn Nombre* clone() const
         * \brief Recopie le nombre appelant
         * \return Nombre* un pointeur vers le nombre créé par recopie
         */
        Nombre* clone() const=0;
    };
}
#endif // NOMBRE_H
