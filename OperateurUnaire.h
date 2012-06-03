#ifndef OPERATEURUNAIRE_H
#define OPERATEURUNAIRE_H

#include "Operateur.h"

namespace Calculatrice {

enum OpUnaire {COS, SIN, SQR, SQRT, INV, SIGN};

class OperateurUnaire : public Operateur {
    private :
        OpUnaire _operateur;

    public:
        OperateurUnaire(QString op);

        QString getOperator();

    };

}


#endif // OPERATEURUNAIRE_H
