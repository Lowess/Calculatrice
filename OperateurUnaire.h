#ifndef OPERATEURUNAIRE_H
#define OPERATEURUNAIRE_H

#include "Operateur.h"
#include "Expression.h"
#include <QString>

namespace Calculatrice {

enum OpUnaire {COS, SIN, COSH, SINH, SQR, CUBE, SQRT, INV, SIGN};

class OperateurUnaire : public Operateur {
    private :
        OpUnaire _operateur;

    public:
        OperateurUnaire(const QString op);

        const QString getOperator();

        Expression& eval(const Expression& e);

    };

}


#endif // OPERATEURUNAIRE_H
