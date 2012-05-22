#include "Rationnel.h"

//Implementation des méthodes vituelles pures de la class "Nombre"

void Calculatrice::Rationnel::SIN(){}
void Calculatrice::Rationnel::COS(){}
void Calculatrice::Rationnel::TAN(){}
void Calculatrice::Rationnel::SINH(){}
void Calculatrice::Rationnel::COSH(){}
void Calculatrice::Rationnel::TANH(){}
void Calculatrice::Rationnel::LN(){}
void Calculatrice::Rationnel::LOG(){}
void Calculatrice::Rationnel::INV(){}
void Calculatrice::Rationnel::SQRT(){}
void Calculatrice::Rationnel::POW(){}


Calculatrice::Nombre& Calculatrice::Rationnel::addition(const Nombre& nb){

    return *this;
}

Calculatrice::Nombre& Calculatrice::Rationnel::soustraction(const Nombre& nb){

    return *this;
}
Calculatrice::Nombre& Calculatrice::Rationnel::multiplication(const Nombre& nb){

    return *this;
}
Calculatrice::Nombre& Calculatrice::Rationnel::division(const Nombre& nb){

    return *this;
}

QString Calculatrice::Rationnel::toString() const{
    QString str1,str2;
    str1.setNum(_n.get_x());
    str2.setNum(_d.get_x());
    return QString(str1+"/"+str2);
}

//Implementation des méthodes vituelles pures de la class "Expression"
void Calculatrice::Rationnel::EVAL(){}
