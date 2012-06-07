#ifndef OPERATEURBINAIRE_H
#define OPERATEURBINAIRE_H

#include "Operateur.h"
#include "Expression.h"
#include <iostream>
#include <QString>
#include <typeinfo>

namespace Calculatrice {
    class OperateurBinaire : public Operateur{
        public:
            OperateurBinaire(const QString& op);

            QString& getOperator() const;

            //Expression& eval(const Expression& e1, const Expression &e2);

            QString toString() const;
    };
}

#endif // OPERATEURBINAIRE_H
