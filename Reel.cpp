#include "Entier.h"
#include "Reel.h"
#include "Rationnel.h"
#include "Complexe.h"
#include "Exp.h"

using namespace LO21;

//Réalise l'addition d'un Reel avec un Constante (Entier, Reel, Rationnel)
LO21::Constante& LO21::Reel::addition(const Constante& nb) const{
    //On essaye le cast en Reel
    const Entier* tmp_en=dynamic_cast<const Entier*>(&nb);
    if(tmp_en==0){ //Si echec on essaye en Reel
        const Reel* tmp_re=dynamic_cast<const Reel*>(&nb);
        if(tmp_re==0){ //Si echec on essaye en Rationnel
            const Rationnel* tmp_ra=dynamic_cast<const Rationnel*>(&nb);
            if(tmp_ra==0){
                const Complexe* tmp_c = dynamic_cast<const Complexe*>(&nb);
                if(tmp_c == 0){
                    const Exp* tmp_exp = dynamic_cast<const Exp*>(&nb);
                    if(tmp_exp == 0){
                        LogSystem::ecrireLog(LogMessage("Erreur classe reel ",ERREUR));
                        throw CalculatriceException(typeid(this).name(),OTHER,"Echec dynamic_cast");
                    }
                    else{
                        Constante* res=new Exp(toString());
                        Constante& ref=res->addition(nb);
                        delete res;
                        return(ref);
                    }
                }
                else {
                    Constante& ref = tmp_c->addition(*this);
                    return (ref);
                }
            }
            else{ //Si succès on réalise l'addition Reel + Rationnel
                Constante& ref=toRationnel().addition(*tmp_ra);
                return (ref);
            }
        }
        else{ //Si succÃ¨s on rÃ©alise l'addition Reel + Reel
            Reel* res= new Reel(_x + tmp_re->get_x());
            Constante& ref=*res;
            return (ref);
        }
    }
    else{ //Si succès on réalise l'addition Reel + Entier
        Constante& ref=tmp_en->addition(*this);
        return (ref);
    }
}

//Réalise la soustraction d'un Reel avec un Constante (Entier, Reel, Rationnel)
LO21::Constante& LO21::Reel::soustraction(const Constante& nb) const{
    //On essaye le cast en Reel
    const Entier* tmp_en=dynamic_cast<const Entier*>(&nb);
    if(tmp_en==0){ //Si echec on essaye en Reel
        const Reel* tmp_re=dynamic_cast<const Reel*>(&nb);
        if(tmp_re==0){ //Si echec on essaye en Rationnel
            const Rationnel* tmp_ra=dynamic_cast<const Rationnel*>(&nb);
            if(tmp_ra==0){
                const Complexe* tmp_c = dynamic_cast<const Complexe*>(&nb);
                if(tmp_c == 0){
                    const Exp* tmp_exp = dynamic_cast<const Exp*>(&nb);
                    if(tmp_exp == 0){
                        LogSystem::ecrireLog(LogMessage("Erreur classe reel ",ERREUR));
                        throw CalculatriceException(typeid(this).name(),OTHER,"Echec dynamic_cast");
                    }
                    else{
                        Constante* res=new Exp(toString());
                        Constante& ref=res->soustraction(nb);
                        delete res;
                        return(ref);
                    }
                }
                else {
                    Constante& ref = tmp_c->soustraction(*this);
                    return (ref);
                }
            }
            else{ //Si succès on réalise la soustraction Reel - Rationnel
                Constante& ref=toRationnel().soustraction(*tmp_ra);
                return (ref);
            }
        }
        else{ //Si succÃ¨s on rÃ©alise la soustraction Reel - Reel
            Reel* res= new Reel(_x - tmp_re->get_x());
            Constante& ref=*res;
            return (ref);
        }
    }
    else{ //Si succès on réalise la soustraction Reel - Entier
        Constante& ref=tmp_en->soustraction(*this).SIGN(); //Inversion de signe car appel �  Entier - Reel
        return (ref);
    }
}

