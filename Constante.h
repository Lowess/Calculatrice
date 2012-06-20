/** \file Constante.h
  * \author Florian Dambrine, Olivia Reaney
  * \brief Fichier d'en-tête pour déclaration de la classe Constante
  */

#ifndef CONSTANTE_H
#define CONSTANTE_H

#include <QDebug>

#include "Expression.h"

/*! \namespace LO21
 *  \brief Désigne les classes définies dans le but du projet de LO21 P12
 */
namespace LO21{

    /*! \class Constante
     * \brief Définit d'une manière générale les opérations possibles sur les constantes
     * qu'elles soient entières, réelles, rationnelles ou complexes.
     */
    class Constante : public Expression{
        private:

        public:
            //Méthodes spécifique

            /*! \fn Constante& SIGN() const
             * \brief Retourne l'opposé de la constante
             * \return Constante& une référence vers la constante créée à partir du résultat
             */
            Constante& SIGN() const;

            /*! \fn Constante& SQR() const
             * \brief Effectue le carré de la constante
             * \return Constante& une référence vers la constante créée à partir du résultat
             */
            Constante& SQR() const;

            /*! \fn Constante& CUBE() const
             * \brief Effectue le cube de la constante
             * \return Constante& une référence vers la constante créée à partir du résultat
             */
            Constante& CUBE() const;

            /*! \fn Constante& operator+(const Constante& nb) const
             * \brief Surcharge de l'opérateur + entre deux constantes
             * \param nb une référence vers une constante
             * \return Constante& une référence vers la constante créée à partir du résultat
             */
            Constante& operator+(const Constante& nb){ return this->addition(nb).hookOperation(); }

            /*! \fn Constante& operator-(const Constante& nb) const
             * \brief Surcharge de l'opérateur - entre deux constantes
             * \param nb une référence vers une constante
             * \return Constante& une référence vers la constante créée à partir du résultat
             */
            Constante& operator-(const Constante& nb){ return this->soustraction(nb).hookOperation(); }

            /*! \fn Constante& operator*(const Constante& nb) const
             * \brief Surcharge de l'opérateur * entre deux constantes
             * \param nb une référence vers une constante
             * \return Constante& une référence vers la constante créée à partir du résultat
             */
            Constante& operator*(const Constante& nb){ return this->multiplication(nb).hookOperation(); }

            /*! \fn Constante& operator/(const Constante& nb) const
             * \brief Surcharge de l'opérateur / entre deux constantes
             * \param nb une référence vers une constante
             * \return Constante& une référence vers la constante créée à partir du résultat
             */
            Constante& operator/(const Constante& nb){ return this->division(nb).hookOperation(); }

            //Implémentation du Template/Methode

            /*! \fn Constante& addition(const Constante& nb) const
             * \brief Gère l'addition entre deux constantes quelles qu'elles soient
             * \param nb une référence vers une constante
             * \return Constante& une référence vers la constante créée à partir du résultat
             */
            virtual Constante& addition(const Constante& nb) const=0;

            /*! \fn Constante& soustraction(const Constante& nb) const
             * \brief Gère la soustraction entre deux constantes quelles qu'elles soient
             * \param nb une référence vers une constante
             * \return Constante& une référence vers la constante créée à partir du résultat
             */
            virtual Constante& soustraction(const Constante& nb) const=0;

            /*! \fn Constante& multiplication(const Constante& nb) const
             * \brief Gère la multiplication entre deux constantes quelles qu'elles soient
             * \param nb une référence vers une constante
             * \return Constante& une référence vers la constante créée à partir du résultat
             */
            virtual Constante& multiplication(const Constante& nb) const=0;

            /*! \fn Constante& division(const Constante& nb) const
             * \brief Gère la division entre deux constantes quelles qu'elles soient
             * \param nb une référence vers une constante
             * \return Constante& une référence vers la constante créée à partir du résultat
             */
            virtual Constante& division(const Constante& nb) const=0;

            /*! \fn Constante& hookOperation()
             * \brief
             * \return Constante& Une référence vers une constante instanciée
             */
            virtual Constante& hookOperation()=0;

            /*! \fn void EVAL()
             * \brief Evalue une constante
             */
            void EVAL();

            /*! \fn Constante* clone() const
             * \brief Recopie la constante appelante
             * \return Constante* un pointeur vers la constante créée par recopie
             */
            Constante* clone() const=0;

    };
}

#endif // CONSTANTE_H
