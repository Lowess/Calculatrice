#include "Nombre.h"

#include "Entier.h"
#include "Reel.h"
#include "Rationnel.h"


//Implémentation issu de la classe Constante

QTextStream& operator<<(QTextStream& s, const Calculatrice::Nombre& n){
    n.afficher();
    return s;
}

//Implémentation issu de la classe Pile
Calculatrice::Nombre& Calculatrice::Nombre::SIGN() const{
    //On essaye le cast en Entier
    const Entier* tmp_en=dynamic_cast<const Entier*>(&*this);
    if(tmp_en==0){ //Si echec on essaye en Reel
        const Reel* tmp_re=dynamic_cast<const Reel*>(&*this);
        if(tmp_re==0){ //Si echec on essaye en Rationnel
            const Rationnel* tmp_ra=dynamic_cast<const Rationnel*>(&*this);
            if(tmp_ra==0){ //Si echec erreur
                throw CalculatriceException(typeid(this).name(),OTHER,"Echec dynamic_cast");
            }
            else{ //Si succÃ¨s on rÃ©alise SIGN Rationnel
                const Entier* inv=dynamic_cast<const Entier*>(&tmp_ra->get_n().SIGN());
                Rationnel* res=new Rationnel(inv->get_x(),tmp_ra->get_d());
                Nombre& ref=*res;
                return (ref);
            }
        }
        else{ //Si succÃ¨s on rÃ©alise SIGN Reel
            Reel* res=new Reel(-tmp_re->get_x());
            Nombre& ref=*res;
            return (ref);
        }
    }
    else{ //Si succÃ¨s on rÃ©alise SIGN Entier
        Entier* res=new Entier(-tmp_en->get_x());
        Nombre& ref=*res;
        return (ref);
    }
}

Calculatrice::Constante& Calculatrice::Nombre::SIN() const{
    const Reel* reel=dynamic_cast<const Reel*>(&toReel());
    if(reel==0){ throw CalculatriceException(typeid(this).name(),OTHER,"Echec dynamic_cast");}
    Constante& ref=*(new Reel(sin(reel->get_x())));
    return (ref);
}

Calculatrice::Constante& Calculatrice::Nombre::COS() const{
    const Reel* reel=dynamic_cast<const Reel*>(&toReel());
    if(reel==0){ throw CalculatriceException(typeid(this).name(),OTHER,"Echec dynamic_cast");}
    Constante& ref=*(new Reel(cos(reel->get_x())));
    return (ref);
}
Calculatrice::Constante& Calculatrice::Nombre::TAN() const{
    const Reel* reel=dynamic_cast<const Reel*>(&toReel());
    if(reel==0){ throw CalculatriceException(typeid(this).name(),OTHER,"Echec dynamic_cast");}
    Constante& ref=*(new Reel(tan(reel->get_x())));
    return (ref);
}
Calculatrice::Constante& Calculatrice::Nombre::SINH() const{
    const Reel* reel=dynamic_cast<const Reel*>(&toReel());
    if(reel==0){ throw CalculatriceException(typeid(this).name(),OTHER,"Echec dynamic_cast");}
    Constante& ref=*(new Reel(sinh(reel->get_x())));
    return (ref);
}
Calculatrice::Constante& Calculatrice::Nombre::COSH() const{
    const Reel* reel=dynamic_cast<const Reel*>(&toReel());
    if(reel==0){ throw CalculatriceException(typeid(this).name(),OTHER,"Echec dynamic_cast");}
    Constante& ref=*(new Reel(cosh(reel->get_x())));
    return (ref);
}
Calculatrice::Constante& Calculatrice::Nombre::TANH() const{
    const Reel* reel=dynamic_cast<const Reel*>(&toReel());
    if(reel==0){ throw CalculatriceException(typeid(this).name(),OTHER,"Echec dynamic_cast");}
    Constante& ref=*(new Reel(tanh(reel->get_x())));
    return (ref);
}
Calculatrice::Constante& Calculatrice::Nombre::LN() const{
    const Reel* reel=dynamic_cast<const Reel*>(&toReel());
    if(reel==0){ throw CalculatriceException(typeid(this).name(),OTHER,"Echec dynamic_cast");}
    Constante& ref=*(new Reel(log(reel->get_x())));
    return (ref);
}
Calculatrice::Constante& Calculatrice::Nombre::LOG() const{
    const Reel* reel=dynamic_cast<const Reel*>(&toReel());
    if(reel==0){ throw CalculatriceException(typeid(this).name(),OTHER,"Echec dynamic_cast");}
    Constante& ref=*(new Reel(log(reel->get_x())));
    return (ref);
}

Calculatrice::Constante& Calculatrice::Nombre::INV() const{
    //On essaye le cast en Entier
    const Entier* tmp_en=dynamic_cast<const Entier*>(&*this);
    if(tmp_en==0){ //Si echec on essaye en Reel
        const Reel* tmp_re=dynamic_cast<const Reel*>(&*this);
        if(tmp_re==0){ //Si echec on essaye en Rationnel
            const Rationnel* tmp_ra=dynamic_cast<const Rationnel*>(&*this);
            if(tmp_ra==0){ //Si echec erreur
                throw CalculatriceException(typeid(this).name(),OTHER,"Echec dynamic_cast");
            }
            else{ //Si succÃ¨s on rÃ©alise INV Rationnel
                Rationnel* res=new Rationnel(tmp_ra->get_d(),tmp_ra->get_n());
                Constante& ref=*res;
                return (ref);
            }
        }
        else{ //Si succÃ¨s on rÃ©alise INV Reel
            const Rationnel* res=dynamic_cast<const Rationnel *>(&tmp_re->toRationnel());

            Rationnel* res2= new Rationnel(res->get_d(), res->get_n()); // On inverse num et den pour rÃ©aliser le INV
            res2->simplifier();
            Constante& ref=*res2;
            return (ref);
        }
    }
    else{ //Si succÃ¨s on rÃ©alise INV Entier
        Rationnel* res=new Rationnel(1,tmp_en->get_x());
        Constante& ref=*res;
        return (ref);
    }
}

