#include "Complexe.h"
#include "Reel.h"
#include "Entier.h"
#include "Rationnel.h"

//Implementation des m√©thodes de la class "Complexe"

using namespace Calculatrice;

//surcharger Complexe constructeur avec deux pointeurs NB

Calculatrice::Complexe::Complexe(const Calculatrice::Nombre* a,const Calculatrice::Nombre* b){
    if(a == 0 || b == 0)
        throw CalculatriceException(typeid(this).name(), OTHER, "Creation de complexe impossible : pas de nombre pour instancier");
    _a = a;
    _b = b;
}


Calculatrice::Complexe::Complexe(const Calculatrice::Constante& a,const Calculatrice::Constante& b){
    const Nombre* tmpA = dynamic_cast<const Nombre*>(&a);
    const Nombre* tmpB = dynamic_cast<const Nombre*>(&b);
    if(tmpA == 0 || tmpB == 0)
        throw CalculatriceException(typeid(this).name(), OTHER, "Creation de complexe impossible : pas de nombre pour instancier");
    _a = tmpA;
    _b = tmpB;
}

Calculatrice::Constante& Calculatrice::Complexe::module() const{
    Constante& tmp = _a->SQR()+_b->SQR();
    Reel* res = dynamic_cast<Reel*>(&tmp);
    res->SQRT();
    Constante& ref = *res;
    return(ref);
}

//a+c,b+d
Calculatrice::Constante& Calculatrice::Complexe::addition(const Calculatrice::Constante& c) const {
    const Complexe* tmp = dynamic_cast<const Complexe*>(&c);
    if(tmp == 0) {
        const Entier* tmp_e = dynamic_cast<const Entier*>(&c);
        if (tmp_e == 0) {
            const Reel* tmp_re = dynamic_cast<const Reel*>(&c);
            if (tmp_re == 0) {
                const Rationnel* tmp_ra = dynamic_cast<const Rationnel*>(&c);
                if (tmp_ra == 0)
                    throw CalculatriceException(typeid(this).name(), OTHER, "Complexe::Addition : impossible de cast Constante en Rationnel");
                Complexe& tmp = tmp_ra->toComplexe();
                Complexe* res = new Complexe( _a->addition(*tmp._a) , _b->addition(*tmp._b));
                Constante& ref = *res;
                return(ref);
            }
            else {
            Complexe& tmp = tmp_re->toComplexe();
            Complexe* res = new Complexe( _a->addition(*tmp._a) , _b->addition(*tmp._b));
            Constante& ref = *res;
            return(ref);
            }
        }
        else {
            Complexe& tmp = tmp_e->toComplexe();
            Complexe* res = new Complexe( _a->addition(*tmp._a) , _b->addition(*tmp._b));
            Constante& ref = *res;
            return(ref);
        }
    }
    else {
        Complexe* res = new Complexe( _a->addition(*tmp->_a) , _b->addition(*tmp->_b));
        Constante& ref = *res;
        return(ref);
    }
}

//a-c,b-d
Calculatrice::Constante& Calculatrice::Complexe::soustraction(const Calculatrice::Constante& c) const {
    const Complexe* tmp = dynamic_cast<const Complexe*>(&c);
    if(tmp == 0) {
        const Entier* tmp_e = dynamic_cast<const Entier*>(&c);
        if (tmp_e == 0) {
            const Reel* tmp_re = dynamic_cast<const Reel*>(&c);
            if (tmp_re == 0) {
                const Rationnel* tmp_ra = dynamic_cast<const Rationnel*>(&c);
                if (tmp_ra == 0)
                    throw CalculatriceException(typeid(this).name(), OTHER, "Complexe::soustraction : impossible de cast Constante en Rationnel");
                Complexe& tmp = tmp_ra->toComplexe();
                Complexe* res = new Complexe( _a->soustraction(*tmp._a) , _b->soustraction(*tmp._b));
                Constante& ref = *res;
                return(ref);
            }
            else {
            Complexe& tmp = tmp_re->toComplexe();
            Complexe* res = new Complexe( _a->soustraction(*tmp._a) , _b->soustraction(*tmp._b));
            Constante& ref = *res;
            return(ref);
            }
        }
        else {
            Complexe& tmp = tmp_e->toComplexe();
            Complexe* res = new Complexe( _a->soustraction(*tmp._a) , _b->soustraction(*tmp._b));
            Constante& ref = *res;
            return(ref);
        }
    }
    else {
        Complexe* res = new Complexe( _a->soustraction(*tmp->_a) , _b->soustraction(*tmp->_b));
        Constante& ref = *res;
        return(ref);
    }
}


//ac-bd,ad+bc
Calculatrice::Constante& Calculatrice::Complexe::multiplication(const Calculatrice::Constante& c) const {
    const Complexe* tmp = dynamic_cast<const Complexe*>(&c);
    if(tmp == 0) {
        const Entier* tmp_e = dynamic_cast<const Entier*>(&c);
        if (tmp_e == 0) {
            const Reel* tmp_re = dynamic_cast<const Reel*>(&c);
            if (tmp_re == 0) {
                const Rationnel* tmp_ra = dynamic_cast<const Rationnel*>(&c);
                if (tmp_ra == 0)
                    throw CalculatriceException(typeid(this).name(), OTHER, "Complexe::Addition : impossible de cast Constante en Rationnel");
                Complexe& tmp = tmp_ra->toComplexe();
                Complexe* res = new Complexe((_a->multiplication(*tmp._a))-(_b->multiplication(*tmp._b)),
                                             (_a->multiplication(*tmp._b))+(_b->multiplication(*tmp._a)));
                Constante& ref = *res;
                return(ref);
            }
            else {
                Complexe& tmp = tmp_re->toComplexe();
                Complexe* res = new Complexe((_a->multiplication(*tmp._a))-(_b->multiplication(*tmp._b)),
                                             (_a->multiplication(*tmp._b))+(_b->multiplication(*tmp._a)));
                Constante& ref = *res;
                return(ref);
                }
        }
        else {
            Complexe& tmp = tmp_e->toComplexe();
            Complexe* res = new Complexe((_a->multiplication(*tmp._a))-(_b->multiplication(*tmp._b)),
                                         (_a->multiplication(*tmp._b))+(_b->multiplication(*tmp._a)));
            Constante& ref = *res;
            return(ref);
            }
    }
    else {
        Complexe* res = new Complexe((_a->multiplication(*tmp->_a))-(_b->multiplication(*tmp->_b)),
                                     (_a->multiplication(*tmp->_b))+(_b->multiplication(*tmp->_a)));
        Constante& ref = *res;
        return(ref);
        }
}

