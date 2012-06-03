#include "Expression.h"

QTextStream& operator<<(QTextStream& s, const Calculatrice::Expression& e){
    e.afficher();
    return s;
}
