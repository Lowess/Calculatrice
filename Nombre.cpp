#include "Nombre.h"

#include "Entier.h"
#include "Reel.h"
#include "Rationnel.h"



QTextStream& operator<<(QTextStream& s, const Calculatrice::Nombre& n){
    n.afficher();
    return s;
}

//Implémentation issu de la classe Constante
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
            else{ //Si succès on réalise SIGN Rationnel
                const Entier* inv=dynamic_cast<const Entier*>(&tmp_ra->get_n().SIGN());
                Rationnel* res=new Rationnel(inv->get_x(),tmp_ra->get_d());
                Nombre& ref=*res;
                return (ref);
            }
        }
        else{ //Si succès on réalise SIGN Reel
            Reel* res=new Reel(-tmp_re->get_x());
            Nombre& ref=*res;
            return (ref);
        }
    }
    else{ //Si succès on réalise SIGN Entier
        Entier* res=new Entier(-tmp_en->get_x());
        Nombre& ref=*res;
        return (ref);
    }
}

Calculatrice::Nombre& Calculatrice::Nombre::SQR() const{}
Calculatrice::Nombre& Calculatrice::Nombre::CUBE() const{}


//Méthodes de classes

Calculatrice::Nombre& Calculatrice::Nombre::SIN() const{}
Calculatrice::Nombre& Calculatrice::Nombre::COS() const{}
Calculatrice::Nombre& Calculatrice::Nombre::TAN() const{}
Calculatrice::Nombre& Calculatrice::Nombre::SINH() const{}
Calculatrice::Nombre& Calculatrice::Nombre::COSH() const{}
Calculatrice::Nombre& Calculatrice::Nombre::TANH() const{}
Calculatrice::Nombre& Calculatrice::Nombre::LN() const{}
Calculatrice::Nombre& Calculatrice::Nombre::LOG() const{}

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
            else{ //Si succès on réalise INV Rationnel
                Rationnel* res=new Rationnel(tmp_ra->get_d(),tmp_ra->get_n());
                Nombre& ref=*res;
                return (ref);
            }
        }
        else{ //Si succès on réalise INV Reel
            const Rationnel* res=dynamic_cast<const Rationnel *>(&tmp_re->toRationnel());

            Rationnel* res2= new Rationnel(res->get_d(), res->get_n()); // On inverse num et den pour réaliser le INV
            res2->simplifier();
            Nombre& ref=*res2;
            return (ref);
        }
    }
    else{ //Si succès on réalise INV Entier
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
            else{ //Si succès on réalise la conversion rationnel en entier
                return (tmp_ra->toEntier());
            }
        }
        else{ //Si succès on réalise la conversion reel en entier
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
            else{ //Si succès on réalise la conversion rationnel en reel
                return (tmp_ra->toReel());
            }
        }
    }
    else{ //Si succès on réalise la conversion entier en reel
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
        else{ //Si succès on réalise la conversion rationnel en entier
            return (tmp_re->toRationnel());
        }
    }
    else{ //Si succès on réalise la conversion reel en entier
        return (tmp_en->toRationnel());
    }
}

