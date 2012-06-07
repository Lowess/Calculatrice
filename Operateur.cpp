#include "Operateur.h"
#include <stdexcept>

using namespace Calculatrice;
using namespace std;

Calculatrice::Operateur::Operateur(const QString expression, bool first){
    _expEntiere = first;
    if (first) {
        QStringList composants = expression.split(' ', QString::SkipEmptyParts);
        _nbItems = composants.count();
        _exp = new Calculatrice::Expression*[_nbItems];
        for(unsigned int i = 0; i < _nbItems ; ++i ) {
            //cout << 'i : ' << i << endl;
            if(isOperateur(composants[i]))
                _exp[i] = new Calculatrice::OperateurBinaire(composants[i]);
            else if(isEntier(composants[i]))
                _exp[i] = new Calculatrice::Entier(composants[i].toInt());
            else if(isReel(composants[i]))
                _exp[i] = new Calculatrice::Reel(composants[i].toDouble());
            else if(isRationnel(composants[i])) {
                QStringList tmpR = composants[i].split('/', QString::SkipEmptyParts);
                _exp[i] = new Calculatrice::Rationnel(Calculatrice::Entier(tmpR[0].toInt()), Calculatrice::Entier(tmpR[1].toInt()));
            }
            else if(isComplexe(composants[i])) {
                QStringList tmpE = composants[i].split('$', QString::SkipEmptyParts);
                _exp[i] = new Calculatrice::Complexe(Calculatrice::Entier(tmpE[0].toInt()), Calculatrice::Entier(tmpE[1].toInt()));
            }
            else
                _exp[i] = new Calculatrice::OperateurUnaire(composants[i]);

        }
    }
}

QString Calculatrice::Operateur::toString() const {
    QString s;
    for(unsigned int i = 0; i < _nbItems ; ++i) {
        s.append(_exp[i]->toString());
    }
    return s;
}

QString& Calculatrice::Operateur::afficher() {
    QString s("");
    for(unsigned int i = 0; i < _nbItems ; ++i) {
        s.append(_exp[i]->toString());
    }
    return s;
}

void Operateur::EVAL(){}

void Calculatrice::Operateur::appliqueOperateur(){
    Pile* p=&Pile::getInstance();

    switch(_operateur){
        // + - * / --> On pop deux éléments et on push le résultat
        case ADD:{
            Expression* x=p->pop();
            Expression* y=p->pop();
            //On test ce que vaut x et y (Constantes ou Expressions?)
            Constante* cx=dynamic_cast<Constante*>(x);
            Constante* cy=dynamic_cast<Constante*>(y);
            if(cx!=0 || cy!=0){ //Deux constantes
                Expression& res=*cx+*cy;
                p->push(&res);

                delete x;
                delete y;
            }
            break;
        }
        case SOU:{
            break;
        }
        case MUL:{
            break;
        }
        case DIV:{
            break;
        //Trigonométrie
        }
        case SIN:{
            Expression* x=p->pop();
            //On test ce que vaut x (Il faut que ce soit soit une Expression soit un Nombre)
            Nombre* nx=dynamic_cast<Nombre*>(x);
            if(nx!=0){ //C'est un nombre
                Expression& res=nx->SIN();
                p->push(&res);

                delete x;
            }
            break;
        }
        case COS:{
            Expression* x=p->pop();
            //On test ce que vaut x (Il faut que ce soit soit une Expression soit un Nombre)
            Nombre* nx=dynamic_cast<Nombre*>(x);
            if(nx!=0){ //C'est un nombre
                Expression& res=nx->COS();
                p->push(&res);

                delete x;
            }
            break;
        }
        case TAN:{
            Expression* x=p->pop();
            //On test ce que vaut x (Il faut que ce soit soit une Expression soit un Nombre)
            Nombre* nx=dynamic_cast<Nombre*>(x);
            if(nx!=0){ //C'est un nombre
                Expression& res=nx->TAN();
                p->push(&res);

                delete x;
            }
            break;
        }
        case SINH:{
            Expression* x=p->pop();
            //On test ce que vaut x (Il faut que ce soit soit une Expression soit un Nombre)
            Nombre* nx=dynamic_cast<Nombre*>(x);
            if(nx!=0){ //C'est un nombre
                Expression& res=nx->SINH();
                p->push(&res);

                delete x;
            }
            break;
        }
        case COSH:{
            Expression* x=p->pop();
            //On test ce que vaut x (Il faut que ce soit soit une Expression soit un Nombre)
            Nombre* nx=dynamic_cast<Nombre*>(x);
            if(nx!=0){ //C'est un nombre
                Expression& res=nx->COSH();
                p->push(&res);

                delete x;
            }
            break;
        }
        case TANH:{
            Expression* x=p->pop();
            //On test ce que vaut x (Il faut que ce soit soit une Expression soit un Nombre)
            Nombre* nx=dynamic_cast<Nombre*>(x);
            if(nx!=0){ //C'est un nombre
                Expression& res=nx->TANH();
                p->push(&res);

                delete x;
            }
            break;
        //Autres
        }
        case SQR:{
            Expression* x=p->pop();
            //On test ce que vaut x (Il faut que ce soit soit une Expression soit un Nombre)
            Constante* nx=dynamic_cast<Constante*>(x);
            if(nx!=0){ //C'est un nombre
                Expression& res=nx->SQR();
                p->push(&res);

                delete x;
            }
            break;
        }
        case CUBE:{
            Expression* x=p->pop();
            //On test ce que vaut x (Il faut que ce soit soit une Expression soit un Nombre)
            Constante* nx=dynamic_cast<Constante*>(x);
            if(nx!=0){ //C'est un nombre
                Expression& res=nx->CUBE();
                p->push(&res);

                delete x;
            }
            break;
        }
        case SQRT:{
            Expression* x=p->pop();
            //On test ce que vaut x (Il faut que ce soit soit une Expression soit un Nombre)
            Nombre* nx=dynamic_cast<Nombre*>(x);
            if(nx!=0){ //C'est un nombre
                Expression& res=nx->SQRT();
                p->push(&res);

                delete x;
            }
            break;
        }
        case INV:{
            Expression* x=p->pop();
            //On test ce que vaut x (Il faut que ce soit soit une Expression soit un Nombre)
            Nombre* nx=dynamic_cast<Nombre*>(x);
            if(nx!=0){ //C'est un nombre
                Expression& res=nx->INV();
                p->push(&res);

                delete x;
            }
            break;
        }
        case SIGN:{
            Expression* x=p->pop();
            //On test ce que vaut x (Il faut que ce soit soit une Expression soit un Nombre)
            Constante* nx=dynamic_cast<Constante*>(x);
            if(nx!=0){ //C'est un nombre
                Expression& res=nx->SIGN();
                p->push(&res);

                delete x;
            }
            break;
        }
        default:{
            throw CalculatriceException(typeid(this).name(), OTHER, "Operateur non reconnu");
            break;
        }
    }
}
