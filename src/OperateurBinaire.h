#ifndef OPERATEURBINAIRE_H
#define OPERATEURBINAIRE_H

/*! \file OperateurBinaire.h
  * \author Florian Dambrine, Olivia Reaney
  * \brief Fichier d'en-tete pour declaration de la classe OperateurBinaire
  */

#include "Operateur.h"
#include "Expression.h"
#include <iostream>
#include <QString>
#include <typeinfo>

/*! \namespace LO21
 *  \brief Designe les classes definies dans le but du projet de LO21 P12
 */
namespace LO21 {
    /*! \class OperateurBinaire
     * \brief Classe permettant de gerer les operateurs binaires presents dans une expression
     */
    class OperateurBinaire : public Operateur{
        public:
            /*! \fn OperateurBinaire(const QString& op)
             * \brief Constructeur de la classe OperateurBinaire
             * \param op le type de l'operateur
             */
            OperateurBinaire(const QString& op);

            /*! \fn QString toString() const
             * \brief Permet de donner une forme textuelle a l'operateur
             * \return QString contenant la version textualisee de l'operateur
             */
            QString toString() const;
    };
}

#endif // OPERATEURBINAIRE_H
