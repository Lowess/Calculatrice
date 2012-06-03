#ifndef OPERATEURBINAIRE_H
#define OPERATEURBINAIRE_H

namespace Calculatrice {

enum OpBinaire {ADD, SOU, MUL, DIV};

    class OperateurBinaire : public Operateur{

        private:
            OpBinaire _operateur;

        public:

            OperateurBinaire(QString op);

            QString getOperator();

    };

}

#endif // OPERATEURBINAIRE_H
