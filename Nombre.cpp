#include "Nombre.h"

#include "Entier.h"
#include "Reel.h"
#include "Rationnel.h"



QTextStream& operator<<(QTextStream& s, const Calculatrice::Nombre& n){
    n.afficher();
    return s;
}

//ImplÃ©mentation issu de la classe Pile

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

//MÃ©thodes de classes

Calculatrice::Nombre& Calculatrice::Nombre::SQR() const{
    return (*this) * (*this);
}

Calculatrice::Nombre& Calculatrice::Nombre::CUBE() const{
    return (*this) * SQR();
}

Calculatrice::Nombre& Calculatrice::Nombre::SIN() const{
    const Reel* reel=dynamic_cast<const Reel*>(&toReel());
    if(reel==0){ throw CalculatriceException(typeid(this).name(),OTHER,"Echec dynamic_cast");}
    Nombre& ref=*(new Reel(sin(reel->get_x())));
    return (ref);
}

Calculatrice::Nombre& Calculatrice::Nombre::COS() const{
    const Reel* reel=dynamic_cast<const Reel*>(&toReel());
    if(reel==0){ throw CalculatriceException(typeid(this).name(),OTHER,"Echec dynamic_cast");}
    Nombre& ref=*(new Reel(cos(reel->get_x())));
    return (ref);
}
Calculatrice::Nombre& Calculatrice::Nombre::TAN() const{
    const Reel* reel=dynamic_cast<const Reel*>(&toReel());
    if(reel==0){ throw CalculatriceException(typeid(this).name(),OTHER,"Echec dynamic_cast");}
    Nombre& ref=*(new Reel(tan(reel->get_x())));
    return (ref);
}
Calculatrice::Nombre& Calculatrice::Nombre::SINH() const{
    const Reel* reel=dynamic_cast<const Reel*>(&toReel());
    if(reel==0){ throw CalculatriceException(typeid(this).name(),OTHER,"Echec dynamic_cast");}
    Nombre& ref=*(new Reel(sinh(reel->get_x())));
    return (ref);
}
Calculatrice::Nombre& Calculatrice::Nombre::COSH() const{
    const Reel* reel=dynamic_cast<const Reel*>(&toReel());
    if(reel==0){ throw CalculatriceException(typeid(this).name(),OTHER,"Echec dynamic_cast");}
    Nombre& ref=*(new Reel(cosh(reel->get_x())));
    return (ref);
}
Calculatrice::Nombre& Calculatrice::Nombre::TANH() const{
    const Reel* reel=dynamic_cast<const Reel*>(&toReel());
    if(reel==0){ throw CalculatriceException(typeid(this).name(),OTHER,"Echec dynamic_cast");}
    Nombre& ref=*(new Reel(tanh(reel->get_x())));
    return (ref);
}
Calculatrice::Nombre& Calculatrice::Nombre::LN() const{
    const Reel* reel=dynamic_cast<const Reel*>(&toReel());
    if(reel==0){ throw CalculatriceException(typeid(this).name(),OTHER,"Echec dynamic_cast");}
    Nombre& ref=*(new Reel(log(reel->get_x())));
    return (ref);
}
Calculatrice::Nombre& Calculatrice::Nombre::LOG() const{
    const Reel* reel=dynamic_cast<const Reel*>(&toReel());
    if(reel==0){ throw CalculatriceException(typeid(this).name(),OTHER,"Echec dynamic_cast");}
    Nombre& ref=*(new Reel(log(reel->get_x())));
    return (ref);
}

Calculatrice::Nombre& Calculatrice::Nombre::INV() const{
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
                Nombre& ref=*res;
                return (ref);
            }
        }
        else{ //Si succÃ¨s on rÃ©alise INV Reel
            const Rationnel* res=dynamic_cast<const Rationnel *>(&tmp_re->toRationnel());

            Rationnel* res2= new Rationnel(res->get_d(), res->get_n()); // On inverse num et den pour rÃ©aliser le INV
            res2->simplifier();
            Nombre& ref=*res2;
            return (ref);
        }
    }
    else{ //Si succÃ¨s on rÃ©alise INV Entier
        Rationnel* res=new Rationnel(1,tmp_en->get_x());
        Nombre& ref=*res;
        return (ref);
    }
}

Calculatrice::Nombre& Calculatrice::Nombre::SQRT() const{}

Calculatrice::Nombre& Calculatrice::Nombre::POW() const{}




Calculatrice::Entier& Calculatrice::Nombre::toEntier() const{
    //On essaye le cast en Entier
    const Entier* tmp_en=dynamic_cast<const Entier*>(&*this);
    if(tmp_en==0){ //Si echec on essaye en Reel
        const Reel* tmp_re=dynamic_cast<const Reel*>(&*this);
        if(tmp_re==0){ //Si echec on essaye en Rationnel
            const Rationnel* tmp_ra=dynamic_cast<const Rationnel*>(&*this);
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
    const Entier* tmp_en=dynamic_cast<const Entier*>(&*this);
    if(tmp_en==0){ //Si echec on essaye en Reel
        const Reel* tmp_re=dynamic_cast<const Reel*>(&*this);
        if(tmp_re==0){ //Si echec on essaye en Rationnel
            const Rationnel* tmp_ra=dynamic_cast<const Rationnel*>(&*this);
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
    const Entier* tmp_en=dynamic_cast<const Entier*>(&*this);
    if(tmp_en==0){ //Si echec on essaye en Reel
        const Reel* tmp_re=dynamic_cast<const Reel*>(&*this);
        if(tmp_re==0){ //Si echec on essaye en Rationnel
            const Rationnel* tmp_ra=dynamic_cast<const Rationnel*>(&*this);
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

bool Calculatrice::Nombre::operator==(const Calculatrice::Nombre& nb){
    Calculatrice::Rationnel* a = &toRationnel();
    Calculatrice::Rationnel* b = &nb.toRationnel();
    return (a->get_n() == b->get_n()) && (a->get_d() == b->get_d());
}

bool Calculatrice::Nombre::operator==(int nb){
    Calculatrice::Rationnel* a = &toRationnel();
    Calculatrice::Rationnel* b = new Rationnel(nb,1);
    return (a->get_n() == b->get_n()) && (a->get_d() == b->get_d());
}
