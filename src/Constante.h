#ifndef CONSTANTE_H
#define CONSTANTE_H

/*! \file Constante.h
  * \author Florian Dambrine, Olivia Reaney
  * \brief Fichier d'en-tete pour declaration de la classe Constante
  */

#include <QDebug>
#include "Expression.h"

/*! \namespace LO21
 *  \brief Designe les classes definies dans le but du projet de LO21 P12
 */
namespace LO21{

    /*! \class Constante
     * \brief Definit d'une maniere generale les operations possibles sur les constantes
     * qu'elles soient entieres, reelles, rationnelles ou complexes.
     */
    class Constante : public Expression{
        private:

        public:
            //Methodes specifique

            /*! \fn Constante& SIGN() const
             * \brief Retourne l'oppose de la constante
             * \return Constante& une reference vers la constante creee a partir du resultat
             */
            Constante& SIGN() const;

            /*! \fn Constante& SQR() const
             * \brief Effectue le carre de la constante
             * \return Constante& une reference vers la constante creee a partir du resultat
             */
            Constante& SQR() const;

            /*! \fn Constante& CUBE() const
             * \brief Effectue le cube de la constante
             * \return Constante& une reference vers la constante creee a partir du resultat
             */
            Constante& CUBE() const;

            /*! \fn Constante& operator+(const Constante& nb) const
             * \brief Surcharge de l'operateur + entre deux constantes
             * \param nb une reference vers une constante
             * \return Constante& une reference vers la constante creee a partir du resultat
             */
            Constante& operator+(const Constante& nb){ return this->addition(nb).hookOperation(); }

            /*! \fn Constante& operator-(const Constante& nb) const
             * \brief Surcharge de l'operateur - entre deux constantes
             * \param nb une reference vers une constante
             * \return Constante& une reference vers la constante creee a partir du resultat
             */
            Constante& operator-(const Constante& nb){ return this->soustraction(nb).hookOperation(); }

            /*! \fn Constante& operator*(const Constante& nb) const
             * \brief Surcharge de l'operateur * entre deux constantes
             * \param nb une reference vers une constante
             * \return Constante& une reference vers la constante creee a partir du resultat
             */
            Constante& operator*(const Constante& nb){ return this->multiplication(nb).hookOperation(); }

            /*! \fn Constante& operator/(const Constante& nb) const
             * \brief Surcharge de l'operateur / entre deux constantes
             * \param nb une reference vers une constante
             * \return Constante& une reference vers la constante creee a partir du resultat
             */
            Constante& operator/(const Constante& nb){ return this->division(nb).hookOperation(); }

            //Implementation du Template/Methode

            /*! \fn Constante& addition(const Constante& nb) const
             * \brief Gere l'addition entre deux constantes quelles qu'elles soient
             * \param nb une reference vers une constante
             * \return Constante& une reference vers la constante creee a partir du resultat
             */
            virtual Constante& addition(const Constante& nb) const=0;

            /*! \fn Constante& soustraction(const Constante& nb) const
             * \brief Gere la soustraction entre deux constantes quelles qu'elles soient
             * \param nb une reference vers une constante
             * \return Constante& une reference vers la constante creee a partir du resultat
             */
            virtual Constante& soustraction(const Constante& nb) const=0;

            /*! \fn Constante& multiplication(const Constante& nb) const
             * \brief Gere la multiplication entre deux constantes quelles qu'elles soient
             * \param nb une reference vers une constante
             * \return Constante& une reference vers la constante creee a partir du resultat
             */
            virtual Constante& multiplication(const Constante& nb) const=0;

            /*! \fn Constante& division(const Constante& nb) const
             * \brief Gere la division entre deux constantes quelles qu'elles soient
             * \param nb une reference vers une constante
             * \return Constante& une reference vers la constante creee a partir du resultat
             */
            virtual Constante& division(const Constante& nb) const=0;

            /*! \fn Constante& hookOperation()
             * \brief Permet de vérifier le type d'opération et de constante pour instancier correctement un objet
             * \return Constante& Une reference vers une constante instanciee
             */
            virtual Constante& hookOperation()=0;

            /*! \fn void EVAL()
             * \brief Evalue une constante
             */
            void EVAL();

            /*! \fn Constante* clone() const
             * \brief Recopie la constante appelante
             * \return Constante* un pointeur vers la constante creee par recopie
             */
            Constante* clone() const=0;

    };
}

#endif // CONSTANTE_H
