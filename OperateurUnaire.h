#ifndef OPERATEURUNAIRE_H
#define OPERATEURUNAIRE_H

#include "Operateur.h"
#include "Expression.h"
<<<<<<< HEAD
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

=======
#include <QString>

namespace Calculatrice {
    class OperateurUnaire : public Operateur {
        public:
            OperateurUnaire(const QString op);

            QString& getOperator() const;

            QString toString() const;


            Expression& eval(const Expression& e);

    };
>>>>>>> d50d9c44f71eff56d4eada027bfcd613b1693de1
}


#endif // OPERATEURUNAIRE_H
