/** \file OperateurBinaire.h
  * \author Florian Dambrine, Olivia Reaney
  * \brief Fichier d'en-t�te pour d�claration de la classe OperateurBinaire
  */

#ifndef OPERATEURBINAIRE_H
#define OPERATEURBINAIRE_H

#include "Operateur.h"
#include "Expression.h"
#include <iostream>
#include <QString>
#include <typeinfo>

/*! \namespace LO21
 *  \brief D�signe les classes d�finies dans le but du projet de LO21 P12
 */
namespace LO21 {
/*! \class Complexe
 * \brief Classe permettant de g�rer les nombres complexes
 */
    class OperateurBinaire : public Operateur{
        public:
        /*! \class Complexe
         * \brief Classe permettant de g�rer les nombres complexes
         */
            OperateurBinaire(const QString& op);
            /*! \class Complexe
             * \brief Classe permettant de g�rer les nombres complexes
             */
            QString toString() const;
    };
}

#endif // OPERATEURBINAIRE_H
