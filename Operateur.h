#ifndef OPERATEUR_H
#define OPERATEUR_H

#include "Expression.h"
#include "Fabrique.h"
#include <QString>
#include <QStringList>

namespace Calculatrice{
    class Operateur: public Expression {
        private:
            Expression** _exp;
            bool _expEntiere;

        public:
            Operateur(const QString& expression, bool first = false);

            virtual QString getOperator() = 0;

            //Expression EVAL();
            void EVAL();

    };
}

#endif // OPERATEUR_H
