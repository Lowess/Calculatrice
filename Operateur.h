#ifndef OPERATEUR_H
#define OPERATEUR_H

#include "Expression.h"
#include "Fabrique.h"
#include <QString>
#include <QStringList>
#include <QStack>

namespace Calculatrice{

    class OperateurUnaire;
    class OperateurBinaire;

    class Operateur: public Expression {
        private:
            unsigned int _nbItems;
            Expression** _exp;
            bool _expEntiere;

        public:
            Operateur(const QString expression, bool first = false);
            Operateur(){}

            QString toString() const;

            //Expression EVAL();
            Expression& EVAL();

    };
}

#endif // OPERATEUR_H
