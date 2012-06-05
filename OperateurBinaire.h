#ifndef OPERATEURBINAIRE_H
#define OPERATEURBINAIRE_H

#include "Operateur.h"
#include "Expression.h"
#include <iostream>
#include <QString>

namespace Calculatrice {

enum OpBinaire {ADD, SOU, MUL, DIV, LOG, PWR};

    class OperateurBinaire : public Operateur{

        private:
            OpBinaire _operateur;

        public:

            OperateurBinaire(const QString op);
            OperateurBinaire(){}

            QString toString() const;

            bool isOperateurBinaire();

            Expression& calcul(const Expression& e1, const Expression &e2);

    };

}

#endif // OPERATEURBINAIRE_H
