#ifndef OPERATEURUNAIRE_H
#define OPERATEURUNAIRE_H

/*! \file OperateurUnaire.h
  * \author Florian Dambrine, Olivia Reaney
  * \brief Fichier d'en-t�te pour d�claration de la classe OperateurUnaire
  */

#include "Operateur.h"
#include "Expression.h"
#include <QString>

/*! \namespace LO21
 *  \brief D�signe les classes d�finies dans le but du projet de LO21 P12
 */
namespace LO21 {
    /*! \class OperateurUnaire
     * \brief Classe permettant de g�rer les op�rateurs unaires pr�sents dans une expression
     */
    class OperateurUnaire : public Operateur {
        public:
            /*! \fn OperateurUnaire(const QString op)
             * \brief Constructeur de la classe OperateurUnaire
             * \param op le type d'op�rateur
             */
            OperateurUnaire(const QString op);

            /*! \fn QString toString() const
             * \brief Permet de donner une forme textuelle � l'op�rateur
             * \return QString contenant la version textualis�e de l'op�rateur
             */
            QString toString() const;
    };
}


#endif // OPERATEURUNAIRE_H
