#ifndef OPERATEURUNAIRE_H
#define OPERATEURUNAIRE_H

#include "Operateur.h"
#include "Expression.h"
#include <iostream>
#include <QString>

namespace Calculatrice {

enum OpUnaire {COS, SIN, TAN, COSH, SINH, TANH, LN, SQR, CUBE, SQRT, INV, SIGN};

class OperateurUnaire : public Operateur {
    private :
        OpUnaire _operateur;

    public:
        OperateurUnaire(const QString op);
        OperateurUnaire(){}

        QString toString() const;

        bool isOperateurUnaire();

        Expression& calcul(const Expression& e);

    };

}


#endif // OPERATEURUNAIRE_H
