#ifndef OPERATEURUNAIRE_H
#define OPERATEURUNAIRE_H

/*! \file OperateurUnaire.h
  * \author Florian Dambrine, Olivia Reaney
  * \brief Fichier d'en-tete pour declaration de la classe OperateurUnaire
  */

#include "Operateur.h"
#include "Expression.h"
#include <QString>

/*! \namespace LO21
 *  \brief Designe les classes definies dans le but du projet de LO21 P12
 */
namespace LO21 {
    /*! \class OperateurUnaire
     * \brief Classe permettant de gerer les operateurs unaires presents dans une expression
     */
    class OperateurUnaire : public Operateur {
        public:
            /*! \fn OperateurUnaire(const QString op)
             * \brief Constructeur de la classe OperateurUnaire
             * \param op le type d'operateur
             */
            OperateurUnaire(const QString op);

            /*! \fn QString toString() const
             * \brief Permet de donner une forme textuelle a l'operateur
             * \return QString contenant la version textualisee de l'operateur
             */
            QString toString() const;
    };
}


#endif // OPERATEURUNAIRE_H
