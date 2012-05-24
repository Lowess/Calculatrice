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

            Nombre& addition(const Nombre& nb) const;
            Nombre& soustraction(const Nombre& nb) const;
            Nombre& multiplication(const Nombre& nb) const;
            Nombre& division(const Nombre& nb) const;

            QString toString() const;

            //Implementation des méthodes virtuelles pures de la class "Expression"
            void EVAL();

            //Méthodes


            //Setter Getter
            const Entier& get_n() const{ return _n; }
            const Entier& get_d() const{ return _d; }

            //Constructeurs
            Rationnel(const Entier& x, const Entier& y){
                _n=x;
                if(y.get_x()==0)
                    throw CalculatriceException(typeid(this).name(),MATHS,"Denominateur nul");
                _d=y;
            }
            Rationnel(unsigned int x=0, unsigned int y=1){
                _n=Entier(x);
                if(y==0)
                    throw CalculatriceException(typeid(this).name(),MATHS,"Denominateur nul");
                _d=Entier(y);
            }




    };
    //Fonctions
    Entier pgcd(const Entier& a, const Entier& b);
    Entier ppcm(const Entier& a, const Entier& b);
}

#endif // RATIONNEL_H
