#include "Operateur.h"


using namespace LO21;
using namespace std;

LO21::Operateur* LO21::Operateur::clone() const{}

void LO21::Operateur::EVAL(){
}

void LO21::Operateur::appliqueOperateur(){
    Pile* p=Calculatrice::getInstance().get_pile();

    switch(_operateur){
        // + - * / --> On pop deux elements et on push le resultat
        case ADD:{
            if(p->count() < 2){
                LogSystem::ecrireLog(LogMessage("Erreur classe operateur ",ERREUR));
                throw CalculatriceException(typeid(this).name(), OTHER, "La pile ne contient pas assez d'operande pour evaluer l'operation");
            }
            Expression* x=p->pop();
            Expression* y=p->pop();
            //On test ce que vaut x et y (Constantes ou Expressions?)
            Constante* cx=dynamic_cast<Constante*>(x);
            Constante* cy=dynamic_cast<Constante*>(y);
            if(cx!=0 && cy!=0){ //Deux constantes
                Expression& res=*cx + *cy;
                p->push(&res);

                delete x;
                delete y;
            }
            else{
                p->push(x);
                p->push(y);
                LogSystem::ecrireLog(LogMessage("Erreur classe operateur ",ERREUR));
                throw CalculatriceException(typeid(this).name(), MATHS, "Operation non definie pour ce type de constante");
            }
            break;
        }
        case SOU:{
            if(p->count() < 2){
                LogSystem::ecrireLog(LogMessage("Erreur classe operateur ",ERREUR));
                throw CalculatriceException(typeid(this).name(), OTHER, "La pile ne contient pas assez d'operande pour evaluer l'operation");
            }
            Expression* x=p->pop();
            Expression* y=p->pop();
            //On test ce que vaut x et y (Constantes ou Expressions?)
            Constante* cx=dynamic_cast<Constante*>(x);
            Constante* cy=dynamic_cast<Constante*>(y);
            if(cx!=0 && cy!=0){ //Deux constantes
                Expression& res=*cx - *cy;
                p->push(&res);

                delete x;
                delete y;
            }
            else{
                p->push(x);
                p->push(y);
                LogSystem::ecrireLog(LogMessage("Erreur classe operateur ",ERREUR));
                throw CalculatriceException(typeid(this).name(), MATHS, "Operation non definie pour ce type de constante");
            }
            break;
        }
        case MUL:{
            if(p->count() < 2){
                LogSystem::ecrireLog(LogMessage("Erreur classe operateur ",ERREUR));
                throw CalculatriceException(typeid(this).name(), OTHER, "La pile ne contient pas assez d'operande pour evaluer l'operation");
            }
            Expression* x=p->pop();
            Expression* y=p->pop();
            //On test ce que vaut x et y (Constantes ou Expressions?)
            Constante* cx=dynamic_cast<Constante*>(x);
            Constante* cy=dynamic_cast<Constante*>(y);
            if(cx!=0 && cy!=0){ //Deux constantes
                Expression& res=*cx * *cy;
                p->push(&res);

                delete x;
                delete y;
            }
            else{
                p->push(x);
                p->push(y);
                LogSystem::ecrireLog(LogMessage("Erreur classe operateur ",ERREUR));
                throw CalculatriceException(typeid(this).name(), MATHS, "Operation non definie pour ce type de constante");
            }
            break;
        }
        case DIV:{
            if(p->count() < 2){
                LogSystem::ecrireLog(LogMessage("Erreur classe operateur ",ERREUR));
                throw CalculatriceException(typeid(this).name(), OTHER, "La pile ne contient pas assez d'operande pour evaluer l'operation");
            }
            Expression* x=p->pop();
            Expression* y=p->pop();
            //On test ce que vaut x et y (Constantes ou Expressions?)
            Constante* cx=dynamic_cast<Constante*>(x);
            Constante* cy=dynamic_cast<Constante*>(y);
            if(cx!=0 && cy!=0){ //Deux constantes
                Expression& res=*cx / *cy;
                p->push(&res);

                delete x;
                delete y;
            }
            else{
                p->push(x);
                p->push(y);
                LogSystem::ecrireLog(LogMessage("Erreur classe operateur ",ERREUR));
                throw CalculatriceException(typeid(this).name(), MATHS, "Operation non definie pour ce type de constante");
            }
            break;
        }
        case POW:{
            if(p->count() < 2){
                LogSystem::ecrireLog(LogMessage("Erreur classe operateur ",ERREUR));
                throw CalculatriceException(typeid(this).name(), OTHER, "La pile ne contient pas assez d'operande pour evaluer l'operation");
            }
            Expression* x=p->pop();
            Expression* y=p->pop();
            //On test ce que vaut x et y (Constantes ou Expressions?)
            Nombre* cx=dynamic_cast<Nombre*>(x);
            Nombre* cy=dynamic_cast<Nombre*>(y);
            if(cx!=0 && cy!=0){ //Deux constantes
                Expression& res=cy->POW(*cx);
                p->push(&res);

                delete x;
                delete y;
            }
            else{
                p->push(x);
                p->push(y);
                LogSystem::ecrireLog(LogMessage("Erreur classe operateur ",ERREUR));
                throw CalculatriceException(typeid(this).name(), MATHS, "Operation non definie pour ce type de constante");
            }
            break;
        }
        case MOD:{
            if(p->count() < 2){
                throw CalculatriceException(typeid(this).name(), OTHER, "La pile ne contient pas assez d'operande pour evaluer l'operation");
            }
            Expression* x=p->pop();
            Expression* y=p->pop();
            //On test ce que vaut x et y (Constantes ou Expressions?)
            Entier* cx=dynamic_cast<Entier*>(x);
            Entier* cy=dynamic_cast<Entier*>(y);
            if(cx!=0 && cy!=0){ //Deux constantes
                Expression& res=cy->MOD(*cx);
                p->push(&res);

                delete x;
                delete y;
            }
            else{
                p->push(x);
                p->push(y);
                LogSystem::ecrireLog(LogMessage("Erreur classe operateur ",ERREUR));
                throw CalculatriceException(typeid(this).name(), MATHS, "Operation non definie pour ce type de constante");
            }
            break;
        //Trigonometrie
        }
        case SIN:{
            if(p->count() < 1){
                LogSystem::ecrireLog(LogMessage("Erreur classe operateur ",ERREUR));
                throw CalculatriceException(typeid(this).name(), OTHER, "La pile ne contient pas assez d'operande pour evaluer l'operation");
            }
            Expression* x=p->pop();
            //On test ce que vaut x (Il faut que ce soit soit une Expression soit un Nombre)
            Nombre* nx=dynamic_cast<Nombre*>(x);
            if(nx!=0){ //C'est un nombre
                Expression& res=nx->SIN();
                p->push(&res);

                delete x;
            }
            else{
                p->push(x);
                LogSystem::ecrireLog(LogMessage("Erreur classe operateur ",ERREUR));
                throw CalculatriceException(typeid(this).name(), MATHS, "Operation non definie pour ce type de constante");
            }
            break;
        }
        case COS:{
            if(p->count() < 1){
                LogSystem::ecrireLog(LogMessage("Erreur classe operateur ",ERREUR));
                throw CalculatriceException(typeid(this).name(), OTHER, "La pile ne contient pas assez d'operande pour evaluer l'operation");
            }
            Expression* x=p->pop();
            //On test ce que vaut x (Il faut que ce soit soit une Expression soit un Nombre)
            Nombre* nx=dynamic_cast<Nombre*>(x);
            if(nx!=0){ //C'est un nombre
                Expression& res=nx->COS();
                p->push(&res);

                delete x;
            }
            else{
                p->push(x);
                LogSystem::ecrireLog(LogMessage("Erreur classe operateur ",ERREUR));
                throw CalculatriceException(typeid(this).name(), MATHS, "Operation non definie pour ce type de constante");
            }
            break;
        }
        case TAN:{
            if(p->count() < 1){
                LogSystem::ecrireLog(LogMessage("Erreur classe operateur ",ERREUR));
                throw CalculatriceException(typeid(this).name(), OTHER, "La pile ne contient pas assez d'operande pour evaluer l'operation");
            }
            Expression* x=p->pop();
            //On test ce que vaut x (Il faut que ce soit soit une Expression soit un Nombre)
            Nombre* nx=dynamic_cast<Nombre*>(x);
            if(nx!=0){ //C'est un nombre
                Expression& res=nx->TAN();
                p->push(&res);

                delete x;
            }
            else{
                p->push(x);
                LogSystem::ecrireLog(LogMessage("Erreur classe operateur ",ERREUR));
                throw CalculatriceException(typeid(this).name(), MATHS, "Operation non definie pour ce type de constante");
            }
            break;
        }
        case SINH:{
            if(p->count() < 1){
                LogSystem::ecrireLog(LogMessage("Erreur classe operateur ",ERREUR));
                throw CalculatriceException(typeid(this).name(), OTHER, "La pile ne contient pas assez d'operande pour evaluer l'operation");
            }
            Expression* x=p->pop();
            //On test ce que vaut x (Il faut que ce soit soit une Expression soit un Nombre)
            Nombre* nx=dynamic_cast<Nombre*>(x);
            if(nx!=0){ //C'est un nombre
                Expression& res=nx->SINH();
                p->push(&res);

                delete x;
            }
            else{
                p->push(x);
                LogSystem::ecrireLog(LogMessage("Erreur classe operateur ",ERREUR));
                throw CalculatriceException(typeid(this).name(), MATHS, "Operation non definie pour ce type de constante");
            }
            break;
        }
        case COSH:{
            if(p->count() < 1){
                LogSystem::ecrireLog(LogMessage("Erreur classe operateur ",ERREUR));
                throw CalculatriceException(typeid(this).name(), OTHER, "La pile ne contient pas assez d'operande pour evaluer l'operation");
            }
            Expression* x=p->pop();
            //On test ce que vaut x (Il faut que ce soit soit une Expression soit un Nombre)
            Nombre* nx=dynamic_cast<Nombre*>(x);
            if(nx!=0){ //C'est un nombre
                Expression& res=nx->COSH();
                p->push(&res);

                delete x;
            }
            else{
                p->push(x);
                LogSystem::ecrireLog(LogMessage("Erreur classe operateur ",ERREUR));
                throw CalculatriceException(typeid(this).name(), MATHS, "Operation non definie pour ce type de constante");
            }
            break;
        }
        case TANH:{
            if(p->count() < 1){
                LogSystem::ecrireLog(LogMessage("Erreur classe operateur ",ERREUR));
                throw CalculatriceException(typeid(this).name(), OTHER, "La pile ne contient pas assez d'operande pour evaluer l'operation");
            }
            Expression* x=p->pop();
            //On test ce que vaut x (Il faut que ce soit soit une Expression soit un Nombre)
            Nombre* nx=dynamic_cast<Nombre*>(x);
            if(nx!=0){ //C'est un nombre
                Expression& res=nx->TANH();
                p->push(&res);

                delete x;
            }
            else{
                p->push(x);
                LogSystem::ecrireLog(LogMessage("Erreur classe operateur ",ERREUR));
                throw CalculatriceException(typeid(this).name(), MATHS, "Operation non definie pour ce type de constante");
            }
            break;
        //Autres
        }
        case FACT:{
            if(p->count() < 1){
                LogSystem::ecrireLog(LogMessage("Erreur classe operateur ",ERREUR));
                throw CalculatriceException(typeid(this).name(), OTHER, "La pile ne contient pas assez d'operande pour evaluer l'operation");
            }
            Expression* x=p->pop();
            //On test ce que vaut x (Il faut que ce soit soit une Expression soit un Nombre)
            Entier* nx=dynamic_cast<Entier*>(x);
            if(nx!=0){ //C'est un entier
                Expression& res=nx->FACTORIELLE();
                p->push(&res);

                delete x;
            }
            else{
                p->push(x);
                LogSystem::ecrireLog(LogMessage("Erreur classe operateur ",ERREUR));
                throw CalculatriceException(typeid(this).name(), MATHS, "Operation non definie pour ce type de constante");
            }
            break;
        }
        case LOG:{
            if(p->count() < 1){
                LogSystem::ecrireLog(LogMessage("Erreur classe operateur ",ERREUR));
                throw CalculatriceException(typeid(this).name(), OTHER, "La pile ne contient pas assez d'operande pour evaluer l'operation");
            }
            Expression* x=p->pop();
            //On test ce que vaut x (Il faut que ce soit soit une Expression soit un Nombre)
            Nombre* nx=dynamic_cast<Nombre*>(x);
            if(nx!=0){ //C'est un nombre
                Expression& res=nx->LOG();
                p->push(&res);

                delete x;
            }
            else{
                p->push(x);
                LogSystem::ecrireLog(LogMessage("Erreur classe operateur ",ERREUR));
                throw CalculatriceException(typeid(this).name(), MATHS, "Operation non definie pour ce type de constante");
            }
            break;
        }
        case LN:{
            if(p->count() < 1){
                LogSystem::ecrireLog(LogMessage("Erreur classe operateur ",ERREUR));
                throw CalculatriceException(typeid(this).name(), OTHER, "La pile ne contient pas assez d'operande pour evaluer l'operation");
            }
            Expression* x=p->pop();
            //On test ce que vaut x (Il faut que ce soit soit une Expression soit un Nombre)
            Nombre* nx=dynamic_cast<Nombre*>(x);
            if(nx!=0){ //C'est un nombre
                Expression& res=nx->LN();
                p->push(&res);

                delete x;
            }
            else{
                p->push(x);
                LogSystem::ecrireLog(LogMessage("Erreur classe operateur ",ERREUR));
                throw CalculatriceException(typeid(this).name(), MATHS, "Operation non definie pour ce type de constante");
            }
            break;
        }
        case SQR:{
            if(p->count() < 1){
                LogSystem::ecrireLog(LogMessage("Erreur classe operateur ",ERREUR));
                throw CalculatriceException(typeid(this).name(), OTHER, "La pile ne contient pas assez d'operande pour evaluer l'operation");
            }
            Expression* x=p->pop();
            //On test ce que vaut x (Il faut que ce soit soit une Expression soit un Nombre)
            Constante* nx=dynamic_cast<Constante*>(x);
            if(nx!=0){ //C'est un nombre
                Expression& res=nx->SQR();
                p->push(&res);

                delete x;
            }
            else{
                p->push(x);
                LogSystem::ecrireLog(LogMessage("Erreur classe operateur ",ERREUR));
                throw CalculatriceException(typeid(this).name(), MATHS, "Operation non definie pour ce type de constante");
            }
            break;
        }
        case CUBE:{
            if(p->count() < 1){
                LogSystem::ecrireLog(LogMessage("Erreur classe operateur ",ERREUR));
                throw CalculatriceException(typeid(this).name(), OTHER, "La pile ne contient pas assez d'operande pour evaluer l'operation");
            }
            Expression* x=p->pop();
            //On test ce que vaut x (Il faut que ce soit soit une Expression soit un Nombre)
            Constante* nx=dynamic_cast<Constante*>(x);
            if(nx!=0){ //C'est un nombre
                Expression& res=nx->CUBE();
                p->push(&res);

                delete x;
            }
            else{
                p->push(x);
                LogSystem::ecrireLog(LogMessage("Erreur classe operateur ",ERREUR));
                throw CalculatriceException(typeid(this).name(), MATHS, "Operation non definie pour ce type de constante");
            }
            break;
        }
        case SQRT:{
            if(p->count() < 1){
                LogSystem::ecrireLog(LogMessage("Erreur classe operateur ",ERREUR));
                throw CalculatriceException(typeid(this).name(), OTHER, "La pile ne contient pas assez d'operande pour evaluer l'operation");
            }
            Expression* x=p->pop();
            //On test ce que vaut x (Il faut que ce soit soit une Expression soit un Nombre)
            Nombre* nx=dynamic_cast<Nombre*>(x);
            if(nx!=0){ //C'est un nombre
                try{
                    Expression& res=nx->SQRT();
                    p->push(&res);
                    delete x;
                }catch(exception& e){
                    LogSystem::ecrireLog(LogMessage("Erreur racine d'un nombre négatif ",ERREUR));
                    throw CalculatriceException(typeid(this).name(), OTHER, "Erreur racine d'un nombre négatif ");
                    p->push(x);
                }
            }
            else{
                p->push(x);
                LogSystem::ecrireLog(LogMessage("Erreur classe operateur ",ERREUR));
                throw CalculatriceException(typeid(this).name(), MATHS, "Operation non definie pour ce type de constante");
            }
            break;
        }
        case INV:{
            if(p->count() < 1){
                LogSystem::ecrireLog(LogMessage("Erreur classe operateur ",ERREUR));
                throw CalculatriceException(typeid(this).name(), OTHER, "La pile ne contient pas assez d'operande pour evaluer l'operation");
            }
            Expression* x=p->pop();
            //On test ce que vaut x (Il faut que ce soit soit une Expression soit un Nombre)
            Nombre* nx=dynamic_cast<Nombre*>(x);
            if(nx!=0){ //C'est un nombre
                Expression& res=nx->INV();
                p->push(&res);

                delete x;
            }
            else{
                p->push(x);
                LogSystem::ecrireLog(LogMessage("Erreur classe operateur ",ERREUR));
                throw CalculatriceException(typeid(this).name(), MATHS, "Operation non definie pour ce type de constante");
            }
            break;
        }
        case SIGN:{
            if(p->count() < 1){
                LogSystem::ecrireLog(LogMessage("Erreur classe operateur ",ERREUR));
                throw CalculatriceException(typeid(this).name(), OTHER, "La pile ne contient pas assez d'operande pour evaluer l'operation");
            }
            Expression* x=p->pop();
            //On test ce que vaut x (Il faut que ce soit soit une Expression soit un Nombre)
            Constante* nx=dynamic_cast<Constante*>(x);
            if(nx!=0){ //C'est un nombre
                Expression& res=nx->SIGN();
                p->push(&res);

                delete x;
            }
            else{
                p->push(x);
                LogSystem::ecrireLog(LogMessage("Erreur classe operateur ",ERREUR));
                throw CalculatriceException(typeid(this).name(), MATHS, "Operation non definie pour ce type de constante");
            }
            break;
        }
        case EVALUATION:{
            if(p->count() < 1){
                LogSystem::ecrireLog(LogMessage("Erreur classe operateur ",ERREUR));
                throw CalculatriceException(typeid(this).name(), OTHER, "La pile ne contient pas assez d'operande pour evaluer l'operation");
            }
            Expression* exp=p->pop();
            Exp* e=dynamic_cast<Exp *>(exp);
            if(e==0){
                p->push(exp);
                LogSystem::ecrireLog(LogMessage("Erreur classe operateur ",ERREUR));
                throw CalculatriceException(typeid(this).name(), OTHER, "L'operande n'est pas une expression, evaluation impossible");
            }
            e->EVAL();

            delete exp;

            break;
        }
        default:{
            LogSystem::ecrireLog(LogMessage("Erreur classe operateur ",ERREUR));
            throw CalculatriceException(typeid(this).name(), OTHER, "Operateur non reconnu");
            break;
        }
    }
}
