#ifndef PILE_H
#define PILE_H

#include <QStack>
#include "Expression.h"


/**
  * DP Singleton
  *
**/
namespace Calculatrice{
    class Pile: public QStack<Expression*>{
        private:
            static Pile* _pile;

            Pile(){}
            Pile(const Pile& p);
            ~Pile(){}
        public:
            static Pile& getInstance();
            static void libereInstance();

            //MÃ©thodes agissant sur la pile
            void SWAP();
            void SUM();
            void MEAN();
            void CLEAR();
            void DUP();
            void DROP();

            //MÃ©thodes de sauvegarde et de chargement
            void sauvegarder();
            void charger();

            void test();
    };
}

#endif // PILE_H
