#ifndef OPERATEURBINAIRE_H
#define OPERATEURBINAIRE_H

#include "Operateur.h"
#include "Expression.h"
<<<<<<< HEAD
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

=======
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
>>>>>>> d50d9c44f71eff56d4eada027bfcd613b1693de1
}

#endif // OPERATEURBINAIRE_H
