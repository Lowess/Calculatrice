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
