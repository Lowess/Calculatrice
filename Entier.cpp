#include "Entier.h"

//Implementation des méthodes vituelles pures de la class "Nombre"

void Calculatrice::Entier::SIN(){}
void Calculatrice::Entier::COS(){}
void Calculatrice::Entier::TAN(){}
void Calculatrice::Entier::SINH(){}
void Calculatrice::Entier::COSH(){}
void Calculatrice::Entier::TANH(){}
void Calculatrice::Entier::LN(){}
void Calculatrice::Entier::LOG(){}
void Calculatrice::Entier::INV(){}
void Calculatrice::Entier::SQRT(){}
void Calculatrice::Entier::POW(){}


Calculatrice::Nombre& Calculatrice::Entier::addition(const Nombre& nb){
    std::cout << typeid(nb).name();

    return *this;
}

Calculatrice::Nombre& Calculatrice::Entier::soustraction(const Nombre& nb){

    return *this;
}
Calculatrice::Nombre& Calculatrice::Entier::multiplication(const Nombre& nb){

    return *this;
}
Calculatrice::Nombre& Calculatrice::Entier::division(const Nombre& nb){

    return *this;
}

QString Calculatrice::Entier::toString() const{
    QString str;
    str.setNum(_x);
    return str;
}

//Implementation des méthodes vituelles pures de la class "Expression"
void Calculatrice::Entier::EVAL(){}

//Constructeurs

