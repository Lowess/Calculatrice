#include "Nombre.h"

QTextStream& operator<<(QTextStream& s, const Calculatrice::Nombre& n){
    n.afficher();
    return s;
}
