#include "Operateur.h"

Calculatrice::Operateur::Operateur(const QString expression, bool first){
    _expEntiere = first;
    if (first) {
        QStringList composants = expression.split(' ', QString::SkipEmptyParts);
        _nbItems = composants.count();
        _exp = new Calculatrice::Expression*[_nbItems];
        for(unsigned int i = 0; i < _nbItems ; ++i ) {
            //cout << 'i : ' << i << endl;
            if(isOperateur(composants[i]))
                _exp[i] = new Calculatrice::OperateurBinaire(composants[i]);
            else if(isEntier(composants[i]))
                _exp[i] = new Calculatrice::Entier(composants[i].toInt());
            else if(isReel(composants[i]))
                _exp[i] = new Calculatrice::Reel(composants[i].toDouble());
            else if(isRationnel(composants[i])) {
                QStringList tmpR = composants[i].split('/', QString::SkipEmptyParts);
                _exp[i] = new Calculatrice::Rationnel(Calculatrice::Entier(tmpR[0].toInt()), Calculatrice::Entier(tmpR[1].toInt()));
            }
            else if(isComplexe(composants[i])) {
                QStringList tmpE = composants[i].split('$', QString::SkipEmptyParts);
                _exp[i] = new Calculatrice::Complexe(Calculatrice::Entier(tmpE[0].toInt()), Calculatrice::Entier(tmpE[1].toInt()));
            }
            else
                _exp[i] = new Calculatrice::OperateurUnaire(composants[i]);

        }
    }
}

QString Calculatrice::Operateur::toString() const {
    QString s;
    for(unsigned int i = 0; i < _nbItems ; ++i) {
        s.append(_exp[i]->toString());
    }
    return s;
}
