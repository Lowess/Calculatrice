#ifndef OPERATEURBINAIRE_H
#define OPERATEURBINAIRE_H

#include "Operateur.h"
#include "Expression.h"
#include <QString>

namespace Calculatrice {

enum OpBinaire {ADD, SOU, MUL, DIV};

    class OperateurBinaire : public Operateur{

        private:
            OpBinaire _operateur;

        public:

            OperateurBinaire(const QString op);

            const QString& getOperator();

            Expression& eval(const Expression& e1, const Expression &e2);

    };

}

#endif // OPERATEURBINAIRE_H
