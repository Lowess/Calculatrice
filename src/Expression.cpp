#include "Expression.h"

QTextStream& operator<<(QTextStream& s, const LO21::Expression& e){
    e.afficher();
    return s;
}
