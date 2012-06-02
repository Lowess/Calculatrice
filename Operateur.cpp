#include "Operateur.h"

Calculatrice::Operateur(unsigned int lengthItems, QString sign):_exp(new Expression* [length_nb]),_length(lengthItems),_firstOp(false){
    if (lengthItems > 1) {
        _firstOp = true;
        for(unsigned int i = 0; i < _length ; ++i) {
               /*Faire une boucle sur chaque signe pour créer opérateurs ou constantes et les insérer dans exp en fonction de i*/
        }
    }
}
