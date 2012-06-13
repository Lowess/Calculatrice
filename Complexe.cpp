#include "Complexe.h"
#include "Reel.h"
#include "Entier.h"
#include "Rationnel.h"

//Implementation des m√©thodes de la class "Complexe"

using namespace LO21;

//surcharger Complexe constructeur avec deux pointeurs NB
/*
LO21::Complexe::Complexe(const LO21::Nombre* a,const LO21::Nombre* b){
    if(a == 0 || b == 0)
        throw CalculatriceException(typeid(this).name(), OTHER, "Creation de complexe impossible : pas de nombre pour instancier");
    _a = a;
    _b = b;
}
*/

LO21::Complexe::Complexe(const LO21::Constante& a,const LO21::Constante& b){
    const Nombre* tmpA = dynamic_cast<const Nombre*>(&a);
    const Nombre* tmpB = dynamic_cast<const Nombre*>(&b);
    if(tmpA == 0 || tmpB == 0)
        throw CalculatriceException(typeid(this).name(), OTHER, "Creation de complexe impossible : pas de nombre pour instancier");
    _a = tmpA;
    _b = tmpB;
}

LO21::Constante& LO21::Complexe::module() const{
    Constante& tmp = _a->SQR()+_b->SQR();
    Reel* res = dynamic_cast<Reel*>(&tmp);
    res->SQRT();
    Constante& ref = *res;
    return(ref);
}

//a+c,b+d
LO21::Constante& LO21::Complexe::addition(const LO21::Constante& c) const {
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
LO21::Constante& LO21::Complexe::soustraction(const LO21::Constante& c) const {
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
LO21::Constante& LO21::Complexe::multiplication(const LO21::Constante& c) const {
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
LO21::Constante& LO21::Complexe::division(const LO21::Constante& c) const {
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

LO21::Constante& LO21::Complexe::SIGN() const {
    Complexe* res = new Complexe(_a->SIGN(),_b->SIGN());
    Constante& ref = *res;
    return (ref);
}

LO21::Constante& LO21::Complexe::CUBE() const {
    Constante& tmp = SQR();
    const Complexe* c = dynamic_cast<const Complexe*>(&tmp);
    if(c == 0)
        throw CalculatriceException(typeid(this).name(), OTHER, "Impossible de cast Constante* en Complexe* dans Complexe::CUBE()");
    Constante& ref = c->multiplication(*this);
    return (ref);
}

LO21::Constante& LO21::Complexe::SQR() const{}


LO21::Constante& LO21::Complexe::hookOperation(){}


LO21::Complexe* LO21::Complexe::clone() const{ return new Complexe(*this); }
