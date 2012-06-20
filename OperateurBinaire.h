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
    /*! \class OperateurBinaire
     * \brief Classe permettant de g�rer les op�rateurs binaires pr�sents dans une expression
     */
    class OperateurBinaire : public Operateur{
        public:
            /*! \fn OperateurBinaire(const QString& op)
             * \brief Constructeur de la classe OperateurBinaire
             * \param op le type de l'op�rateur
             */
            OperateurBinaire(const QString& op);

            /*! \fn QString toString() const
             * \brief Permet de donner une forme textuelle � l'op�rateur
             * \return QString contenant la version textualis�e de l'op�rateur
             */
            QString toString() const;
    };
}

#endif // OPERATEURBINAIRE_H
