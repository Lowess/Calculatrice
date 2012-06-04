#ifndef PILE_H
#define PILE_H

#include <QStack>

namespace Calculatrice{
    class Pile: public QStack{
        private:

        public:
            //Méthodes agissant sur la pile
            void SWAP();
            void SUM();
            void MEAN();
            void CLEAR();
            void DUP();
            void DROP();

            //Méthodes de sauvegarde et de chargement
            void sauvegarder();
            void charger();
    };

}

#endif // PILE_H