//Réalise la multiplication d'un Reel avec un Constante (Entier, Reel, Rationnel)
LO21::Constante& LO21::Reel::multiplication(const Constante& nb) const{
    //On essaye le cast en Reel
    const Entier* tmp_en=dynamic_cast<const Entier*>(&nb);
    if(tmp_en==0){ //Si echec on essaye en Reel
        const Reel* tmp_re=dynamic_cast<const Reel*>(&nb);
        if(tmp_re==0){ //Si echec on essaye en Rationnel
            const Rationnel* tmp_ra=dynamic_cast<const Rationnel*>(&nb);
            if(tmp_ra==0){
                const Complexe* tmp_c = dynamic_cast<const Complexe*>(&nb);
                if(tmp_c == 0){
                    const Exp* tmp_exp = dynamic_cast<const Exp*>(&nb);
                    if(tmp_exp == 0){
                        LogSystem::ecrireLog(LogMessage("Erreur classe reel ",ERREUR));
                        throw CalculatriceException(typeid(this).name(),OTHER,"Echec dynamic_cast");
                    }
                    else{
                        Constante* res=new Exp(toString());
                        Constante& ref=res->multiplication(nb);
                        delete res;
                        return(ref);
                    }
                }
                else {
                    Constante& ref = tmp_c->multiplication(*this);
                    return (ref);
                }
            }
            else{ //Si succÃ¨s on rÃ©alise la multiplication Reel * Rationnel
                Reel res(_x * tmp_ra->get_n().get_x());
                Constante& ref=res.toRationnel();
                return (ref);
            }
        }
        else{ //Si succÃ¨s on rÃ©alise la multiplication Reel * Reel
            Reel* res= new Reel(_x * tmp_re->get_x());
            Constante& ref=*res;
            return (ref);
        }
    }
    else{ //Si succès on réalise la multiplication Reel * Entier
        Constante& ref=tmp_en->multiplication(*this);
        return (ref);
    }
}

//Réalise la division d'un Reel par un Constante (Entier, Reel, Rationnel)
LO21::Constante& LO21::Reel::division(const Constante& nb) const{
    //On essaye le cast en Reel
    const Entier* tmp_en=dynamic_cast<const Entier*>(&nb);
    if(tmp_en==0){ //Si echec on essaye en Reel
        const Reel* tmp_re=dynamic_cast<const Reel*>(&nb);
        if(tmp_re==0){ //Si echec on essaye en Rationnel
            const Rationnel* tmp_ra=dynamic_cast<const Rationnel*>(&nb);
            if(tmp_ra==0){
                const Complexe* tmp_c = dynamic_cast<const Complexe*>(&nb);
                if(tmp_c == 0){
                    const Exp* tmp_exp = dynamic_cast<const Exp*>(&nb);
                    if(tmp_exp == 0){
                        LogSystem::ecrireLog(LogMessage("Erreur classe reel ",ERREUR));
                        throw CalculatriceException(typeid(this).name(),OTHER,"Echec dynamic_cast");
                    }
                    else{
                        Constante* res=new Exp(toString());
                        Constante& ref=res->soustraction(nb);
                        delete res;
                        return(ref);
                    }
                }
                else {
                    Constante& ref = tmp_c->soustraction(*this);
                    return (ref);
                }
            }
            else{ //Si succès on réalise la division Reel / Rationnel
                Constante& ref=toRationnel().division(*tmp_ra);
                return (ref);
            }
        }
        else{ //Si succÃ¨s on rÃ©alise la division Reel / Reel
            if(tmp_re->get_x()==0) //Si division par 0 Exception
                throw CalculatriceException(typeid(nb).name(),MATHS,"Division par 0");
            Reel* res=new Reel(this->_x / tmp_re->get_x());
            Constante& ref=*res;
            return (ref);
        }
    }
    else{ //Si succès on réalise la division Reel / Entier
        Constante& pt=tmp_en->division(*this);
        Nombre* pt2=dynamic_cast<Nombre *>(&pt);
        Constante& ref=pt2->INV();
        return (ref);
    }
}


QString LO21::Reel::toString() const{
    QString str;
    str.setNum(_x);
    return str;
}

LO21::Reel* LO21::Reel::clone() const{ return new Reel(*this); }

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

LO21::Rationnel& LO21::Reel::toRationnel() const{
    //Conversion du rÃ©el en rationnel 3.31 = 331/100
    QString str;
    str.setNum(_x); //CrÃ©ation d'un QString depuis le Reel

    QStringList list=str.split("."); //Séparation partie entiere et decimale
    int nbdec=list.value(1).count(); //Compte le Constante de décimale

    Rationnel* res= new Rationnel(_x * pow(10.,nbdec), pow(10.,nbdec));
    res->simplifier();
    Rationnel& ref=*res;
    return (ref); //Construction du Rationnel correspondant au Reel +1 car valeur tronquÃ©e
}


LO21::Entier& LO21::Reel::toEntier() const{
    //Conversion du rÃ©el en entier 3.0 = 3
    Entier* res= new Entier(_x);
    Entier& ref=*res;
    return (ref);
}

LO21::Complexe& LO21::Reel::toComplexe() const {
    //Conversion du r�el en complexe 3.0 = 3.0 + 0.0i
    const Constante* a = (Constante*)this;
    const Constante* b = new Reel(0);
    Complexe* res = new Complexe(*a,*b);
    Complexe& ref = *res;
    return (ref);

}
