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

        /*! \class Complexe
         * \brief Classe permettant de gérer les nombres complexes
         */
        QString toString() const =0;

        /*! \class Complexe
         * \brief Classe permettant de gérer les nombres complexes
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

            //Méthode qui va permettre d'appliquer le mode de constante utilisateur;

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
