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
    /*! \class OperateurBinaire
     * \brief Classe permettant de gérer les opérateurs binaires présents dans une expression
     */
    class OperateurBinaire : public Operateur{
        public:
            /*! \fn OperateurBinaire(const QString& op)
             * \brief Constructeur de la classe OperateurBinaire
             * \param op le type de l'opérateur
             */
            OperateurBinaire(const QString& op);

            /*! \fn QString toString() const
             * \brief Permet de donner une forme textuelle à l'opérateur
             * \return QString contenant la version textualisée de l'opérateur
             */
            QString toString() const;
    };
}

#endif // OPERATEURBINAIRE_H
