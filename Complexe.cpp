#include "Complexe.h"

//Implementation des mÃ©thodes de la class "Complexe"

using namespace Calculatrice;

void Complexe::conjugue(){
    this->_b.SIGN();
}

Constante& Complexe::module() const{
    Nombre* res = new Nombre(this->_a.SQR() + this->_b.SQR());
    res.SQRT();
    Constante& ref = *res;
    return(ref);
}

//a+c,b+d
Constante& Complexe::addition(const Complexe& c) const {
    Complexe* res = new Complexe( _a + c->_a , _b + c->_b);
    Constante& ref = *res;
    return(ref);
}

//a-c,b-d
Constante& Complexe::soustraction(const Complexe& c) const {
    Complexe* res = new Complexe( _a - c->_a , _b - c->_b);
    Constante& ref = *res;
    return(ref);
}


//ac-bd,ad+bc
Constante& Complexe::multiplication(const Complexe& c) const {
    Complexe* res = new Complexe( (_a->multiplication(c->_a)).soustraction(_b->multiplication(c->_b))
            ,
            (_a->multiplication(c->_b)).addition(_b->multiplication(c->_a)));
    Constante& ref = *res;
    return(ref);
}

//(a/c)-(b/d),(a/d)+(b/d)
Constante& Complexe::division(const Complexe& c) const {
    Complexe* res = new Complexe( (_a->division(c->_a)).soustraction(_b->division(c->_b))
                                  ,
                                  (_a->division(c->_b)).soustraction(_b->division(c->_a)));
    Constante& ref = *res;
    return(ref);
}
