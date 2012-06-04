#include "Operateur.h"

Calculatrice::Operateur(const QString& expression, bool first){
    _expEntiere = first;
    Fabrique* f = Fabrique::getInstance();
    if (first) {
        QStringList composants = expression.split(' ', QString::SkipEmptyParts);
        _exp = new Expression*[composants.count()];
        for(unsigned int i = 0; i < composants.count() ; ++i ) {
            cout << 'i : ' << i << endl;
            if(isOperateur(composants[i]))
                _exp[i] = new OperateurBinaire(composants[i]);
            else if(isEntier(composants[i]))
                _exp[i] = new Entier(composants[i]);
            else if(isReel(composants[i]))
                _exp[i] = new Reel(composants[i]);
            else if(isRationnel(composants[i]))
                _exp[i] = new Rationnel(composants[i]);
            else if(isComplexe(composants[i]))
                _exp[i] = new Complexe(composants[i]);
            else
                _exp[i] = new OperateurUnaire(composants[i]);
        }
    }
}

QString& Calculatrice::Operateur::afficher();
