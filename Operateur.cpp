#include "Operateur.h"

QString& Calculatrice::Operateur::afficher() {
    QString s("");
    for(unsigned int i = 0; i < __nbItems ; ++i) {
        s.append(_exp[i]->toString());
    }
    return s;
}
