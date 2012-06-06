#include "Complexe.h"
#include "Reel.h"
/*
//Implementation des méthodes de la class "Complexe"

using namespace Calculatrice;

void Calculatrice::Complexe::conjugue(){
    this->_b->SIGN();
}

Constante& Calculatrice::Complexe::module() const{
    Nombre* tmp =&(this->_a->SQR() + this->_b->SQR());
    Reel* res = dynamic_cast<Reel*>(tmp);
    //Reel* res = new Reel();
    res->SQRT();
    Constante& ref = *res;
    return(ref);
}

//a+c,b+d
Constante& Calculatrice::Complexe::addition(const Complexe& c) const {
    Complexe* res = new Complexe( _a + c._a , _b + c._b);
    Constante& ref = *res;
    return(ref);
}

//a-c,b-d
Constante& Calculatrice::Complexe::soustraction(const Complexe& c) const {
    Complexe* res = new Complexe( _a - c._a , _b - c._b);
    Constante& ref = *res;
    return(ref);
}


//ac-bd,ad+bc
Constante& Calculatrice::Complexe::multiplication(const Complexe& c) const {
    Complexe* res = new Complexe( (_a->multiplication(c._a)).soustraction(_b->multiplication(c._b))
            ,
            (_a->multiplication(c._b)).addition(_b->multiplication(c._a)));
    Constante& ref = *res;
    return(ref);
}

//(a/c)-(b/d),(a/d)+(b/d)
Constante& Calculatrice::Complexe::division(const Complexe& c) const {
    Complexe* res = new Complexe( (_a->division(c._a)).soustraction(_b->division(c._b))
                                  ,
                                  (_a->division(c._b)).soustraction(_b->division(c._a)));
    Constante& ref = *res;
    return(ref);
}
*/
