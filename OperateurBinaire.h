#ifndef OPERATEURBINAIRE_H
#define OPERATEURBINAIRE_H

#include "Operateur.h"
#include "Expression.h"
#include <QString>
#include <typeinfo>

namespace Calculatrice {
    class OperateurBinaire : public Operateur{
        public:
            OperateurBinaire(const QString& op);

            QString toString() const;
    };
}

#endif // OPERATEURBINAIRE_H
