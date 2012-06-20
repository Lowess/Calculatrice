/** \file Exp.h
  * \author Florian Dambrine, Olivia Reaney
  * \brief Fichier d'en-tête pour déclaration de la classe Exp
  */

#ifndef EXP_H
#define EXP_H


#include "Constante.h"
#include "Fabrique.h"

/*! \namespace LO21
 *  \brief Désigne les classes définies dans le but du projet de LO21 P12
 */
namespace LO21{
    /*! \class Complexe
     * \brief Classe permettant de gérer les nombres complexes
     */
    class Exp: public Constante {
        private:
            const QString _exp; /*! */
        public:
            /*! \class Complexe
             * \brief Classe permettant de gérer les nombres complexes
             */
            Exp(const QString& s):_exp(s){}

            /*! \class Complexe
             * \brief Classe permettant de gérer les nombres complexes
             */
            Constante& addition(const Constante& nb) const;

            /*! \class Complexe
             * \brief Classe permettant de gérer les nombres complexes
             */
            Constante& soustraction(const Constante& nb) const;

            /*! \class Complexe
             * \brief Classe permettant de gérer les nombres complexes
             */
            Constante& multiplication(const Constante& nb) const;

            /*! \class Complexe
             * \brief Classe permettant de gérer les nombres complexes
             */
            Constante& division(const Constante& nb) const;

            /*! \class Complexe
             * \brief Classe permettant de gérer les nombres complexes
             */
            void EVAL();

            /*! \class Complexe
             * \brief Classe permettant de gérer les nombres complexes
             */
            Constante& hookOperation();

            /*! \class Complexe
             * \brief Classe permettant de gérer les nombres complexes
             */
            QString toString() const;

            /*! \class Complexe
             * \brief Classe permettant de gérer les nombres complexes
             */
            Exp* clone() const;
    };
}

#endif // EXP_H
