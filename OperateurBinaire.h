#ifndef OPERATEURBINAIRE_H
#define OPERATEURBINAIRE_H

#include "Operateur.h"
#include "Expression.h"
#include <iostream>
#include <QString>
#include <typeinfo>

namespace LO21 {
    class OperateurBinaire : public Operateur{
        public:
            OperateurBinaire(const QString& op);

            QString toString() const;
    };
}

#endif // OPERATEURBINAIRE_H
