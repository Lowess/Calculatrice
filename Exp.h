/** \file Exp.h
  * \author Florian Dambrine, Olivia Reaney
  * \brief Fichier d'en-tête pour déclaration de la classe Exp
  */

#ifndef EXP_H
#define EXP_H


#include "Constante.h"
#include "Fabrique.h"

namespace LO21{
    class Exp: public Constante {
        private:
            const QString _exp;
        public:
            Exp(const QString& s):_exp(s){}

            Constante& addition(const Constante& nb) const;
            Constante& soustraction(const Constante& nb) const;
            Constante& multiplication(const Constante& nb) const;
            Constante& division(const Constante& nb) const;

            void EVAL();

            Constante& hookOperation();

            QString toString() const;

            Exp* clone() const;
    };
}

#endif // EXP_H
