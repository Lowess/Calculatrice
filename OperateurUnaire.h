/** \file OperateurUnaire.h
  * \author Florian Dambrine, Olivia Reaney
  * \brief Fichier d'en-t�te pour d�claration de la classe OperateurUnaire
  */

#ifndef OPERATEURUNAIRE_H
#define OPERATEURUNAIRE_H

#include "Operateur.h"
#include "Expression.h"
#include <QString>

/*! \namespace LO21
 *  \brief D�signe les classes d�finies dans le but du projet de LO21 P12
 */
namespace LO21 {
/*! \class Complexe
 * \brief Classe permettant de g�rer les nombres complexes
 */
    class OperateurUnaire : public Operateur {
        public:
        /*! \class Complexe
         * \brief Classe permettant de g�rer les nombres complexes
         */
            OperateurUnaire(const QString op);
            /*! \class Complexe
             * \brief Classe permettant de g�rer les nombres complexes
             */
            QString toString() const;
    };
}


#endif // OPERATEURUNAIRE_H