Calculatrice::Constante& Calculatrice::Nombre::SQRT() const{
    Constante* res = new Entier(3);
    Constante& ref = *res;
    return (ref);
}

Calculatrice::Constante& Calculatrice::Nombre::POW(const Calculatrice::Nombre& power) const{
    int puis = power.toEntier().get_x();
    const Calculatrice::Entier* tmpE = dynamic_cast<const Calculatrice::Entier*>(this);
    if (tmpE == 0)
        throw Calculatrice::CalculatriceException(typeid(this).name(), OTHER, "Nombre::POW : pas possible de cast en entier");
    else {
        const Calculatrice::Rationnel* tmpRa = dynamic_cast<const Calculatrice::Rationnel*>(this);
        if (tmpRa == 0)
            throw Calculatrice::CalculatriceException(typeid(this).name(), OTHER, "Nombre::POW : pas possible de cast en rationnel");
        else {
            const Calculatrice::Reel* tmpRe = dynamic_cast<const Calculatrice::Reel*>(this);
            if (tmpRe == 0)
                throw Calculatrice::CalculatriceException(typeid(this).name(), OTHER, "Nombre::POW : pas possible de cast en reel");
            else {
                Constante* res = new Reel(tmpRe->get_x());
                for(int i = 0; i < puis-1 ; ++i) {
                   res = &res->multiplication(*tmpRe);
                }
                Constante& ref = *res;
                return ref;
            }
        }
        Constante* res = new Rationnel(tmpRa->get_n(),tmpRa->get_d());
        for(int i = 0; i < puis-1 ; ++i) {
           res = &res->multiplication(*tmpRa);
        }
        Constante& ref = *res;
        return ref;
    }
    Constante* res = new Entier(tmpE->get_x());
    for(int i = 0; i < puis-1 ; ++i) {
       res = &res->multiplication(*tmpE);
    }
    Constante& ref = *res;
    return ref;
}


Calculatrice::Entier& Calculatrice::Nombre::toEntier() const{
    //On essaye le cast en Entier
    const Entier* tmp_en=dynamic_cast<const Entier*>(this);
    if(tmp_en==0){ //Si echec on essaye en Reel
        const Reel* tmp_re=dynamic_cast<const Reel*>(this);
        if(tmp_re==0){ //Si echec on essaye en Rationnel
            const Rationnel* tmp_ra=dynamic_cast<const Rationnel*>(this);
            if(tmp_ra==0){ //Si echec erreur
                throw CalculatriceException(typeid(this).name(),OTHER,"Echec dynamic_cast");
            }
            else{ //Si succÃ¨s on rÃ©alise la conversion rationnel en entier
                return (tmp_ra->toEntier());
            }
        }
        else{ //Si succÃ¨s on rÃ©alise la conversion reel en entier
            return (tmp_re->toEntier());
        }
    }
}

Calculatrice::Reel& Calculatrice::Nombre::toReel() const{
    //On essaye le cast en Entier
    const Entier* tmp_en=dynamic_cast<const Entier*>(this);
    if(tmp_en==0){ //Si echec on essaye en Reel
        const Reel* tmp_re=dynamic_cast<const Reel*>(this);
        if(tmp_re==0){ //Si echec on essaye en Rationnel
            const Rationnel* tmp_ra=dynamic_cast<const Rationnel*>(this);
            if(tmp_ra==0){ //Si echec erreur
                throw CalculatriceException(typeid(this).name(),OTHER,"Echec dynamic_cast");
            }
            else{ //Si succÃ¨s on rÃ©alise la conversion rationnel en reel
                return (tmp_ra->toReel());
            }
        }
    }
    else{ //Si succÃ¨s on rÃ©alise la conversion entier en reel
        return (tmp_en->toReel());
    }
}

Calculatrice::Rationnel& Calculatrice::Nombre::toRationnel() const{
    //On essaye le cast en Entier
    const Entier* tmp_en=dynamic_cast<const Entier*>(this);
    if(tmp_en==0){ //Si echec on essaye en Reel
        const Reel* tmp_re=dynamic_cast<const Reel*>(this);
        if(tmp_re==0){ //Si echec on essaye en Rationnel
            const Rationnel* tmp_ra=dynamic_cast<const Rationnel*>(this);
            if(tmp_ra==0){ //Si echec erreur
                throw CalculatriceException(typeid(this).name(),OTHER,"Echec dynamic_cast");
            }
        }
        else{ //Si succÃ¨s on rÃ©alise la conversion rationnel en entier
            return (tmp_re->toRationnel());
        }
    }
    else{ //Si succÃ¨s on rÃ©alise la conversion reel en entier
        return (tmp_en->toRationnel());
    }
}

bool Calculatrice::Nombre::operator==(const Calculatrice::Nombre& nb) const{
    Calculatrice::Rationnel* a = &toRationnel();
    Calculatrice::Rationnel* b = &nb.toRationnel();
    return (a->get_n().get_x() == b->get_n().get_x()) && (a->get_d().get_x() == b->get_d().get_x());
}

bool Calculatrice::Nombre::operator==(int nb) const{
    Calculatrice::Rationnel* a = &toRationnel();
    Calculatrice::Rationnel* b = new Rationnel(nb,1);
    return (a->get_n().get_x() == b->get_n().get_x()) && (a->get_d().get_x() == b->get_d().get_x());
}
