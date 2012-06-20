#ifndef EXP_H
#define EXP_H

/*! \file Exp.h
  * \author Florian Dambrine, Olivia Reaney
  * \brief Fichier d'en-t�te pour d�claration de la classe Exp
  */

#include "Constante.h"
#include "Fabrique.h"

/*! \namespace LO21
 *  \brief D�signe les classes d�finies dans le but du projet de LO21 P12
 */
namespace LO21{

    /*! \class Exp
     * \brief Classe permettant de g�rer les expressions entre ' ' � �valuer plus tard
     */
    class Exp: public Constante {
        private:
            const QString _exp; /*! Expression � garder en m�moire */
        public:
            /*! \fn Exp(const QString& s)
             * \brief Constructeur de la classe Exp
             * \param s l'expression � stocker
             */
            Exp(const QString& s):_exp(s){}

            /*! \fn Constante& addition(const Constante& nb) const
             * \brief G�re l'addition d'une constante avec l'�valuation
             * \param nb une r�f�rence vers une constante
             * \return Constante& une r�f�rence vers la constante cr��e � partir du r�sultat
             */
            Constante& addition(const Constante& nb) const;

            /*! \fn Constante& soustraction(const Constante& nb) const
             * \brief G�re la soustraction d'une constante avec l'�valuation
             * \param nb une r�f�rence vers une constante
             * \return Constante& une r�f�rence vers la constante cr��e � partir du r�sultat
             */
            Constante& soustraction(const Constante& nb) const;

            /*! \fn Constante& multiplication(const Constante& nb) const
             * \brief G�re la multiplication d'une constante avec l'�valuation
             * \param nb une r�f�rence vers une constante
             * \return Constante& une r�f�rence vers la constante cr��e � partir du r�sultat
             */
            Constante& multiplication(const Constante& nb) const;

            /*! \fn Constante& division(const Constante& nb) const
             * \brief G�re la division d'une constante avec l'�valuation
             * \param nb une r�f�rence vers une constante
             * \return Constante& une r�f�rence vers la constante cr��e � partir du r�sultat
             */
            Constante& division(const Constante& nb) const;

            /*! \fn void EVAL()
             * \brief Evalue le contenu d'une expression
             */
            void EVAL();

            /*! \fn Constante& hookOperation()
             * \brief ?
             * \return Constante&
             */
            Constante& hookOperation();

            /*! \fn QString toString() const
             * \brief Permet d'afficher le contenu de l'expression
             * \return QString l'expression stock�e
             */
            QString toString() const;

            /*! \fn Exp* clone() const
             * \brief Duplique une expression
             * \return Exp* un pointeur vers l'expression clon�e
             */
            Exp* clone() const;
    };
}

#endif // EXP_H
