/** \file Constante.h
  * \author Florian Dambrine, Olivia Reaney
  * \brief Fichier d'en-t�te pour d�claration de la classe Constante
  */

#ifndef CONSTANTE_H
#define CONSTANTE_H

#include <QDebug>

#include "Expression.h"

/*! \namespace LO21
 *  \brief D�signe les classes d�finies dans le but du projet de LO21 P12
 */
namespace LO21{

    /*! \class Constante
     * \brief D�finit d'une mani�re g�n�rale les op�rations possibles sur les constantes
     * qu'elles soient enti�res, r�elles, rationnelles ou complexes.
     */
    class Constante : public Expression{
        private:

        public:
            //M�thodes sp�cifique

            /*! \fn Constante& SIGN() const
             * \brief Retourne l'oppos� de la constante
             * \return Constante& une r�f�rence vers la constante cr��e � partir du r�sultat
             */
            Constante& SIGN() const;

            /*! \fn Constante& SQR() const
             * \brief Effectue le carr� de la constante
             * \return Constante& une r�f�rence vers la constante cr��e � partir du r�sultat
             */
            Constante& SQR() const;

            /*! \fn Constante& CUBE() const
             * \brief Effectue le cube de la constante
             * \return Constante& une r�f�rence vers la constante cr��e � partir du r�sultat
             */
            Constante& CUBE() const;

            /*! \fn Constante& operator+(const Constante& nb) const
             * \brief Surcharge de l'op�rateur + entre deux constantes
             * \param nb une r�f�rence vers une constante
             * \return Constante& une r�f�rence vers la constante cr��e � partir du r�sultat
             */
            Constante& operator+(const Constante& nb){ return this->addition(nb).hookOperation(); }

            /*! \fn Constante& operator-(const Constante& nb) const
             * \brief Surcharge de l'op�rateur - entre deux constantes
             * \param nb une r�f�rence vers une constante
             * \return Constante& une r�f�rence vers la constante cr��e � partir du r�sultat
             */
            Constante& operator-(const Constante& nb){ return this->soustraction(nb).hookOperation(); }

            /*! \fn Constante& operator*(const Constante& nb) const
             * \brief Surcharge de l'op�rateur * entre deux constantes
             * \param nb une r�f�rence vers une constante
             * \return Constante& une r�f�rence vers la constante cr��e � partir du r�sultat
             */
            Constante& operator*(const Constante& nb){ return this->multiplication(nb).hookOperation(); }

            /*! \fn Constante& operator/(const Constante& nb) const
             * \brief Surcharge de l'op�rateur / entre deux constantes
             * \param nb une r�f�rence vers une constante
             * \return Constante& une r�f�rence vers la constante cr��e � partir du r�sultat
             */
            Constante& operator/(const Constante& nb){ return this->division(nb).hookOperation(); }

            //Impl�mentation du Template/Methode

            /*! \fn Constante& addition(const Constante& nb) const
             * \brief G�re l'addition entre deux constantes quelles qu'elles soient
             * \param nb une r�f�rence vers une constante
             * \return Constante& une r�f�rence vers la constante cr��e � partir du r�sultat
             */
            virtual Constante& addition(const Constante& nb) const=0;

            /*! \fn Constante& soustraction(const Constante& nb) const
             * \brief G�re la soustraction entre deux constantes quelles qu'elles soient
             * \param nb une r�f�rence vers une constante
             * \return Constante& une r�f�rence vers la constante cr��e � partir du r�sultat
             */
            virtual Constante& soustraction(const Constante& nb) const=0;

            /*! \fn Constante& multiplication(const Constante& nb) const
             * \brief G�re la multiplication entre deux constantes quelles qu'elles soient
             * \param nb une r�f�rence vers une constante
             * \return Constante& une r�f�rence vers la constante cr��e � partir du r�sultat
             */
            virtual Constante& multiplication(const Constante& nb) const=0;

            /*! \fn Constante& division(const Constante& nb) const
             * \brief G�re la division entre deux constantes quelles qu'elles soient
             * \param nb une r�f�rence vers une constante
             * \return Constante& une r�f�rence vers la constante cr��e � partir du r�sultat
             */
            virtual Constante& division(const Constante& nb) const=0;

            /*! \fn Constante& hookOperation()
             * \brief
             * \return Constante& Une r�f�rence vers une constante instanci�e
             */
            virtual Constante& hookOperation()=0;

            /*! \fn void EVAL()
             * \brief Evalue une constante
             */
            void EVAL();

            /*! \fn Constante* clone() const
             * \brief Recopie la constante appelante
             * \return Constante* un pointeur vers la constante cr��e par recopie
             */
            Constante* clone() const=0;

    };
}

#endif // CONSTANTE_H
