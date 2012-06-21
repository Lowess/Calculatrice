#include "Exp.h"

using namespace LO21;
using namespace std;

//Methodes de concatenation utiliser le toString de Expression on mettant dans une ref de ce type
LO21::Constante& LO21::Exp::addition(const Constante& nb) const{
    Exp* concat=new Exp(nb.toString()+ " " + _exp + " +");
    Constante& ref=*concat;
    return ref;
}
LO21::Constante& LO21::Exp::soustraction(const Constante& nb) const{
    Exp* concat=new Exp(nb.toString()+ " " + _exp + " -");
    Constante& ref=*concat;
    return ref;
}

LO21::Constante& LO21::Exp::multiplication(const Constante& nb) const{
    Exp* concat=new Exp(nb.toString()+ " " + _exp + " *");
    Constante& ref=*concat;
    return ref;
}

LO21::Constante& LO21::Exp::division(const Constante& nb) const{
    Exp* concat=new Exp(nb.toString()+ " " + _exp + " /");
    Constante& ref=*concat;
    return ref;
}

void LO21::Exp::EVAL(){
    Fabrique::getInstance().creer(toString());
}

QString LO21::Exp::toString() const{
    return _exp;
}

LO21::Constante& LO21::Exp::hookOperation(){}

LO21::Exp* LO21::Exp::clone() const{ return new Exp(*this); }
