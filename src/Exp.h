#ifndef EXP_H
#define EXP_H

/*! \file Exp.h
  * \author Florian Dambrine, Olivia Reaney
  * \brief Fichier d'en-tete pour declaration de la classe Exp
  */

#include "Constante.h"
#include "Fabrique.h"

/*! \namespace LO21
 *  \brief Designe les classes definies dans le but du projet de LO21 P12
 */
namespace LO21{

    /*! \class Exp
     * \brief Classe permettant de gerer les expressions entre ' ' a evaluer plus tard
     */
    class Exp: public Constante {
        private:
            const QString _exp; /*! Expression a garder en memoire */
        public:
            /*! \fn Exp(const QString& s)
             * \brief Constructeur de la classe Exp
             * \param s l'expression a stocker
             */
            Exp(const QString& s):_exp(s){}

            /*! \fn Constante& addition(const Constante& nb) const
             * \brief Gere l'addition d'une constante avec l'evaluation
             * \param nb une reference vers une constante
             * \return Constante& une reference vers la constante creee a partir du resultat
             */
            Constante& addition(const Constante& nb) const;

            /*! \fn Constante& soustraction(const Constante& nb) const
             * \brief Gere la soustraction d'une constante avec l'evaluation
             * \param nb une reference vers une constante
             * \return Constante& une reference vers la constante creee a partir du resultat
             */
            Constante& soustraction(const Constante& nb) const;

            /*! \fn Constante& multiplication(const Constante& nb) const
             * \brief Gere la multiplication d'une constante avec l'evaluation
             * \param nb une reference vers une constante
             * \return Constante& une reference vers la constante creee a partir du resultat
             */
            Constante& multiplication(const Constante& nb) const;

            /*! \fn Constante& division(const Constante& nb) const
             * \brief Gere la division d'une constante avec l'evaluation
             * \param nb une reference vers une constante
             * \return Constante& une reference vers la constante creee a partir du resultat
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
             * \return QString l'expression stockee
             */
            QString toString() const;

            /*! \fn Exp* clone() const
             * \brief Duplique une expression
             * \return Exp* un pointeur vers l'expression clonee
             */
            Exp* clone() const;
    };
}

#endif // EXP_H
