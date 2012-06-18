/** \file OperateurUnaire.h
  * \author Florian Dambrine, Olivia Reaney
  * \brief Fichier d'en-tête pour déclaration de la classe OperateurUnaire
  */

#ifndef OPERATEURUNAIRE_H
#define OPERATEURUNAIRE_H

#include "Operateur.h"
#include "Expression.h"
#include <QString>

namespace LO21 {
    class OperateurUnaire : public Operateur {
        public:
            OperateurUnaire(const QString op);

            QString toString() const;
    };
}


#endif // OPERATEURUNAIRE_H
