#ifndef EXPRESSION_H
#define EXPRESSION_H

#include <QTextStream>

<<<<<<< HEAD
/**
  * DP iterator pour parcourir l'expression
  *
**/
=======

>>>>>>> 275b14b2101be9e7e4bcc79c86bf928fdd16c288
namespace Calculatrice{

    class Constante;
    class Operateur;

    class Expression {
        private:

        public:
            //Méthodes virtuelles pures
            virtual Expression& EVAL() =0;

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
