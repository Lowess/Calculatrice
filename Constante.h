#ifndef CONSTANTE_H
#define CONSTANTE_H

#include <QDebug>

#include "Expression.h"

namespace Calculatrice{
    class Constante{
        private:
            /*Partie r�elle*/
            int _entierR;
            float _decimalR;
            int _denominateurR;

            /*Partie imaginaire*/
            int _entierI;
            float _decimalI;
            int _denominateurI;

        public:
            Calculatrice::Constante();

            QString Calculatrice::toString(){
                return QString(this->_a + "+" + this->_b + "i");
            }

            //Impl�mentation des m�thodes virtuelles pures de la class "Expression"
            void EVAL();

            //M�thodes publiques
            Constante& addition(const Constante& c) const;
            Constante& soustraction(const Constante& c) const;
            Constante& multiplication(const Constante& c) const;
            Constante& division(const Constante& c) const;

    };
}

#endif // CONSTANTE_H
