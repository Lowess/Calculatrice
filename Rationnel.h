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
            Constante& addition(const Constante& nb) const;
            Constante& soustraction(const Constante& nb) const;
            Constante& multiplication(const Constante& nb) const;
            Constante& division(const Constante& nb) const;

            QString toString() const;

            //Implementation des méthodes virtuelles pures de la class "Expression"
            void EVAL();

            //Méthodes
            void simplifier();

            Reel& toReel() const;
            Entier& toEntier() const;

            //Setter Getter
            const Entier& get_n() const{ return _n; }
            const Entier& get_d() const{ return _d; }
            //void set_n(const Entier& e) { _n=e; }
            //void set_d(const Entier& e) { _d=e; }

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
/*
            //Recopie et operator=
            Rationnel(const Rationnel& e);
            Rationnel& operator=(const Rationnel& e);

            //Destructeur
            ~Rationnel(){}
*/


    };
    //Fonctions
    Entier pgcd(const Entier& a, const Entier& b);
    Entier ppcm(const Entier& a, const Entier& b);
}

#endif // RATIONNEL_H
