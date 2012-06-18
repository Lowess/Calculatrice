/** \file Expression.h
  * \author Florian Dambrine, Olivia Reaney
  * \brief Fichier d'en-t�te pour d�claration de la classe Expression
  */

#ifndef EXPRESSION_H
#define EXPRESSION_H

#include <QTextStream>

namespace LO21{

    class Constante;
    class Operateur;

    class Expression {
        private:

        public:
            //Méthodes virtuelles pures
            //virtual Expression& EVAL() =0;

            virtual void EVAL() = 0;

            virtual QString toString() const =0;

            void afficher() const{
                QTextStream cout(stdout, QIODevice::WriteOnly);
                cout << this->toString();
            }

            virtual Expression* clone() const=0;
    };
}

//operator<<
QTextStream& operator<<(QTextStream& s, const LO21::Expression& n);

#endif // EXPRESSION_H
