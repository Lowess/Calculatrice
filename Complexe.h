#ifndef COMPLEXE_H
#define COMPLEXE_H

#include <iostream>
#include "Constante.h"
#include "Nombre.h"
#include <typeinfo>
#include <QString>

namespace LO21{

    class Entier;
    class Reel;
    class Rationnel;
    class Constante;

    class Complexe:public Constante{
        private:
            const Nombre* _a;
            const Nombre* _b;

        public:
            //Complexe(const Nombre* a,const Nombre* b);
            Complexe(const Constante& a, const Constante& b);
            ~Complexe() {
                delete _a;
                delete _b;
            }

            QString toString() const{
                return (QString(_a->toString() + "$" + _b->toString()));
            }

            //MÃ©thodes publiques
            Constante& module() const;
            Constante& addition(const Constante& c) const;
            Constante& soustraction(const Constante& c) const;
            Constante& multiplication(const Constante& c) const;
            Constante& division(const Constante& c) const;

            Constante& SIGN() const;
            Constante& SQR() const;
            Constante& CUBE() const;

            Constante& hookOperation();


            Complexe* clone() const;
    };
}

#endif // COMPLEXE_H
