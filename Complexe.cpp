#include "Complexe.h"
#include "Reel.h"

//Implementation des m√©thodes de la class "Complexe"

using namespace Calculatrice;

void Calculatrice::Complexe::conjugue(){
    _b.SIGN();
}

Calculatrice::Constante& Calculatrice::Complexe::module() const{
    Nombre& tmp = _a.SQR()+_b.SQR();
    Reel* res = dynamic_cast<Reel*>(&tmp);
    //Reel* res = new Reel();
    res->SQRT();
    Constante& ref = *res;
    return(ref);
}

//a+c,b+d
Calculatrice::Constante& Calculatrice::Complexe::addition(const Calculatrice::Constante& c) const {
    const Complexe* tmp_c = dynamic_cast<const Complexe*>(&c);
    if(tmp_c == 0)
        //throw erreur OTHER
        std::cout << "Erreur" << std::endl;
    Complexe* res = new Complexe( _a + tmp_c->_a , _b + tmp_c->_b);
    Constante& ref = *res;
    return(ref);
}

//a-c,b-d
Calculatrice::Constante& Calculatrice::Complexe::soustraction(const Calculatrice::Constante& c) const {
    const Complexe* tmp_c = dynamic_cast<const Complexe*>(&c);
    if(tmp_c == 0)
        //throw erreur OTHER
        std::cout << "Erreur" << std::endl;
    Complexe* res = new Complexe( _a - tmp_c->_a , _b - tmp_c->_b);
    Constante& ref = *res;
    return(ref);
}


//ac-bd,ad+bc
Calculatrice::Constante& Calculatrice::Complexe::multiplication(const Calculatrice::Constante& c) const {
    const Complexe* tmp_c = dynamic_cast<const Complexe*>(&c);
    if(tmp_c == 0)
        //throw erreur OTHER
        std::cout << "Erreur" << std::endl;
    Complexe* res = new Complexe((_a*tmp_c->_a)-(_b*tmp_c->_b),
            (_a*tmp_c->_b)+(_b*tmp_c->_a));
    Constante& ref = *res;
    return(ref);
}

//(ac+bd+i(bc-ad))/c≤+d≤
Calculatrice::Constante& Calculatrice::Complexe::division(const Calculatrice::Constante& c) const {
    const Complexe* tmp_c = dynamic_cast<const Complexe*>(&c);
    if(tmp_c == 0)
        //throw erreur OTHER
        std::cout << "Erreur" << std::endl;
    if(tmp_c->_a == 0 && tmp_c->_b == 0)
        //throw erreur MATHS
        std::cout << "Erreur" << std::endl;
    Nombre& aBis = ( (_a*tmp_c->_a) + (_b*tmp_c->_b) ) / ( (tmp_c->_a*tmp_c->_a) + (tmp_c->_b*tmp_c->_b) );
    Nombre& bBis = ( (_b*tmp_c->_a) + (_a*tmp_c->_b) ) / ( (tmp_c->_a*tmp_c->_a) + (tmp_c->_b*tmp_c->_b) );
    Complexe* res = new Complexe(aBis, bBis);
    Constante& ref = *res;
    return(ref);
}

Calculatrice::Constante& Calculatrice::Complexe::SIGN() const {
    Complexe* res = new Complexe(_a.SIGN(),_b.SIGN());
    Constante& ref = *res;
    return (ref);
}

Calculatrice::Constante& Calculatrice::Complexe::SQR() const {
    Constante& ref = (*this).multiplication(*this);
    return (ref);
}

Calculatrice::Constante& Calculatrice::Complexe::CUBE() const {
    Constante& tmp = SQR();
    const Complexe* c = dynamic_cast<const Complexe*>(&tmp);
    if(c == 0)
        //throw erreur
        std::cout << "Erreur" << std::endl;
    Constante& ref = *c.multiplication(*this);
    return (ref);
}
