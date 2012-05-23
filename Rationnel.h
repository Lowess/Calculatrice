#ifndef RATIONNEL_H
#define RATIONNEL_H

#include <iostream>

#include "Nombre.h"
#include "Entier.h"

namespace Calculatrice{
    class Rationnel: public Nombre {
        private:
            Calculatrice::Entier _n;
            Calculatrice::Entier _d;
        public:
            //Implémentation des méthodes virtuelles pures de la class "Nombre"
            void SIN();
            void COS();
            void TAN();
            void SINH();
            void COSH();
            void TANH();
            void LN();
            void LOG();
            void INV();
            void SQRT();
            void POW();

            Nombre& addition(const Nombre& nb);
            Nombre& soustraction(const Nombre& nb);
            Nombre& multiplication(const Nombre& nb);
            Nombre& division(const Nombre& nb);

            QString toString() const;

            //Implementation des méthodes virtuelles pures de la class "Expression"
            void EVAL();

            //Méthodes

            //Setter Getter
            const Entier& get_n() const{ return _n; }
            const Entier& get_d() const{ return _d; }

            //Constructeur
            Rationnel(const Entier& x, const Entier& y):_n(x),_d(y){}
            Rationnel(unsigned int x, unsigned int y):_n(Entier(x)),_d(Entier(y)){}




    };
}
//Fonctions

Calculatrice::Entier pgcd(const Calculatrice::Entier& a, const Calculatrice::Entier& b) const;

#endif // RATIONNEL_H
