#include "Nombre.h"

#include "Entier.h"
#include "Reel.h"
#include "Rationnel.h"

#define _USE_MATH_DEFINES
#include <math.h>

using namespace LO21;

//Implementation issu de la classe Constante

QTextStream& operator<<(QTextStream& s, const LO21::Nombre& n){
    n.afficher();
    return s;
}

//Implementation issu de la classe Pile
LO21::Nombre& LO21::Nombre::SIGN() const{
    //On essaye le cast en Entier
    const Entier* tmp_en=dynamic_cast<const Entier*>(&*this);
    if(tmp_en==0){ //Si echec on essaye en Reel
        const Reel* tmp_re=dynamic_cast<const Reel*>(&*this);
        if(tmp_re==0){ //Si echec on essaye en Rationnel
            const Rationnel* tmp_ra=dynamic_cast<const Rationnel*>(&*this);
            if(tmp_ra==0){ //Si echec erreur
                LogSystem::ecrireLog(LogMessage("Erreur classe nombre ",ERREUR));
                throw CalculatriceException(typeid(this).name(),OTHER,"Echec dynamic_cast");
            }
            else{ //Si succes on realise SIGN Rationnel
                const Entier* inv=dynamic_cast<const Entier*>(&tmp_ra->get_n().SIGN());
                Rationnel* res=new Rationnel(inv->get_x(),tmp_ra->get_d());
                Nombre& ref=*res;
                return (ref);
            }
        }
        else{ //Si succes on realise SIGN Reel
            Reel* res=new Reel(-tmp_re->get_x());
            Nombre& ref=*res;
            return (ref);
        }
    }
    else{ //Si succes on realise SIGN Entier
        Entier* res=new Entier(-tmp_en->get_x());
        Nombre& ref=*res;
        return (ref);
    }
}

LO21::Constante& LO21::Nombre::SIN() const{
    const Reel* reel=dynamic_cast<const Reel*>(&toReel());
    if(reel==0){
        LogSystem::ecrireLog(LogMessage("Erreur classe nombre ",ERREUR));
        throw CalculatriceException(typeid(this).name(),OTHER,"Echec dynamic_cast");
    }

    if(Option::getInstance().get_degre()) {// En degree
        Constante& ref=*(new Reel(sin( (M_PI * reel->get_x()) / 180)));
        return (ref);
    } else {
        Constante& ref=*(new Reel(sin(reel->get_x())));
        return (ref);
    }
}

LO21::Constante& LO21::Nombre::COS() const{
    const Reel* reel=dynamic_cast<const Reel*>(&toReel());
    if(reel==0){
        LogSystem::ecrireLog(LogMessage("Erreur classe nombre ",ERREUR));
        throw CalculatriceException(typeid(this).name(),OTHER,"Echec dynamic_cast");
    }

    if(Option::getInstance().get_degre()) {// En degree
        Constante& ref=*(new Reel(cos( (M_PI * reel->get_x()) / 180)));
        return (ref);
    } else {
        Constante& ref=*(new Reel(cos(reel->get_x())));
        return (ref);
    }
}
LO21::Constante& LO21::Nombre::TAN() const{
    const Reel* reel=dynamic_cast<const Reel*>(&toReel());
    if(reel==0){
        LogSystem::ecrireLog(LogMessage("Erreur classe nombre ",ERREUR));
        throw CalculatriceException(typeid(this).name(),OTHER,"Echec dynamic_cast");
    }

    if(Option::getInstance().get_degre()) {// En degree
        Constante& ref=*(new Reel(tan( (M_PI * reel->get_x()) / 180)));
        return (ref);
    } else {
        Constante& ref=*(new Reel(tan(reel->get_x())));
        return (ref);
    }
}
LO21::Constante& LO21::Nombre::SINH() const{
    const Reel* reel=dynamic_cast<const Reel*>(&toReel());
    if(reel==0){
        LogSystem::ecrireLog(LogMessage("Erreur classe nombre ",ERREUR));
        throw CalculatriceException(typeid(this).name(),OTHER,"Echec dynamic_cast");
    }

    if(Option::getInstance().get_degre()) {// En degree
        Constante& ref=*(new Reel(sinh( (M_PI * reel->get_x()) / 180)));
        return (ref);
    } else {
        Constante& ref=*(new Reel(sinh(reel->get_x())));
        return (ref);
    }
}
LO21::Constante& LO21::Nombre::COSH() const{
    const Reel* reel=dynamic_cast<const Reel*>(&toReel());
    if(reel==0){
        LogSystem::ecrireLog(LogMessage("Erreur classe nombre ",ERREUR));
        throw CalculatriceException(typeid(this).name(),OTHER,"Echec dynamic_cast");
    }

    if(Option::getInstance().get_degre()) {// En degree
        Constante& ref=*(new Reel(cosh( (M_PI * reel->get_x()) / 180)));
        return (ref);
    } else {
        Constante& ref=*(new Reel(cosh(reel->get_x())));
        return (ref);
    }
}
LO21::Constante& LO21::Nombre::TANH() const{
    const Reel* reel=dynamic_cast<const Reel*>(&toReel());
    if(reel==0){
        LogSystem::ecrireLog(LogMessage("Erreur classe nombre ",ERREUR));
        throw CalculatriceException(typeid(this).name(),OTHER,"Echec dynamic_cast");
    }

    if(Option::getInstance().get_degre()) {// En degree
        Constante& ref=*(new Reel(tanh( (M_PI * reel->get_x()) / 180)));
        return (ref);
    } else {
        Constante& ref=*(new Reel(tanh(reel->get_x())));
        return (ref);
    }
}
LO21::Constante& LO21::Nombre::LN() const{
    const Reel* reel=dynamic_cast<const Reel*>(&toReel());
    if(reel==0){
        LogSystem::ecrireLog(LogMessage("Erreur classe nombre ",ERREUR));
        throw CalculatriceException(typeid(this).name(),OTHER,"Echec dynamic_cast");
    }
    Constante& ref=*(new Reel(log(reel->get_x())));
    return (ref);
}
LO21::Constante& LO21::Nombre::LOG() const{
    const Reel* reel=dynamic_cast<const Reel*>(&toReel());
    if(reel==0){
        LogSystem::ecrireLog(LogMessage("Erreur classe nombre ",ERREUR));
        throw CalculatriceException(typeid(this).name(),OTHER,"Echec dynamic_cast");
    }
    Constante& ref=*(new Reel(log10(reel->get_x())));
    return (ref);
}

