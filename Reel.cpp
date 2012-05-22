#include "Reel.h"

//Implementation des méthodes vituelles pures de la class "Nombre"
void Calculatrice::Reel::SIN(){}
void Calculatrice::Reel::COS(){}
void Calculatrice::Reel::TAN(){}
void Calculatrice::Reel::SINH(){}
void Calculatrice::Reel::COSH(){}
void Calculatrice::Reel::TANH(){}
void Calculatrice::Reel::LN(){}
void Calculatrice::Reel::LOG(){}
void Calculatrice::Reel::INV(){}
void Calculatrice::Reel::SQRT(){}
void Calculatrice::Reel::POW(){}


Calculatrice::Nombre& Calculatrice::Reel::addition(const Nombre& nb){

    return *this;
}

Calculatrice::Nombre& Calculatrice::Reel::soustraction(const Nombre& nb){

    return *this;
}
Calculatrice::Nombre& Calculatrice::Reel::multiplication(const Nombre& nb){

    return *this;
}
Calculatrice::Nombre& Calculatrice::Reel::division(const Nombre& nb){

    return *this;
}

QString Calculatrice::Reel::toString() const{
    QString str;
    str.setNum(_x);
    return str;
}

//Implementation des méthodes vituelles pures de la class "Expression"
void Calculatrice::Reel::EVAL(){}
