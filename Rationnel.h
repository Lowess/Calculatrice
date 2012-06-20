/** \file Rationnel.h
  * \author Florian Dambrine, Olivia Reaney
  * \brief Fichier d'en-tête pour déclaration de la classe Rationnel
  */

#ifndef RATIONNEL_H
#define RATIONNEL_H

#include <iostream>

#include "Nombre.h"
#include "Entier.h"

/*! \namespace LO21
 *  \brief Désigne les classes définies dans le but du projet de LO21 P12
 */
namespace LO21{

    class Rationnel: public Nombre {
        private:
            LO21::Entier _n;
            LO21::Entier _d;
        public:
            Constante& addition(const Constante& nb) const;
            Constante& soustraction(const Constante& nb) const;
            Constante& multiplication(const Constante& nb) const;
            Constante& division(const Constante& nb) const;

            QString toString() const;

            //MÃƒÂ©thodes
            void simplifier();

            Reel& toReel() const;
            Entier& toEntier() const;
            Complexe& toComplexe() const;

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

            Rationnel* clone() const;
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