LO21::Constante& LO21::Nombre::INV() const{
    //On essaye le cast en Entier
    const Entier* tmp_en=dynamic_cast<const Entier*>(&*this);
    if(tmp_en==0){ //Si echec on essaye en Reel
        const Reel* tmp_re=dynamic_cast<const Reel*>(&*this);
        if(tmp_re==0){ //Si echec on essaye en Rationnel
            const Rationnel* tmp_ra=dynamic_cast<const Rationnel*>(&*this);
            if(tmp_ra==0){ //Si echec erreur
                LogSystem::ecrireLog(LogMessage("Erreur classe nombre ",ERREUR));
                throw CalculatriceException(typeid(this).name(),OTHER,"Echec dynamic_cast");
            }
            else{ //Si succes on realise INV Rationnel
                Rationnel* res=new Rationnel(tmp_ra->get_d(),tmp_ra->get_n());
                Constante& ref=*res;
                return (ref);
            }
        }
        else{ //Si succes on realise INV Reel
            const Rationnel* res=dynamic_cast<const Rationnel *>(&tmp_re->toRationnel());

            Rationnel* res2= new Rationnel(res->get_d(), res->get_n()); // On inverse num et den pour realiser le INV
            res2->simplifier();
            Constante& ref=*res2;
            return (ref);
        }
    }
    else{ //Si succes on realise INV Entier
        Rationnel* res=new Rationnel(1,tmp_en->get_x());
        Constante& ref=*res;
        return (ref);
    }
}

LO21::Constante& LO21::Nombre::SQRT() const{
    double nb=toReel().get_x();
    if(nb < 0){
        LogSystem::ecrireLog(LogMessage("Erreur classe nombre racine d'un nombre negative ",ERREUR));
        throw CalculatriceException(typeid(this).name(),OTHER,"Erreur classe nombre racine d'un nombre negative");
    }

    Constante* res = new Reel(sqrt(nb));
    Constante& ref = *res;
    return (ref);
}

LO21::Constante& LO21::Nombre::POW(const LO21::Nombre& power) const{
    double puis = power.toReel().get_x();

    const LO21::Entier* tmpE = dynamic_cast<const LO21::Entier*>(this);
    if (tmpE == 0){
        const LO21::Rationnel* tmpRa = dynamic_cast<const LO21::Rationnel*>(this);
        if(tmpRa == 0){
            const LO21::Reel* tmpRe = dynamic_cast<const LO21::Reel*>(this);
            if (tmpRe == 0){
                LogSystem::ecrireLog(LogMessage("Erreur classe nombre ",ERREUR));
                throw CalculatriceException(typeid(this).name(),OTHER,"Echec dynamic_cast");
            }
            else {
                //Reel
                Reel* res= new Reel(pow(tmpRe->get_x(),puis));
                Constante& ref = *res;
                return ref;
            }
            //Rationnels
            Rationnel* res= new Rationnel(pow(tmpRa->get_n().get_x(), puis),pow(tmpRa->get_d().get_x(), puis));
            Constante& ref = *res;
            return ref;
        }
    }
    else{
        //Entiers
        Entier* res= new Entier(pow(tmpE->get_x(),puis));
        Constante& ref = *res;
        return ref;
    }
}

