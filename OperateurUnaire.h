#ifndef OPERATEURUNAIRE_H
#define OPERATEURUNAIRE_H

#include "Operateur.h"
#include "Expression.h"
#include <QString>

namespace Calculatrice {
    class OperateurUnaire : public Operateur {
        public:
            OperateurUnaire(const QString op);

            QString toString() const;

            Expression& eval(const Expression& e);

    };
}


#endif // OPERATEURUNAIRE_H
