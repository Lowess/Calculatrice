#ifndef OPERATEURUNAIRE_H
#define OPERATEURUNAIRE_H

/*! \file OperateurUnaire.h
  * \author Florian Dambrine, Olivia Reaney
  * \brief Fichier d'en-tête pour déclaration de la classe OperateurUnaire
  */

#include "Operateur.h"
#include "Expression.h"
#include <QString>

/*! \namespace LO21
 *  \brief Désigne les classes définies dans le but du projet de LO21 P12
 */
namespace LO21 {
    /*! \class OperateurUnaire
     * \brief Classe permettant de gérer les opérateurs unaires présents dans une expression
     */
    class OperateurUnaire : public Operateur {
        public:
            /*! \fn OperateurUnaire(const QString op)
             * \brief Constructeur de la classe OperateurUnaire
             * \param op le type d'opérateur
             */
            OperateurUnaire(const QString op);

            /*! \fn QString toString() const
             * \brief Permet de donner une forme textuelle à l'opérateur
             * \return QString contenant la version textualisée de l'opérateur
             */
            QString toString() const;
    };
}


#endif // OPERATEURUNAIRE_H
