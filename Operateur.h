/** \file Operateur.h
  * \author Florian Dambrine, Olivia Reaney
  * \brief Fichier d'en-tête pour déclaration de la classe Operateur
  */

#ifndef OPERATEUR_H
#define OPERATEUR_H

#include <stdexcept>
#include <QString>
#include <QStringList>

#include "Expression.h"
#include "Fabrique.h"
#include "Pile.h"
#include "Calculatrice.h"

/*! \namespace LO21
 *  \brief Désigne les classes définies dans le but du projet de LO21 P12
 */
namespace LO21{
/*! \class Complexe
 * \brief Classe permettant de gérer les nombres complexes
 */
    enum enumOperateurs {ADD, MUL, SOU, DIV, COS, SIN, TAN, COSH, SINH, TANH, SQR, CUBE, SQRT, INV, SIGN, LN, LOG, POW, FACT, MOD, EVALUATION};

    /*! \class Complexe
     * \brief Classe permettant de gérer les nombres complexes
     */
    class Operateur: public Expression {
        protected:
            enumOperateurs _operateur; /*! */

        public:
            /*! \class Complexe
             * \brief Classe permettant de gérer les nombres complexes
             */
            QString toString() const =0;

            /*! \class Complexe
             * \brief Classe permettant de gérer les nombres complexes
             */
            QString getOperator() const{ return toString(); }

            /*! \class Complexe
             * \brief Classe permettant de gérer les nombres complexes
             */
            void appliqueOperateur();

            /*! \class Complexe
             * \brief Classe permettant de gérer les nombres complexes
             */
            void EVAL();

            /*! \class Complexe
             * \brief Classe permettant de gérer les nombres complexes
             */
            QString& afficher();

            /*! \class Complexe
             * \brief Classe permettant de gérer les nombres complexes
             */
            Operateur* clone() const;
    };
}

#endif // OPERATEUR_H
