#include "Exp.h"

using namespace Calculatrice;
using namespace std;

//Méthodes de concaténation utiliser le toString de Expression on mettant dans une ref de ce type
Calculatrice::Constante& Calculatrice::Exp::addition(const Constante& nb) const{
    Exp* concat=new Exp(_exp + " " + nb.toString()+ " +");
    Constante& ref=*concat;
    return ref;
}
Calculatrice::Constante& Calculatrice::Exp::soustraction(const Constante& nb) const{
    Exp* concat=new Exp(_exp + " " + nb.toString()+ " -");
    Constante& ref=*concat;
    return ref;
}

Calculatrice::Constante& Calculatrice::Exp::multiplication(const Constante& nb) const{
    Exp* concat=new Exp(_exp + " " + nb.toString()+ " *");
    Constante& ref=*concat;
    return ref;
}

Calculatrice::Constante& Calculatrice::Exp::division(const Constante& nb) const{
    Exp* concat=new Exp(_exp + " " + nb.toString()+ " /");
    Constante& ref=*concat;
    return ref;
}

void Calculatrice::Exp::EVAL(){}

QString Calculatrice::Exp::toString() const{
    QString str=_exp;
    str.replace(QString("'"), QString(""));
    return str;
}
