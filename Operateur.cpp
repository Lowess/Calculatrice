#include "Operateur.h"

Calculatrice::Operateur(const QString& expression, bool first){
    _expEntiere = first;
    if (first) {
        QStringList composants = expression.split(' ');
        for(unsigned int i = 0; i < composants.count() ; ++i ) {
            cout << 'i : ' << i << endl;
            if(composants[i].)
            _exp[i] = newComposant;
        }
    }
    else {

    }
    //On splitte expression avec les espaces
    //on alloue un tableau de la longueur de QStringList
    //On fait une boucle pour créer chaque operateur
}