//(ac+bd+i(bc-ad))/c≤+d≤
Calculatrice::Constante& Calculatrice::Complexe::division(const Calculatrice::Constante& c) const {
    const Complexe* tmp = dynamic_cast<const Complexe*>(&c);
    if(tmp == 0) {
        const Entier* tmp_e = dynamic_cast<const Entier*>(&c);
        if (tmp_e == 0) {
            const Reel* tmp_re = dynamic_cast<const Reel*>(&c);
            if (tmp_re == 0) {
                const Rationnel* tmp_ra = dynamic_cast<const Rationnel*>(&c);
                if (tmp_ra == 0)
                    throw CalculatriceException(typeid(this).name(), OTHER, "Complexe::Addition : impossible de cast Constante en Rationnel");
                Complexe& tmp = tmp_ra->toComplexe();
                if(tmp._a == 0 && tmp._b == 0)
                    throw CalculatriceException(typeid(this).name(), MATHS, "Complexe::Divison : essai de division par 0 (vous voulez vraiment dÈtruire l'univers?)!");
                Constante& aBis = ((_a->multiplication(*tmp._a)).addition(_b->multiplication(*tmp._b))).division((tmp._a->SQR()).addition(tmp._b->SQR()));
                Constante& bBis = ((_b->multiplication(*tmp._a)).addition(_a->multiplication(*tmp._b))).division((tmp._a->SQR()).addition(tmp._b->SQR()));
                Complexe* res = new Complexe(aBis, bBis);
                Constante& ref = *res;
                return(ref);
            }
            else {
                Complexe& tmp = tmp_re->toComplexe();
                if(tmp._a == 0 && tmp._b == 0)
                    throw CalculatriceException(typeid(this).name(), MATHS, "Complexe::Divison : essai de division par 0 (vous voulez vraiment dÈtruire l'univers?)!");
                Constante& aBis = ((_a->multiplication(*tmp._a)).addition(_b->multiplication(*tmp._b))).division((tmp._a->SQR()).addition(tmp._b->SQR()));
                Constante& bBis = ((_b->multiplication(*tmp._a)).addition(_a->multiplication(*tmp._b))).division((tmp._a->SQR()).addition(tmp._b->SQR()));
                Complexe* res = new Complexe(aBis, bBis);
                Constante& ref = *res;
                return(ref);
            }
        }
        else {
            Complexe& tmp = tmp_e->toComplexe();
            if(tmp._a == 0 && tmp._b == 0)
                throw CalculatriceException(typeid(this).name(), MATHS, "Complexe::Divison : essai de division par 0 (vous voulez vraiment dÈtruire l'univers?)!");
            Constante& aBis = ((_a->multiplication(*tmp._a)).addition(_b->multiplication(*tmp._b))).division((tmp._a->SQR()).addition(tmp._b->SQR()));
            Constante& bBis = ((_b->multiplication(*tmp._a)).addition(_a->multiplication(*tmp._b))).division((tmp._a->SQR()).addition(tmp._b->SQR()));
            Complexe* res = new Complexe(aBis, bBis);
            Constante& ref = *res;
            return(ref);
        }
    }
    else {
        if(tmp->_a == 0 && tmp->_b == 0)
            throw CalculatriceException(typeid(this).name(), MATHS, "Complexe::Divison : essai de division par 0 (vous voulez vraiment dÈtruire l'univers?)!");
        Constante& aBis = ((_a->multiplication(*tmp->_a)).addition(_b->multiplication(*tmp->_b))).division((tmp->_a->SQR()).addition(tmp->_b->SQR()));
        Constante& bBis = ((_b->multiplication(*tmp->_a)).addition(_a->multiplication(*tmp->_b))).division((tmp->_a->SQR()).addition(tmp->_b->SQR()));
        Complexe* res = new Complexe(aBis, bBis);
        Constante& ref = *res;
        return(ref);
    }
}

Calculatrice::Constante& Calculatrice::Complexe::SIGN() const {
    Complexe* res = new Complexe(_a->SIGN(),_b->SIGN());
    Constante& ref = *res;
    return (ref);
}

Calculatrice::Constante& Calculatrice::Complexe::CUBE() const {
    Constante& tmp = SQR();
    const Complexe* c = dynamic_cast<const Complexe*>(&tmp);
    if(c == 0)
        throw CalculatriceException(typeid(this).name(), OTHER, "Impossible de cast Constante* en Complexe* dans Complexe::CUBE()");
    Constante& ref = c->multiplication(*this);
    return (ref);
}

Calculatrice::Constante& Calculatrice::Complexe::SQR() const{}


Calculatrice::Constante& Calculatrice::Complexe::hookOperation(){}
