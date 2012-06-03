#ifndef PILE_H
#define PILE_H

#include "QStack"

namespace Calculatrice{
    class Pile: public QStack{
        private:

        public:
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
<<<<<<< .merge_file_a04364

            //MÃ©thodes spÃ©cifique
            void SIGN();
            void SQR();
            void CUBE();

=======
>>>>>>> .merge_file_a04808
    };

}

#endif // PILE_H
