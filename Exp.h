#ifndef EXP_H
#define EXP_H

/*! \file Exp.h
  * \author Florian Dambrine, Olivia Reaney
  * \brief Fichier d'en-tête pour déclaration de la classe Exp
  */

#include "Constante.h"
#include "Fabrique.h"

/*! \namespace LO21
 *  \brief Désigne les classes définies dans le but du projet de LO21 P12
 */
namespace LO21{

    /*! \class Exp
     * \brief Classe permettant de gérer les expressions entre ' ' à évaluer plus tard
     */
    class Exp: public Constante {
        private:
            const QString _exp; /*! Expression à garder en mémoire */
        public:
            /*! \fn Exp(const QString& s)
             * \brief Constructeur de la classe Exp
             * \param s l'expression à stocker
             */
            Exp(const QString& s):_exp(s){}

            /*! \fn Constante& addition(const Constante& nb) const
             * \brief Gère l'addition d'une constante avec l'évaluation
             * \param nb une référence vers une constante
             * \return Constante& une référence vers la constante créée à partir du résultat
             */
            Constante& addition(const Constante& nb) const;

            /*! \fn Constante& soustraction(const Constante& nb) const
             * \brief Gère la soustraction d'une constante avec l'évaluation
             * \param nb une référence vers une constante
             * \return Constante& une référence vers la constante créée à partir du résultat
             */
            Constante& soustraction(const Constante& nb) const;

            /*! \fn Constante& multiplication(const Constante& nb) const
             * \brief Gère la multiplication d'une constante avec l'évaluation
             * \param nb une référence vers une constante
             * \return Constante& une référence vers la constante créée à partir du résultat
             */
            Constante& multiplication(const Constante& nb) const;

            /*! \fn Constante& division(const Constante& nb) const
             * \brief Gère la division d'une constante avec l'évaluation
             * \param nb une référence vers une constante
             * \return Constante& une référence vers la constante créée à partir du résultat
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
             * \return QString l'expression stockée
             */
            QString toString() const;

            /*! \fn Exp* clone() const
             * \brief Duplique une expression
             * \return Exp* un pointeur vers l'expression clonée
             */
            Exp* clone() const;
    };
}

#endif // EXP_H
