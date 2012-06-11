#include "Operateur.h"
#include <stdexcept>

using namespace Calculatrice;
using namespace std;

void Operateur::EVAL(){}

void Calculatrice::Operateur::appliqueOperateur(){
    Pile* p=&Pile::getInstance();

    switch(_operateur){
        // + - * / --> On pop deux éléments et on push le résultat
        case ADD:{
            if(p->count() < 2)
                throw CalculatriceException(typeid(this).name(), OTHER, "La pile ne contient pas assez d'opérande pour évaluer l'opération");
            Expression* x=p->pop();
            Expression* y=p->pop();
            //On test ce que vaut x et y (Constantes ou Expressions?)
            Constante* cx=dynamic_cast<Constante*>(x);
            Constante* cy=dynamic_cast<Constante*>(y);
            if(cx!=0 || cy!=0){ //Deux constantes
                Expression& res=*cx + *cy;
                p->push(&res);

                delete x;
                delete y;
            }
            break;
        }
        case SOU:{
            if(p->count() < 2)
                throw CalculatriceException(typeid(this).name(), OTHER, "La pile ne contient pas assez d'opérande pour évaluer l'opération");

            Expression* x=p->pop();
            Expression* y=p->pop();
            //On test ce que vaut x et y (Constantes ou Expressions?)
            Constante* cx=dynamic_cast<Constante*>(x);
            Constante* cy=dynamic_cast<Constante*>(y);
            if(cx!=0 || cy!=0){ //Deux constantes
                Expression& res=*cx - *cy;
                p->push(&res);

                delete x;
                delete y;
            }
            break;
        }
        case MUL:{
            if(p->count() < 2)
                throw CalculatriceException(typeid(this).name(), OTHER, "La pile ne contient pas assez d'opérande pour évaluer l'opération");

            Expression* x=p->pop();
            Expression* y=p->pop();
            //On test ce que vaut x et y (Constantes ou Expressions?)
            Constante* cx=dynamic_cast<Constante*>(x);
            Constante* cy=dynamic_cast<Constante*>(y);
            if(cx!=0 || cy!=0){ //Deux constantes
                Expression& res=*cx * *cy;
                p->push(&res);

                delete x;
                delete y;
            }
            break;
        }
        case DIV:{
            if(p->count() < 2)
                throw CalculatriceException(typeid(this).name(), OTHER, "La pile ne contient pas assez d'opérande pour évaluer l'opération");

            Expression* x=p->pop();
            Expression* y=p->pop();
            //On test ce que vaut x et y (Constantes ou Expressions?)
            Constante* cx=dynamic_cast<Constante*>(x);
            Constante* cy=dynamic_cast<Constante*>(y);
            if(cx!=0 || cy!=0){ //Deux constantes
                Expression& res=*cx / *cy;
                p->push(&res);

                delete x;
                delete y;
            }
            break;
        //Trigonométrie
        }
        case SIN:{
            if(p->count() < 1)
                throw CalculatriceException(typeid(this).name(), OTHER, "La pile ne contient pas assez d'opérande pour évaluer l'opération");

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
            if(p->count() < 1)
                throw CalculatriceException(typeid(this).name(), OTHER, "La pile ne contient pas assez d'opérande pour évaluer l'opération");

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
            if(p->count() < 1)
                throw CalculatriceException(typeid(this).name(), OTHER, "La pile ne contient pas assez d'opérande pour évaluer l'opération");

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
            if(p->count() < 1)
                throw CalculatriceException(typeid(this).name(), OTHER, "La pile ne contient pas assez d'opérande pour évaluer l'opération");

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
            if(p->count() < 1)
                throw CalculatriceException(typeid(this).name(), OTHER, "La pile ne contient pas assez d'opérande pour évaluer l'opération");

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
            if(p->count() < 1)
                throw CalculatriceException(typeid(this).name(), OTHER, "La pile ne contient pas assez d'opérande pour évaluer l'opération");

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
            if(p->count() < 1)
                throw CalculatriceException(typeid(this).name(), OTHER, "La pile ne contient pas assez d'opérande pour évaluer l'opération");

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
            if(p->count() < 1)
                throw CalculatriceException(typeid(this).name(), OTHER, "La pile ne contient pas assez d'opérande pour évaluer l'opération");

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
            if(p->count() < 1)
                throw CalculatriceException(typeid(this).name(), OTHER, "La pile ne contient pas assez d'opérande pour évaluer l'opération");

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
            if(p->count() < 1)
                throw CalculatriceException(typeid(this).name(), OTHER, "La pile ne contient pas assez d'opérande pour évaluer l'opération");

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
            if(p->count() < 1)
                throw CalculatriceException(typeid(this).name(), OTHER, "La pile ne contient pas assez d'opérande pour évaluer l'opération");

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
