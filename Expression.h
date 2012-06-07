#ifndef EXPRESSION_H
#define EXPRESSION_H

#include <QTextStream>

/**
  * DP iterator pour parcourir l'expression
  *
**/
namespace Calculatrice{
    class Expression {
        private:

        public:
            //Méthodes virtuelles pures
            virtual void EVAL() =0;

            virtual QString toString() const =0;

            void afficher() const{
                QTextStream cout(stdout, QIODevice::WriteOnly);
                cout << this->toString();
            }
    };

}

//operator<<
QTextStream& operator<<(QTextStream& s, const Calculatrice::Expression& n);

#endif // EXPRESSION_H