LO21::Constante& LO21::Nombre::hookOperation(){
    switch (Option::getInstance().get_typeDiv()){
        case MENU_ENTIER:{
            Constante& ref=this->toEntier();
            LogSystem::ecrireLog(LogMessage("Conversion d'une constante en Entier: " + this->toString() + " --> " + ref.toString()));
            return (ref);
            break;
        }
        case MENU_REEL:{
            Constante& ref=this->toReel();
            LogSystem::ecrireLog(LogMessage("Conversion d'une constante en Reel: " + this->toString() + " --> " + ref.toString()));
            return (ref);
            break;
        }
        case MENU_RATIONNEL:{
            Constante& ref=this->toRationnel();
            LogSystem::ecrireLog(LogMessage("Conversion d'une constante en Rationnel: " + this->toString() + " --> " + ref.toString()));
            return (ref);
            break;
        }
        default:
            LogSystem::ecrireLog(LogMessage("Option de constante inexistante",ERREUR));
            throw CalculatriceException(typeid(this).name(),OPTION,"Option de constante inexistante");
    }
}


LO21::Entier& LO21::Nombre::toEntier() const{
    //On essaye le cast en Entier
    const Entier* tmp_en=dynamic_cast<const Entier*>(this);
    if(tmp_en==0){ //Si echec on essaye en Reel
        const Reel* tmp_re=dynamic_cast<const Reel*>(this);
        if(tmp_re==0){ //Si echec on essaye en Rationnel
            const Rationnel* tmp_ra=dynamic_cast<const Rationnel*>(this);
            if(tmp_ra==0){ //Si echec erreur
                LogSystem::ecrireLog(LogMessage("Erreur classe nombre ",ERREUR));
                throw CalculatriceException(typeid(this).name(),OTHER,"Echec dynamic_cast");
            }
            else{ //Si succes on realise la conversion rationnel en entier
                return (tmp_ra->toEntier());
            }
        }
        else{ //Si succes on realise la conversion reel en entier
            return (tmp_re->toEntier());
        }
    }
}

LO21::Reel& LO21::Nombre::toReel() const{
    //On essaye le cast en Entier
    const Entier* tmp_en=dynamic_cast<const Entier*>(this);
    if(tmp_en==0){ //Si echec on essaye en Reel
        const Reel* tmp_re=dynamic_cast<const Reel*>(this);
        if(tmp_re==0){ //Si echec on essaye en Rationnel
            const Rationnel* tmp_ra=dynamic_cast<const Rationnel*>(this);
            if(tmp_ra==0){ //Si echec erreur
                LogSystem::ecrireLog(LogMessage("Erreur classe nombre ",ERREUR));
                throw CalculatriceException(typeid(this).name(),OTHER,"Echec dynamic_cast");
            }
            else{ //Si succes on realise la conversion rationnel en reel
                return (tmp_ra->toReel());
            }
        }
    }
    else{ //Si succes on realise la conversion entier en reel
        return (tmp_en->toReel());
    }
}

LO21::Rationnel& LO21::Nombre::toRationnel() const{
    //On essaye le cast en Entier
    const Entier* tmp_en=dynamic_cast<const Entier*>(this);
    if(tmp_en==0){ //Si echec on essaye en Reel
        const Reel* tmp_re=dynamic_cast<const Reel*>(this);
        if(tmp_re==0){ //Si echec on essaye en Rationnel
            const Rationnel* tmp_ra=dynamic_cast<const Rationnel*>(this);
            if(tmp_ra==0){ //Si echec erreur
                LogSystem::ecrireLog(LogMessage("Erreur classe nombre ",ERREUR));
                throw CalculatriceException(typeid(this).name(),OTHER,"Echec dynamic_cast");
            }
        }
        else{ //Si succes on realise la conversion rationnel en entier
            return (tmp_re->toRationnel());
        }
    }
    else{ //Si succes on realise la conversion reel en entier
        return (tmp_en->toRationnel());
    }
}

bool LO21::Nombre::operator==(const LO21::Nombre& nb) const{
    LO21::Rationnel* a = &toRationnel();
    LO21::Rationnel* b = &nb.toRationnel();
    return (a->get_n().get_x() == b->get_n().get_x()) && (a->get_d().get_x() == b->get_d().get_x());
}

bool LO21::Nombre::operator==(int nb) const{
    LO21::Rationnel* a = &toRationnel();
    LO21::Rationnel* b = new Rationnel(nb,1);
    return (a->get_n().get_x() == b->get_n().get_x()) && (a->get_d().get_x() == b->get_d().get_x());
}
