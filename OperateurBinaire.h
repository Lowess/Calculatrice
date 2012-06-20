/** \file OperateurBinaire.h
  * \author Florian Dambrine, Olivia Reaney
  * \brief Fichier d'en-tête pour déclaration de la classe OperateurBinaire
  */

#ifndef OPERATEURBINAIRE_H
#define OPERATEURBINAIRE_H

#include "Operateur.h"
#include "Expression.h"
#include <iostream>
#include <QString>
#include <typeinfo>

/*! \namespace LO21
 *  \brief Désigne les classes définies dans le but du projet de LO21 P12
 */
namespace LO21 {
/*! \class Complexe
 * \brief Classe permettant de gérer les nombres complexes
 */
    class OperateurBinaire : public Operateur{
        public:
        /*! \class Complexe
         * \brief Classe permettant de gérer les nombres complexes
         */
            OperateurBinaire(const QString& op);
            /*! \class Complexe
             * \brief Classe permettant de gérer les nombres complexes
             */
            QString toString() const;
    };
}

#endif // OPERATEURBINAIRE_H
